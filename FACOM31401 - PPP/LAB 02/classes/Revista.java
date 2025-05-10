package classes;

public class Revista extends MaterialBibliografico {
	private String organizacao;
	private int volume;
	private int numero;
	
	public Revista(String titulo, String organizacao, int  volume, int numero, int ano) {
		super(titulo, ano);
		setOrganizacao(organizacao);
		setVolume(volume);
		setNumero(numero);
	}
	
	public String getOrganizacao() {
		return this.organizacao;
	}
	
	public void setOrganizacao(String organizacao) throws IllegalArgumentException {
		// o nome da organização não pode estar vazio
		if(organizacao.length() > 0) this.organizacao = organizacao;
		else throw new IllegalArgumentException();
	}

	public int getVolume() {
		return this.volume;
	}

	public void setVolume(int volume) throws IllegalArgumentException {
		// o volume deve ser um valor inteiro positivo
		if(volume > 0) this.volume = volume;
		else throw new IllegalArgumentException();
	}

	public int getNumero() {
		return this.numero;
	}

	public void setNumero(int numero) throws IllegalArgumentException{
		// o número deve ser um valor inteiro positivo
		if(numero > 0) this.numero = numero;
		else throw new IllegalArgumentException();
	}
	
	@Override
	public String toString() {
		return "Revista: " 
				+ super.getTitulo() + ", "
				+ getOrganizacao() 
				+ " - Vol. " + getVolume() + ", "
				+ "Nro. " + getNumero()
				+ " (" + super.getAno() + ")";
	}
}
