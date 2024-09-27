package tcd;

import java.util.ArrayList;
import java.io.Serializable;

public class DadosCliente implements Serializable{
	// arraylist
	private ArrayList<Cliente> clientes;
	
	public DadosCliente() {
		inicializar();
	}
	
	public void inicializar() {
		
		clientes = (ArrayList<Cliente>)Persist.recuperar("alunos.dat");
		
		if(clientes == null) {
			clientes = new ArrayList<Cliente>();
		} 
	}

	// cadastrar (inserir no array)
	public boolean cadastrarCliente(Cliente c) {
		if (consultarCliente(c.getCpf())) {
			return false;
		}
		this.clientes.add(c);
		boolean r = Persist.gravar(clientes, "cliente.dat");
		return true;
	}

	// consultar (buscar no array)
	public boolean consultarCliente(String cpf) {
		for (int i = 0; i < clientes.size(); i++) {
			Cliente temp = clientes.get(i);
			if (cpf == temp.getCpf())
				return true;
		}
		return false;
	}

	// remover (retirar do array)
	public boolean removerCliente(String cpf) {
		for (int i = 0; i < clientes.size(); i++) {
			Cliente temp = clientes.get(i);
			if (cpf == temp.getCpf()) {
				clientes.remove(i);
				return true;
			}
		}
		return false;
	}
}