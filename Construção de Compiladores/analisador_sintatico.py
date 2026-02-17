import csv
from analisador_lexico_codificacao_direta import AnalisadorLexico, Token


class No:
    """
    Representa um nó na árvore sintática concreta.
    Estrutura encadeada para representar a árvore de derivação.
    """

    def __init__(self, simbolo, tipo='nao_terminal'):
        self.simbolo = simbolo  # Nome do símbolo (terminal ou não-terminal)
        self.tipo = tipo  # 'terminal' ou 'nao_terminal'
        self.filhos = []  # Lista de nós filhos
        self.token = None  # Para terminais, guarda o token correspondente

    def adicionar_filho(self, filho):
        """Adiciona um filho ao nó"""
        self.filhos.append(filho)

    def __str__(self):
        """Representação em string do nó"""
        if self.tipo == 'terminal':
            return f"{self.simbolo}"
        return f"<{self.simbolo}>"

    def imprimir_arvore(self, nivel=0, prefixo="", eh_ultimo=True):
        """
        Imprime a árvore sintática de forma hierárquica e bonita
        Formato: raiz no topo, filhos abaixo
        """
        if nivel == 0:
            # Raiz da árvore
            print(f"\n{self}")
        else:
            # Determina o conector
            conector = "└── " if eh_ultimo else "├── "
            print(f"{prefixo}{conector}{self}")

        # Calcula o prefixo para os filhos
        if nivel == 0:
            novo_prefixo = ""
        else:
            extensao = "    " if eh_ultimo else "│   "
            novo_prefixo = prefixo + extensao

        # Imprime os filhos
        for i, filho in enumerate(self.filhos):
            eh_ultimo_filho = (i == len(self.filhos) - 1)
            filho.imprimir_arvore(nivel + 1, novo_prefixo, eh_ultimo_filho)


