

CREATE SCHEMA hipermercado
SET search_path TO hipermercado
SET datestyle TO DMY

CREATE TABLE categoria
(
  cat_codigo INT NOT NULL,
  cat_descricao VARCHAR NOT NULL,
  PRIMARY KEY (cat_codigo)
);

CREATE TABLE secao
(
  sec_codigo INT NOT NULL,
  sec_nome VARCHAR NOT NULL,
  cat_codigo INT NOT NULL,
  PRIMARY KEY (sec_codigo),
  FOREIGN KEY (cat_codigo) 
  	REFERENCES categoria(cat_codigo)
);


CREATE TABLE produto
(
  prd_nro_cadastro INT NOT NULL,
  prd_descricao VARCHAR NOT NULL,
  prd_media_venda_mes INT NOT NULL,
  prd_nome_fabricante VARCHAR NOT NULL,
  prd_unidade_venda VARCHAR NOT NULL,
  prd_foto BYTEA,
  prd_preco FLOAT NOT NULL CHECK (prd_preco > 0),
  prd_qnt_estoque INT NOT NULL,
  sec_codigo INT NOT NULL,
  PRIMARY KEY (prd_nro_cadastro),
  FOREIGN KEY (sec_codigo) 
REFERENCES secao(sec_codigo)
);

CREATE TABLE promocao
(
  pro_codigo INT NOT NULL,
  pro_descricao VARCHAR NOT NULL,
  pro_data_inicio DATE NOT NULL,
  pro_data_fim DATE NOT NULL,
  pro_nome VARCHAR NOT NULL,
  PRIMARY KEY (pro_codigo)
);


CREATE TABLE fornecedor
(
  for_nro_cadastro INT NOT NULL,
  for_valor_total_venda_ano_pas FLOAT NOT NULL,
  for_denominacao_social VARCHAR NOT NULL,
  for_desconto FLOAT NOT NULL,
  for_prazo_medio_entrega INT NOT NULL,
  for_pessoa_contato VARCHAR NOT NULL,
  for_email VARCHAR NOT NULL,
  for_condicao_pagamento VARCHAR NOT NULL,
  for_cidade VARCHAR NOT NULL,
  for_estado VARCHAR NOT NULL,
  for_bairro VARCHAR NOT NULL,
  for_cep VARCHAR NOT NULL,
  PRIMARY KEY (for_nro_cadastro)
);


CREATE TABLE cliente
(
  cli_cpf VARCHAR NOT NULL,
  cli_nome VARCHAR NOT NULL,
  cli_data_nascimento DATE NOT NULL,
  cli_gasto_total_ano_pas FLOAT NOT NULL,
  cli_profissao VARCHAR NOT NULL,
  cli_end_residencial VARCHAR NOT NULL,
  PRIMARY KEY (cli_cpf)
);


CREATE TABLE diamante
(
  dia_gasto_minimo FLOAT NOT NULL,
  cli_cpf VARCHAR NOT NULL,
  PRIMARY KEY (cli_cpf),
  FOREIGN KEY (cli_cpf) 
REFERENCES cliente(cli_cpf)
);

CREATE TABLE ouro
(
  our_gasto_minimo FLOAT NOT NULL,
  cli_cpf VARCHAR NOT NULL,
  PRIMARY KEY (cli_cpf),
  FOREIGN KEY (cli_cpf) 
REFERENCES cliente(cli_cpf)
);


CREATE TABLE prata
(
  pra_gasto_minimo FLOAT NOT NULL,
  cli_cpf VARCHAR NOT NULL,
  PRIMARY KEY (cli_cpf),
  FOREIGN KEY (cli_cpf) 
REFERENCES cliente(cli_cpf)
);


CREATE TABLE oferece_produto
(
  ofe_preco FLOAT NOT NULL CHECK (ofe_preco > 0),
  for_nro_cadastro INT NOT NULL,
  prd_nro_cadastro INT NOT NULL,
  PRIMARY KEY (for_nro_cadastro, prd_nro_cadastro),
  FOREIGN KEY (for_nro_cadastro) 
REFERENCES fornecedor(for_nro_cadastro),
  FOREIGN KEY (prd_nro_cadastro) 
REFERENCES produto(prd_nro_cadastro)
);


