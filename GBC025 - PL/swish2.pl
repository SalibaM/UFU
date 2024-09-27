estuda(fabricio,programação).
estuda(joana,lógica).
estuda(ana,tcc).
estuda(josé,banco).
estuda(lucas,estrutura).
estuda(nicolas,lógica).
estuda(fernanda,tcc).
estuda(maria,tcc).

aluno(fabricio,ufmg).
aluno(joana,ufu).
aluno(ana,ufu).
aluno(josé,ufu).
aluno(lucas,ufmg).
aluno(nicolas,ufu).
aluno(fernanda,ufu).
aluno(maria,ufu).

professor(joão,programação).
professor(clara,lógica).
professor(roberta,tcc).
professor(antonio,banco).
professor(leandro,estrutura).

reitor(beatriz,ufmg).
reitor(marcos,ufu).

ofeerta(bcc,programação).
oferta(bcc,lógica).
oferta(si,tcc).
oferta(si,banco).
oferta(bcc,estrutura).


alunos_professor(X,Y):-estuda(X,W),professor(Y,W).

alunos_bcc(X):-estuda(X,Y),oferta(bcc,Y).

alunos_si(X):-estuda(X,Y),oferta(si,Y).

alunos_universidade(X,Y):-aluno(X,Y).

disciplinas_professor(X,Y):-professor(Y,X).
    
professor_universidade(X,Y):-professor(X,W),estuda(Z,W),aluno(Z,Y).

disciplinas_universidade(X,Y):-professor(_Z,X),estuda(W,X),aluno(W,Y).

reitor_professor(X,Y):-professor(Y,Z),estuda(W,Z),aluno(W,M),reitor(X,M).


















