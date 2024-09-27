caminho(a,b,5).
caminho(a,f,5).
caminho(b,e,25).
caminho(a,c,10).
caminho(c,d,10).
caminho(d,e,5).
caminho(e,f,5).
caminho(b,f,25).
caminho(a,g,75).
caminho(g,f,20).

custo(X,Y,Z):-caminho(X,Y,Z).

custo(X,Y,Z):-caminho(X,W,C),
    			custo(W,Y,H),
    			Z is H+C.
    		