CREATE TABLE fornecedor_telefone
(
  for_telefone VARCHAR NOT NULL,
  for_nro_cadastro INT NOT NULL,
  PRIMARY KEY (for_telefone, for_nro_cadastro),
  FOREIGN KEY (for_nro_cadastro) 
REFERENCES fornecedor(for_nro_cadastro)
);


CREATE TABLE cliente_endereco
(
  cli_endereco_entrega VARCHAR NOT NULL,
  cli_cpf VARCHAR NOT NULL,
  PRIMARY KEY (cli_endereco_entrega, cli_cpf),
  FOREIGN KEY (cli_cpf) 
REFERENCES cliente(cli_cpf)
);


CREATE TABLE cliente_telefone
(
  cli_telefone VARCHAR NOT NULL,
  cli_cpf VARCHAR NOT NULL,
  PRIMARY KEY (cli_telefone, cli_cpf),
  FOREIGN KEY (cli_cpf) 
REFERENCES cliente(cli_cpf)
);

CREATE TABLE compra
(
  com_forma_pagamento VARCHAR NOT NULL,
  com_valor_total_desc FLOAT NOT NULL,
  com_valor_total FLOAT NOT NULL,
  com_horario TIME NOT NULL,
  com_data DATE NOT NULL,
  com_num_cupom_fiscal VARCHAR NOT NULL,
  cli_cpf VARCHAR NOT NULL,
  PRIMARY KEY (com_num_cupom_fiscal),
  FOREIGN KEY (cli_cpf) 
REFERENCES cliente(cli_cpf)
);



CREATE TABLE funcionario_funcao
(
  fnc_codigo INT NOT NULL,
  fnc_nome VARCHAR NOT NULL,
  PRIMARY KEY (fnc_codigo)
);


 
CREATE TABLE realiza_compra
(
  com_quantidade INT NOT NULL,
  com_desconto FLOAT NOT NULL,
  prd_nro_cadastro INT NOT NULL,
  com_num_cupom_fiscal VARCHAR NOT NULL,
  cli_cpf VARCHAR NOT NULL,
  PRIMARY KEY (prd_nro_cadastro, cli_cpf),
  FOREIGN KEY (prd_nro_cadastro) 
REFERENCES produto(prd_nro_cadastro),
  FOREIGN KEY (com_num_cupom_fiscal) 
REFERENCES compra(com_num_cupom_fiscal),
  FOREIGN KEY (cli_cpf) 
REFERENCES cliente(cli_cpf)
);

CREATE TABLE funcionario
(
  fun_cpf VARCHAR NOT NULL,
  fun_nome VARCHAR NOT NULL,
  fun_endereco VARCHAR NOT NULL,
  fun_telefone VARCHAR NOT NULL,
  fun_estado_civil VARCHAR NOT NULL,
  fun_data_nascimento DATE NOT NULL 
CHECK (fun_data_nascimento <= 
CURRENT_DATE - INTERVAL '18 years'),
  fun_nivel_formacao VARCHAR NOT NULL,
  fun_valor_hora_extra FLOAT NOT NULL,
  fun_salario FLOAT NOT NULL,
  fun_jornada_trabalho INT NOT NULL,
  fun_cpf_gerente VARCHAR,
  fnc_codigo INT NOT NULL,
  PRIMARY KEY (fun_cpf),
  FOREIGN KEY (fnc_codigo) 
REFERENCES funcionario_funcao(fnc_codigo)
);
 

CREATE TABLE gerente
(
  ger_data_ingresso DATE NOT NULL,
  ger_formacao_basica VARCHAR NOT NULL,
  fun_cpf VARCHAR NOT NULL,
  PRIMARY KEY (fun_cpf),
  FOREIGN KEY (fun_cpf) 
REFERENCES funcionario(fun_cpf)
);


ALTER TABLE funcionario
ADD FOREIGN KEY (fun_cpf_gerente) 
REFERENCES gerente(fun_cpf);


