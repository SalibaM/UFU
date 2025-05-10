package RefactoringManual.EX02;

public class Pessoa {
    private String nome;
    private String email;
    private String telefone;
    private Endereco endereco;

    public Pessoa(String nome, String email, String telefone, Endereco endereco) {
        this.nome = nome;
        this.email = email;
        this.telefone = telefone;
        this.endereco = endereco;
    }

    public void exibirInformacoes() {
        System.out.println("Nome: " + nome);
        System.out.println("Email: " + email);
        System.out.println("Telefone: " + telefone);
        System.out.println(endereco);
    }
}
