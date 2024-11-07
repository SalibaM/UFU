#APRENDIZADO NÃO SUPERVISIONADO
#O MODELO K-MEANS

#Queremos clusterizar objetos com semelhança entre si, calculando o "cetoide".
#Faremos isso pelos pixels da imagem, colorindo no final com 3 cores. Vamos compactar a imagem.

library(jpeg)

gatinhos <- readJPEG("6_Image.jpg")
str(gatinhos)
#altura, largura, rgb

R <- as.vector(gatinhos[,,1])

G <- as.vector(gatinhos[,,2])

B <- as.vector(gatinhos[,,3])

X <- rep(1:640, each = 640) #número é da largura e altura respectivamente.
X
Y<- rep(640:1, times = 640)
Y

dados <- data.frame(X,Y,R,G,B)
head(dados)


?kmeans

clusterizacao <- kmeans(x = dados[,3:5], centers = 3, nstart = 20)

clusterizacao$centers
cores <- rgb(clusterizacao$centers)
cluster <- as.factor(clusterizacao$cluster)

dados$cluster <- cluster
head(dados)


ggplot(data = dados, aes(x = X, y = Y, col = cluster))+
  geom_point()+
  scale_color_manual(values = cores)+
  theme_void()
