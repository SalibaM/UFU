media <- mean(sample(1:6,size = 500, replace = TRUE))

resultados <- c()

for(i in 1:1000){
  resultados[i] <- mean(sample(1:6,size = 500, replace = TRUE))
}

hist(resultados)

#-------------------

dados <- data.frame(resultados)

library(ggplot2)
ggplot(dados,aes(x = resultados))+
  geom_density(fill = "darkorange")+ #Curva que tenta aproximar essa distribuição normal
  theme_minimal()

#A média de uma coisa sempre será uma distribuição normal...
#Review sobre distribuição normal, variância, padronização de dados etc etc...
# ----------------------


populacao <- sample(0:1,size = 100000, replace = TRUE,prob = c(0.9,0.1))
valor_real <- mean(populacao) #Valor real em relação à população

amostra <- sample(populacao, size = 500, replace = TRUE)
media <- mean(amostra)
media


parte_inferior <- media - 1.96*(sqrt(media*(1-media))/sqrt(500)) #Intervalos
parte_superior <- media + 1.96*(sqrt(media*(1-media))/sqrt(500))

inferiores <- c()
superiores <- c()

for(k in 1:100){ #Realizando para ter vários intervalos de amostras diferentes
  
  amostra <- sample(populacao, size = 500, replace = TRUE)
  media <- mean(amostra)

  inferiores[k] <- media - 1.96*(sqrt(media*(1-media))/sqrt(500)) #Intervalos
  superiores[k] <- media + 1.96*(sqrt(media*(1-media))/sqrt(500))
  
}

inferiores[23]
superiores[23]

intervalos <- data.frame(inferiores,superiores,contador = 1:100)

# Agora, plotaremos todas as linhas em um gráfico para ver se há diferença ou não...

ggplot(data = intervalos)+
  geom_segment(aes(x = inferiores, xend = superiores, y = contador , yend = contador))+
  geom_vline(xintercept = valor_real, col = "red")
  

#Intervalo inferior passou valor real, é erro!
#Intervalo superior abaixo do valor real? Erro também!

categoria <- ifelse(intervalos$inferiores > valor_real | intervalos$superiores < valor_real, 0, 1)

intervalos$categoria <- as.factor(categoria)
#Adicionamos categoria no intervalo...

ggplot(data = intervalos)+
  geom_segment(aes(x = inferiores, xend = superiores, y = contador , yend = contador, col = categoria))+
  geom_vline(xintercept = valor_real, col = "red")
#Adicionamos agora, cores em relação a categoria
