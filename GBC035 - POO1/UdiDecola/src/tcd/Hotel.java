package tcd;

import java.util.Date;
import java.time.LocalDate;
import java.time.LocalTime;
import java.util.Calendar;
import java.util.ArrayList;

public class Hotel extends Empresa // Item 1f) registro de hotéis
{
	// Item 1f) atributos do hotel
	private int numEstrelas;
	private boolean accPet;
	private int numQuartos;  // Número total de quartos do hotel, sem label.
	private LocalTime horaCheckin;
	private LocalTime horaCheckout;
	private String msgDivulg;
	private String desc;
	private final static double taxa = 0.05; //Item 1p) taxa que será aplicada de acordo com valor para a UdiDecola e Item 5)
	private Date dataPoliticaCancelamento;
	private boolean cancelamentoAceito;
	private ArrayList<Quarto> quartos;
	private ArrayList<FuncHotel> funcsHotel;

    
	public LocalTime getHoraCheckin() {
		return horaCheckin;
	}

	public void setHoraCheckin(int hCheckin,int minCheckin,int segCheckin) {
		if((hCheckin<0) || (hCheckin>23)) {
			hCheckin = -1;
			minCheckin = -1;
			segCheckin = -1;
		}
		
		if((minCheckin<0) || (minCheckin>59)) {
			hCheckin = -1;
			minCheckin = -1;
			segCheckin = -1;
		}
		
		if((segCheckin<0) || (segCheckin>59)) {
			hCheckin = -1;
			minCheckin = -1;
			segCheckin = -1;
		}
		
		this.horaCheckin = LocalTime.of(hCheckin, minCheckin, segCheckin);
	}



	public LocalTime getHoraCheckout() {
		return horaCheckout;
	}



	public void setHoraCheckout(int hCheckout,int minCheckout,int segCheckout) {
		if((hCheckout<0) || (hCheckout>23)) {
			hCheckout = -1;
			minCheckout = -1;
			segCheckout = -1;
		}
		
		if((minCheckout<0) || (minCheckout>59)) {
			hCheckout = -1;
			minCheckout = -1;
			segCheckout = -1;
		}
		
		if((segCheckout<0) || (segCheckout>59)) {
			hCheckout = -1;
			minCheckout = -1;
			segCheckout = -1;
		}
		this.horaCheckout = LocalTime.of(hCheckout, minCheckout, segCheckout);
	}
	
	public Date getDataPoliticaCancelamento() {
		return dataPoliticaCancelamento;
	}



	public void setDataPoliticaCancelamento(Date dataPoliticaCancelamento) {
		this.dataPoliticaCancelamento = dataPoliticaCancelamento;
	}



	public boolean isCancelamentoAceito() {
		return cancelamentoAceito;
	}



	public void setCancelamentoAceito(boolean cancelamentoAceito) {
		this.cancelamentoAceito = cancelamentoAceito;
	}
	
	
	public static double getTaxa() {
	    return taxa;
	}


	public int getNumEstrelas() {
		return numEstrelas;
	}



	public void setNumEstrelas(int numEstrelas) {
		if(numEstrelas>0 && numEstrelas<=5) this.numEstrelas = numEstrelas;
		else numEstrelas = -1;
	}

	public boolean isAccPet() {
		return accPet;
	}

	public void setAccPet(boolean accPet) {
		this.accPet = accPet;
	}

	public int getNumQuartos() {
		return numQuartos;
	}

	public void setNumQuartos(int numQuartos) {
		if(numQuartos>0) this.numQuartos = numQuartos;
		else this.numQuartos = -1;
	}

	public String getMsgDivulg() {
		return msgDivulg;
	}



	public void setMsgDivulg(String msgDivulg) {
		if (msgDivulg != null && !msgDivulg.isEmpty()) 
		{
			this.msgDivulg = msgDivulg;
		}
		else this.msgDivulg = null;
	}



	public String getDesc() {
		return desc;
	}



