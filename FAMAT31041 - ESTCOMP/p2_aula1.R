library(rvest)
library(dplyr)

url <- "https://www.bbc.com/portuguese/articles/cql3lwgl3ldo"

html <- read_html(url)
html

html |>
  html_elements("h1") |>
  html_text2()


html |>
  html_elements("p-bbc-hhl7in") |>
  html_text2()


library(tidytext)

?unnest_tokens
