package classes;

import java.util.ArrayList;

public class MaterialBibliografico {
	private static ArrayList<MaterialBibliografico> materialBibliografico = new ArrayList<>();
	private String titulo;
	private int ano;

	public MaterialBibliografico(String titulo, int ano) {
		setTitulo(titulo);
	    setAno(ano);
	}

	public String getTitulo() {
	    return this.titulo;
	}
	
	public void setTitulo(String titulo) throws IllegalArgumentException {
		// o título não pode estar vazio
	    if(titulo.length() > 0) this.titulo = titulo;
	    else throw new IllegalArgumentException();
	}

	public int getAno() {
		return this.ano;
	}

	public void setAno(int ano) throws IllegalArgumentException {
		// o ano deve ser um valor inteiro positivo
	    if(ano > 0) this.ano = ano;
	    else throw new IllegalArgumentException();
	}

	public static String listarMaterialBibliografico() {
		if(materialBibliografico.isEmpty()) 
			return "Não há nenhum material bibliográfico cadastrado.";
		else {
			String str = "";
			for(MaterialBibliografico material : materialBibliografico) 
				str = str + material.toString() + "\n";
			return str;
		}
	}

	public static void adicionarMaterialBibliografico(MaterialBibliografico material) throws IllegalArgumentException {
	    try {
	    	materialBibliografico.add(material);
	    } catch(IllegalArgumentException error) {
	    	throw new IllegalArgumentException();
	    }
	}
}

