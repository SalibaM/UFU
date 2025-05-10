package RefactoringIDE.EX03;

public class Carro extends Veiculo {

    public Carro(String modelo, String marca, int ano) {
        super(modelo, marca, ano);
    }

    @Override
    public void ligar() {
        System.out.println("Ligando o carro " + modelo);
    }
}