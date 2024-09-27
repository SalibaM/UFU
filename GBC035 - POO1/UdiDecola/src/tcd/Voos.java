package tcd;

import java.time.LocalTime;
import java.time.LocalDate;

public class Voos {
	
	private LocalDate dataVoo;
	private LocalTime horaSaida;
	private LocalTime horaChegada;
	private int vagas; //item 1e) vagas do udidecola
	private double preco;

	//item 1e) possibilidade de diferentes horários e trecho e voo são estabelecidos aqui
	public Voos(int diaVoo,int mesVoo,int anoVoo,int hSaida,int minSaida,int segSaida,int hChegada,int minChegada,int segChegada,int vagas,double preco) {
		
		setDataVoo(diaVoo,mesVoo,anoVoo);
		setHoraSaida(hSaida,minSaida,segSaida);
		setHoraChegada(hChegada,minChegada,segChegada);
		setVagas(vagas);
		setPreco(diaVoo,mesVoo,anoVoo,preco);
		
	}

	public LocalDate getDataVoo() {
		return dataVoo;
	}

	public void setDataVoo(int diaVoo,int mesVoo,int anoVoo) {

        this.dataVoo = LocalDate.of(anoVoo, mesVoo, diaVoo);
	}

	public LocalTime getHoraSaida() {
		return horaSaida;
	}

	public void setHoraSaida(int hSaida,int minSaida,int segSaida) {
		if((hSaida<0) || (hSaida>23)) {
			hSaida = -1;
			minSaida = -1;
			segSaida = -1;
		}
		
		if((minSaida<0) || (minSaida>59)) {
			hSaida = -1;
			minSaida = -1;
			segSaida = -1;
		}
		
		if((segSaida<0) || (segSaida>59)) {
			hSaida = -1;
			minSaida = -1;
			segSaida = -1;
		}
		
		this.horaSaida = LocalTime.of(hSaida, minSaida, segSaida);
	}

	public LocalTime getHoraChegada() {
		return horaChegada;
	}

	public void setHoraChegada(int hChegada,int minChegada,int segChegada) {
		if((hChegada<0) || (hChegada>23)) {
			hChegada = -1;
			minChegada = -1;
			segChegada = -1;
		}
		
		if((minChegada<0) || (minChegada>59)) {
			hChegada = -1;
			minChegada = -1;
			segChegada = -1;
		}
		
		if((segChegada<0) || (segChegada>59)) {
			hChegada = -1;
			minChegada = -1;
			segChegada = -1;
		}
		
		this.horaChegada = LocalTime.of(hChegada, minChegada, segChegada);
	}

	public int getVagas() {
		return vagas;
	}

	public void setVagas(int vagas) {
		
		if(vagas<0) {
			this.vagas = 0;
		} else {
			this.vagas = vagas;
		}
		
	}

	public double getPreco() {
		return preco;
	}

	public void setPreco(int diaVoo,int mesVoo,int anoVoo,double preco) { //Item 1e) variação de preço de passagens de acordo com eventos ou datas do ano
		
		double valorAumentado;
		
		//Ano novo e Natal
		if(((diaVoo > 15) && (diaVoo < 31)) && (mesVoo == 12) ) {
			valorAumentado = 0.1 * preco;
			this.preco = (preco+valorAumentado);
		} else {
			//Carnaval
			if(((diaVoo > 10) && (diaVoo < 17)) && (mesVoo == 2) ) {
				valorAumentado = 0.1 * preco;
				this.preco = (preco+valorAumentado);
			} else {
				//Páscoa
				if(((diaVoo > 25) && (diaVoo < 31)) && (mesVoo == 3) ) {
					valorAumentado = 0.1 * preco;
					this.preco = (preco+valorAumentado);
				} else {
					//Corpus Christi
					if(((diaVoo > 24) && (diaVoo < 30)) && (mesVoo == 5) ) {
						valorAumentado = 0.1 * preco;
						this.preco = (preco+valorAumentado);
					} else {
						//Proclamação da República
						if(((diaVoo > 9) && (diaVoo < 15)) && (mesVoo == 11) ) {
							valorAumentado = 0.1 * preco;
							this.preco = (preco+valorAumentado);
						} else {
							//Férias escolares
							if(((diaVoo > 1) && (diaVoo < 31)) && (mesVoo == 7) ) {
								valorAumentado = 0.1 * preco;
								this.preco = (preco+valorAumentado);
							} else {
								//Dia das mães
								if(((diaVoo > 1) && (diaVoo < 12)) && (mesVoo == 5) ) {
									valorAumentado = 0.1 * preco;
									this.preco = (preco+valorAumentado);
								} else {
									//Dia dos pais
									if(((diaVoo > 1) && (diaVoo < 11)) && (mesVoo == 8) ) {
										valorAumentado = 0.1 * preco;
										this.preco = (preco+valorAumentado);
									} else {
										//Data padrão
										this.preco = preco;
									}
								}
							}
						}
					}
				}
			}
		}
	}
	

}
