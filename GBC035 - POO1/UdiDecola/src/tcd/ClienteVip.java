package tcd;

import java.time.LocalDate;

// item 1K: classe de clientes vip
// item 4: cliente vip é subclasse de cliente
public class ClienteVip extends Cliente {
	private static double descontoVip = 0.20;
	private LocalDate dataVip;

	// item 3D: construtor criado por nós
	public ClienteVip(String nome, String endLogradouro, int endNumero, String endBairro, String endCidade,
			String endUf, String endCep, String cpf, int diaNasc, int mesNasc, int anoNasc, int diaCad, int mesCad,
			int anoCad, String email, int numCompras, int diaVip, int mesVip, int anoVip) {

		super(nome, endLogradouro, endNumero, endBairro, endCidade, endUf, endCep, cpf, diaNasc, mesNasc, anoNasc,
				diaCad, mesCad, anoCad, email, numCompras);

		setDataVip(diaVip, mesVip, anoVip);
	}

	// item 3D: construtor criado por nós
	public ClienteVip(Cliente cliente, int diaVip, int mesVip, int anoVip, int diaCad, int mesCad, int anoCad) {
		super(cliente.getNome(), cliente.getEndLogradouro(), cliente.getEndNumero(), cliente.getEndBairro(),
				cliente.getEndCidade(), cliente.getEndUf(), cliente.getEndCep(), cliente.getCpf(), diaVip, mesVip,
				anoVip, diaCad, mesCad, anoCad, cliente.getEmail(), cliente.getNumCompras());
		setDataVip(diaVip, mesVip, anoVip);
	}

	public double getDescontoVip() {
		return descontoVip;
	}

	public LocalDate getDataVip() {
		return dataVip;
	}

	public void setDataVip(int dia, int mes, int ano) {
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

		if ((dia != -1) && (mes != -1) && (ano != -1)) {
			this.dataVip = LocalDate.of(ano, mes, dia);
		}
	}
}
