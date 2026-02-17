# Explicação Completa do Analisador Sintático

---

## 1. VISÃO GERAL — Estrutura do Arquivo

O código é dividido em **3 classes** e **1 bloco de testes**:

```
analisador_sintatico.py
│
├── class No                    → Nó da árvore sintática
├── class TabelaPreditiva       → Tabela M[Não-Terminal, Terminal]
├── class AnalisadorSintatico   → Motor da análise preditiva
└── def testar_analisador()     → Testes
```

---

## 2. CLASSE `No` — O Nó da Árvore Sintática

Representa **um único nó** da árvore de derivação. Toda a árvore é formada
por objetos dessa classe encadeados entre si.

```python
class No:
    def __init__(self, simbolo, tipo='nao_terminal'):
        self.simbolo = simbolo  # Ex: '<programa>', 'INT', 'MAIN'
        self.tipo    = tipo     # 'terminal' ou 'nao_terminal'
        self.filhos  = []       # Lista de objetos No (filhos deste nó)
        self.token   = None     # Guarda o Token do léxico (só para terminais)
```

### Por que `filhos` é uma lista?
Porque cada nó pode ter **vários filhos**. Ex: `<programa>` tem 4 filhos:
```
<programa>
├── MAIN
├── ABRE_CHAVES
├── <bloco>
└── FECHA_CHAVES
```

### Métodos

**`adicionar_filho(filho)`**
Simplesmente faz `self.filhos.append(filho)`. Chamado durante a análise para
montar a árvore à medida que as produções são aplicadas.

**`__str__()`**
Define como o nó aparece quando impresso:
- Se terminal:     imprime  `MAIN`, `INT`, `ID`, etc.
- Se não-terminal: imprime  `<programa>`, `<bloco>`, etc.

**`imprimir_arvore(nivel, prefixo, eh_ultimo)`**
Método **recursivo** que percorre a árvore de cima para baixo e imprime
com os conectores visuais (`├──`, `└──`, `│`). A lógica é:

```
nivel == 0  → é a raiz, imprime sem conector
nivel > 0   → é filho, usa "└── " se for o último filho, ou "├── " caso contrário
```

O `prefixo` acumula os espaços e barras verticais `│` que formam as linhas
de continuação ao longo da árvore. Para cada filho:
- Se NÃO é o último: herda `prefixo + "│   "` (mantém a barra vertical)
- Se É o último:     herda `prefixo + "    "` (encerra a barra vertical)

---

## 3. CLASSE `TabelaPreditiva` — A Tabela M[NT, T]

Responsável por carregar e consultar a tabela de análise preditiva.
Armazena dois dicionários principais:

```python
self.tabela     = { ('<programa>', 'MAIN'): 0, ('<bloco>', 'INT'): 1, ... }
self.producoes  = { 0: ('<programa>', ['MAIN', 'ABRE_CHAVES', ...]), ... }
self.nao_terminais = { '<programa>', '<bloco>', '<comando>', ... }
self.terminais     = { 'MAIN', 'INT', 'IF', 'WHILE', ... }
```

### Método `_carregar_tabela(arquivo_csv)`

Lê o arquivo CSV e popula `self.tabela`, `self.nao_terminais` e
`self.terminais`. O CSV tem este formato:

```
         | MAIN | VOID | INT | IF | ID | ...
<programa>|  0   |      |     |    |    |
<bloco>   |      |  1   |  1  | 1  | 1  |
...
```

O método percorre cada linha (não-terminal) e cada coluna (terminal),
e onde há um número, registra:
```python
self.tabela[('<programa>', 'MAIN')] = 0
self.tabela[('<bloco>', 'INT')]     = 1
# ...
```

Também coleta todos os não-terminais (coluna 1) e terminais (linha 1 do CSV)
nos conjuntos `self.nao_terminais` e `self.terminais`.

### Método `_definir_producoes()`

Define manualmente todas as **62 produções** da gramática no formato:
```python
numero: (cabeça, [corpo])

0:  ('<programa>',              ['MAIN', 'ABRE_CHAVES', '<bloco>', 'FECHA_CHAVES'])
1:  ('<bloco>',                 ['<comando>', '<bloco>'])
2:  ('<bloco>',                 ['ε'])
...
61: ('<fator_rest>',            ['ε'])
```

