package tcd;

public class CompanhiaAerea extends Empresa{
	private static double taxaUdi = 50.00; // Item 1q) Valor fixo pago pela companhia aérea, Item 5

	//item 1c) cadastro de companhias aéreas
	public CompanhiaAerea(String CNPJ, String nome, String nomeDivulg, String endLogradouro, int diaCria, int mesCria,
			int anoCria, int endNumero, String endBairro, String endCidade, String endUf,
			String endCep) {
		super(CNPJ, nome, nomeDivulg, endLogradouro, diaCria, mesCria, anoCria, endNumero, endBairro, endCidade,
				endUf, endCep);
	}
	
	public static double getTaxaUdi() {
		return taxaUdi;
	}
	
	
	
}

