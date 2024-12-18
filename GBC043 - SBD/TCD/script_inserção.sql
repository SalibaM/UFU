SET search_path TO hipermercado;

INSERT INTO categoria (cat_codigo, cat_descricao) VALUES
(1, 'Alimentos'),
(2, 'Bebidas'),
(3, 'Limpeza'),
(4, 'Higiene Pessoal'),
(5, 'Eletrônicos'),
(6, 'Roupas'),
(7, 'Calçados'),
(8, 'Utensílios Domésticos'),
(9, 'Jardinagem'),
(10, 'Pet Shop');

INSERT INTO secao (sec_codigo, sec_nome, cat_codigo) VALUES
(1, 'Padaria', 1),
(2, 'Açougue', 1),
(3, 'Frutas e Verduras', 1),
(4, 'Bebidas Alcoólicas', 2),
(5, 'Refrigerantes', 2),
(6, 'Produtos de Limpeza', 3),
(7, 'Higiene Bucal', 4),
(8, 'Smartphones', 5),
(9, 'Camisetas', 6),
(10, 'Tênis', 7);

INSERT INTO produto (prd_nro_cadastro, prd_descricao, prd_media_venda_mes, prd_nome_fabricante, prd_unidade_venda, prd_preco, prd_qnt_estoque, sec_codigo) VALUES
(1, 'Pão Francês', 1000, 'Padaria do Hipermercado', 1, 0.50, 500, 1),
(2, 'Filé Mignon', 200, 'Frigorífico ABC', 1, 59.90, 100, 2),
(3, 'Maçã Gala', 500, 'Fazenda Maçãs', 1, 5.99, 1000, 3),
(4, 'Cerveja Pilsen 350ml', 2000, 'Cervejaria XYZ', 1, 3.50, 5000, 4),
(5, 'Refrigerante Cola 2L', 1500, 'Bebidas Refrescantes', 1, 7.99, 2000, 5),
(6, 'Detergente Líquido 500ml', 800, 'Limpeza Total', 1, 2.99, 1500, 6),
(7, 'Escova de Dentes', 300, 'Higiene Brilhante', 1, 4.99, 1000, 7),
(8, 'Smartphone XYZ', 50, 'TechMobile', 1, 1999.99, 100, 8),
(9, 'Camiseta Básica', 200, 'Moda Conforto', 1, 29.90, 500, 9),
(10, 'Tênis Esportivo', 100, 'Calçados Ágeis', 1, 159.90, 200, 10);

INSERT INTO promocao (pro_codigo, pro_descricao, pro_data_inicio, pro_data_fim, pro_nome) VALUES
(1, 'Desconto de 10% em todos os pães', '01-10-2024', '07-10-2024', 'Semana do Pão'),
(2, 'Compre 1 kg de carne e leve outro com 50% de desconto', '08-10-2024', '14-10-2024', 'Feira de Carnes'),
(3, 'Frutas com 20% de desconto', '15-10-2024', '21-10-2024', 'Semana Saudável'),
(4, 'Cerveja em dobro', '22-10-2024', '28-10-2024', 'Happy Hour em Casa'),
(5, 'Refrigerantes com 30% de desconto', '29-10-2024', '04-11-2024', 'Refrescância Total'),
(6, 'Leve 3, Pague 2 em produtos de limpeza', '05-11-2024', '11-11-2024', 'Casa Limpa'),
(7, 'Kit de higiene bucal com 25% off', '12-11-2024', '18-11-2024', 'Sorria Mais'),
(8, 'Smartphones com até R$500 de desconto', '19-11-2024', '25-11-2024', 'TechWeek'),
(9, 'Compre 2 camisetas e ganhe 1', '26-11-2024', '02-12-2024', 'Moda em Triplo'),
(10, 'Tênis com 40% de desconto', '03-12-2024', '09-12-2024', 'Corrida de Ofertas');

