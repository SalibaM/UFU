package RefactoringIDE.EX02;

public class Pessoa {
    private final Endereco endereco = new Endereco();
    private String nome;
    private String email;
    private String telefone;

    public Pessoa(String nome, String email, String telefone, String rua, String cidade, String estado, String cep) {
        this.nome = nome;
        this.email = email;
        this.telefone = telefone;
        this.endereco.rua = rua;
        this.endereco.cidade = cidade;
        this.endereco.estado = estado;
        this.endereco.cep = cep;
    }

    public void exibirInformacoes() {
        System.out.println("Nome: " + nome);
        System.out.println("Email: " + email);
        System.out.println("Telefone: " + telefone);
        System.out.println("Endereço: " + endereco.rua + ", " + endereco.cidade + ", " + endereco.estado + " - " + endereco.cep);
    }
}
