package tcd;

import java.util.ArrayList;
import java.io.Serializable;

public class DadosFuncionario implements Serializable {
	// arraylist
	private ArrayList<Funcionario> funcionarios;
	
	public void inicializar() {
		
		funcionarios = (ArrayList<Funcionario>)Persist.recuperar("funcionarios.dat");
		
		if(funcionarios == null) {
			funcionarios = new ArrayList<Funcionario>();
		} 
	}
	
	public DadosFuncionario() {
		inicializar();
	}

	// cadastrar (inserir no array)
	public boolean cadastrarFuncionario(Funcionario f) {
		if (consultarFuncionario(f.getCpf())) {
			return false;
		}
		boolean r = Persist.gravar(funcionarios, "funcionarios.dat");
		this.funcionarios.add(f);
		return true;
	}

	// consultar (buscar no array)
	public boolean consultarFuncionario(String cpf) {
		for (int i = 0; i < funcionarios.size(); i++) {
			Funcionario temp = funcionarios.get(i);
			if (cpf == temp.getCpf())
				return true;
		}
		return false;
	}

	// remover (retirar do array)
	public boolean removerFuncionario(String cpf) {
		for (int i = 0; i < funcionarios.size(); i++) {
			Funcionario temp = funcionarios.get(i);
			if (cpf == temp.getCpf()) {
				funcionarios.remove(i);
				return true;
			}
		}
		return false;
	}
}