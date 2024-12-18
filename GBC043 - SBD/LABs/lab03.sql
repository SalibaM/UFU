SELECT nm_candidato,nm_urna_candidato,can.nr_partido,par.sg_partido,par.nm_partido
FROM candidato can JOIN partido par ON can.nr_partido = par.nr_partido JOIN cargo car
ON can.cd_cargo = car.cd_cargo
WHERE (ds_cargo = 'PREFEITO' OR ds_cargo = 'VICE-PREFEITO') AND
(can.nm_ue = 'FLORIANÓPOLIS' OR can.nm_ue = 'CURITIBA' OR can.nm_ue = 'PORTO ALEGRE')


SELECT sg_partido, COUNT(*)ALL
FROM candidato can JOIN partido par ON can.nr_partido = par.nr_partido JOIN ocupacao ocup
ON can.cd_ocupacao = ocup.cd_ocupacao
WHERE ocup.ds_ocupacao = 'GARIMPEIRO'
GROUP BY sg_partido
HAVING COUNT(*) >= ALL (SELECT COUNT(*) as qtd
					   FROM candidato can JOIN partido par ON can.nr_partido = par.nr_partido JOIN ocupacao ocup
					   ON can.cd_ocupacao = ocup.cd_ocupacao
					   WHERE ocup.ds_ocupacao = 'GARIMPEIRO'
					   GROUP BY sg_partido)
					   
					   
SELECT sg_partido, COUNT(*) as qtd
FROM candidato can JOIN partido par ON can.nr_partido = par.nr_partido JOIN ocupacao ocup
ON can.cd_ocupacao = ocup.cd_ocupacao
WHERE ocup.ds_ocupacao = 'GARIMPEIRO'
GROUP BY sg_partido
ORDER BY qtd DESC LIMIT 1


SELECT nr_partido,ds_genero,COUNT(*)
FROM candidato can JOIN genero gen ON can.cd_genero = gen.cd_genero
GROUP BY ROLLUP(nr_partido,ds_genero)
ORDER BY nr_partido,ds_genero


SELECT nr_partido,ds_genero,COUNT(*)
FROM candidato can JOIN genero gen ON can.cd_genero = gen.cd_genero
GROUP BY CUBE(nr_partido,ds_genero)
ORDER BY nr_partido,ds_genero


SELECT nr_partido,ds_estado_civil,COUNT(*)
FROM candidato can JOIN estado_civil est ON can.cd_estado_civil = est.cd_estado_civil
GROUP BY ROLLUP(nr_partido,ds_estado_civil)
ORDER BY nr_partido,ds_estado_civil


SELECT nr_partido,ds_estado_civil,COUNT(*)
FROM candidato can JOIN estado_civil est ON can.cd_estado_civil = est.cd_estado_civil
GROUP BY CUBE(nr_partido,ds_estado_civil)
ORDER BY nr_partido,ds_estado_civil


INSERT INTO estado_civil (cd_estado_civil,ds_estado_civil) VALUES ('99','UNIÃO ESTÁVEL')

	
-- left join
SELECT *
FROM estado_civil est LEFT OUTER JOIN candidato can
ON can.cd_estado_civil = est.cd_estado_civil
-- WHERE can.nm_candidato IS NULL

	
-- right join
SELECT *
FROM candidato can RIGHT OUTER JOIN estado_civil est
ON can.cd_estado_civil = est.cd_estado_civil
--WHERE can.nm_candidato IS NULL

	
-- full join
SELECT *
FROM candidato can FULL OUTER JOIN estado_civil est
ON can.cd_estado_civil = est.cd_estado_civil
--WHERE can.nm_candidato IS NULL


CREATE VIEW info_candidatos AS
SELECT can.nm_candidato, can.sg_uf, par.sg_partido
FROM candidato can
JOIN partido par ON can.nr_partido = par.nr_partido;


SELECT sg_uf, sg_partido, COUNT(*)
FROM info_candidatos
GROUP BY sg_uf, sg_partido
ORDER BY sg_uf;


CREATE MATERIALIZED VIEW info_candidatos_mat AS 
SELECT nm_candidato, nr_partido, sg_uf, COUNT(vr_bem_candidato)
FROM candidato can 
	JOIN bem_candidato bem ON can.sq_candidato = bem.sq_candidato
GROUP BY nm_candidato, nr_partido, sg_uf 
WITH NO DATA 

	
SELECT * 
FROM info_candidatos_mat


CREATE VIEW candidatos_milionarios AS
SELECT can.nm_candidato, can.nr_partido, can.sg_uf, 
	SUM(bem.vr_bem_candidato) AS total_bens
FROM candidato can
	JOIN bem_candidato bem ON can.sq_candidato = bem.sq_candidato
	JOIN cargo car ON can.cd_cargo = car.cd_cargo
WHERE car.ds_cargo = 'PREFEITO'
GROUP BY can.nm_candidato, can.nr_partido, can.sg_uf
HAVING SUM(bem.vr_bem_candidato) > 1000000;


SELECT * 
FROM candidatos_milionarios;


CREATE VIEW candidatos_instrucao AS
SELECT can.nm_candidato, par.nm_partido, gri.ds_grau_instrucao
FROM candidato can
	JOIN partido par ON can.nr_partido = par.nr_partido
	JOIN grau_instrucao gri ON can.cd_grau_instrucao = gri.cd_grau_instrucao;

SELECT ds_grau_instrucao, COUNT(*) AS qtd_candidatos
FROM candidatos_instrucao
GROUP BY ds_grau_instrucao;


CREATE VIEW candidatos_ocupacao_estado AS
SELECT can.sg_uf, ocu.ds_ocupacao, COUNT(*) AS qtd_candidatos
FROM candidato can
	JOIN ocupacao ocu ON can.cd_ocupacao = ocu.cd_ocupacao
GROUP BY can.sg_uf, ocu.ds_ocupacao;


SELECT * FROM candidatos_ocupacao_estado;


CREATE VIEW candidatos_coligacao_bens AS
SELECT col.nm_coligacao, can.nm_candidato, SUM(bem.vr_bem_candidato) AS total_bens
FROM candidato can
	JOIN coligacao col ON can.sq_coligacao = col.sq_coligacao
	LEFT JOIN bem_candidato bem ON can.sq_candidato = bem.sq_candidato
GROUP BY col.nm_coligacao, can.nm_candidato;


SELECT nm_coligacao, SUM(total_bens) AS total_bens_coligacao
FROM candidatos_coligacao_bens
GROUP BY nm_coligacao;
