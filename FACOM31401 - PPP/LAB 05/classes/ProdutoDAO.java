package database;
import classes.Produto;
import java.sql.*;
import java.util.*;

public class ProdutoDAO {
   private Connection connection;

   public ProdutoDAO(Connection connection) {
       this.connection = connection;
   }

   public int inserirProduto(Produto produto) throws SQLException {
       String sql = "INSERT INTO produtos (nome, descricao, preco, estoque) VALUES (?, ?, ?, ?)";

       try(PreparedStatement stmt = connection.prepareStatement(sql, Statement.RETURN_GENERATED_KEYS)) {
           stmt.setString(1, produto.getNome());
           stmt.setString(2, produto.getDescricao());
           stmt.setDouble(3, produto.getPreco());
           stmt.setInt(4, produto.getQuantidade());
           int linhasAfetadas = stmt.executeUpdate();
           if(linhasAfetadas > 0) {
               try(ResultSet generatedKeys = stmt.getGeneratedKeys()) {
                   if(generatedKeys.next())
                       return generatedKeys.getInt(1);
               }
           }
           return -1;

       } catch (SQLException e) {
           throw e;
       }
   }

   public int removerProduto(int id) throws SQLException {
       String sql = "DELETE FROM produtos WHERE id = ?";
       PreparedStatement stmt = null;

       try {
           stmt = connection.prepareStatement(sql);
           stmt.setInt(1, id);
           return stmt.executeUpdate();

       } catch(SQLException e) {
           throw e;
       }
   }

   public boolean atualizarProduto(Produto produto) throws SQLException {
       String sql = "UPDATE produtos SET nome = ?, descricao = ?, preco = ?, estoque = ? WHERE id = ?";
       PreparedStatement stmt = null;

       try {
           stmt = connection.prepareStatement(sql);
           stmt.setString(1, produto.getNome());
           stmt.setString(2, produto.getDescricao());
           stmt.setDouble(3, produto.getPreco());
           stmt.setInt(4, produto.getQuantidade());
           stmt.setInt(5, produto.getId());

           int linhasAfetadas = stmt.executeUpdate();
           return linhasAfetadas > 0;

       } catch (SQLException e) {
           throw e;
       }
   }
  
   public boolean diminuirEstoque(int id, int quantidade) throws SQLException {
       String sql = "UPDATE produtos SET estoque = CASE WHEN estoque >= ? THEN estoque - ? ELSE estoque END WHERE id = ?";

       try (PreparedStatement stmt = connection.prepareStatement(sql)) {
           stmt.setInt(1, quantidade);
           stmt.setInt(2, quantidade);
           stmt.setInt(3, id);

           int linhasAfetadas = stmt.executeUpdate();
           return linhasAfetadas > 0;
       } catch (SQLException e) {
           throw e;
       }
   }

   public boolean aumentarEstoque(int id, int quantidade) throws SQLException {
       String sql = "UPDATE produtos SET estoque = estoque + ? WHERE id = ?";
       PreparedStatement stmt = null;

       try {
           stmt = connection.prepareStatement(sql);
           stmt.setInt(1, quantidade);
           stmt.setInt(2, id);
           int linhasAfetadas = stmt.executeUpdate();
           return linhasAfetadas > 0;

       } catch (SQLException e) {
           throw e;
       }
   }

   public List<Produto> selecionarProdutos() throws SQLException {
       List<Produto> produtos = new ArrayList<>();
       String sql = "SELECT * FROM produtos";

       try (Statement stmt = connection.createStatement();
            ResultSet rs = stmt.executeQuery(sql)) {

           while (rs.next()) {
               Produto produto = new Produto(
                       rs.getInt("id"),
                       rs.getString("nome"),
                       rs.getString("descricao"),
                       rs.getDouble("preco"),
                       rs.getInt("estoque")
               );
               produtos.add(produto);
           }
       } catch(SQLException e) {
           return null;
       }
       return produtos;
   }
}
