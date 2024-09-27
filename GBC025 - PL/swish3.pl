nota(joao,5.0). 
nota(jose,6.0). 
nota(joana,8.0). 
nota(luiz,9.0). 
nota(antonio,8.5). 
nota(felipe,6.5). 
nota(maria,4.5). 
nota(sandra,4.0). 
nota(marcia,10.0). 
nota(suely,2.0).
nota(jessica,4.9).

aprovado(X):-nota(X,Y),Y>=7.

reprovado(X):-nota(X,Y),Y=<4.9.

recuperação(X):-nota(X,Y),Y>=5,Y=<6.9.