class TabelaPreditiva:
    """
    Representa a tabela de análise preditiva M[Não-Terminal, Terminal]
    """

    def __init__(self, arquivo_csv):
        self.tabela = {}  # Dicionário: {(nao_terminal, terminal): numero_producao}
        self.producoes = {}  # Dicionário: {numero: (cabeca, corpo)}
        self.nao_terminais = set()
        self.terminais = set()
        self._carregar_tabela(arquivo_csv)
        self._definir_producoes()

    def _carregar_tabela(self, arquivo_csv):
        """Carrega a tabela de análise do arquivo CSV"""
        with open(arquivo_csv, 'r', encoding='utf-8') as f:
            leitor = csv.reader(f)
            linhas = list(leitor)

            # Linha 2 contém os terminais (colunas)
            cabecalho = linhas[1]
            terminais = [t.strip() for t in cabecalho[2:] if t.strip()]
            self.terminais = set(terminais)

            # Linhas 3 em diante contém as produções
            for linha in linhas[2:]:
                if len(linha) < 2 or not linha[1].strip():
                    continue

                nao_terminal = linha[1].strip()
                self.nao_terminais.add(nao_terminal)

                # Para cada terminal (coluna)
                for i, valor in enumerate(linha[2:], start=0):
                    if i >= len(terminais):
                        break

                    valor = valor.strip()
                    if valor and valor.isdigit():
                        terminal = terminais[i]
                        self.tabela[(nao_terminal, terminal)] = int(valor)

    def _definir_producoes(self):
        """
        Define todas as produções da gramática.
        Número da produção -> (cabeça, [corpo])
        """
        self.producoes = {
            0: ('<programa>', ['MAIN', 'ABRE_CHAVES', '<bloco>', 'FECHA_CHAVES']),
            1: ('<bloco>', ['<comando>', '<bloco>']),
            2: ('<bloco>', ['ε']),
            3: ('<comando>', ['<declaracao>']),
            4: ('<comando>', ['<atribuicao>']),
            5: ('<comando>', ['<estrutura_controle>']),
            6: ('<declaracao>', ['<tipo>', '<lista_declaracao>', 'PONTO_VIRGULA']),
            7: ('<tipo>', ['VOID']),
            8: ('<tipo>', ['INT']),
            9: ('<tipo>', ['CHAR']),
            10: ('<tipo>', ['FLOAT']),
            11: ('<lista_declaracao>', ['<declaracao_simples>', '<lista_declaracao_rest>']),
            12: ('<lista_declaracao_rest>', ['VIRGULA', '<declaracao_simples>', '<lista_declaracao_rest>']),
            13: ('<lista_declaracao_rest>', ['ε']),
            14: ('<declaracao_simples>', ['ID', '<declaracao_simples_rest>']),
            15: ('<declaracao_simples_rest>', ['ε']),
            16: ('<declaracao_simples_rest>', ['ABRE_COLC', 'NUM', 'FECHA_COLC']),
            17: ('<declaracao_simples_rest>', ['ASSIGN', '<expressao>']),
            18: ('<atribuicao>', ['ID', '<atribuicao_rest>']),
            19: ('<atribuicao_rest>', ['ASSIGN', '<expressao>', 'PONTO_VIRGULA']),
            20: ('<atribuicao_rest>',
                 ['ABRE_COLC', '<expressao>', 'FECHA_COLC', 'ASSIGN', '<expressao>', 'PONTO_VIRGULA']),
            21: ('<estrutura_controle>', ['<if_then>']),
            22: ('<estrutura_controle>', ['<while>']),
            23: ('<estrutura_controle>', ['<for>']),
            24: ('<if_then>', ['IF', 'ABRE_PAREN', '<expressao_relacional>', 'FECHA_PAREN', 'THEN', '<bloco_comando>',
                               '<elsif_part>']),
            25: ('<elsif_part>',
                 ['ELSIF', 'ABRE_PAREN', '<expressao_relacional>', 'FECHA_PAREN', 'THEN', '<bloco_comando>',
                  '<elsif_part>']),
            26: ('<elsif_part>', ['<else_part>']),
            27: ('<else_part>', ['ELSE', '<bloco_comando>']),
            28: ('<else_part>', ['ε']),
            29: ('<bloco_comando>', ['ABRE_CHAVES', '<bloco>', 'FECHA_CHAVES']),
            30: ('<bloco_comando>', ['<comando>']),
            31: ('<while>', ['WHILE', 'ABRE_PAREN', '<expressao_relacional>', 'FECHA_PAREN', 'DO', '<bloco_comando>']),
            32: ('<for>',
                 ['FOR', 'ABRE_PAREN', '<atribuicao_for>', 'PONTO_VIRGULA', '<expressao_relacional>', 'PONTO_VIRGULA',
                  '<atribuicao_for>', 'FECHA_PAREN', 'DO', '<bloco_comando>']),
            33: ('<atribuicao_for>', ['ID', 'ASSIGN', '<expressao>']),
            34: ('<expressao_relacional>', ['<expressao>', '<expressao_relacional_rest>']),
            35: ('<expressao_relacional_rest>', ['<relop>', '<expressao>']),
            36: ('<expressao_relacional_rest>', ['ε']),
            37: ('<relop>', ['EQEQ']),
            38: ('<relop>', ['NE']),
            39: ('<relop>', ['LT']),
            40: ('<relop>', ['GT']),
            41: ('<relop>', ['LE']),
            42: ('<relop>', ['GE']),
            43: ('<expressao>', ['<termo>', '<expressao_rest>']),
            44: ('<expressao_rest>', ['SOMA', '<termo>', '<expressao_rest>']),
            45: ('<expressao_rest>', ['SUBTRACAO', '<termo>', '<expressao_rest>']),
            46: ('<expressao_rest>', ['ε']),
            47: ('<termo>', ['<potencia>', '<termo_rest>']),
            48: ('<termo_rest>', ['MULTIPLICACAO', '<potencia>', '<termo_rest>']),
            49: ('<termo_rest>', ['DIVISAO', '<potencia>', '<termo_rest>']),
            50: ('<termo_rest>', ['ε']),
            51: ('<potencia>', ['<fator>', '<potencia_rest>']),
            52: ('<potencia_rest>', ['POTENCIA', '<fator>', '<potencia_rest>']),
            53: ('<potencia_rest>', ['ε']),
            54: ('<fator>', ['ID', '<fator_rest>']),
            55: ('<fator>', ['NUM']),
            56: ('<fator>', ['CONST_CHAR']),
            57: ('<fator>', ['ABRE_PAREN', '<expressao>', 'FECHA_PAREN']),
            58: ('<fator>', ['SOMA', '<fator>']),
            59: ('<fator>', ['SUBTRACAO', '<fator>']),
            60: ('<fator_rest>', ['ABRE_COLC', '<expressao>', 'FECHA_COLC']),
            61: ('<fator_rest>', ['ε']),
        }

    def consultar(self, nao_terminal, terminal):
        """
        Consulta a tabela preditiva.
        Retorna o número da produção ou None se não houver entrada.
        """
        # Trata RELOP como caso especial (atributos do token)
        if terminal == 'RELOP':
            # Mapeia os atributos do RELOP para os terminais da tabela
            return self.tabela.get((nao_terminal, terminal))

        return self.tabela.get((nao_terminal, terminal))

    def obter_producao(self, numero):
        """Retorna a produção dado seu número"""
        return self.producoes.get(numero)


