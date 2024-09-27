a <- c(1,2,5)
b <- c(10,12)
d <- c(a,6)

3*a
3+a
d + b

#for no R
x <- 0
for(i in 1:20){
  x <- x + i
}
x

aniversarios <- sample(x=1:365, size = 10, replace = TRUE) #cria um dado
duplicated(aniversarios) #compara o vetor
any(duplicated(aniversarios)) #ve se tem algum igual, pelo menos 1


resultados <- c()
for(j in 1:10000){
  aniversarios <- sample(x=1:365, size = 10, replace = TRUE) #cria um dado
  resultados[j] <- any(duplicated(aniversarios))
}
mean(resultados) #media do vetor resultados

calcula_probabilidae <- function(n){
  resultados <- c()
  for(j in 1:10000){
    aniversarios <- sample(x=1:365, size = n, replace = TRUE) #cria um dado
    resultados[j] <- any(duplicated(aniversarios))
  }
  return(mean(resultados)) #media do vetor resultados
}
calcula_probabilidae(n = 23)




#MEGA SENA TOMA
bilhete <- c(14,2,25,39,47,51)
sorteio <- sample(x = 1:60, size = 6, replace = FALSE)
bilhete %in% sorteio

semanas <- 0
acertos <- 0

while(acertos < 4){
  sorteio <- sample(x = 1:60, size = 6, replace = FALSE)
  acertos <- sum(bilhete %in% sorteio)
  semanas <- semanas + 1
}
semanas/52