femur <- read.csv("femur.csv")

#PASSO 1

femur_homens <- femur[femur$genero == "Male",]
str(femur_homens)

correlacao <- cor(femur_homens$altura,femur_homens$femur)

ggplot(data = femur_homens, aes( x = femur, y = altura))+
  geom_point()+
  geom_smooth(method = "lm")


#cor.test : teste de hipoteses para verificar se o coef. de correlação é zero.

#H0:coeficiente de correlacao é zero
#Ha:coeficiente de correlacao não é zero

cor.test(femur_homens$altura, femur_homens$femur)
#p-value < 2.2e-16 é muito menor que 5%, entao rejeitamos H0, portanto o
#coeficiente de correlação não é zero.
#se fosse zero já acabava.

#--------------------------------------------------------------------

#vamos determinar a reta de regressao (PASSO 2)

modelo <- lm(data = femur_homens, formula = altura ~ femur)
modelo


summary(modelo)
#intercept é a da reta
#femur é b da reta, não queremos que femur seja zero, já que a altura não estaria sendo explicada pelo femur.

#Eu posso rejeitar intercept, mas não femur. Rejeitar intercept continua mantendo a reta

#signif codes fala sobre quais os intervalos p está.

#----------------------------------------------------------------------


#Vamos agora, analisar os resíduos (PASSO 3)

hist(modelo$residuals)

#Para analisar melhor, vamos fazer outra análise, melhor dessa vez...
#Um teste de hipóteses para verificar se os resíduos seguem uma distribuição normal.

#H0:resíduos seguem uma distribuição normal
#Ha:resíduos não seguem distribuição normal

#Vamos torcer para p valor ser maior que 5%, para não rejeitarmos.

shapiro.test(modelo$residuals)

#Portanto modelo não serve, já que deu acima de 5%, e não queríamos que ele seguisse uma normal.
#PROVA : Dar modelo e falar se é bom ou não.
