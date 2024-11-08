cerebelo <- read.csv("cerebelo.csv") #Lendo conjunto de dados

----------------

ggplot(cerebelo, aes(x = Body_g, y = Cerebellum_g))+ #Gráfico de dispersão sem reta
  geom_point()

ggplot(cerebelo, aes(x = Log_body, y = Log_cerebellum))+ #Gráfico de dispersão sem reta
  geom_point()

---------------

correlacao_g <- cor(cerebelo$Body_g,cerebelo$Cerebellum_g) #Correlação de duas variáveis

correlacao_log <- cor(cerebelo$Log_body,cerebelo$Log_cerebellum) #Correlação de duas variáveis

---------------

modelo <- lm(data = cerebelo, formula = Log_body ~ Log_cerebellum) #Modelo linear pra equação da reta

summary(modelo) #Conseguir equação da reta

# A = Intercept
# B = outra variável    EQUAÇÃO DA RETA : ax + by = 0

cor.test(cerebelo$Log_body,cerebelo$Log_cerebellum) #Teste de hipótese para ver se rejeita ou aceita

#P-valor menor que 5%, rejeita H0.

#H0 = índice de correlação é zero (se for esse, acaba aqui)
#Ha = índice que correlação não é zero (se não, analisamos resíduos para ver se é o modelo é bom ou ruim)

---------------

ggplot(cerebelo, aes(x = Body_g, y = Cerebellum_g))+  #Gráfico de dispersão com reta
  geom_point()+
  geom_smooth(method = "lm")

ggplot(cerebelo, aes(x = Log_body, y = Log_cerebellum))+ #Gráfico de dispersão com reta
  geom_point()+ 
  geom_smooth(method = "lm")

---------------

shapiro.test(modelo$residuals) #Ver se resíduos seguem distribuição normal.

#P-valor menor que 5%, rejeita H0

#H0 = resíduos seguem uma distribuição normal (se der aqui, é ruim)
#Ha = resíduos não seguem a distribuição normal (se der aqui, é bom)
 
