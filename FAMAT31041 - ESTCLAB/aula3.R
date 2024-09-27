dados <- read.table(file = "titanic.txt", header = TRUE, sep = ",")

dados = dados[,c(-1,-12)]
#Questão de prova = Excluir colunas

dados$Survived <- as.factor(dados$Survived)
#Transforma dados em fator, e não mais na análise numérica
#Fator é quantos elementos cabem em cada possibilidade, quantidade

dados$Pclass <- as.factor(dados$Pclass)

sobreviventes <- sum(dados[,1])

summary(dados)

str(dados)
#Indica quais são factor, num, int etc etc...

dados[1,4]
#Primeira linha, quarta coluna...

dados[,4]

dados[c(10,6),]
#Concatenar para mostrar dois dados ( LINHA 10 e 6 )

homens <- dados[dados$Sex == "male",]
summary(homens)
table(homens$Survived)
barplot(table(homens$Survived))

mulheres <- dados[dados$Sex == "female",]
table(mulheres$Survived)
barplot(table(mulheres$Survived))
summary(mulheres)

sum(homens$Survived == 1)

homensT <- homens[homens$Pclass == "3",]

table(homensT$Survived)

library(ggplot2)