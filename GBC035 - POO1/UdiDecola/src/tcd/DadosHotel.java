package tcd;

import java.util.ArrayList;
import java.io.Serializable;

public class DadosHotel implements Serializable{
	private ArrayList<Hotel> hoteis;
	
	public void inicializar() {
		
		hoteis = (ArrayList<Hotel>)Persist.recuperar("hoteis.dat");
		
		if(hoteis == null) {
			hoteis = new ArrayList<Hotel>();
		} 
	}
	
	public DadosHotel() {
		inicializar();
	}
	
	public ArrayList<Hotel> getHoteis() {
		return hoteis;
	}

	public boolean cadastrarHotel(Hotel hotel) {
		if (consultarHotel(hotel.getCNPJ())) {
            return false;
        }
		else {
			boolean r = Persist.gravar(hoteis, "hoteis.dat");
			this.hoteis.add(hotel);
	        return true;
		}
	}
	
	public boolean consultarHotel(String cnpj) {
	    	
	    	for(int i = 0; i < hoteis.size(); i++) {
	    		Hotel temp = hoteis.get(i);
	    		if(cnpj == temp.getCNPJ()) return true;
	    	} 
	    	return false;	
	}
	
	public boolean removerHotel(String cnpj) {
		for(int i = 0; i < hoteis.size(); i++) {
			Hotel temp = hoteis.get(i);
    		if(cnpj == temp.getCNPJ()) {
    			hoteis.remove(i);
    			return true;
    		}
    	}
		return false;
	}
}