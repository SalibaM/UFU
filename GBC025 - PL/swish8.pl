governou(joao, 1952, 1968).
governou(jose, 1968, 1970).
governou(maria, 1970, 1974).
governou(joana, 1974, 1982).
governou(mario, 1982, 1988).
governou(rodrigo, 1988, 1994).
governou(ana, 1994, 1995).
governou(lucio, 1995, 2005).
governou(fernanda, 2005, 2010).

presidente(X,_Y):-governou(X,W,_Z),
				write(X ),write(' governou de '),write(W ),write(' a '),
				governou(X,_,J),
				write(J).
