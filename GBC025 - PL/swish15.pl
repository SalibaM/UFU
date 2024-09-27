pot(_,0,1).

pot(X,Y,Z):-Y1 is Y-1, 
    		pot(X,Y1,Z1),
    		Z is Z1*X.
    		
    		