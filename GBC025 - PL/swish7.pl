professor(claudiney,pp,3).
professor(marcia,logica,5).
professor(bonfim,gaal,1).

aluno(nelson,gaal,10).
aluno(cks,pp,7).
aluno(amanda,pp,9).
aluno(saliba,logica,6).
aluno(mg,gaal,8).

nota(X,Y,Z):-aluno(X,Y,Z1),
    		professor(_,Y,W),
    		Z2 is Z1*W,
    		Z is Z2/5.

maiorNota(X,Y):-

