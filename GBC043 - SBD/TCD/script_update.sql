INSERT INTO funcionario (fun_cpf, fun_nome, fun_endereco, fun_telefone, fun_estado_civil, fun_data_nascimento, fun_nivel_formacao, fun_valor_hora_extra, fun_salario, fun_jornada_trabalho, fun_cpf_gerente, fnc_codigo) VALUES
('123.456.789-01', 'Luísa Mendes', 'Avenida Principal, 789', '(11) 98765-4321', 'Divorciada', '1982-09-15', 'Pós-graduação', 35.00, 5500.00, 44, NULL, 1);

INSERT INTO gerente (ger_data_ingresso, ger_formacao_basica, fun_cpf) VALUES
('2020-03-01', 'Contabilidade', '123.456.789-01');

UPDATE funcionario
SET fun_cpf_gerente = '123.456.789-01'
WHERE fnc_codigo = 3;


UPDATE produto 
SET prd_preco = prd_preco * 1.10 
WHERE sec_codigo IN ( 
  SELECT sec_codigo 
  FROM secao 
  WHERE cat_codigo = ( 
    SELECT cat_codigo 
    FROM categoria 
    WHERE cat_descricao = 'Laticínios' ));
