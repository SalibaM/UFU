package classes;

// ALTERAÇÃO: criada nova classe Video

public class Video extends MaterialBibliografico {

	private String autor;
	private int duracao;
	
	public Video(String titulo, int ano, String autor, int duracao) {
		super(titulo, ano);
		setAutor(autor);
		setDuracao(duracao);
	}

	public String getAutor() {
		return autor;
	}

	public void setAutor(String autor) throws IllegalArgumentException {
		if(autor.length() > 0) this.autor = autor;
		else throw new IllegalArgumentException();
	}

	public int getDuracao() {
		return duracao;
	}

	public void setDuracao(int duracao) throws IllegalArgumentException {
		if(duracao > 0) this.duracao = duracao;
		else throw new IllegalArgumentException();
	}
	
	@Override
	public String toString() {
		return "Vídeo: " 
				+ super.getTitulo() 
				+ " (" + super.getAno() + "), "
				+ getAutor() + " - "
				+ getDuracao() + " min";
	}
}
