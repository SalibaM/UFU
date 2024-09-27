
type IdEstudante = Int
type Nome = String
type Sobrenome = String
type Idade = Int

data Estudantes = Estudantes { 
    idEstudante :: IdEstudante,
    nome :: Nome,
    sobrenome :: Sobrenome,
    idade :: Idade
} deriving (Show)

bancoEstudantes :: [Estudantes]
bancoEstudantes = []

adicionarEstudante :: IdEstudante -> Nome -> Sobrenome -> Idade -> [Estudantes] -> [Estudantes]
adicionarEstudante ident nome sobrenome idade lista = Estudantes ident nome sobrenome idade : lista

filtraEstudante :: IdEstudante -> [Estudantes] -> IO ()
filtraEstudante ident lista = do 
    let f = filter (\estudante -> idEstudante estudante == ident) lista
    case f of
        [] -> putStrLn "Estudante não encontrado." {-Tentamos fazer o controle dentro do menu, mas não conseguimos-}
        [estudante] -> do                          {-então, preferimos deixar ele dentro da função mesmo :)-}
            putStrLn "Estudante encontrado.\n" 
            putStrLn $ "ID:" ++ show (idEstudante estudante)
            putStrLn $ "Nome:" ++ nome estudante
            putStrLn $ "Sobrenome:" ++ sobrenome estudante
            putStrLn $ "Idade:" ++ show (idade estudante)

novoCadastroEstudante :: IdEstudante -> Nome -> Sobrenome -> Idade -> [Estudantes] -> [Estudantes]
novoCadastroEstudante ident nome sobrenome idade lista =
    map (\estudante -> if idEstudante estudante == ident
                        then Estudantes ident nome sobrenome idade
                        else estudante) lista

menu :: [Estudantes] -> IO ()
menu bancoEstudantes = do
    putStrLn "Bem-vindo ao sistema de cadastro de estudantes :)"
    putStrLn "Escolha uma opção:"
    putStrLn "1. Adicionar estudante"
    putStrLn "2. Filtrar estudante por ID"
    putStrLn "3. Atualizar informações do estudante"
    putStrLn "4. Sair"

    opcao <- getLine
    case opcao of
        "1" -> do
            putStrLn "Digite o ID do estudante:"
            ident <- readLn
            putStrLn "Digite o primeiro nome do estudante:"
            nome <- getLine
            putStrLn "Digite o sobrenome do estudante:"
            sobrenome <- getLine
            putStrLn "Digite a idade do estudante:"
            idade <- readLn
            let banco = adicionarEstudante ident nome sobrenome idade bancoEstudantes
            putStrLn "Estudante adicionado com sucesso!"
            putStrLn "Banco de dados atualizado:"
            print banco
            menu banco

        "2" -> do
            putStrLn "Digite o ID do estudante:"
            ident <- readLn
            filtraEstudante ident bancoEstudantes
            menu bancoEstudantes

        "3" -> do
            putStrLn "Digite o ID do estudante que voce deseja alterar:"
            ident <- readLn
            putStrLn "Nome atualizado do estudante:"
            nomeNovo <- getLine
            putStrLn "Sobrenome atualizado do estudante:"
            sobrenomeNovo <- getLine
            putStrLn "Idade atualizado do estudante:"
            idadeNova <- readLn
            let banco = novoCadastroEstudante ident nomeNovo sobrenomeNovo idadeNova bancoEstudantes
            putStrLn "Cliente atualizado com sucesso!"
            putStrLn "Banco de dados atualizado:"
            print banco
            menu banco

        "4" -> putStrLn "Saindo..."

        _ -> do
            putStrLn "Opção inválida.Tente novamente"
            menu bancoEstudantes

main :: IO ()
main = do
    menu bancoEstudantes