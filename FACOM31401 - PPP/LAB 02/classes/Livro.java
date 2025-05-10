package classes;

public class Livro extends MaterialBibliografico {
	private String autor;
	
	public Livro(String titulo, String autor, int ano) { 
		super(titulo, ano);
		setAutor(autor);
	}
	
	public String getAutor() {
		return this.autor;
	}
	
	public void setAutor(String autor) throws IllegalArgumentException {
		// o nome do autor não pode estar vazio
	 	if(autor.length() > 0) this.autor = autor;
		else throw new IllegalArgumentException();
	}

	@Override
	public String toString() {
		return "Livro: " 
				+ super.getTitulo() + ", " 
				+ getAutor() 
				+ " (" + super.getAno() + ")";
	}
}
