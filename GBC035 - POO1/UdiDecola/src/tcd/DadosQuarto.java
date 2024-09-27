package tcd;

import java.util.ArrayList;
import java.io.Serializable;

public class DadosQuarto implements Serializable{
	private ArrayList<Quarto> Quartos;

	public ArrayList<Quarto> getQuartos() {
		return Quartos;
	}
	
	public void inicializar() {
		
		Quartos = (ArrayList<Quarto>)Persist.recuperar("quartos.dat");
		
		if(Quartos == null) {
			Quartos = new ArrayList<Quarto>();
		}
	}
	
	public DadosQuarto() {
		inicializar();
	}

	public boolean cadastrarQuarto(Quarto Quarto) {
		if (consultarQuarto(Quarto)) {
			return false;
		} else {
			boolean r = Persist.gravar(Quartos, "quartos.dat");
			this.Quartos.add(Quarto);
			return true;
		}
	}

	public boolean consultarQuarto(Quarto Quarto) {

		for (int i = 0; i < Quartos.size(); i++) {
			if (Quarto == Quartos.get(i))
				return true;
		}
		return false;
	}

	public boolean removerQuarto(Quarto Quarto) {
		for (int i = 0; i < Quartos.size(); i++) {
			if (Quarto == Quartos.get(i)) {
				Quartos.remove(i);
				return true;
			}
		}
		return false;
	}
}