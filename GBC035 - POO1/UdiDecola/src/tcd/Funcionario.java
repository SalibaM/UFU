// item 1I: classe de funcionários da empresa
// item 4: funcionário é subclasse de pessoa
package tcd;


public class Funcionario extends Pessoa {
	private String carteiraTrab;
	private static double salarioFixo;

	// item 3D: construtor criado por nós
	public Funcionario(String nome, String endLogradouro, int endNumero, String endBairro, String endCidade, String endUf,
			String endCep, String cpf, int diaNasc, int mesNasc, int anoNasc, String carteiraTrab) {

		super(nome, endLogradouro, endNumero, endBairro, endCidade, endUf, endCep, cpf, diaNasc, mesNasc, anoNasc);

		setCarteiraTrab(carteiraTrab);
	}

	public String getCarteiraTrab() {
		return carteiraTrab;
	}

	public void setCarteiraTrab(String carteiraTrab) {
		this.carteiraTrab = carteiraTrab;
	}

	public static void setSalarioFixo(double salarioFixo) {
		if (salarioFixo > 0)
			Funcionario.salarioFixo = salarioFixo;
		else
			Funcionario.salarioFixo = -1;
	}

	public double getSalarioFixo() {
		return salarioFixo;
	}

	// item 1I: método para definir salário dos funcionários
	public void definirSalario(double salario) {
		setSalarioFixo(salario);
	}
}
