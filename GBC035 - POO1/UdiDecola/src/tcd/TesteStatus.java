package tcd;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

public class TesteStatus {

    public static void main(String[] args) {
        Connection connection = null;
        PreparedStatement preparedStatement = null;

        try {
            // Carregar o driver JDBC
            Class.forName("org.postgresql.Driver");

            // Estabelecer conexão com o banco de dados
            String url = "jdbc:postgresql://localhost:5432/postgres";
            String usuario = "postgres";
            String senhaBanco = "facom";
            connection = DriverManager.getConnection(url, usuario, senhaBanco);

            // Verificar status da conexão
            if (connection != null && !connection.isClosed()) {
                System.out.println("Conexão estabelecida com sucesso!");
            }

            // Se necessário, realizar operações com o banco de dados aqui

        } catch (ClassNotFoundException e) {
            System.err.println("Driver JDBC não encontrado: " + e.getMessage());
        } catch (SQLException e) {
            System.err.println("Erro ao conectar ao banco de dados: " + e.getMessage());
        } finally {
            // Fechar conexão
            try {
                if (preparedStatement != null) {
                    preparedStatement.close();
                }
                if (connection != null) {
                    connection.close();
                }
            } catch (SQLException e) {
                System.err.println("Erro ao fechar conexão: " + e.getMessage());
            }
        }
    }
}