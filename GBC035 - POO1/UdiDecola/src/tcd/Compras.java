package tcd;

import java.util.ArrayList;
import java.time.LocalTime;
import java.time.LocalDate; 

// item 1a) Classe feita para realizar buscas e compras de passagens aéreas e diárias de hoteis no udi-decola
public class Compras {
    private Cliente cliente;
    private double precoTotal;
    private ArrayList<Voos> listaVoos;
    private ArrayList<Quarto> listaQuartos;
    private LocalDate dataCompra;
	private LocalTime horaCompra;
    
    
    public Compras(Cliente cliente)
    {
    	setCliente(cliente);
    }

	
    public Compras (Cliente cliente, Voos voo, int diaCompra, int mesCompra, int anoCompra, int hCompra, int minCompra, int segCompra) { //Item 1M) criação de compras
    	setCliente(cliente);
    	adicionarVoo(voo);
    	setDataCompra(diaCompra, mesCompra, anoCompra);
    	setHoraCompra(hCompra, minCompra, segCompra);
    }
    
    public Compras (Cliente cliente, Quarto quarto, int diaCompra, int mesCompra, int anoCompra, int hCompra, int minCompra, int segCompra) {
    	setCliente(cliente);
    	adicionarQuarto(quarto);
    	setDataCompra(diaCompra, mesCompra, anoCompra);
    	setHoraCompra(hCompra, minCompra, segCompra);
    }
    
    public double calcularTaxaQuarto() { //percorre a lista de quartos, somando o valor de cada elemento * taxa
        double taxaQuarto = 0.0;
        for (int i = 0; i < listaQuartos.size(); i++) {
            Quarto quarto = listaQuartos.get(i);
            taxaQuarto += quarto.getDiariaCdesc() * Hotel.getTaxa();
        }
        return taxaQuarto;
    }
    
    public double calcularTaxaVoo() { //percorre a lista de voos, somando o valor de cada elemento * taxa
        double taxaVoo = 0.0;
        for (int i = 0; i < listaVoos.size(); i++) {
            Voos voo = listaVoos.get(i);
            taxaVoo += voo.getPreco() * CompanhiaAerea.getTaxaUdi();
        }
        return taxaVoo;
    }
    
    public LocalDate getDataCompra() {
		return dataCompra;
	}

	public void setDataCompra(int diaCompra, int mesCompra, int anoCompra) {
		if(anoCompra<=2024) {
			diaCompra = -1;
			mesCompra = -1;
			anoCompra = -1;
		}
        
        if(mesCompra<0 && mesCompra>13) {
        	diaCompra = -1;
			mesCompra = -1;
			anoCompra = -1;
        }
        
        if (diaCompra < 0) {
            diaCompra = -1;
            mesCompra = -1;
            anoCompra = -1;
        }
        
        if(mesCompra == 2 && (anoCompra % 4 == 0) && ((anoCompra % 100 != 0) || (anoCompra % 400 == 0)))
        {
            if(diaCompra<0 && diaCompra>29) {
            	diaCompra = -1;
    			mesCompra = -1;
    			anoCompra = -1;
            }
        }
        else if(mesCompra == 2 && diaCompra<0 && diaCompra>28) {
        		diaCompra = -1;
        		mesCompra = -1;
        		anoCompra = -1;
        }
        else if(diaCompra<0 && diaCompra>31) {
        		diaCompra = -1;
        		mesCompra = -1;
        		anoCompra = -1;
        }
        
        this.dataCompra = LocalDate.of(anoCompra, mesCompra, diaCompra);
	}

	public LocalTime getHoraCompra() {
		return horaCompra;
	}

	public void setHoraCompra(int hCompra, int minCompra, int segCompra) {
		if((hCompra<0) || (hCompra>23)) {
			hCompra = -1;
			minCompra = -1;
			segCompra = -1;
		}
		
		if((minCompra<0) || (minCompra>59)) {
			hCompra = -1;
			minCompra = -1;
			segCompra = -1;
		}
		
		if((segCompra<0) || (segCompra>59)) {
			hCompra = -1;
			minCompra = -1;
			segCompra = -1;
		}
		
		this.horaCompra = LocalTime.of(hCompra, minCompra, segCompra);
	}

	public void adicionarQuarto(Quarto quarto) {
        this.listaQuartos.add(quarto); //adicionar na lista de quartos
    }
    
    public ArrayList<Quarto> getListaQuartos() {
		return listaQuartos;
	}

	public void setListaQuartos(ArrayList<Quarto> listaQuartos) {
		this.listaQuartos = listaQuartos;
	}

	public void adicionarVoo(Voos voo) {
        this.listaVoos.add(voo); //adicionar na lista de voos
    }
    
    public ArrayList<Voos> getListaVoos() {
        return this.listaVoos;
    }
    
    public Cliente getCliente() {
		return cliente;
	}

	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}

	public void setListaVoos(ArrayList<Voos> listaVoos) {
        this.listaVoos = listaVoos;
    }
    
    public double calculaPreco() //Item 6, função usada pra cálculo final do preço
    {
    	precoTotal = 0.0;
    	
    	for(int i = 0; i < listaVoos.size(); i++) {
    		Voos voo = listaVoos.get(i);
    		precoTotal += voo.getPreco();
    	}
    	
    	for (int i = 0; i < listaQuartos.size(); i++) {
            Quarto quarto = listaQuartos.get(i);
            precoTotal += quarto.getDiariaCdesc();
        }
    	
    	return precoTotal;
    }
}
