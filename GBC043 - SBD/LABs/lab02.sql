SELECT MAX(vr_bem_candidato) AS maximo,MIN(vr_bem_candidato) AS minimo
FROM candidato can, bem_candidato bem
WHERE can.sq_candidato = bem.sq_candidato 
	AND can.sg_uf = 'MG'

	
SELECT nm_candidato,nr_partido,nm_ue,sg_uf,vr_bem_candidato
FROM candidato can, bem_candidato bem
WHERE can.sq_candidato = bem.sq_candidato 
	AND vr_bem_candidato = (SELECT max(vr_bem_candidato)FROM bem_candidato)

	
SELECT avg(vr_bem_candidato) AS média
FROM candidato can,bem_candidato bem 
WHERE can.sq_candidato = bem.sq_candidato 
	AND nm_candidato = 'JOSE LUIZ DATENA'

	
SELECT sg_uf, COUNT(*)
FROM candidato can,cargo car
WHERE can.cd_cargo = car.cd_cargo 
	AND car.ds_cargo = 'VEREADOR'
GROUP BY sg_uf
ORDER BY can.sg_uf


SELECT nm_ue, COUNT(*)
FROM candidato can, cargo car, genero gen
WHERE can.cd_cargo = car.cd_cargo 
	AND car.ds_cargo = 'VEREADOR' 
	AND gen.cd_genero = can.cd_genero 
	AND gen.ds_genero = 'FEMININO' 
	AND (nm_ue = 'RIO DE JANEIRO' OR nm_ue = 'SÃO PAULO' OR nm_ue = 'VITÓRIA' OR nm_ue = 'BELO HORIZONTE')
GROUP BY nm_ue


SELECT COUNT(DISTINCT sq_coligacao)
FROM coligacao


SELECT sg_partido, COUNT(*) as qtd
FROM candidato can, genero gen,cargo car, partido par
WHERE can.cd_genero = gen.cd_genero 
	AND gen.ds_genero = 'FEMININO' 
	AND can.cd_cargo = car.cd_cargo 
	AND car.ds_cargo = 'VEREADOR' 
	AND can.nm_ue = 'UBERLÂNDIA' 
	AND can.nr_partido = par.nr_partido
GROUP BY sg_partido
ORDER BY qtd


SELECT sg_partido, COUNT(*)
FROM candidato can, genero gen, partido par
WHERE can.cd_genero = gen.cd_genero 
	AND gen.ds_genero = 'FEMININO' 
	AND can.nm_ue = 'SÃO PAULO' 
	AND can.nr_partido = par.nr_partido
GROUP BY sg_partido
HAVING COUNT(*) > 10


SELECT sg_partido,ds_cor_raca,COUNT(*)
FROM candidato can, partido par, cor_raca cr
WHERE can.nm_ue = 'CUIABÁ' 
	AND can.nr_partido = par.nr_partido 
	AND can.cd_cor_raca = cr.cd_cor_raca
GROUP BY sg_partido, ds_cor_raca


SELECT sg_partido,COUNT(*)
FROM candidato can, partido par
WHERE can.nm_ue = 'BELO HORIZONTE' 
	AND can.nr_partido = par.nr_partido
GROUP BY sg_partido
HAVING COUNT(*) >= ALL (SELECT COUNT(*) as qtd
	FROM candidato can, partido par
	WHERE can.nm_ue = 'BELO HORIZONTE' 
		AND can.nr_partido = par.nr_partido
	GROUP BY sg_partido)


SELECT sg_partido, COUNT(*)
FROM candidato can, partido par
WHERE can.nm_ue = 'CACONDE' 
	AND can.nr_partido = par.nr_partido
GROUP BY sg_partido
HAVING COUNT(*) >= ALL (SELECT COUNT(*) as qtd
	FROM candidato can, partido par
	WHERE can.nm_ue = 'CACONDE' 
		AND can.nr_partido = par.nr_partido
	GROUP BY sg_partido)


SELECT sg_partido,COUNT(*) as qtd
FROM candidato can, genero gen,cargo car, partido par
WHERE can.cd_genero = gen.cd_genero 
	AND gen.ds_genero = 'FEMININO' 
	AND can.cd_cargo = car.cd_cargo 
	AND car.ds_cargo = 'PREFEITO' 
	AND can.nm_ue = 'RIBEIRÃO PRETO' 
	AND can.nr_partido = par.nr_partido
GROUP BY sg_partido
ORDER BY qtd