INSERT INTO fornecedor (for_nro_cadastro, for_valor_total_venda_ano_pas, for_denominacao_social, for_desconto, for_prazo_medio_entrega, for_pessoa_contato, for_email, for_condicao_pagamento, for_cidade, for_estado, for_bairro, for_cep) VALUES
(1, 1000000.00, 'Padaria Wholesaler Ltda', 5.0, 2, 'João Silva', 'joao@padariawholesaler.com', '30 dias', 'São Paulo', 'SP', 'Centro', '01001-000'),
(2, 2500000.00, 'Frigorífico ABC S.A.', 3.5, 3, 'Maria Santos', 'maria@frigorificoabc.com', '45 dias', 'Porto Alegre', 'RS', 'Sarandi', '91110-001'),
(3, 800000.00, 'Fazenda Maçãs Ltda', 2.0, 1, 'Pedro Oliveira', 'pedro@fazendamacas.com', '15 dias', 'Vacaria', 'RS', 'Rural', '95200-000'),
(4, 5000000.00, 'Cervejaria XYZ S.A.', 7.5, 5, 'Ana Rodrigues', 'ana@cervejariaxyz.com', '60 dias', 'Belo Horizonte', 'MG', 'Pampulha', '31270-901'),
(5, 3000000.00, 'Bebidas Refrescantes Ltda', 4.0, 4, 'Carlos Ferreira', 'carlos@bebidasrefrescantes.com', '30 dias', 'Rio de Janeiro', 'RJ', 'Barra da Tijuca', '22631-004'),
(6, 1200000.00, 'Limpeza Total S.A.', 6.0, 2, 'Lúcia Mendes', 'lucia@limpezatotal.com', '45 dias', 'Curitiba', 'PR', 'Batel', '80420-090'),
(7, 900000.00, 'Higiene Brilhante Ltda', 3.0, 3, 'Roberto Almeida', 'roberto@higienebrilhante.com', '30 dias', 'Salvador', 'BA', 'Pituba', '41810-011'),
(8, 10000000.00, 'TechMobile S.A.', 2.5, 7, 'Fernanda Costa', 'fernanda@techmobile.com', '90 dias', 'São Paulo', 'SP', 'Moema', '04524-001'),
(9, 1500000.00, 'Moda Conforto Ltda', 5.5, 4, 'Ricardo Nunes', 'ricardo@modaconforto.com', '60 dias', 'Fortaleza', 'CE', 'Meireles', '60165-121'),
(10, 2000000.00, 'Calçados Ágeis S.A.', 4.5, 5, 'Patrícia Lima', 'patricia@calcadosageis.com', '45 dias', 'Novo Hamburgo', 'RS', 'Centro', '93510-100');

INSERT INTO cliente (cli_cpf, cli_nome, cli_data_nascimento, cli_gasto_total_ano_pas, cli_profissao, cli_end_residencial) VALUES
('123.456.789-00', 'Ana Silva', '15-03-1985', 5000.00, 'Professora', 'Rua das Flores, 123'),
('234.567.890-11', 'Carlos Santos', '22-07-1990', 7500.00, 'Engenheiro', 'Av. Principal, 456'),
('345.678.901-22', 'Mariana Oliveira', '30-11-1988', 6200.00, 'Advogada', 'Rua dos Pinheiros, 789'),
('456.789.012-33', 'Rafael Ferreira', '10-05-1982', 4800.00, 'Médico', 'Av. Paulista, 1000'),
('567.890.123-44', 'Juliana Costa', '18-09-1995', 3500.00, 'Designer', 'Rua Augusta, 2345'),
('678.901.234-55', 'Fernando Rodrigues', '25-01-1980', 9000.00, 'Empresário', 'Rua Oscar Freire, 500'),
('789.012.345-66', 'Beatriz Almeida', '05-04-1992', 5500.00, 'Jornalista', 'Av. Brigadeiro Faria Lima, 1500'),
('890.123.456-77', 'Ricardo Mendes', '12-08-1987', 6800.00, 'Arquiteto', 'Rua Teodoro Sampaio, 800'),
('901.234.567-88', 'Camila Nunes', '20-12-1993', 4200.00, 'Psicóloga', 'Av. Rebouças, 3000'),
('012.345.678-99', 'Lucas Lima', '08-06-1986', 7200.00, 'Contador', 'Rua da Consolação, 1200');

INSERT INTO diamante (dia_gasto_minimo, cli_cpf) VALUES
(8000.00, '678.901.234-55');