Cada entrada do dicionário `self.tabela` guarda um **número** (ex: `0`),
e `self.producoes` usa esse número para devolver o corpo correspondente.

### Método `consultar(nao_terminal, terminal)`

Faz a consulta principal: dado o topo da pilha e o token atual, qual
produção usar?

```python
self.tabela.get(('<bloco>', 'INT'))  →  1
self.tabela.get(('<bloco>', '$'))    →  None  (erro)
```

Retorna o número da produção, ou `None` se a célula estiver vazia (erro).

### Método `obter_producao(numero)`

Recebe um número e devolve a tupla `(cabeça, corpo)`:

```python
self.producoes.get(1)  →  ('<bloco>', ['<comando>', '<bloco>'])
```

Usado pelo analisador para saber quais símbolos empilhar e quais nós
filhos criar na árvore.

---

## 4. CLASSE `AnalisadorSintatico` — O Motor da Análise

É aqui que o algoritmo preditivo de fato acontece.

```python
def __init__(self, tabela_csv):
    self.tabela     = TabelaPreditiva(tabela_csv)  # A tabela M
    self.pilha      = []                           # Pilha de símbolos
    self.arvore_raiz = None                        # Raiz da árvore
    self.pilha_nos  = []                           # Pilha paralela de nós
    self.derivacao  = []                           # Produções aplicadas (opcional)
```

**`self.pilha` e `self.pilha_nos` são paralelas!**
Cada posição de `pilha` corresponde ao mesmo índice em `pilha_nos`:

```
pilha     = [ '$',  '<programa>' ]
pilha_nos = [ None, No('<programa>') ]
```

O `None` no fundo representa o `$` — ele não tem nó na árvore.

---

### Método `analisar(codigo_fonte)` — O Coração do Sistema

Este é o método principal. Implementa o algoritmo preditivo clássico.

**Inicialização:**
```python
lexico        = AnalisadorLexico(codigo_fonte)  # Cria o léxico
self.pilha    = ['$', '<programa>']             # Pilha começa com $ e símbolo inicial
self.arvore_raiz = No('<programa>', 'nao_terminal')
self.pilha_nos   = [None, self.arvore_raiz]     # Paralela à pilha
token_atual      = lexico.proximo_token()       # Primeiro token da entrada
```

**Loop principal — enquanto a pilha não estiver vazia:**

A cada iteração:
```python
topo       = self.pilha[-1]        # Peek no topo da pilha (não remove)
tipo_token = self._obter_tipo_token(token_atual)  # Tipo do token atual
```

Há dois casos possíveis:

---

**CASO 1 — Topo é terminal** (`topo not in self.tabela.nao_terminais`)

Três subcasos:

```
a) topo == '$' e tipo_token == '$'  →  ACEITA (fim da análise com sucesso)
b) topo == '$' e tipo_token != '$'  →  ERRO (sobrou entrada depois do fim)
c) topo == 'ε'                      →  desempilha epsilon, continua
d) topo casa com token_atual        →  desempilha topo, avança token
e) topo NÃO casa com token_atual    →  ERRO (token inesperado)
```

O "casar" significa que o terminal esperado bate com o token lido.
Quando casa, o token é associado ao nó na árvore:
```python
no_atual.token = token_atual   # Salva o token no nó folha
token_atual = lexico.proximo_token()  # Avança para o próximo
```

---

**CASO 2 — Topo é não-terminal** (`topo in self.tabela.nao_terminais`)

```python
# Consulta M[topo, tipo_token]
num_producao = self.tabela.consultar(topo, tipo_token)

# Se vazio → ERRO
if num_producao is None:
    self._erro_sintatico(...)

# Obtém o corpo da produção
cabeca, corpo = self.tabela.obter_producao(num_producao)

# Desempilha o não-terminal atual
self.pilha.pop()
no_atual = self.pilha_nos.pop()

# Cria os nós filhos na ordem correta (esquerda → direita)
filhos_criados = []
for simbolo in corpo:
    if simbolo != 'ε':
        filho = No(simbolo, tipo_adequado)
        filhos_criados.append(filho)

# Adiciona filhos ao nó atual da árvore (ordem correta)
for filho in filhos_criados:
    no_atual.adicionar_filho(filho)

# Empilha na ordem INVERSA (para processar da esquerda para direita)
for filho in reversed(filhos_criados):
    self.pilha.append(filho.simbolo)
    self.pilha_nos.append(filho)

# Produção epsilon: cria nó ε como filho
if corpo == ['ε']:
    no_atual.adicionar_filho(No('ε', 'terminal'))
```

