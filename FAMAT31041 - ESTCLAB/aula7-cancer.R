library(ggplot2)
library(class)


cancer <- read.csv("cancer.csv", TRUE)
cancer <- na.omit(cancer)

n <- round(0.8*nrow(cancer))

indices_treino <-sample(1:nrow(cancer),n,FALSE)
#Vamos sortear os pinguins que serão colocados no treino
#ao invés de só embaralhar

treino <- cancer[indices_treino,]

teste <- cancer[-indices_treino,]

treino_padronizado <- scale(treino[,-1])
#Padronizando o treino nas colunas(só numérico)
#Tiramos espécies

teste_padronizado <- scale(teste[,-1])

classe_treino <- treino$diagnosis
classe_teste <- teste$diagnosis

modelo1 <- knn(train = treino_padronizado, test = teste_padronizado, cl = classe_treino, k = 1)

mean(modelo1 == teste$diagnosis)


#MATRIZ DE CONFUSAO
#DIAGONAL PRINCIPAL SAO ACERTOS \
#DIAGONAL SECUNDARIA SAO ERROS /

mean(modelo1 == classe_teste)
table(modelo1,classe_teste)