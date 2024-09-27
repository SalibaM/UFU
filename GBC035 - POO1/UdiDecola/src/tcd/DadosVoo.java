package tcd;

import java.util.ArrayList;
import java.io.Serializable;

public class DadosVoo implements Serializable{
	private ArrayList<Voos> Vooss;
	
	public ArrayList<Voos> getVooss() {
		return Vooss;
	}
	
	public void inicializar() {
		
		Vooss = (ArrayList<Voos>)Persist.recuperar("voos.dat");
		
		if(Vooss == null) {
			Vooss = new ArrayList<Voos>();
		}
	}
	
	public DadosVoo() {
		inicializar();
	}

	public boolean cadastrarVoos(Voos Voos) {
		if (consultarVoos(Voos)) {
            return false;
        }
		else {
			boolean r = Persist.gravar(Vooss, "voos.dat");
			this.Vooss.add(Voos);
	        return true;
		}
	}
	
	public boolean consultarVoos(Voos Voos) {
	    	
	    	for(int i = 0; i < Vooss.size(); i++) {
	    		if(Voos == Vooss.get(i)) return true;
	    	} 
	    	return false;	
	}
	
	public boolean removerVoos(Voos Voos) {
		for(int i = 0; i < Vooss.size(); i++) {
    		if(Voos == Vooss.get(i)) {
    			Vooss.remove(i);
    			return true;
    		}
    	}
		return false;
	}
}