disciplina(lógica).
disciplina(matematica).
disciplina(portugues).
disciplina(ciencias).
disciplina(historia).

mediaarit(N1,N2,N3,N4,N5,X1):- X is N1+N2+N3+N4+N5,
    							X1 is X/5.

aprovadodis(X):- X>60 -> write('Você foi aprovado nessa matéria!') ;
    			true.
    	


aprovado(_):-write('Digite a primeira nota(Lógica):'),
			read(N1),
    		aprovadodis(N1),
    		nl, write('Digite a segunda nota(Matemática):'),
			read(N2),
            aprovadodis(N2),
			nl, write('Digite a terceira nota(Português):'),
			read(N3),
            aprovadodis(N3),
    		nl, write('Digite a quarta nota(Ciências):'),
			read(N4),
            aprovadodis(N4),
			nl, write('Digite a quinta nota(História):'),
			read(N5),
            aprovadodis(N5),                      
			mediaarit(N1,N2,N3,N4,N5,X1),
			nl, write('A sua média das notas é:'),
			write(X1).
