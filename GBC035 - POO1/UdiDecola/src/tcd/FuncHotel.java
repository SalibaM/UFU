// item IJ: funcionários responsáveis por parcerias com hoteis
// item 4: funcionário (que cadastra) hotel é subclasse de funcionário
package tcd;


public class FuncHotel extends Funcionario {
	private static double bonusSal; //Item 5
	private int hoteisCad; // item IJ: número de hoteis cadastrados
	private Hotel h1;

	// item 3D: construtor criado por nós
	public FuncHotel(String nome, String endLogradouro, int endNumero, String endBairro, String endCidade,
			String endUf, String endCep, String cpf, int diaNasc, int mesNasc, int anoNasc, String carteiraTrab,double BonusSal) {

		super(nome, endLogradouro, endNumero, endBairro, endCidade, endUf, endCep, cpf, diaNasc, mesNasc, anoNasc,
				carteiraTrab);
		setBonusSal(bonusSal);
		setHoteisCad(0);
	}

	// item 3D: construtor criado por nós
	public FuncHotel(FuncHotel f, int diaNasc, int mesNasc, int anoNasc) {
		super(f.getNome(), f.getEndLogradouro(), f.getEndNumero(), f.getEndBairro(), f.getEndCidade(), f.getEndUf(),
				f.getEndCep(), f.getCpf(), diaNasc, mesNasc, anoNasc, f.getCarteiraTrab());

		setHoteisCad(0);
	}

	public static double getBonusSal() {
		return bonusSal;
	}

	public static void setBonusSal(double bonusSal) {
		if (bonusSal > 0)
			FuncHotel.bonusSal = bonusSal;
		else
			FuncHotel.bonusSal = -1;
	}

	public int getHoteisCad() {
		return hoteisCad;
	}

	public void setHoteisCad(int hoteisCad) {
		this.hoteisCad = hoteisCad;
	}

	// item IJ: método para definir bônus salarial dos funcionários especiais
	public void definirBonus(double bonus) {
		setBonusSal(bonus);
	}

	// item IJ: método para calcular salário do funcionário 
	public double calculaSalario() {
		double salario = getSalarioFixo() + (getSalarioFixo() * bonusSal * hoteisCad);
		return salario;
	}

}
