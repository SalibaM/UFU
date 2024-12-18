CREATE SCHEMA eleicao_2024;
SET search_path TO eleicao_2024;

SELECT nm_urna_candidato,nm_candidato
FROM candidato
WHERE nm_ue = 'UBERLÂNDIA'
ORDER BY nm_candidato DESC

SELECT nm_candidato
FROM candidato
WHERE dt_nascimento < '01/01/1954' 
      AND sg_uf = 'AC'

      
SELECT nm_urna_candidato
FROM candidato
WHERE nm_urna_candidato 
      LIKE '%LULA%' OR nm_urna_candidato LIKE '%BOLSONARO%'


SELECT can.nm_candidato, gr.ds_grau_instrucao
FROM candidato can, grau_instrucao gr
WHERE can.nm_ue = 'CASA BRANCA' 
      AND can.sg_uf = 'SP'


SELECT can.nm_candidato,par.sg_partido
FROM candidato can, partido par
WHERE can.nm_ue = 'CUIABÁ' 
      AND can.nr_partido = par.nr_partido


SELECT DISTINCT gr.ds_grau_instrucao
FROM candidato can, partido par, grau_instrucao gr
WHERE can.sg_uf_nascimento = 'BA' 
      AND par.nr_partido = can.nr_partido 
      AND par.sg_partido = 'PSDB'
      AND can.cd_grau_instrucao = gr.cd_grau_instrucao


SELECT can.nm_urna_candidato,can.nr_candidato,par.sg_partido,col.ds_coligacao
FROM candidato can, partido par, coligacao col, cargo carg
WHERE (carg.ds_cargo = 'PREFEITO' OR carg.ds_cargo = 'VICE-PREFEITO') 
      AND (can.cd_cargo = carg.cd_cargo) 
      AND (can.nm_ue = 'SÃO PAULO' OR can.nm_ue = 'RIO DE JANEIRO' OR can.nm_ue = 'VITÓRIA' OR can.nm_ue = 'BELO HORIZONTE')
      AND (can.sq_coligacao = col.sq_coligacao) 
      AND (can.nr_partido = par.nr_partido)


SELECT can.nm_candidato, par.sg_partido, bem.ds_tipo_bem_candidato, bem.vr_bem_candidato
FROM candidato can, partido par, bem_candidato bem, cargo car
WHERE car.cd_cargo = can.cd_cargo 
      AND car.ds_cargo = 'PREFEITO'
      AND can.nm_ue = 'SÃO PAULO' 
      AND can.sq_candidato = bem.sq_candidato
      AND can.nr_partido = par.nr_partido


SELECT nm_ue
FROM candidato
WHERE dt_nascimento = NULL


SELECT can.nm_candidato, par.sg_partido, est.ds_estado_civil, ocup.ds_ocupacao
FROM candidato can, partido par, estado_civil est, ocupacao ocup , genero gen, cargo car
WHERE (gen.cd_genero = can.cd_genero) 
      AND (gen.ds_genero = 'FEMININO') 
      AND (car.cd_cargo = can.cd_cargo) 
      AND (car.ds_cargo = 'PREFEITO') 
      AND (can.nm_ue = 'SÃO PAULO' OR can.nm_ue = 'RIO DE JANEIRO' OR can.nm_ue = 'VITÓRIA' OR can.nm_ue = 'BELO HORIZONTE') 
      AND (can.nr_partido = par.nr_partido) 
      AND (can.cd_estado_civil = est.cd_estado_civil)
      AND (can.cd_ocupacao = ocup.cd_ocupacao)


SELECT can.nm_candidato, par.sg_partido, est.ds_estado_civil, ocup.ds_ocupacao
FROM candidato can, partido par, estado_civil est, ocupacao ocup , genero gen, cargo car
WHERE (gen.cd_genero = can.cd_genero) 
      AND (gen.ds_genero = 'FEMININO') 
      AND (car.cd_cargo = can.cd_cargo) 
      AND (car.ds_cargo = 'PREFEITO' OR car.ds_cargo = 'VICE-PREFEITO') 
      AND (can.nm_ue = 'UBERLÂNDIA') 
      AND (can.nr_partido = par.nr_partido) 
      AND (can.cd_estado_civil = est.cd_estado_civil) 
      AND (can.cd_ocupacao = ocup.cd_ocupacao)


SELECT can.nm_candidato, can.dt_nascimento
FROM candidato can, partido par
WHERE can.nm_ue = 'UBERLÂNDIA' 
      AND can.nr_partido = par.nr_partido