CREATE TABLE pedido
(
  ped_codigo INT NOT NULL,
  ped_quantidade INT NOT NULL,
  ped_valor_desc FLOAT NOT NULL,
  ped_valor_total FLOAT NOT NULL,
  ped_devolucao VARCHAR NOT NULL,
  ped_data_entrega DATE NOT NULL,
  ped_data_previsao DATE NOT NULL,
  ped_data_emissao DATE NOT NULL,
  for_nro_cadastro INT NOT NULL,
  prd_nro_cadastro INT NOT NULL,
  fun_cpf VARCHAR NOT NULL,
  PRIMARY KEY (ped_codigo),
  FOREIGN KEY (for_nro_cadastro) 
REFERENCES fornecedor(for_nro_cadastro),
  FOREIGN KEY (prd_nro_cadastro) 
REFERENCES produto(prd_nro_cadastro),
  FOREIGN KEY (fun_cpf) 
REFERENCES gerente(fun_cpf),
  CHECK (ped_data_previsao >= ped_data_emissao),
  CHECK (ped_data_entrega >= ped_data_emissao)
);



CREATE TABLE empacotador
(
  fun_cpf VARCHAR NOT NULL,
  PRIMARY KEY (fun_cpf),
  FOREIGN KEY (fun_cpf) 
REFERENCES funcionario(fun_cpf)
);



CREATE TABLE marketing
(
  mar_portfolio VARCHAR NOT NULL,
  mar_formacao_basica VARCHAR NOT NULL,
  fun_cpf VARCHAR NOT NULL,
  PRIMARY KEY (fun_cpf),
  FOREIGN KEY (fun_cpf) 
REFERENCES funcionario(fun_cpf)
);


CREATE TABLE propaganda
(
  prd_nro_cadastro INT NOT NULL,
  pro_codigo INT NOT NULL,
  fun_cpf VARCHAR NOT NULL,
  PRIMARY KEY (prd_nro_cadastro, pro_codigo),
  FOREIGN KEY (prd_nro_cadastro) 
REFERENCES produto(prd_nro_cadastro),
  FOREIGN KEY (pro_codigo) 
REFERENCES promocao(pro_codigo),
  FOREIGN KEY (fun_cpf) 
REFERENCES marketing(fun_cpf)
);

CREATE TABLE atendente_padaria
(
  fun_cpf VARCHAR NOT NULL,
  PRIMARY KEY (fun_cpf),
  FOREIGN KEY (fun_cpf) 
REFERENCES funcionario(fun_cpf)
);

CREATE TABLE faxineiro
(
  fun_cpf VARCHAR NOT NULL,
  PRIMARY KEY (fun_cpf),
  FOREIGN KEY (fun_cpf) 
REFERENCES funcionario(fun_cpf)
);

CREATE TABLE atendente_caixa
(
  fun_cpf VARCHAR NOT NULL,
  PRIMARY KEY (fun_cpf),
  FOREIGN KEY (fun_cpf) 
REFERENCES funcionario(fun_cpf)
);


CREATE TABLE registra_compra
(
  com_num_cupom_fiscal VARCHAR NOT NULL,
  fun_cpf VARCHAR NOT NULL,
  PRIMARY KEY (com_num_cupom_fiscal, fun_cpf),
  FOREIGN KEY (com_num_cupom_fiscal) 
REFERENCES compra(com_num_cupom_fiscal),
  FOREIGN KEY (fun_cpf) 
REFERENCES atendente_caixa(fun_cpf)
);

CREATE TABLE repositor
(
  fun_cpf VARCHAR NOT NULL,
  PRIMARY KEY (fun_cpf),
  FOREIGN KEY (fun_cpf) 
REFERENCES funcionario(fun_cpf)
);


CREATE TABLE responsavel_secao
(
  fun_cpf VARCHAR NOT NULL,
  sec_codigo INT NOT NULL,
  PRIMARY KEY (fun_cpf, sec_codigo),
  FOREIGN KEY (fun_cpf) 
REFERENCES repositor(fun_cpf),
  FOREIGN KEY (sec_codigo) 
REFERENCES secao(sec_codigo)
);

CREATE TABLE esta_incluido
(
  pro_desc_diamante INT NOT NULL,
  pro_desc_ouro INT NOT NULL,
  pro_desc_prata INT NOT NULL,
  prd_nro_cadastro INT NOT NULL,
  pro_codigo INT NOT NULL,
  PRIMARY KEY (prd_nro_cadastro, pro_codigo),
  FOREIGN KEY (prd_nro_cadastro) REFERENCES produto(prd_nro_cadastro),
  FOREIGN KEY (pro_codigo) REFERENCES promocao(pro_codigo)
);