INSERT INTO ouro (our_gasto_minimo, cli_cpf) VALUES
(6000.00, '234.567.890-11'),
(6000.00, '345.678.901-22'),
(6000.00, '890.123.456-77'),
(6000.00, '012.345.678-99');

INSERT INTO prata (pra_gasto_minimo, cli_cpf) VALUES
(4000.00, '123.456.789-00'),
(4000.00, '456.789.012-33'),
(4000.00, '567.890.123-44'),
(4000.00, '789.012.345-66'),
(4000.00, '901.234.567-88');

INSERT INTO oferece_produto (ofe_preco, for_nro_cadastro, prd_nro_cadastro) VALUES
(0.40, 1, 1),
(55.00, 2, 2),
(5.50, 3, 3),
(3.20, 4, 4),
(7.50, 5, 5),
(2.80, 6, 6),
(4.50, 7, 7),
(1900.00, 8, 8),
(25.00, 9, 9),
(150.00, 10, 10);

INSERT INTO fornecedor_telefone (for_telefone, for_nro_cadastro) VALUES
('(11) 1234-5678', 1),
('(51) 2345-6789', 2),
('(54) 3456-7890', 3),
('(31) 4567-8901', 4),
('(21) 5678-9012', 5),
('(41) 6789-0123', 6),
('(71) 7890-1234', 7),
('(11) 8901-2345', 8),
('(85) 9012-3456', 9),
('(51) 0123-4567', 10);

INSERT INTO cliente_endereco (cli_endereco_entrega, cli_cpf) VALUES
('Rua das Flores, 123, Vila Mariana, São Paulo - SP', '123.456.789-00'),
('Avenida Paulista, 1000, Bela Vista, São Paulo - SP', '234.567.890-11'),
('Rua Oscar Freire, 456, Jardins, São Paulo - SP', '345.678.901-22'),
('Alameda Santos, 789, Cerqueira César, São Paulo - SP', '456.789.012-33'),
('Rua Augusta, 321, Consolação, São Paulo - SP', '567.890.123-44'),
('Avenida Brigadeiro Faria Lima, 2468, Pinheiros, São Paulo - SP', '678.901.234-55'),
('Rua Vergueiro, 1357, Vila Mariana, São Paulo - SP', '789.012.345-66'),
('Rua da Consolação, 951, Consolação, São Paulo - SP', '890.123.456-77'),
('Avenida São João, 1234, República, São Paulo - SP', '901.234.567-88'),
('Rua Teodoro Sampaio, 753, Pinheiros, São Paulo - SP', '012.345.678-99');

INSERT INTO cliente_telefone (cli_telefone, cli_cpf) VALUES
('(11) 98765-4321', '123.456.789-00'),
('(11) 87654-3210', '234.567.890-11'),
('(11) 76543-2109', '345.678.901-22'),
('(11) 65432-1098', '456.789.012-33'),
('(11) 54321-0987', '567.890.123-44'),
('(11) 43210-9876', '678.901.234-55'),
('(11) 32109-8765', '789.012.345-66'),
('(11) 21098-7654', '890.123.456-77'),
('(11) 10987-6543', '901.234.567-88'),
('(11) 09876-5432', '012.345.678-99');

INSERT INTO compra (com_forma_pagamento, com_valor_total_desc, com_valor_total, com_horario, com_data, com_num_cupom_fiscal, cli_cpf) VALUES
('Cartão de Crédito', 2.40, 2.50, '10:30:00', '01-10-2024', 'CF001', '123.456.789-00'),
('Dinheiro', 114.81, 119.80, '11:45:00', '02-10-2024', 'CF002', '234.567.890-11'),
('Cartão de Débito', 17.97, 17.97, '14:20:00', '03-10-2024', 'CF003', '345.678.901-22'),
('Pix', 33.00, 35.00, '16:10:00', '04-10-2024', 'CF004', '456.789.012-33'),
('Cartão de Crédito', 30.96, 31.96, '09:55:00', '05-10-2024', 'CF005', '567.890.123-44'),
('Dinheiro', 5.48, 5.98, '13:30:00', '06-10-2024', 'CF006', '678.901.234-55'),
('Cartão de Débito', 4.99, 4.99, '15:45:00', '07-10-2024', 'CF007', '789.012.345-66'),
('Pix', 1899.99, 1999.99, '17:20:00', '08-10-2024', 'CF008', '890.123.456-77'),
('Cartão de Crédito', 84.70, 89.70, '10:15:00', '09-10-2024', 'CF009', '901.234.567-88'),
('Dinheiro', 149.90, 159.90, '12:40:00', '10-10-2024', 'CF010', '012.345.678-99');

