package tcd;

import java.util.ArrayList;
import java.io.Serializable;

public class DadosTrecho implements Serializable{
	
	private ArrayList<Trechos> trechos;
	
	public void inicializar() {
		
		trechos = (ArrayList<Trechos>)Persist.recuperar("trechos.dat");
		
		if(trechos == null) {
			trechos = new ArrayList<Trechos>();
		}
	}
	
	public DadosTrecho() {
		inicializar();
	}
	
	public boolean cadastrarTrecho (Trechos trecho) {
		if (consultarTrecho(trecho)) {
            return false;
        }
		else {
			boolean r = Persist.gravar(trechos, "trechos.dat");
			this.trechos.add(trecho);
	        return true;
		}
	}
	
	public boolean consultarTrecho(Trechos trecho) {
	    	
	    	for(int i = 0; i < trechos.size(); i++) {
	    		if(trecho == trechos.get(i)) return true;
	    	} 
	    	return false;	
	}
	
	public boolean removerTrecho(Trechos trecho) {
		for(int i = 0; i < trechos.size(); i++) {
    		if(trecho == trechos.get(i)) {
    			trechos.remove(i);
    			return true;
    		}
    	}
		return false;
	}
}