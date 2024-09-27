import System.Random
import System.IO(stdout,hSetBuffering,BufferMode(NoBuffering))

main::IO()
main = do
        hSetBuffering stdout NoBuffering
        putStrLn("Bem vindo ao jogo da adivinhacao!")
        putStrLn("Estou pensando em um numero de 1 a 100. Tente adivinhar.")
        numeroA <- randomRIO(1,100) :: IO Int
        jogarJogo 1 numeroA


jogarJogo :: Int -> Int -> IO()
jogarJogo t numeroA = do 
        putStrLn("Tentativa de número " ++ show t ++ ":")
        n <- getLine
        let nDigitado = read n :: Int
        if nDigitado==numeroA then do
                putStrLn("Correto! Voce acertou com " ++ show t ++ " tentativas!")
                r <- readFile "C:/Users/ANA FLAVIA/Desktop/highscore.txt"
                let record = read r :: Int
                if t<record then 
                        do putStrLn("Voce bateu o record!")
                           writeFile "C:/Users/ANA FLAVIA/Desktop/highscore.txt" ""
                           writeFile "C:/Users/ANA FLAVIA/Desktop/highscore.txt" (show t)
                else putStrLn("Jogue mais para tentar bater o seu record!")
                putStrLn("Deseja jogar novamente? Digite 's' se sim, ou qualquer outro pra sair.")
                op <- getLine
                if op=="s" then main else error("Saindo...")
                else if nDigitado>numeroA then do
                        putStrLn("O numero que voce digitou eh maior.Tente novamente...")
                        jogarJogo (t+1) numeroA
                        else if nDigitado<numeroA then do
                                putStrLn("O numero que voce digitou eh menor.Tente novamente...")
                                jogarJogo (t+1) numeroA
                                else error("Erro!")
        









        