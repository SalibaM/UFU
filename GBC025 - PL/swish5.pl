filho(jorge,ana).
filho(jorge,george).
filho(joao,jorge).


feliz(X):-filho(_Y,X).

casal(X,Y):-filho(Z,X),filho(Z,Y).