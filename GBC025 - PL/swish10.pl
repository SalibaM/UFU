sucessor(X,Y):- Z is X+1,
    			Y=:=Z ->  true ; false.

par(X):- Z is X mod 2,
    	Z=\=0 ->  false ; true.

triplo(X,Y):- Z is X*3,
    		Z=:=Y ->  true ; false.

entre(X,A,B):- X>=A,X=<B ->  true ; false.
    	
    	