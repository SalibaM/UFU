package tcd;
import java.time.LocalDate;

import validacoes.ValidaCNPJ;

public class Empresa {
	
	private String CNPJ; //Definido por meio de um método auxiliar com o uso do pacote ValidaCNPJ
	private String nome;
	private String nomeDivulg;
	private LocalDate dataCria;
	private String endLogradouro;
	private int endNumero;
	private String endBairro;
	private String endCidade;
	private String endUf;
	private String endCep;
	
	public Empresa(String CNPJ,String nome, String nomeDivulg, String endLogradouro,int diaCria,int mesCria,int anoCria, int endNumero, String endBairro, String endCidade, String endUf, String endCep)
	{
		setCNPJ(CNPJ);
		
		setNome(nome); // Sem restrições
		
		setNomeDivulg(nomeDivulg);
		
		setEndLogradouro(endLogradouro); //Pode ser o que ele quiser
		setEndNumero(endNumero); //Pode ser o que ele quiser
		setEndBairro(endBairro); //Pode ser o que ele quiser
		setEndCidade(endCidade); //Pode ser o que ele quiser
		
		setEndUf(endUf);
		
		setEndCep(endCep);
		
		setDataCria(diaCria,mesCria,anoCria);
	}
	
	public String getEndLogradouro() {
		return endLogradouro;
	}
	
	public void setEndLogradouro(String endLogradouro) {
		this.endLogradouro = endLogradouro;
	}
	
	public int getEndNumero() {
		return endNumero;
	}
	
	public void setEndNumero(int endNumero) {
		this.endNumero = endNumero;
	}
	
	public String getEndBairro() {
		return endBairro;
	}
	
	public void setEndBairro(String endBairro) {
		this.endBairro = endBairro;
	}
	
	public String getEndCidade() {
		return endCidade;
	}
	
	public void setEndCidade(String endCidade) {
		if (endCidade != null && !endCidade.isEmpty()) 
		{
			this.endCidade = endCidade;
		}
		else this.endCidade = null;
	}
	
	public String getEndUf() {
		return endUf;
	}
	
	public void setEndUf(String endUf) {
		
		if(endUf.length()<=2) {
			this.endUf = endUf;
		} else {
			this.endUf = null;
		}
	}
	
	public String getEndCep() {
		return endCep;
	}
	
	public void setEndCep(String endCep) {
		
		if(endCep.length()==8) {
			this.endCep = endCep;
		} else {
			this.endCep = null;
		}
	}
	public String getCNPJ() {
		return CNPJ;
	}
	public void setCNPJ(String CNPJ) {
		
		if(ValidaCNPJ.isCNPJ(CNPJ) == true) {
			this.CNPJ = CNPJ;
		} else {
			this.CNPJ = null;
		}
	}
	
	public String getNome() {
		return nome;
	}
	
	public void setNome(String Nome) {
		nome = Nome;
	}
	
	public String getNomeDivulg() {
		return nomeDivulg;
	}
	
	public void setNomeDivulg(String nomeDivulg) {
		if(nomeDivulg.length()<=20) { // Nome de divulgação menor ou igual a 20 caracteres
			this.nomeDivulg = nomeDivulg;
		} else {
			this.nomeDivulg = null;
		}
	}

	public LocalDate getDataCria() {
		return dataCria;
	}

	public void setDataCria(int diaCria,int mesCria,int anoCria) {
		
		if(anoCria>=2024) {
			diaCria = -1;
			mesCria = -1;
			anoCria = -1;
		}
        
        if(mesCria<0 && mesCria>13) {
        	diaCria = -1;
			mesCria = -1;
			anoCria = -1;
        }
        
        if (diaCria < 0) {
            diaCria = -1;
            mesCria = -1;
            anoCria = -1;
        }
        
        if(mesCria == 2 && (anoCria % 4 == 0) && ((anoCria % 100 != 0) || (anoCria % 400 == 0)))
        {
            if(diaCria<0 && diaCria>29) {
            	diaCria = -1;
    			mesCria = -1;
    			anoCria = -1;
            }
        }
        else if(mesCria == 2 && diaCria<0 && diaCria>28) {
        		diaCria = -1;
        		mesCria = -1;
        		anoCria = -1;
        }
        else if(diaCria<0 && diaCria>31) {
        		diaCria = -1;
        		mesCria = -1;
        		anoCria = -1;
        }
        
        this.dataCria = LocalDate.of(anoCria, mesCria, diaCria);
        
        
        
	}
	
}
