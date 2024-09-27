install.packages("ggplot2")
library(ggplot2)

titanic <- read.table(file = "titanic.txt", sep = ",", header = TRUE)

titanic <- titanic[,-c(1,9:12)] # Tirando colunas 1, e depois de 9 até 12
# 9 até 12 : 9:12 ou 9,10,11,12 :)

str(titanic)

titanic$Survived <- as.factor(titanic$Survived)  #Transformando em fator
# para facilitar uso
titanic$Pclass <- as.factor(titanic$Pclass)

titanic$Sex <- as.factor(titanic$Sex)

str(titanic) # Indica tipos/estruturas de dados

summary(titanic) # Resumo de cada variável da tabela

# aes é aesthetic, aparência do gráfico, definimos o eixo x...
#geom define tipo de gráfico (geométrico)
#theme é o tema

ggplot(data = titanic, aes(x = Survived))+
  geom_bar(color = "red", fill = "red")+
  theme_minimal()

#fill em aes quer fazer divisão entre sexo
#scale fill manual permite escolher cores da escala de acordo com valores

ggplot(data = titanic, aes(x = Survived, fill = Sex))+
  geom_bar()+
  scale_fill_manual(values = c("male" = "#5B99C2", "female" = "#F9DBBA"))+
  theme_minimal()

# esse gráfico é melhor por permitir entender a diferença
# quantitativa entre homens e mulheres, assim como a proporção
# de sobrevivência

ggplot(data = titanic, aes(x = Sex, fill = Survived))+
  geom_bar()+
  scale_fill_manual(values = c("0" = "#5B99C2", "1" = "#F9DBBA"))+
  theme_minimal()


#~ é em função de.
# facet_wrap divide em faces, utilizando outra variável
# labs permite adicionar título
#labels permite mudar nome dos elem. da legenda dentro de scale fill
#fill dentro de labs muda nome da legenda

ggplot(data = titanic, aes(x = Sex, fill = Survived))+
  geom_bar()+
  scale_fill_manual(values = c("0" = "#5B99C2", "1" = "#F9DBBA"),
                    labels = c("0" = "não", "1" = "sim"))+
  facet_wrap(~Pclass)+
  labs(titles = "Análise de sobrevivência de homens e mulheres por classe",
       fill = "Sobreviveu")+
  scale_x_discrete(labels = c("female" = "mulher", "male" = "homem"))+
  theme_classic()