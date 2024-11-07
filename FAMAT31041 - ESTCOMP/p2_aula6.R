grilo <- read.table(file = "grilo.txt", header = TRUE, sep = ',')

summary(grilo)
str(grilo)

library(ggplot2)

#X = temperatura
#Y = frequencia

correlacao <- cor(grilo$temperatura,grilo$frequencia)
#OU
correlacao <- cor(grilo)

ggplot(data = grilo, aes(x = frequencia))+
  geom_histogram(bins = 10,color = "pink")+
  theme_minimal()

ggplot(data = grilo, aes(x = temperatura, y = frequencia))+
  geom_point()+
  theme_minimal()+
  geom_smooth(method = 'lm', se = FALSE) #criar reta de regressao linear simples (lm = linear-model)

#Começamos a falar sobre intervalo de confiança, a parte cinza, para as estimativas pontuais do seu dado
#Ao adicionar se, tiramos esse intervalo.

#Coeficiente angular da reta vai trazer coisas interessantes para a análise:

modelo_linear <- lm(formula = frequencia ~ temperatura, data = grilo)
#Nesse modelo, em fórmula, colocamos qual variável está em função de qual. Nesse caso, freq e temp (var dep e indep).
#Aumentar 1 grau na temperatura do ambiente afetara 0.3812 na frequência

summary(grilo$temperatura)

#Começamos agora a fazer previsões:

w <- data.frame(temperatura = c(21,23.6,30.9))

predict(modelo_linear, newdata = w)
#Quando a temperatura for 21, qual será a minha frequência aproximadamente?
#Nos retorna isso...


#----------------------------------

library(palmerpenguins)


pinguim <- penguins
pinguim <- na.omit(pinguim)

cor(pinguim[,3:6],)

ggplot(data = pinguim, aes(x = flipper_length_mm, y = body_mass_g,color = species))+ #as melhores duas variáveis para correlação
  geom_point()+
  theme_minimal()+
  geom_smooth(method = 'lm')


library(dplyr)
pinguim |>
  filter(species == 'Chinstrap')|>
  select(flipper_length_mm,body_mass_g)|>
  cor() #Selecionando por espécie,a correlação diminui


modelo2 <- lm(formula = flipper_length_mm ~ body_mass_g + bill_length_mm, data = pinguim)
modelo2
summary(modelo2) #vamos aprender a ler isso na próxima aula, fazendo testes de hipótese
