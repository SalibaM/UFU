library(ggplot2)
library(palmerpenguins)
library(class)

data(penguins)
pinguins <- penguins
str(pinguins)

pinguins <- pinguins[,-c(2,7,8)]

pinguins <- na.omit(pinguins)

n <- round(0.8*nrow(pinguins))

indices_treino <-sample(1:nrow(pinguins),n,FALSE)
#Vamos sortear os pinguins que serão colocados no treino
#ao invés de só embaralhar

treino <- pinguins[indices_treino,]

teste <- pinguins[-indices_treino,]

treino_padronizado <- scale(treino[,-1])
#Padronizando o treino nas colunas(só numérico)
#Tiramos espécies

teste_padronizado <- scale(teste[,-1])

classe_treino <- treino$species
classe_teste <- teste$species

modelo1 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = 1)
#Classe(cl) separada para permitir knn entre os tipos numéricos de teste
#classe_treino são os nomes separados
#k = 1 vizinho (IGUAL AULA PASSADA SÓ QUE COM UM COMANDO)

mean(modelo1 == teste$species)
#Compara modelo de teste com espécies vendo qual a média de acertos

modelo2 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = 2)
mean(modelo1 == teste$species)

modelo3 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = 3)
mean(modelo1 == teste$species)

modelo4 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = 4)
mean(modelo1 == teste$species)

modelo5 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = 5)
mean(modelo1 == teste$species)

modelo6 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = 6)
mean(modelo1 == teste$species)

modelo7 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = 7)
mean(modelo1 == teste$species)

modelo8 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = 8)
mean(modelo1 == teste$species)

modelo9 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = 9)
mean(modelo1 == teste$species)

modelo10 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = 10)
mean(modelo1 == teste$species)

cor(treino[,-1])

#Fazer só com bico e peso, e bico com asa em casa
#Bico bico

taxa_acerto <- c()

for(k in 1:100){
  #AUMENTAMOS A QUANTIDADE DE VIZINHOS, A TABELA COMEÇA A INVADIR OUTROS PINGUINS
  
  modelo1 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = k)
  
  taxa_acerto[k] <- mean(modelo1==teste$species)
  
}


df <- data.frame(k = 1:100, taxa_acerto)

ggplot(data = df, aes(x = k, y = taxa_acerto))+
  geom_line()

#VALIDACAO CRUZADA
# 10 ou 5 pastas com qntds padronizadas
# Vai testando e aumentando quantidade



