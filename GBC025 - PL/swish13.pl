mdc(X,X,X).

mdc(X,Y,Z):- Y>X, Y1 is Y-X,
    		mdc(X,Y1,Z).

mdc(X,Y,Z):-Y<X,
    		mdc(Y,X,Z).