INSERT INTO realiza_compra (com_quantidade, com_desconto, cli_cpf, prd_nro_cadastro,com_num_cupom_fiscal) VALUES
(5, 0.00, '123.456.789-00', 1, 'CF001'),
(2, 5.00, '234.567.890-11', 2, 'CF002'),
(3, 0.00, '345.678.901-22', 3, 'CF003'),
(10, 2.00, '456.789.012-33', 4, 'CF004'),
(4, 1.00, '567.890.123-44', 5, 'CF005'),
(2, 0.50, '678.901.234-55', 6, 'CF006'),
(1, 0.00, '789.012.345-66', 7, 'CF007'),
(1, 100.00, '890.123.456-77', 8, 'CF008'),
(3, 5.00, '901.234.567-88', 9, 'CF009'),
(1, 10.00, '012.345.678-99', 10, 'CF010');

INSERT INTO funcionario_funcao (fnc_codigo, fnc_nome) VALUES
(1, 'Gerente'),
(2, 'Empacotador'),
(3, 'Marketing'),
(4, 'Atendente de Padaria'),
(5, 'Faxineiro'),
(6, 'Atendente de Caixa'),
(7, 'Repositor'),
(8, 'Açougueiro'),
(9, 'Segurança'),
(10, 'Auxiliar Administrativo');

INSERT INTO funcionario (fun_cpf, fun_nome, fun_endereco, fun_telefone, fun_estado_civil, fun_data_nascimento, fun_nivel_formacao, fun_valor_hora_extra, fun_salario, fun_jornada_trabalho, fun_cpf_gerente, fnc_codigo) VALUES
('111.222.333-44', 'Roberto Gomes', 'Rua A, 123', '(11) 91234-5678', 'Casado', '15-05-1980', 'Superior Completo', 30.00, 5000.00, 40, NULL, 1),
('222.333.444-55', 'Carla Silva', 'Rua B, 456', '(11) 92345-6789', 'Solteira', '22-08-1995', 'Ensino Médio', 15.00, 1800.00, 40, NULL, 2),
('333.444.555-66', 'Marcelo Santos', 'Rua C, 789', '(11) 93456-7890', 'Casado', '10-11-1988', 'Superior Completo', 25.00, 3500.00, 40, NULL, 3),
('444.555.666-77', 'Amanda Oliveira', 'Rua D, 1011', '(11) 94567-8901', 'Solteira', '25-03-1992', 'Ensino Médio', 18.00, 2200.00, 40, NULL, 4),
('555.666.777-88', 'José Ferreira', 'Rua E, 1213', '(11) 95678-9012', 'Divorciado', '30-09-1975', 'Ensino Fundamental', 15.00, 1600.00, 40, NULL, 5),
('666.777.888-99', 'Márcia Costa', 'Rua F, 1415', '(11) 96789-0123', 'Casada', '12-07-1990', 'Ensino Médio', 20.00, 2500.00, 40, NULL, 6),
('777.888.999-00', 'Paulo Rodrigues', 'Rua G, 1617', '(11) 97890-1234', 'Solteiro', '05-01-1993', 'Ensino Médio', 18.00, 2000.00, 40, NULL, 7),
('888.999.000-11', 'Fernanda Lima', 'Rua H, 1819', '(11) 98901-2345', 'Casada', '18-12-1985', 'Superior Completo', 28.00, 4000.00, 40, NULL, 8),
('999.000.111-22', 'Ricardo Alves', 'Rua I, 2021', '(11) 99012-3456', 'Solteiro', '20-06-1987', 'Ensino Médio', 20.00, 2300.00, 40, NULL, 9),
('000.111.222-33', 'Juliana Martins', 'Rua J, 2223', '(11) 90123-4567', 'Casada', '08-04-1991', 'Superior Completo', 25.00, 3000.00, 40, NULL, 10);

