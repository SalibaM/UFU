package tcd;

import java.util.ArrayList;
import java.io.Serializable;

public class DadosCompanhiaAerea implements Serializable {
	private ArrayList<CompanhiaAerea> CompanhiasAereas;

	public ArrayList<CompanhiaAerea> getCompanhiasAereas() {
		return CompanhiasAereas;
	}
	
	public DadosCompanhiaAerea() {
		inicializar();
	}
	
	public void inicializar() {
		
		CompanhiasAereas = (ArrayList<CompanhiaAerea>)Persist.recuperar("compAerea.dat");
			
		if(CompanhiasAereas == null) {
			CompanhiasAereas = new ArrayList<CompanhiaAerea>();
		} 
	}

	public boolean cadastrarCompanhiaAerea(CompanhiaAerea CompanhiaAerea) {
		if (consultarCompanhiaAerea(CompanhiaAerea.getCNPJ())) {
			return false;
		} else {
			this.CompanhiasAereas.add(CompanhiaAerea);
			boolean r = Persist.gravar(CompanhiasAereas, "compAerea.dat");
			return true;
		}
	}

	public boolean consultarCompanhiaAerea(String cnpj) {
		for (int i = 0; i < CompanhiasAereas.size(); i++) {
			CompanhiaAerea temp = CompanhiasAereas.get(i);
			if (cnpj == temp.getCNPJ()) {
				return true;
			}
		}
		return false;
	}

	public boolean removerCompanhiaAerea(String cnpj) {
		for (int i = 0; i < CompanhiasAereas.size(); i++) {
			CompanhiaAerea temp = CompanhiasAereas.get(i);
			if (cnpj == temp.getCNPJ()) {
				CompanhiasAereas.remove(i);
				return true;
			}
		}
		return false;
	}
}