**Por que empilhar ao contrário?**
A pilha é LIFO. Para processar `['MAIN', 'ABRE_CHAVES', '<bloco>', 'FECHA_CHAVES']`
da esquerda para a direita, precisamos empilhar da direita para a esquerda:
```
Empilha: FECHA_CHAVES, <bloco>, ABRE_CHAVES, MAIN
Pilha:   [... FECHA_CHAVES, <bloco>, ABRE_CHAVES, MAIN]  ← topo
Processa: MAIN primeiro ✓
```

---

### Método `_obter_tipo_token(token)`

Extrai o "tipo" do token para consulta na tabela. O caso especial é o
`RELOP`, cujo tipo genérico no léxico é `RELOP`, mas na tabela cada
operador relacional está separado (`EQEQ`, `NE`, `LT`, `GT`, `LE`, `GE`).

```python
Token(tipo='RELOP', atributo='GE')  →  retorna 'GE'
Token(tipo='INT')                   →  retorna 'INT'
token None ou '$'                   →  retorna '$'
```

### Método `_casar_terminal(simbolo_esperado, token)`

Verifica se o terminal no topo da pilha bate com o token atual.
O caso especial é novamente o RELOP: o símbolo na pilha é `GE` (por exemplo),
mas o token tem `tipo='RELOP'` e `atributo='GE'`.

```python
# Caso normal:
'INT' == token.tipo              → True/False

# Caso RELOP:
simbolo_esperado == 'GE'
token.tipo == 'RELOP' e token.atributo == 'GE'  → True
```

### Método `_erro_sintatico(token, mensagem)`

Imprime uma mensagem de erro formatada com:
- Linha e coluna do token problemático
- Descrição do erro
- Tipo e valor do token

### Método `imprimir_arvore()`

Chama `self.arvore_raiz.imprimir_arvore()`, que percorre recursivamente
toda a árvore de cima para baixo.

### Método `imprimir_derivacao()`

Opcional. Imprime a lista `self.derivacao`, que acumulou todas as
produções aplicadas durante a análise.

---

## 5. FLUXO COMPLETO — Do código fonte à árvore

```
USUÁRIO
  │
  │  analisador = AnalisadorSintatico('tabela.csv')
  ▼
AnalisadorSintatico.__init__()
  │
  ├──► TabelaPreditiva.__init__('tabela.csv')
  │       │
  │       ├──► _carregar_tabela()   → popula self.tabela {(NT,T): num}
  │       └──► _definir_producoes() → popula self.producoes {num: (cab,corpo)}
  │
  │  arvore = analisador.analisar(codigo_fonte)
  ▼
AnalisadorSintatico.analisar()
  │
  ├──► AnalisadorLexico(codigo_fonte)    → cria o léxico
  ├──► pilha    = ['$', '<programa>']   → inicializa pilha
  ├──► arvore_raiz = No('<programa>')   → cria raiz da árvore
  ├──► pilha_nos = [None, arvore_raiz]  → pilha paralela
  ├──► token_atual = lexico.proximo_token()  → pega 1º token
  │
  └──► LOOP: enquanto pilha não vazia
         │
         ├── topo = pilha[-1]
         ├── tipo_token = _obter_tipo_token(token_atual)
         │
         ├── [SE topo é TERMINAL]
         │     ├── topo == '$' e token == '$'  → ACEITA, retorna arvore_raiz
         │     ├── topo == 'ε'                 → desempilha, continua
         │     ├── _casar_terminal() == True   → desempilha, salva token no nó,
         │     │                                  lexico.proximo_token()
         │     └── _casar_terminal() == False  → _erro_sintatico(), retorna None
         │
         └── [SE topo é NÃO-TERMINAL]
               ├── tabela.consultar(topo, tipo_token) → num_producao
               ├── num_producao == None        → _erro_sintatico(), retorna None
               ├── tabela.obter_producao(num)  → (cabeca, corpo)
               ├── desempilha topo (pilha e pilha_nos)
               ├── cria nós filhos para cada símbolo do corpo
               ├── adiciona filhos ao nó atual (ordem normal)
               ├── empilha filhos ao contrário (ordem inversa)
               └── se corpo == ['ε'] → adiciona nó ε como filho
  │
  │  analisador.imprimir_arvore()
  ▼
No.imprimir_arvore()  [recursivo]
  │
  ├── imprime raiz
  └── para cada filho:
        └── filho.imprimir_arvore(nivel+1, novo_prefixo, eh_ultimo)
```

