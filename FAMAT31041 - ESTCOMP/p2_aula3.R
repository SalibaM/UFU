library(janeaustenr)
library(tidytext)
library(dplyr)
library(ggplot2)
library(stringr)
library(stopwords)


livros <- austen_books()
unique(livros$book)

#livros[livros$book == "Emma"]
#Basicamente o que filter faz...

stopwordsen <- data.frame(word = stopwords("en"))

livros |>
  filter(book == "Emma") |>
  unnest_tokens(output = word,input = text) |>
  #input e output
  anti_join(stopwordsen) |>
  count(word, sort = TRUE) |>
  top_n(10)
  

emma <- livros |>
  filter(book == "Emma")

# ^ em chapter é para identificar somente CHAPTER de capítulo,
# e não chapter escrito no meio do livro

#Colchetes pega todos os caracteres de uma só vez

capitulos <- str_detect(emma$text, "^CHAPTER [IVXLCDLM]+") #Identificando linhas que tinham capitulo

capitulos <- cumsum(capitulos) #Soma acumulada para identificar os capítulos
capitulos
emma$capitulos <- capitulos
str(emma)

#inner_join conecta sentimentos com palavra
#spread mostra positivos e negativos do capítulo na mesma linha
#mutate cria total baseado em positive e negative

emma |>
  unnest_tokens(word,text) |>
  anti_join(stopwordsen)|>
  inner_join(get_sentiments("bing"))|>
  count(capitulos, sentiment) |>
  spread(sentiment,n,fill = 0)|>
  mutate(total = positive - negative) |>
  ggplot(aes(x = capitulos, y = total)) +
  geom_col()

# regex tira restrições e instaura expressão regular para identificação
# estamos classificando linhas por capítulos

livros |>
  group_by(book)|>
  mutate(capitulos = cumsum(str_detect(text, regex("^chapter (\\d|[IVXCDLM])+", ignore_case = TRUE)))) |>
  ungroup() |>
  unnest_tokens(word, text) |>
  anti_join(stopwordsen) |>
  inner_join(get_sentiments("bing"),relationship = "many-to-many") |>
  count(book,capitulos,sentiment) |>
  spread(sentiment,n,fill = 0) |>
  mutate(total = positive - negative) |>
  ggplot(aes(x = capitulos, y = total, fill = book))+
  geom_col(show.legend = FALSE) +
  facet_wrap(~book, scales="free_x")
  
