#Mais uma aula de modelo linear. Avaliando ele com histogramas e muito mais...
#Suposições, etc...

#Hoje vamos relembrar intervalos de confiança.

populacao <- sample(0:1, size = 100000, replace = TRUE,prob = c(0.9,0.1))
valor_real <- mean(populacao)

amostra <- sample(populacao, size = 200, replace = TRUE)
media <- mean(amostra)

#Criaremos um intervalo para todo mundo da hipótese.
#Fizemos uma suposição baseada no conceito da doença, ou seja, 10% da população teria tal doença.
#Então, pelo intervalo, precisamos definir o que é "perto" de 0.10 ou longe.

#Precisamos determinar probabilisticamente os erros que cometeremos com a suposição de que 10% tem doença,
#já que não sabemos qual a %.

#Temos duas possibilidades de erro: supor errado e achar certo, supor certo e achar errado.

#Queremos que a taxa de erro de ambos seja muito pequena, mas quando uma aumenta, a outra diminui. Não
#temos como considerar os dois erros.

#ERRO 1 : Rejeitar H0 e H0 é verdadeiro. Vamos supor que é 0,05 (5%).
#Essa probabilidade será a probabilidade de eu olhar pra média rejeitando H0.
#Usamos aula passada, média sobre qualquer coisa é sempre uma distribuição normal...
#Vamos fazer tudo isso com a função:

?prop.test (TESTE DE HIPOTESE SE A VERDADEIRA PROPORCAO DA DOENCA é 0.10)


prop <- prop.test(sum(amostra == 1), 200, p = 0.1, alternative = "two.sided")

# x = soma dos sucessos
# n = tamanho da amostra
# p = probabilidade que queremos testar se tá certa, no caso 0.10

prop
#Solta o p valor,se tiver abaixo de 0.10, 2x
#0.9062 <- p-value

#------------------------------------------------------------------------------------
EXEMPLO COM CJTO DE DADOS DE REGRESSAO LINEAR
RECEITA DE BOLO ABAIXO


library(Stat2Data)
library(ggplot2)

data("Oysters")
Oysters

ggplot(Oysters,aes(x = TwoD, y = Volume))+ #Forma uma reta,portanto talvez há correlação.
  geom_point()

correlacao <- cor(Oysters$TwoD,Oysters$Volume)

#Portanto, faremos um teste de hipótese com a correlacao para determinar a incerteza...

cor.test(Oysters$TwoD,Oysters$Volume)
#Vai soltar um p-valor ( MINUSCULO ), estamos dentro da região crítica, rejeitamos hipótese nula e
#existe correlação portanto. P-valor menor rejeita.

ggplot(Oysters,aes(x = TwoD, y = Volume))+ #Forma uma reta,portanto talvez há correlação.
  geom_point()+
  geom_smooth(method = "lm")

modelo <- lm(formula = Volume  ~ TwoD  , Oysters)
summary(modelo)

#Agora,será que os erros fazem parte de uma distribuição normal?

hist(modelo$residuals)
#Não descartamos a possibilidade de isso ser uma distribuição normal...

shapiro.test(modelo$residuals)
#Maneira estatística por teste de shapiro, e como o p-valor é alto, não estamos rejeitando h0,
#então os erros estão normais.
