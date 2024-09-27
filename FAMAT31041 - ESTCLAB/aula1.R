#operações

2+5
2-3
2*3
2/3
30**2 #potenciação
10%%3

#atribuindo valores

a <- 3*2
4*3 -> b

class(a) #Pega classe de cada variável
class(1)

d <- TRUE
class(d)

d+a #TRUE = 1 e FALSE = 0

FALSE + a
TRUE + TRUE
TRUE + FALSE
FALSE + FALSE

TRUE + FALSE/FALSE
TRUE/FALSE #Infinito

v1 <- 4+3
V1 <- 4*9

x <- "teste" 
class(x)

#criando vetores
#função combine(concatenar)

x1 <- c(3,10,78) #cria vetor
length(x1)
sum(x1)
mean(x1) #média do vetor

x2 <- c(1,6,"teste") #tudo vira string

x1[2]
x1[c(2,3)]
x1[c(2,3,1,2)]

x2 <- c(x1,1,2,3)
x2
x2 < 70

sum(x2 < 70)

x2[x2<70]

x2 > 54
x2 == 10
x2 != 10
!TRUE

TRUE | FALSE #ou
TRUE & FALSE #e

p <- TRUE
q <- FALSE

#sample(x, size, replace = FALSE, prob = NULL)
# intervalo, tamanho, reposição sim ou não, probabilidade específica

dado <- sample(x = 1:6, 1000000 ,replace = TRUE)
dado
dado[987]

sum(dado == 3)
mean(dado == 3)

table(dado)
barplot(table(dado))