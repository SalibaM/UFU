somainteiros(1,1).

somainteiros(X,Y):- X1 is X-1,
    				somainteiros(X1,Y1),
    				Y is Y1 + X.