# Explicação sobre o Teorema de Bayes
# Falando sobre síndrome de patau

numerador <- (1/5000)*0.999
denominador <- ((1/5000) * 0.999) + ((4999/5000)*(1-0.999))

numerador/denominador
#Cerca de 16%

20*0.999
999980

#----------------------------------

# Teorema de Bayes tem total a ver com a classfificação de notícias
# tomando como base palavra em notícias específicas

library(dplyr)
library(tidytext)  
library(SnowballC) #lematização/radicalização (radical da palavra)
library(quanteda) #analise quantitativa texto
library(quanteda.textmodels) #modelagem de texto


stopwords_pt <- data.frame(word = stopwords("pt"))

noticias[1,] |>
  unnest_tokens(word,texto) |> #tornando texto inteiro em tokens
  anti_join(stopwords_pt) |> #tirando stopwords
  mutate(word = wordStem(word, "portuguese")) |> #lematização -> leva pro mesmo radical de palavras,pega só começo
  count(word, sort = TRUE) |>
  top_n(20)

#Agora, não usaremos mais unnest tokens, porque agora queremos os tokens + o texto desses tokens completos especificamente

noticias_tokens <- tokens(noticias$texto, remove_punct = TRUE, remove_symbols = TRUE, remove_url = TRUE) |>
            tokens_remove(stopwords("pt")) |>
            tokens_wordstem(language = "portuguese")


matriz_frequencia <- dfm(noticias_tokens) #criação de matriz

n <- round(0.8*nrow(noticias))
indices <- sample(1:nrow(noticias), size = n, replace = FALSE)


treino <- matriz_frequencia[indices,]
teste <- matriz_frequencia[-indices,]


modelo_nb <- textmodel_nb(treino, noticias$categorias[indices]) #Classifica teorema com base em Bayes


previsao <- predict(modelo_nb, newdata = teste)

mean(previsao == noticias$categorias[-indices])


# Para raspar várias notícias de um mesmo site, identificar lista de noticias da página e pegar com base no HTML uma rotina
# que mostre as páginas