class AnalisadorSintatico:
    """
    Analisador Sintático Preditivo Dirigido por Tabela
    Constrói árvore sintática concreta
    """

    def __init__(self, tabela_csv):
        self.tabela = TabelaPreditiva(tabela_csv)
        self.pilha = []
        self.arvore_raiz = None
        self.pilha_nos = []  # Pilha paralela para construção da árvore
        self.derivacao = []  # Guarda a sequência de produções aplicadas

    def analisar(self, codigo_fonte):
        """
        Realiza a análise sintática do código fonte.
        Retorna a árvore sintática se bem-sucedido, None caso contrário.
        """
        # Inicializa o analisador léxico
        lexico = AnalisadorLexico(codigo_fonte)

        # Inicializa a pilha com símbolo inicial e $
        self.pilha = ['$', '<programa>']

        # Cria o nó raiz da árvore
        self.arvore_raiz = No('<programa>', 'nao_terminal')
        self.pilha_nos = [None, self.arvore_raiz]  # Paralelo à pilha de símbolos

        # Obtém o primeiro token
        token_atual = lexico.proximo_token()
        if token_atual is None:
            self._erro_sintatico(None, "Código fonte vazio")
            return None

        # Análise silenciosa (sem impressão passo-a-passo)
        while len(self.pilha) > 0:
            topo = self.pilha[-1]
            no_topo = self.pilha_nos[-1]

            # Obtém o tipo do token atual
            tipo_token = self._obter_tipo_token(token_atual)

            # Caso 1: Topo é terminal
            if topo not in self.tabela.nao_terminais:
                if topo == '$':
                    if tipo_token == '$':
                        print("\n" + "=" * 80)
                        print("✓ ANÁLISE SINTÁTICA CONCLUÍDA COM SUCESSO!")
                        print("=" * 80)
                        return self.arvore_raiz
                    else:
                        self._erro_sintatico(token_atual, f"Esperado fim de arquivo, mas encontrado {token_atual.tipo}")
                        return None

                elif topo == 'ε':
                    # Epsilon: apenas desempilha
                    self.pilha.pop()
                    self.pilha_nos.pop()
                    continue

                elif self._casar_terminal(topo, token_atual):
                    # Terminal casa com token
                    self.pilha.pop()
                    no_atual = self.pilha_nos.pop()

                    # Adiciona token ao nó terminal na árvore
                    if no_atual:
                        no_atual.token = token_atual

                    # Avança para próximo token
                    token_atual = lexico.proximo_token()
                    if token_atual is None:
                        token_atual = Token('$', -1, -1)
                else:
                    self._erro_sintatico(token_atual, f"Esperado '{topo}', mas encontrado '{token_atual.tipo}'")
                    return None

            # Caso 2: Topo é não-terminal
            else:
                # Consulta a tabela preditiva
                num_producao = self.tabela.consultar(topo, tipo_token)

                if num_producao is None:
                    self._erro_sintatico(token_atual,
                                         f"Não há produção para {topo} com entrada '{tipo_token}'. "
                                         f"Possíveis tokens esperados neste contexto.")
                    return None

                # Obtém a produção
                cabeca, corpo = self.tabela.obter_producao(num_producao)

                # Guarda a derivação
                self.derivacao.append((num_producao, cabeca, corpo))

                # Desempilha o não-terminal
                self.pilha.pop()
                no_atual = self.pilha_nos.pop()

                # Empilha os símbolos do corpo da produção (da direita para esquerda)
                # Mas adiciona filhos na ordem correta (da esquerda para direita)
                filhos_criados = []
                for simbolo in corpo:
                    if simbolo != 'ε':
                        # Cria nó filho na árvore
                        if simbolo in self.tabela.nao_terminais:
                            filho = No(simbolo, 'nao_terminal')
                        else:
                            filho = No(simbolo, 'terminal')

                        filhos_criados.append(filho)

                # Adiciona filhos na ordem correta à árvore
                for filho in filhos_criados:
                    no_atual.adicionar_filho(filho)

                # Empilha na ordem inversa (para processar da esquerda para direita)
                for filho in reversed(filhos_criados):
                    self.pilha.append(filho.simbolo)
                    self.pilha_nos.append(filho)

                # Se a produção for ε, adiciona nó epsilon
                if corpo == ['ε']:
                    filho_epsilon = No('ε', 'terminal')
                    no_atual.adicionar_filho(filho_epsilon)

        self._erro_sintatico(None, "Pilha vazia antes de consumir toda a entrada")
        return None

    def _obter_tipo_token(self, token):
        """Obtém o tipo do token para consulta na tabela"""
        if token is None or token.tipo == '$':
            return '$'

        # Caso especial: RELOP tem atributos
        if token.tipo == 'RELOP':
            # Retorna o atributo específico do RELOP
            return token.atributo

        return token.tipo

    def _casar_terminal(self, simbolo_esperado, token):
        """
        Verifica se o terminal esperado casa com o token atual.
        Trata casos especiais como RELOP.
        """
        if token is None:
            return False

        # Caso especial: RELOP
        if simbolo_esperado in ['EQEQ', 'NE', 'LT', 'GT', 'LE', 'GE']:
            return token.tipo == 'RELOP' and token.atributo == simbolo_esperado

        return simbolo_esperado == token.tipo

    def _erro_sintatico(self, token, mensagem):
        """Emite mensagem de erro sintático útil"""
        print("\n" + "=" * 100)
        print("ERRO SINTÁTICO DETECTADO")
        print("=" * 100)

        if token and hasattr(token, 'linha') and hasattr(token, 'coluna'):
            print(f"Localização: Linha {token.linha}, Coluna {token.coluna}")

        print(f"Descrição: {mensagem}")

        if token and hasattr(token, 'tipo'):
            print(f"Token problemático: {token.tipo}", end="")
            if hasattr(token, 'atributo') and token.atributo:
                print(f" (valor: {token.atributo})", end="")
            print()

        print("=" * 100)

    def imprimir_arvore(self):
        """Imprime a árvore sintática"""
        if self.arvore_raiz:
            print("\n" + "=" * 80)
            print("ÁRVORE SINTÁTICA CONCRETA")
            print("=" * 80)
            self.arvore_raiz.imprimir_arvore()
            print("=" * 80)
        else:
            print("Árvore sintática não foi construída (erro na análise)")

    def imprimir_derivacao(self):
        """Imprime a sequência de produções aplicadas"""
        print("\n=== Derivação (Sequência de Produções Aplicadas) ===\n")
        for i, (num, cabeca, corpo) in enumerate(self.derivacao, 1):
            print(f"{i}. Produção {num}: {cabeca} → {' '.join(corpo)}")


