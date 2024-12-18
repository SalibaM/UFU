CREATE OR REPLACE FUNCTION classificar_cliente()
RETURNS trigger AS $$
	BEGIN
	IF NEW.cli_gasto_total_ano_pas >= 8000 THEN
	IF NOT EXISTS (SELECT 1 FROM diamante WHERE cli_cpf = NEW.cli_cpf) THEN
	INSERT INTO diamante (dia_gasto_minimo, cli_cpf) VALUES (NEW.cli_gasto_total_ano_pas, NEW.cli_cpf);
	END IF;
	DELETE FROM ouro WHERE cli_cpf = NEW.cli_cpf;
	DELETE FROM prata WHERE cli_cpf = NEW.cli_cpf;
	
	ELSEIF NEW.cli_gasto_total_ano_pas >= 6000 THEN
	IF NOT EXISTS (SELECT 1 FROM ouro WHERE cli_cpf = NEW.cli_cpf) THEN
	INSERT INTO ouro (our_gasto_minimo, cli_cpf) VALUES (NEW.cli_gasto_total_ano_pas, NEW.cli_cpf);
	END IF;
	DELETE FROM diamante WHERE cli_cpf = NEW.cli_cpf;
	DELETE FROM prata WHERE cli_cpf = NEW.cli_cpf;
	
	ELSEIF NEW.cli_gasto_total_ano_pas >= 4000 THEN
	IF NOT EXISTS (SELECT 1 FROM prata WHERE cli_cpf = NEW.cli_cpf) THEN
	INSERT INTO prata (pra_gasto_minimo, cli_cpf) VALUES (NEW.cli_gasto_total_ano_pas, NEW.cli_cpf);
	END IF;
	DELETE FROM diamante WHERE cli_cpf = NEW.cli_cpf;
	DELETE FROM ouro WHERE cli_cpf = NEW.cli_cpf;
	ELSEIF NEW.cli_gasto_total_ano_pas < 4000 THEN
	DELETE FROM diamante WHERE cli_cpf = NEW.cli_cpf;
	DELETE FROM ouro WHERE cli_cpf = NEW.cli_cpf;
	DELETE FROM prata WHERE cli_cpf = NEW.cli_cpf;
	END IF;
	
	RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER gatilho_class_cliente
AFTER INSERT OR UPDATE OF cli_gasto_total_ano_pas ON cliente
FOR EACH ROW
EXECUTE PROCEDURE classificar_cliente();

--TESTE
INSERT INTO cliente (cli_cpf, cli_nome, cli_data_nascimento, cli_gasto_total_ano_pas, cli_profissao, cli_end_residencial) VALUES
('000.000.000-42', 'Robertinho', '15-03-1985', 10000.0, 'Professor', 'Rua das Orquídeas, 222')

SELECT * 
FROM diamante


CREATE OR REPLACE PROCEDURE atualizar_estoque(
	IN p_nro_cadastro INT,
	IN p_quantidade_vendida INT) 
	LANGUAGE plpgsql AS $$ 
BEGIN 
	UPDATE produto 
	SET prd_qnt_estoque = prd_qnt_estoque - p_quantidade_vendida 
	WHERE prd_nro_cadastro = p_nro_cadastro; 
	IF (SELECT prd_qnt_estoque FROM produto 
	WHERE prd_nro_cadastro = p_nro_cadastro) < 0 
	THEN 
	RAISE WARNING 'Estoque insuficiente para o produto com número de cadastro %', p_nro_cadastro; 
	END IF; 
END; $$;

--TESTE
CALL atualizar_estoque(4,1000)

SELECT *
FROM produto
