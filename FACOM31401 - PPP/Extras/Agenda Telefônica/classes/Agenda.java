package classes;

import java.util.ArrayList;

public class Agenda {
	private static ArrayList<Contato> contatos = new ArrayList<>();
		
	public static ArrayList<Contato> getContatos() {
		return contatos;
	}
	
	public static Contato procurarContato(String telefone) {
		Contato contatoEncontrado = null;
		for (Contato c : contatos) {
			if(c.getTelefone().equalsIgnoreCase(telefone)) {
				contatoEncontrado = c;
				break;
			}
		}
		return contatoEncontrado;
	}
	
	public static Contato apagarContato(String telefone) {
		Contato contatoEncontrado = null;
		for(Contato c : contatos) {
			if(c.getTelefone().equalsIgnoreCase(telefone)) {
				contatoEncontrado = c;
				break;
			}
		}
		if(contatoEncontrado != null) {
			contatos.remove(contatoEncontrado);
		}
		return contatoEncontrado;
	}
	
	public static String cadastrarContato(String nome, String telefone, String endereco) {
		if(nome.isEmpty() || telefone.isEmpty() || endereco.isEmpty()) {
			return "Dados incompletos.";
		}
		if(telefone.length() != 11) {
			return "Formato de telefone incorreto.";
		}
		contatos.add(new Contato(nome, telefone, endereco));
		return "Contato cadastrado.";
	}
}