# ===== FUNÇÃO DE TESTE =====
def testar_analisador():
    """Testa o analisador sintático com exemplos"""

    # Código de teste 1: Programa válido simples
    codigo_teste_1 = """
main {
    int x;
    x := 10;
}
"""

    # Código de teste 2: Programa com estrutura de controle
    codigo_teste_2 = """
main {
    float contador := 10.5;
    int maximo := 50;

    if (contador >= 10.0) then {
        contador := contador + 1.0;
    }

    while (contador < maximo) do {
        contador := contador + 2.0;
    }
}
"""

    # Código de teste 3: Programa com erro sintático (falta ponto e vírgula)
    codigo_teste_3 = """
main {
    int x
    x := 10;
}
"""

    print("\n" + "=" * 80)
    print("TESTE 1: Programa Simples Válido")
    print("=" * 80)
    print(f"Código:\n{codigo_teste_1}")

    analisador = AnalisadorSintatico(
        'tabela_preditiva.csv')
    arvore = analisador.analisar(codigo_teste_1)
    if arvore:
        analisador.imprimir_arvore()

    print("\n\n" + "=" * 80)
    print("TESTE 2: Programa com Estruturas de Controle")
    print("=" * 80)
    print(f"Código:\n{codigo_teste_2}")

    analisador2 = AnalisadorSintatico(
        'tabela_preditiva.csv')
    arvore2 = analisador2.analisar(codigo_teste_2)
    if arvore2:
        analisador2.imprimir_arvore()

    print("\n\n" + "=" * 80)
    print("TESTE 3: Programa com Erro Sintático")
    print("=" * 80)
    print(f"Código:\n{codigo_teste_3}")
    print("(Esperado: erro - falta ';' após 'int x')\n")

    analisador3 = AnalisadorSintatico(
        'tabela_preditiva.csv')
    arvore3 = analisador3.analisar(codigo_teste_3)


if __name__ == "__main__":
    testar_analisador()