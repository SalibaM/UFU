package tcd;

import java.util.ArrayList;
import java.io.Serializable;

public class DadosFuncHotel implements Serializable {
	// arraylist
	private ArrayList<FuncHotel> funcsHotel;
	
	public void inicializar() {
		
		funcsHotel = (ArrayList<FuncHotel>)Persist.recuperar("funcHotel.dat");
		
		if(funcsHotel == null) {
			funcsHotel = new ArrayList<FuncHotel>();
		} 
	}
	
	public DadosFuncHotel() {
		inicializar();
	}

	// cadastrar (inserir no array)
	public boolean cadastrarFuncHotel(FuncHotel fh) {
		if (consultarFuncHotel(fh.getCpf())) {
			return false;
		}
		boolean r = Persist.gravar(funcsHotel, "funcHotel.dat");
		this.funcsHotel.add(fh);
		return true;
	}

	// consultar (buscar no array)
	public boolean consultarFuncHotel(String cpf) {
		for (int i = 0; i < funcsHotel.size(); i++) {
			FuncHotel temp = funcsHotel.get(i);
			if (cpf == temp.getCpf())
				return true;
		}
		return false;
	}

	// remover (retirar do array)
	public boolean removerFuncHotel(String cpf) {
		for (int i = 0; i < funcsHotel.size(); i++) {
			FuncHotel temp = funcsHotel.get(i);
			if (cpf == temp.getCpf()) {
				funcsHotel.remove(i);
				return true;
			}
		}
		return false;
	}
}