INSERT INTO gerente (ger_data_ingresso, ger_formacao_basica, fun_cpf) VALUES
('15-01-2010', 'Administração', '111.222.333-44');

INSERT INTO empacotador (fun_cpf) VALUES
('222.333.444-55');

INSERT INTO marketing (mar_portfolio, mar_formacao_basica, fun_cpf) VALUES
('Portfolio1.pdf', 'Marketing', '333.444.555-66');

INSERT INTO propaganda (prd_nro_cadastro, pro_codigo, fun_cpf) VALUES
(1, 1, '333.444.555-66'),
(2, 2, '333.444.555-66'),
(3, 3, '333.444.555-66'),
(4, 4, '333.444.555-66'),
(5, 5, '333.444.555-66'),
(6, 6, '333.444.555-66'),
(7, 7, '333.444.555-66'),
(8, 8, '333.444.555-66'),
(9, 9, '333.444.555-66'),
(10, 10, '333.444.555-66');

INSERT INTO atendente_padaria (fun_cpf) VALUES
('444.555.666-77');

INSERT INTO faxineiro (fun_cpf) VALUES
('555.666.777-88');

INSERT INTO atendente_caixa (fun_cpf) VALUES
('666.777.888-99');

INSERT INTO repositor (fun_cpf) VALUES
('777.888.999-00');

INSERT INTO responsavel_secao (fun_cpf, sec_codigo) VALUES
('777.888.999-00', 1),
('777.888.999-00', 2),
('777.888.999-00', 3);

INSERT INTO pedido (ped_codigo, ped_quantidade, ped_valor_desc, ped_valor_total, ped_devolucao, ped_data_entrega, ped_data_previsao, ped_data_emissao, for_nro_cadastro, prd_nro_cadastro, fun_cpf) VALUES
(1, 100, 47.50, 50.00, 'Não', '03-10-2024', '03-10-2024', '01-10-2024', 1, 1, '111.222.333-44'),
(2, 50, 2890.18, 2995.00, 'Não', '05-10-2024', '06-10-2024', '02-10-2024', 2, 2, '111.222.333-44'),
(3, 200, 1174.20, 1198.00, 'Não', '04-10-2024', '04-10-2024', '03-10-2024', 3, 3, '111.222.333-44'),
(4, 500, 1618.75, 1750.00, 'Não', '09-10-2024', '09-10-2024', '04-10-2024', 4, 4, '111.222.333-44'),
(5, 300, 2301.12, 2397.00, 'Não', '08-10-2024', '08-10-2024', '04-10-2024', 5, 5, '111.222.333-44'),
(6, 150, 421.59, 448.50, 'Não', '06-10-2024', '06-10-2024', '04-10-2024', 6, 6, '111.222.333-44'),
(7, 100, 484.03, 499.00, 'Não', '07-10-2024', '07-10-2024', '04-10-2024', 7, 7, '111.222.333-44'),
(8, 20, 39000.00, 40000.00, 'Não', '11-10-2024', '11-10-2024', '04-10-2024', 8, 8, '111.222.333-44'),
(9, 80, 2260.44, 2392.00, 'Não', '08-10-2024', '08-10-2024', '04-10-2024', 9, 9, '111.222.333-44'),
(10, 30, 4580.64, 4797.00, 'Não', '09-10-2024', '09-10-2024', '04-10-2024', 10, 10, '111.222.333-44');

INSERT INTO registra_compra (com_num_cupom_fiscal,fun_cpf) VALUES
('CF001', '666.777.888-99'),
('CF002', '666.777.888-99'),
('CF003', '666.777.888-99'),
('CF004', '666.777.888-99'),
('CF005', '666.777.888-99'),
('CF006', '666.777.888-99'),
('CF007', '666.777.888-99'),
('CF008', '666.777.888-99'),
('CF009', '666.777.888-99'),
('CF010', '666.777.888-99');

UPDATE funcionario
SET fun_cpf_gerente = '111.222.333-44'
WHERE fun_cpf != '111.222.333-44';
