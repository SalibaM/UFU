#nrow mostra num. de linhas do conjunto de dados
set.seed(1711)
library(ggplot2)

iris
iris <- iris[sample(nrow(iris)),] #embaralhar dados de iris, especificamente 
#as linhas

# 80% de iris
n <- round(0.8*nrow(iris)) #arredondar para 80%
n #(120)

treinamento <- iris[1:n,] #pegar dados de iris de 1 até 120(estão embaralhados)
teste <- iris[-(1:n),] #pegar o que não foi pego(restante)

ggplot(data = treinamento, aes(x = Species))+
  geom_bar()+
  theme_classic()

ggplot(data = treinamento, aes(x = Petal.Length))+
  geom_histogram(bins = 20, fill = "blue")+
  theme_classic()

ggplot(treinamento, aes(y=Petal.Length))+
  geom_boxplot()+
  facet_wrap(~Species) #Separamos diferentes gráficos por espécies

#Relacionando com o boxplot
#summary(treinamento$Petal.Length)
#Min. 1st Qu.  Median    Mean 3rd Qu.    Max. 
#1.000   1.600   4.250   3.757   5.100   6.900 

ggplot(treinamento, aes(x = Petal.Length,y = Petal.Width, color = Species))+
  geom_point()

resultado <- c()

#ARVORE DE DECISÕES
for(j in 1:nrow(teste)){
  
  if(teste$Petal.Length[j] < 2.5){
    resultado[j] <- "setosa"
  } else {
    if(teste$Petal.Width[j] < 1.75){
      resultado[j] <- "versicolor"
    } else {
      resultado[j] <- "virginica"
    }
  }
  
}

#Para ver consistência,usar:
mean(teste$Species == resultado)