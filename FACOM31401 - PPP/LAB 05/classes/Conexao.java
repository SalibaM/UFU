package database;
import java.sql.*;

public class Conexao {
   private static Connection conn = null;

   public static Connection abrirConexao() {
       String url = "jdbc:derby:C:/Users/amand/IdeaProjects/lab05/ProdutosDB";
       try {
           if (conn == null || conn.isClosed()) {
               conn = DriverManager.getConnection(url);
               System.out.println("A conexão com o banco de dados foi estabelecida.");
           }
           return conn;
       } catch(SQLException e) {
           System.err.println("Erro ao abrir conexão com o banco de dados.");
           return null;
       }
   }

   public static void fecharConexao() {
       try {
           if (conn != null && !conn.isClosed()) {
               conn.close();
               System.out.println("A conexão com o banco de dados foi fechada.");
           }
       } catch(SQLException e) {
           System.err.println("Erro ao fechar conexão com o banco de dados.");
       }
   }
}
