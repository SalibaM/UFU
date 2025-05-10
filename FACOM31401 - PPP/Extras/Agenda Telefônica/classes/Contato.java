package classes;

public class Contato {
	private String nome;
	private String telefone;
	private String endereco;
	
	public Contato(String nome, String telefone, String endereco) {
		setNome(nome);
		setTelefone(telefone);
		setEndereco(endereco);
	}
	
	public Contato(Contato contato) {
		setNome(contato.getNome());
		setTelefone(contato.getTelefone());
		setEndereco(contato.getEndereco());
	}

	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		if(!nome.isEmpty()) this.nome = nome;
	}

	public String getTelefone() {
		return telefone;
	}

	public void setTelefone(String telefone) {
		if(telefone.length() == 11) this.telefone = telefone;
		else this.telefone = null;
	}

	public String getEndereco() {
		return endereco;
	}

	public void setEndereco(String endereco) {
		if(!endereco.isEmpty()) this.endereco = endereco;
	}

	@Override
	public String toString() {
		return "Nome: " + nome + 
				"\nTelefone: " + telefone + 
				"\nEndereco: " + endereco + "\n";
	}
}