	public void setDesc(String desc) {
		if (desc != null && !desc.isEmpty()) 
		{
			this.desc = desc;
		}
		else this.desc = null;
	}

	// Item 1f) cadastro de hotéis parceiros
	public Hotel(String CNPJ, String nome, String nomeDivulg, String endLogradouro, int diaCria, int mesCria,
			int anoCria, int endNumero, String endBairro, String endCidade, String endUf, String endCep,int numEstrelas,boolean accPet,int numQuartos,String msgDivulg,String desc,int hCheckin,int minCheckin,int segCheckin,int hCheckout,int minCheckout,int segCheckout) {
		
		super(CNPJ, nome, nomeDivulg, endLogradouro, diaCria, mesCria, anoCria, endNumero, endBairro, endCidade, endUf, endCep);
		
		setNumEstrelas(numEstrelas);
		setAccPet(accPet);
		setNumQuartos(numQuartos);
		setMsgDivulg(msgDivulg);
		setDesc(desc);
		setHoraCheckin(hCheckin,minCheckin,segCheckin);
		setHoraCheckout(hCheckout,minCheckout,segCheckout);
		this.funcsHotel = new ArrayList<>();
		this.quartos = new ArrayList<>();
	}
	
	public void alugouQuarto(Quarto quarto) {
		int qtdQuartos = quarto.getQuantidade();
		qtdQuartos--;
		quarto.setQuantidade(qtdQuartos);
	}
	
	public boolean disponibilidadeQuartos(Quarto quarto) { //Item 1g) e 1h) verificação de quartos disponíveis 
		int qtdQuartos = quarto.getQuantidade();
		if(qtdQuartos<=0) {
			return false;
		} else {
			return true;
		}
	}

	public void registrarQuarto(double diariaSdesc, double desconto, double diariaCdesc, int quantidade, String tipo) // Item 1g) e 1h)
	{
        Quarto quarto = new Quarto(diariaSdesc,desconto,quantidade,tipo); //Função feita para o registro de quartos pelo hotel.
        this.quartos.add(quarto);
        
    }
	
	public void registrarFuncHotel(String nome, String endLogradouro, int endNumero, String endBairro, String endCidade,
			String endUf, String endCep, String cpf, int diaNasc, int mesNasc, int anoNasc, String carteiraTrab,double BonusSal) // Item 1g) e 1h)
	{
        FuncHotel func = new FuncHotel(nome,endLogradouro,endNumero,endBairro,endCidade,endUf,endCep,cpf,diaNasc,mesNasc,anoNasc,carteiraTrab,BonusSal); //Função feita para o registro de quartos pelo hotel.
        this.funcsHotel.add(func);
        
    }
	
	 //Item 1g) política de cancelamento
	public boolean CancelamentoAceito(Date data) { //Item 1g) política de cancelamento
	    Calendar cal1 = Calendar.getInstance();
	    cal1.setTime(data);
	    
	    Calendar cal2 = Calendar.getInstance();
	    cal2.setTime(dataPoliticaCancelamento);
	    
	    return cal1.get(Calendar.YEAR) == cal2.get(Calendar.YEAR) &&
	           cal1.get(Calendar.MONTH) == cal2.get(Calendar.MONTH) &&
	           cal1.get(Calendar.DAY_OF_MONTH) == cal2.get(Calendar.DAY_OF_MONTH) &&
	           cancelamentoAceito;
	}

    public void definirPoliticaCancelamento(Date data, boolean cancelamentoAceito) //Item 1g) política de cancelamento
    {
        this.dataPoliticaCancelamento = data;
        this.cancelamentoAceito = cancelamentoAceito;
    }

	public ArrayList<FuncHotel> getFuncsHotel() {
		return funcsHotel;
	}

	public void setFuncsHotel(ArrayList<FuncHotel> funcsHotel) {
		this.funcsHotel = funcsHotel;
	}
	

}
