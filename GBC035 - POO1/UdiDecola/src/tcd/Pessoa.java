package tcd;

import validacoes.VerificaCPF;
import java.time.LocalDate;

// Pessoa é uma superclasse para Cliente e Funcionário (item 4)
public class Pessoa {
	// atributos em comum entre Cliente e Funcionário
	private String nome;
	private String endLogradouro;
	private int endNumero;
	private String endBairro;
	private String endCidade;
	private String endUf;
	private String endCep;
	private String cpf;
	private LocalDate dataNasc;

	// construtor (item 3D)
	public Pessoa(String nome, String endLogradouro, int endNumero, String endBairro, String endCidade, String endUf,
			String endCep, String cpf, int diaNasc, int mesNasc, int anoNasc) {

		setNome(nome);
		setEndLogradouro(endLogradouro);
		setEndNumero(endNumero);
		setEndBairro(endBairro);
		setEndCidade(endCidade);
		setEndUf(endUf);
		setEndCep(endCep);
		setCpf(cpf);
		setDataNasc(diaNasc, mesNasc, anoNasc);
	}

	// construtor (item 3D)
	public Pessoa() {

	}

	// getters e setters
	public String getNome() {
		return nome;
	}

	public void setNome(String nome) {
		if (nome.length() > 0)
			this.nome = nome;
		else
			this.nome = null;
	}

	public String getEndLogradouro() {
		return endLogradouro;
	}

	public void setEndLogradouro(String endLogradouro) {
		if (endLogradouro.length() > 0)
			this.endLogradouro = endLogradouro;
		else
			this.endLogradouro = null;
	}

	public int getEndNumero() {
		return endNumero;
	}

	public void setEndNumero(int endNumero) {
		if (endNumero > 0)
			this.endNumero = endNumero;
		else
			this.endNumero = -1;
	}

	public String getEndBairro() {
		return endBairro;
	}

	public void setEndBairro(String endBairro) {
		if (endBairro.length() > 0)
			this.endBairro = endBairro;
		else
			this.endBairro = null;
	}

	public String getEndCidade() {
		return endCidade;
	}

	public void setEndCidade(String endCidade) {
		if (endCidade.length() > 0)
			this.endCidade = endCidade;
		else
			this.endCidade = null;
	}

	public String getEndUf() {
		return endUf;
	}

	public void setEndUf(String endUf) {
		if (endUf.length() == 2)
			this.endUf = endUf;
		else
			this.endUf = null;
	}

	public String getEndCep() {
		return endCep;
	}

	public void setEndCep(String endCep) {
		if (endCep.length() == 8)
			this.endCep = endCep;
		else
			this.endCep = null;
	}

	public String getCpf() {
		return cpf;
	}

	public void setCpf(String cpf) {
		if (VerificaCPF.isCPF(cpf))
			this.cpf = cpf;
		else
			this.cpf = null;
	}

	public LocalDate getDataNasc() {
		return dataNasc;
	}

	public void setDataNasc(int dia, int mes, int ano) {
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
			this.dataNasc = LocalDate.of(ano, mes, dia);
		}
	}
}
