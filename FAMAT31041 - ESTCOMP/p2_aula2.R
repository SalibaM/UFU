library(tidytext) #manipulação texto
library(dplyr) #manipulação dados
library(ggplot2) #visualizar dados
library(tidyr) # organizar cjto bagunçado
library(stopwords)
library(rvest) #raspagem de dados

url <- "https://www.bbc.com/portuguese/articles/c303ev01582o"

html <- read_html(url)
texto <- html |>
  html_elements("p.bbc-hhl7in") |>
  html_text2() |>
  paste(collapse = " ")

#Colocamos a classe do parágrafo para filtrar EXATAMENTE quais são os parágrafos
#Queremos concatenar isso, usando um paste, com collapse = ' '

conjunto <- data.frame(texto)
conjunto

#Colocamos o texto no data_frame, agora queremos separar ele em pedaços menores, os famosos tokens.
#unnest_tokens tem entradas: OUTPUT(nomes das colunas do dataframe) e INPUT(coluna do dataframe que contem o texto que eu quero quebrar)
#Count com coluna word vai contar todas as inserções de cada palavra, sort vai ordená-las do maior para o menor
#top_n mostra os top (*) que você quer

conjunto |>
  unnest_tokens(output = word, input = texto) |>
  count(word,sort = TRUE) |>
  top_n(10)

#Stopwords nos deixa focar nas palavras mais significativas de textos, tirando as mais comuns (presentes no stopwords) do nosso texto
#Mutate permite a gente reordenar de acordo com outra coluna
#anti_join tira tudo que nao está


stopwords_br <- data.frame(word = stopwords("pt"))

conjunto |>
  unnest_tokens(output = word, input = texto) |>
  anti_join(stopwords_br) |>
  count(word, sort = TRUE) |>
  top_n(10) |>
  mutate(word = reorder(word,n)) |>
  ggplot(aes(x = n, y = word))+
    geom_col(color = "lightblue", fill = "lightblue")+
    theme_minimal()

library(janeaustenr)
livro <- prideprejudice  

pride <- data.frame(livro)

stopwords_en <- data.frame(word = stopwords("en"))

pride |>
  unnest_tokens(output = word, input = livro) |>
  anti_join(stopwords_en) |> #retirei de pride as palavras mais comuns do inglês, para deixar as + significantes
  count(word, sort = TRUE) |>
    top_n(10) |>
    mutate(word = reorder(word,n)) |>
    ggplot(aes(x = n, y = word))+
      geom_col(color = "pink", fill = "lightblue")+
      theme_minimal()


#Pela biblioteca tidytext, vamos tentar ver qual capítulo é feliz ou triste

sentimentos <- get_sentiments("bing")
library(stringr)
capitulos <- str_detect(pride$livro, "^Chapter \\d+")
capitulos <- cumsum(capitulos)
#possibilita identificar quais linhas possuem capítulos e classificá-las como TRUE

library(tidyr)
#Uso do spread

#SEPARADO DO PRIDE DE CIMA PARA DAR CERTO

pride |>
  mutate(capitulo = capitulos) |>
  unnest_tokens(output = word, input = livro) |>
  inner_join(sentimentos) |> #inner_join permite relacionar as palavras que temos em uma com a coluna da outra
  count(capitulo, sentiment) |> #o contrário do anti_join
  spread(sentiment,n, fill = 0) |>
  mutate(total = positive - negative) |>
  ggplot(aes(x = capitulo, y = total)) +
    geom_col(color = "white", fill = "purple")+
    theme_minimal()
