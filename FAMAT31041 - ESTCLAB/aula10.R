library(httr) #Não usaremos o rvest...
library(dplyr)
library(jsonlite)


url <- "https://blaze.ac/api/roulette_games/history?startDate=2024-08-14T16:48:28.307Z&endDate=2024-09-13T16:48:28.308Z&page=1"

GET(url)

content(GET(url))

dados<- content(GET(url),"text")

dados<- fromJSON(dados)
#Transforma tabela em data.frame :)

table(dados$records$color)


url_base <- "https://blaze.ac/api/roulette_games/history?startDate=2024-08-14T16:48:28.307Z&endDate=2024-09-13T16:48:28.308Z&page="

resultados <- c()

for(j in 1:50){
  url <- paste0(url_base, j)
  
  dados <- content(GET(url),"text")
  
  dados <- fromJSON(dados)
  
  resultados<- c(resultados, dados$records$color)
}


resultados

prop.table(table(resultados))

library(rvest)
library(dplyr)


url <- "https://www.letras.mus.br/kendrick-lamar/count-me-out/"

html <- read_html(url)

html |>
  html_elements("h1") |>
  html_text2()

letra <- html|>
  html_elements("div.lyric") |>
  html_elements("p") |>
  html_text2() |>
  paste(collapse = " ")

letra


library(tidytext)

library(ggplot2)

letra <- data.frame(letra)

letra |>
  unnest_tokens(output = word, input = letra) |>
  count(word,sort = TRUE)|>
  head(n = 10) |>
  ggplot(aes(y = word, x = n))+
  geom_col()











