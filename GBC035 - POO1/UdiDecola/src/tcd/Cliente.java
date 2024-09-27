package tcd;

import java.time.LocalDate;
import java.util.ArrayList;

// item 1K: classe de clientes
// item 4: cliente é subclasse de pessoa
public class Cliente extends Pessoa {

	private LocalDate dataCad;
	private String email;
	private int numCompras;
	private ArrayList<Pesquisas> pesquisas; // Item 8a) extra: cada cliente terá um ArrayList de pesquisas associada a ele.
	//Basicamente todo cliente terá um ArrayList que armazenará as suas pesquisas e compras de forma específica, tornando cada um deles
	// mais individual ainda, além de facilitar o acesso de histórico tanto de pesquisas quanto de compras.
	private ArrayList<Compras> compras;

	// item 3D: construtor criado por nós
	public Cliente(String nome, String endLogradouro, int endNumero, String endBairro, String endCidade, String endUf,
			String endCep, String cpf, int diaNasc, int mesNasc, int anoNasc, int diaCad, int mesCad, int anoCad,
			String email, int numCompras) {
		super(nome, endLogradouro, endNumero, endBairro, endCidade, endUf, endCep, cpf, diaNasc, mesNasc, anoNasc);
		setDataCad(diaCad, mesCad, anoCad);
		setEmail(email);
		setNumCompras(numCompras);
		this.pesquisas = new ArrayList<>();
		this.compras = new ArrayList<>();
	}

	// item 3A: construtor de cliente que recebe nome e cpf
	public Cliente(String nome, String cpf) {
		setNome(nome);
		setCpf(cpf);
	}

	// item 3B: contrutor default de cliente
	public Cliente() {

	}

	// item 1K: método que transforma um cliente em vip a partir do seu número de compras
	public void transformaEmVip() {
		if (numCompras == 20) { //Item 5
			ClienteVip clienteVip = new ClienteVip(this, getDataNasc().getDayOfMonth(), getDataNasc().getMonthValue(),
					getDataNasc().getYear(), getDataCad().getDayOfMonth(), getDataCad().getMonthValue(),
					getDataCad().getYear());
			ArrayList<Compras> comprasCliente = getCompras();

			for (int i = 0; i < comprasCliente.size(); i++) { // percorre o array de compras do cliente
				Compras compra = comprasCliente.get(i); // pega o item
				clienteVip.adicionarCompra(compra); // adiciona na lista de compras do clienteVip
			}
		}
	}

	public void efetivarCompraVoo(Compras compra) { //Item 1M) realização e registro de compra e Item 5

		this.compras.add(compra);

		transformaEmVip(); // se o cliente for elegível a vip, vira vip, senão nada acontece

		double taxaVoo = compra.calcularTaxaVoo();

	}

	public void efetivarCompraQuarto(Compras compra) { //Item 1M) realização e registro de compra e Item 5

		this.compras.add(compra);

		transformaEmVip(); // se o cliente for elegível a vip, vira vip, senão nada acontece

		double taxaQuarto = compra.calcularTaxaQuarto();

	}
 
	public void adicionarCompra(Compras compra) { //Item 1M) realização e registro de compra e Item 5
		this.compras.add(compra);
		numCompras++; // Item 1o) atualização do número de compras após adição a ArrayList
	}

	public ArrayList<Compras> getCompras() {
		return compras;
	}

	public void adicionarPesquisa(Pesquisas p1) {
		this.pesquisas.add(p1);
	}

	public ArrayList<Pesquisas> getPesquisas() {
		return pesquisas;
	}

	public void setPesquisas(ArrayList<Pesquisas> pesquisas) {
		this.pesquisas = pesquisas;
	}

	public LocalDate getDataCad() {
		return dataCad;
	}

	public void setDataCad(int dia, int mes, int ano) {
		if (ano < 0) {
			dia = -1;
			mes = -1;
			ano = -1;
		}

		if ((mes < 0) && (mes > 13)) {
			dia = -1;
			mes = -1;
			ano = -1;
		}

		if (dia < 0) {
			dia = -1;
			mes = -1;
			ano = -1;
		}

		if ((mes == 2) && (ano % 4 == 0) && ((ano % 100 != 0) || (ano % 400 == 0))) {
			if ((dia < 0) && (dia > 29)) {
				dia = -1;
				mes = -1;
				ano = -1;
			}
		} else if ((mes == 2) && (dia < 0) && (dia > 28)) {
			dia = -1;
			mes = -1;
			ano = -1;
		}

		if ((mes == 1) || (mes == 3) || (mes == 5) || (mes == 7) || (mes == 8) || (mes == 10) || (mes == 12)) {
			if ((dia < 0) && (dia > 31)) {
				dia = -1;
				mes = -1;
				ano = -1;
			}
		}

		if ((mes == 4) || (mes == 6) || (mes == 9) || (mes == 11)) {
			if ((dia < 0) && (dia > 30)) {
				dia = -1;
				mes = -1;
				ano = -1;
			}
		}

		this.dataCad = LocalDate.of(ano, mes, dia);
	}

	public String getEmail() {
		return email;
	}

	public void setEmail(String email) {
		this.email = email;
	}

	public int getNumCompras() {
		return numCompras;
	}

	public void setNumCompras(int numCompras) {
		if (numCompras >= 0)
			this.numCompras = numCompras;
		else
			this.numCompras = -1;
	}
}
