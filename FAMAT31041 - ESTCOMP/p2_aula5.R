# Com o tamanho do fêmur de uma pessoa, podemos prever a altura dela?
# Correlação é uma relação entre duas variáveis, podem ser representados por pares ordenados.
# EXEMPLO: (X,Y), onde X é a variável independente e Y a dependente.

#TIPOS : Correlação linear negativa = conforme X cresce, y diminui.
#        Correlação linear positiva = conforme X cresce, y cresce.
#        Correlação não linear = sem padrão

# Coeficiente de correlação

data(iris)

library(ggplot2)

ggplot(data = iris, aes(x = Petal.Length, y = Petal.Width))+
  geom_point()

cor(iris$Petal.Length,iris$Petal.Width) #Função entre correlação das duas

cor(iris[,-5]) # Matriz de correlação

setosa <- iris[iris$Species == "setosa",]
cor(setosa$Petal.Length,setosa$Petal.Width) #Correlação fraca em relação ao conjunto total

# Queremos fazer o gráfico de dispersão para identificar quais serão as variáveis
# e principalmente se elas tem sentido entre si. Correlação não implica necessariamente
# uma variável em função da outra.

#-----------------------------------------------------------------------------

femur$genero <- as.factor(femur$genero)
femur <- femur[,-1]

homens <- femur[femur$genero == "Male",]
mulheres <- femur[femur$genero == "Female",]

ggplot(data = mulheres, aes(x = altura, y = femur))+
  geom_point()

cor(homens$femur,homens$altura)
mean(homens$altura)

cor(mulheres$femur,mulheres$altura)

ggplot(data = homens, aes(x = altura, y = femur))+
  geom_point()

modelo_linear <- lm(data = homens, formula = altura ~ femur) #lm é linear_model, tiw(~) utilizado para indicar variável independente e dependente
modelo_linear

summary(homens$femur) #Informações do valor mínimo e máximo dessa variável (limites do eixo X), necessário para fazer previsões
