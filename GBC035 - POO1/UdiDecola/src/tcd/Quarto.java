// classe quarto é uma "classe auxiliar" para hotel
package tcd;

import java.time.LocalDate;

public class Quarto {
	// atributos
	private double diariaSdesc;
	private double desconto;
	private double diariaCdesc;
	private int quantidade;
	private String tipo;
	
	// construtor
	public Quarto(double diariaSdesc, double desconto,int quantidade,String tipo) {
		this.diariaSdesc = diariaSdesc;
		this.desconto = desconto;
		this.quantidade = quantidade;
		setTipo(tipo);
	}
	
	// getters and setters 
	public double getDiariaSdesc() {
		return diariaSdesc;
	}

	public void setDiariaSdesc(double diariaSdesc) {
		this.diariaSdesc = diariaSdesc;
	}

	public double getDesconto() {
		return desconto;
	}

	public void setDesconto(double desconto) {
		this.desconto = desconto;
	}

	public double getDiariaCdesc() {
		return diariaCdesc;
	}

	public void setDiariaCdesc(double diariaCdesc) {
		this.diariaCdesc = diariaCdesc;
	}

	public int getQuantidade() {
		return quantidade;
	}

	public void setQuantidade(int quantidade) {
		this.quantidade = quantidade;
	}

	public String getTipo() {
		return tipo;
	}

	public void setTipo(String tipo) {
		
		if(tipo == "Single") {
			this.tipo = "Single";
		} else {
			if(tipo == "Standard Single") {
				this.tipo = "Standard Single";
			} else {
				if(tipo=="Standard Duplo") {
					this.tipo = "Standard Duplo";
				} else {
					if(tipo == "Standard Triplo") {
						this.tipo = "Standard Triplo";
					} else {
						this.tipo = null;
					}
				}
			}
		}
		
		
		
		
	}

}
