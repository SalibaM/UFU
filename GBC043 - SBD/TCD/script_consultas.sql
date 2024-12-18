SELECT fun_nome,ped_valor_total,ped_data_previsao
FROM pedido ped, funcionario func, gerente ger
WHERE ped.fun_cpf = ger.fun_cpf 
AND func.fun_cpf = ger.fun_cpf
ORDER BY ped_data_previsao ASC

SELECT prd_descricao
FROM produto prd, secao sec
WHERE prd.sec_codigo = sec.sec_codigo 
AND sec_nome = 'Refrigerantes' -- defina aqui a seção

SELECT for_denominacao_social
FROM fornecedor forn, pedido ped
WHERE ped.for_nro_cadastro = forn.for_nro_cadastro 
AND ped.ped_quantidade = (
SELECT MAX(ped_quantidade) FROM pedido)

SELECT pro_codigo, pro_descricao, pro_data_inicio, pro_data_fim
FROM promocao
WHERE (pro_data_inicio BETWEEN '01-01-2024' AND '31-12-2024')
AND (pro_data_fim BETWEEN '31-01-2024' AND '31-12-2024') 
ORDER BY pro_data_inicio DESC;

SELECT fun.fun_cpf,fun_nome
FROM funcionario fun, propaganda pro
WHERE fun.fun_cpf = pro.fun_cpf 
AND pro.pro_codigo = '1'

SELECT * FROM promoção

SELECT cli.cli_cpf,cli_nome,com_forma_pagamento
FROM cliente cli, compra com
WHERE cli.cli_cpf = com.cli_cpf 
AND com.com_num_cupom_fiscal = 'CF005'

SELECT forn.for_denominacao_social, 
COUNT(prod.prd_nro_cadastro), AVG(prod.prd_preco)
FROM fornecedor forn, oferece_produto ofe, produto prod
WHERE forn.for_nro_cadastro = ofe.for_nro_cadastro 
AND ofe.prd_nro_cadastro = prod.prd_nro_cadastro
GROUP BY forn.for_nro_cadastro, forn.for_denominacao_social
HAVING AVG(prod.prd_preco) < 60

SELECT cat_descricao, SUM(prd_media_venda_mes)
FROM categoria cat, produto prod, secao sec
WHERE cat.cat_codigo = sec.cat_codigo 
AND sec.sec_codigo = prod.sec_codigo
GROUP BY cat_descricao
ORDER BY SUM(prd_media_venda_mes) DESC

SELECT forn.for_denominacao_social, COUNT (*)
FROM produto pro, fornecedor forn, oferece_produto ofe
WHERE pro.prd_qnt_estoque < 50 
AND pro.prd_nro_cadastro = ofe.prd_nro_cadastro 
AND forn.for_nro_cadastro = ofe.for_nro_cadastro
GROUP BY forn.for_denominacao_social

SELECT 
(SELECT COUNT(com.com_num_cupom_fiscal) 
FROM compra com, cliente cli 
WHERE com.cli_cpf = cli.cli_cpf
AND cli.cli_cpf IN (SELECT cli_cpf FROM diamante))
AS Diamante,
     
(SELECT COUNT(com.com_num_cupom_fiscal) 
FROM compra com, cliente cli 
WHERE com.cli_cpf = cli.cli_cpf
AND cli.cli_cpf IN (SELECT cli_cpf FROM ouro))
AS Ouro,
     
(SELECT COUNT(com.com_num_cupom_fiscal) 
FROM compra com, cliente cli 
WHERE com.cli_cpf = cli.cli_cpf
AND cli.cli_cpf IN (SELECT cli_cpf FROM prata))
AS Prata
