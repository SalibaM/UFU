#MODELO KNN

#Basicamente, no modelo KNN, utilizaremos os dados de vizinhos mais próximos a um dado
# para classificá-lo. E para isso, na maioria das vezes, usaremos o gráfico de pontos também

Vamos iniciar nosso trabalho lendo o pacote 'palmerpenguins' e salvando o conjunto em um objeto chamado 'penguins'.


library(palmerpenguins) #Lendo o pacote
pinguins <- penguins
str(pinguins) #Estrutura do objeto.


A seguir, vamos imprimir um resumo estatístico dos dados de cada uma das variáveis digitadas :)


summary(pinguins) #Resumo estatístico


A partir do resumo das variáveis, identificamos alguns valores faltantes(NAs), vamos removê-los.

pinguins <- na.omit(pinguins)
summary(pinguins)



pinguins <- pinguins[sample(nrow(pinguins)),]
n <- round(0.8*nrow(pinguins))

treino <- pinguins[(1:n),]
teste <- pinguins[-(1:n),]


Criando gráficos...


library(ggplot2)

ggplot(treino,aes(x=species,y=flipper_length_mm))+
  geom_boxplot()+
  theme_classic()

ggplot(treino,aes(x=body_mass_g,y=bill_length_mm,color=species))+
  geom_point()+
  theme_classic()


Classificando o primeiro pinguim do teste:


distancia <- c()

for(k in 1:nrow(treino)){
  distancia[k] <- sqrt((teste$body_mass_g[1] - treino$body_mass_g[k])*2 + (teste$bill_length_mm[1] - treino$bill_length_mm[k])*2)


treino$species[order(distancia)[1]]
teste$species[1]


distancia <- c()
classificacao <- c()

for(j in 1:nrow(teste)){
for(k in 1:nrow(treino)){
  distancia[k] <- sqrt((teste$body_mass_g[j] - treino$body_mass_g[k])**2 + (teste$bill_length_mm[j] - treino$bill_length_mm[k])**2)
}
  classificacao[j] <- as.character(treino$species[order(distancia)[1]])
}

mean(teste$species == classificacao)


# ------------------------------------------------------

Fazer o modelo KNN na mão é bem mais difícil, por isso, usamos a função knn, que vai nos dar a mesma análise
de forma MUITO mais fácil.

library(class)

cancer <- read.csv("cancer.csv", TRUE)
cancer <- na.omit(cancer)

n <- round(0.8*nrow(cancer))

indices_treino <-sample(1:nrow(cancer),n,FALSE)

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










