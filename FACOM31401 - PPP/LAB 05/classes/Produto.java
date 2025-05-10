package classes;

public class Produto {
   private int id;
   private String nome;
   private String descricao;
   private double preco;
   private int quantidade;

   public Produto(int id, String nome, String descricao, double preco, int quantidade) {
       setId(id);
       setNome(nome);
       setDescricao(descricao);
       setPreco(preco);
       setQuantidade(quantidade);
   }

   public int getId() {
       return id;
   }

   public void setId(int id) throws IllegalArgumentException {
       if(id > 0) this.id = id;
       else throw new IllegalArgumentException("Id inválido.");
   }

   public String getNome() {
       return nome;
   }

   public void setNome(String nome) throws IllegalArgumentException {
       if(!nome.isEmpty()) this.nome = nome;
       else throw new IllegalArgumentException("Nome inválido.");
   }

   public String getDescricao() {
       return descricao;
   }

   public void setDescricao(String descricao) throws IllegalArgumentException {
       if(!descricao.isEmpty()) this.descricao = descricao;
       else throw new IllegalArgumentException("Descrição inválida.");
   }

   public double getPreco() {
       return preco;
   }

   public void setPreco(double preco) throws IllegalArgumentException {
       if(preco > 0) this.preco = preco;
       else throw new IllegalArgumentException("Preço inválido.");
   }

   public int getQuantidade() {
       return quantidade;
   }

   public void setQuantidade(int quantidade) throws IllegalArgumentException {
       if(quantidade >= 0) this.quantidade = quantidade;
       else throw new IllegalArgumentException("Quantidade inválida.");
   }

   @Override
   public String toString() {
       return "\nProduto " + id +
              "\nNome: " + nome +
              "\nDescricao: " + descricao +
              "\nPreço: " + preco +
              "\nQuantidade em estoque: " + quantidade;
   }
}
