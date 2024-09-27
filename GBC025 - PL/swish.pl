mulher(ana).
mulher(eva).
mulher(bia).
mulher(clô).
mulher(lia).
mulher(gal).

homem(ivo).
homem(raí).
homem(noé).
homem(gil).
homem(ary).

filho(eva,ana).
filho(eva,ivo).
filho(noé,eva).
filho(noé,raí).
filho(raí,bia).
filho(raí,gil).
filho(clô,bia).
filho(clô,gil).
filho(ary,bia).
filho(ary,gil).
filho(gal,ary).
filho(gal,lia).

pai(X,Y):-homem(X),filho(Y,X).

mae(X,Y):-mulher(X),filho(Y,X).

irmao(X,Y):-homem(X),filho(X,W),filho(Y,W),X\=Y.

irma(X,Y):-mulher(X),filho(X,W),filho(Y,W),X\=Y.

irmaos(X,Y):-filho(X,W),filho(Y,W),X\=Y.

tio(X,Y):-homem(X),irmaos(X,W),((pai(W,Y);mae(W,Y))),X\=W.

tia(X,Y):-mulher(X),irmaos(X,W),((pai(W,Y);mae(W,Y))),X\=W.

avô(X,Y):-homem(X),(pai(W,Y);mae(W,Y)),pai(X,W),X\=Y.

avó(X,Y):-mulher(X),(pai(W,Y);mae(W,Y)),mae(X,W),X\=Y.






