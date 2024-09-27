package tcd;
import java.time.LocalDate;
import java.time.LocalTime;

public class Pesquisas {

	//Item 1L) registro das informações, data, hora etc.
	Cliente cliente; // Cada pesquisa terá exatamente qual cliente a fez, para facilitar no registro.
	private String origem;
	private String destino;
	private LocalDate dataInicio;
	private LocalDate dataFim;
	private LocalTime horaPesquisa;
	private LocalDate dataPesquisa;
	
	public Pesquisas(Cliente cliente,String origem,String destino,int diaInicio,int mesInicio,int anoInicio,int diaFim,int mesFim,int anoFim) {
		setOrigem(origem);
		setDestino(destino);
		setDataInicio(diaInicio,mesInicio,anoInicio);
		setDataFim(diaFim,mesFim,anoFim);
		setHoraPesquisa();
		setDataPesquisa();
		setCliente(cliente);
	}
	
	public Cliente getCliente() {
		return cliente;
	}

	public void setCliente(Cliente cliente) {
		this.cliente = cliente;
	}

	public LocalTime getHoraPesquisa() {
		return horaPesquisa;
	}
	
	public void setHoraPesquisa() {
		this.horaPesquisa = LocalTime.now();
	}
	
	public LocalDate getDataPesquisa() {
		return dataPesquisa;
	}
	public void setDataPesquisa() { 
		this.dataPesquisa = LocalDate.now();
	}

	public String getOrigem() {
		return origem;
	}

	public void setOrigem(String origem) {
		this.origem = origem;
	}

	public String getDestino() {
		return destino;
	}

	public void setDestino(String destino) {
		this.destino = destino;
	}

	public LocalDate getDataInicio() {
		return dataInicio;
	}

	public void setDataInicio(int diaInicio,int mesInicio,int anoInicio) {

		if(anoInicio<=2024) {
			diaInicio = -1;
			mesInicio = -1;
			anoInicio = -1;
		}
        
        if(mesInicio<0 && mesInicio>13) {
        	diaInicio = -1;
			mesInicio = -1;
			anoInicio = -1;
        }
        
        if (diaInicio < 0) {
            diaInicio = -1;
            mesInicio = -1;
            anoInicio = -1;
        }
        
        if(mesInicio == 2 && (anoInicio % 4 == 0) && ((anoInicio % 100 != 0) || (anoInicio % 400 == 0)))
        {
            if(diaInicio<0 && diaInicio>29) {
            	diaInicio = -1;
    			mesInicio = -1;
    			anoInicio = -1;
            }
        }
        else if(mesInicio == 2 && diaInicio<0 && diaInicio>28) {
        		diaInicio = -1;
        		mesInicio = -1;
        		anoInicio = -1;
        }
        else if(diaInicio<0 && diaInicio>31) {
        		diaInicio = -1;
        		mesInicio = -1;
        		anoInicio = -1;
        }
        
        this.dataInicio = LocalDate.of(anoInicio, mesInicio, diaInicio);
        
	}

	public LocalDate getDataFim() {
		return dataFim;
	}

	public void setDataFim(int diaFim,int mesFim,int anoFim) {

		if(anoFim<=2024) {
			diaFim = -1;
			mesFim = -1;
			anoFim = -1;
		}
        
        if(mesFim<0 && mesFim>13) {
        	diaFim = -1;
			mesFim = -1;
			anoFim = -1;
        }
        
        if (diaFim < 0) {
            diaFim = -1;
            mesFim = -1;
            anoFim = -1;
        }
        
        if(mesFim == 2 && (anoFim % 4 == 0) && ((anoFim % 100 != 0) || (anoFim % 400 == 0)))
        {
            if(diaFim<0 && diaFim>29) {
            	diaFim = -1;
    			mesFim = -1;
    			anoFim = -1;
            }
        }
        else if(mesFim == 2 && diaFim<0 && diaFim>28) {
        		diaFim = -1;
        		mesFim = -1;
        		anoFim = -1;
        }
        else if(diaFim<0 && diaFim>31) {
        		diaFim = -1;
        		mesFim = -1;
        		anoFim = -1;
        }
        
        this.dataInicio = LocalDate.of(anoFim, mesFim, diaFim);
        
	}
	
	
	
	
	
}