---

## 6. EXEMPLO CONCRETO — `int x;`

Dado o trecho `int x;`, veja o que acontece passo a passo:

```
Pilha inicial:  [$ | <programa>]   Token: MAIN  (do código completo)
...
Momento em que chegamos à declaração:

Pilha:  [... | <tipo> | <lista_declaracao> | PONTO_VIRGULA | ...]
Token:  INT

1. Topo = <tipo> (não-terminal)
   → consultar('<tipo>', 'INT') = 8
   → obter_producao(8) = ('<tipo>', ['INT'])
   → desempilha <tipo>
   → cria filho No('INT', 'terminal')
   → adiciona como filho do nó <tipo> na árvore
   → empilha 'INT'

2. Topo = INT (terminal)
   Token = INT
   → _casar_terminal('INT', token) = True
   → desempilha INT
   → no_atual.token = token  (salva o token INT no nó folha)
   → avança: token = ID ('x')

3. Topo = <lista_declaracao> (não-terminal)
   → consultar('<lista_declaracao>', 'ID') = 11
   → obter_producao(11) = ('<lista_declaracao>', ['<declaracao_simples>', '<lista_declaracao_rest>'])
   → cria filhos: No('<declaracao_simples>'), No('<lista_declaracao_rest>')
   → empilha ao contrário: <lista_declaracao_rest>, <declaracao_simples>

4. Topo = <declaracao_simples>
   → consultar = 14  →  ['ID', '<declaracao_simples_rest>']
   → cria filhos: No('ID'), No('<declaracao_simples_rest>')

5. Topo = ID (terminal)
   Token = ID ('x')
   → casa → salva token, avança: token = PONTO_VIRGULA

6. Topo = <declaracao_simples_rest>
   Token = PONTO_VIRGULA
   → consultar = 15  →  ['ε']
   → cria nó filho ε

7. Topo = <lista_declaracao_rest>
   Token = PONTO_VIRGULA
   → consultar = 13  →  ['ε']
   → cria nó filho ε

8. Topo = PONTO_VIRGULA (terminal)
   Token = PONTO_VIRGULA
   → casa → avança token

Resultado na árvore:
<declaracao>
├── <tipo>
│   └── INT          ← token salvo aqui
├── <lista_declaracao>
│   ├── <declaracao_simples>
│   │   ├── ID       ← token 'x' salvo aqui
│   │   └── <declaracao_simples_rest>
│   │       └── ε
│   └── <lista_declaracao_rest>
│       └── ε
└── PONTO_VIRGULA    ← token salvo aqui
```

---

## 7. RESUMO DAS RESPONSABILIDADES

| Classe / Método          | Responsabilidade                                      |
|--------------------------|-------------------------------------------------------|
| `No`                     | Representa um nó da árvore, encadeia filhos           |
| `No.imprimir_arvore()`   | Imprime a árvore recursivamente com formatação visual |
| `TabelaPreditiva`        | Armazena e consulta a tabela M[NT, T]                 |
| `_carregar_tabela()`     | Lê o CSV e monta o dicionário da tabela               |
| `_definir_producoes()`   | Define as 62 produções da gramática                   |
| `consultar()`            | Retorna o número da produção para M[NT, T]            |
| `obter_producao()`       | Retorna (cabeça, corpo) dado o número da produção     |
| `AnalisadorSintatico`    | Motor principal da análise preditiva                  |
| `analisar()`             | Loop principal do algoritmo preditivo                 |
| `_obter_tipo_token()`    | Extrai o tipo do token (trata RELOP especialmente)    |
| `_casar_terminal()`      | Verifica se terminal casa com token atual             |
| `_erro_sintatico()`      | Emite mensagem de erro com localização e descrição    |
| `imprimir_arvore()`      | Aciona a impressão da árvore a partir da raiz         |
| `imprimir_derivacao()`   | Imprime a sequência de produções aplicadas (opcional) |
