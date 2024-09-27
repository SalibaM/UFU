library(ggplot2)
library(class)
library(rpart) # calcula índice gini
library(rpart.plot)

cancer <- read.csv("cancer.csv", TRUE)
cancer <- na.omit(cancer)

n <- round(0.8*nrow(cancer))

indices_treino <-sample(1:nrow(cancer),n,FALSE)

treino <- cancer[indices_treino,]
teste <- cancer[-indices_treino,]

#. = todos
#uma árvore de decisão pode ser dividida em: 
#arvore classificação algo que já existe, regressão prever algum valor

modelo.arvore <- rpart(formula = diagnosis~ ., data = treino, method = "class")
rpart.plot(modelo.arvore, extra = 101)

previsao <- predict(modelo.arvore, newdata = cancer, type = "class")

mean(previsao == cancer$diagnosis)

#fazer matriz confusão

table(previsao, cancer$diagnosis)

#linha = modelo
#coluna = erro

#------------------------------------------------------------------------------

#BPM ALto
# Gs = Pv(1-Pv) + Pa(1-Pa) (esquerdo = SIM, índice de gini calcula pureza)
# = 8/10*2/10 + 2/10 * 8/10 = 32/100 

#Variável com maior pureza será escolhida como base da árvore de decisões

#pureza direita
# = 0

# G final = 14/10 * 32/100 + 4/14 * 0 = 32/140 = 0,23

#Colesterol Alto
# Gs = Pv(1-Pv) + Pa(1-Pa) (direita = Não, índice de gini calcula pureza)
# 4/11 *7/11 + 7/11*4/11 = 56/121 = 0,46

#Gn = 2/3 * 1/3 + 1/3* 2/3= 4/9

#G final = 11/14*56/121+ 3/14 * 4/9 = 0,46

#treino_padronizado <- scale(treino[,-1])
#Padronizando o treino nas colunas(só numérico)
#Tiramos espécies

#teste_padronizado <- scale(teste[,-1])

#classe_treino <- treino$diagnosis
#classe_teste <- teste$diagnosis