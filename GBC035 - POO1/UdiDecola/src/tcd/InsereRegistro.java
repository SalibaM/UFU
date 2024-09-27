package tcd;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;

public class InsereRegistro {
    public static void inserirClienteBanco(String nome, String endLogradouro, int endNumero, String endBairro, String endCidade, String endUf,
            String endCep, String cpf, int diaNasc, int mesNasc, int anoNasc, int diaCad, int mesCad, int anoCad,
            String email, int numCompras) {
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

            // Query SQL para inserção de dados
            String query = "INSERT INTO cliente (nome, endLogradouro, endNumero, endBairro, endCidade, endUf, endCep, cpf, diaNasc, mesNasc, anoNasc, diaCad, mesCad, anoCad, email, numCompras) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?)";

            // Preparar a declaração SQL
            preparedStatement = connection.prepareStatement(query);

            // Substituir os parâmetros na consulta SQL pelos valores passados como argumentos            
            preparedStatement.setString(1, nome);
            preparedStatement.setString(2, endLogradouro);
            preparedStatement.setInt(3, endNumero);
            preparedStatement.setString(4, endBairro);
            preparedStatement.setString(5, endCidade);
            preparedStatement.setString(6, endUf);
            preparedStatement.setString(7, endCep);
            preparedStatement.setString(8, cpf);
            preparedStatement.setInt(9, diaNasc);
            preparedStatement.setInt(10, mesNasc);
            preparedStatement.setInt(11, anoNasc);
            preparedStatement.setInt(12, diaCad);
            preparedStatement.setInt(13, mesCad);
            preparedStatement.setInt(14, anoCad);
            preparedStatement.setString(15, email);
            preparedStatement.setInt(16,  numCompras);
            // Executar a declaração SQL para inserir os dados
            int linhasAfetadas = preparedStatement.executeUpdate();

            // Verificar se a inserção foi bem-sucedida
            if (linhasAfetadas > 0) {
                System.out.println("Dados inseridos com sucesso!");
            } else {
                System.out.println("Nenhum dado foi inserido.");
            }
        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            // Fechar recursos
            try {
                if (preparedStatement != null) preparedStatement.close();
                if (connection != null) connection.close();
            } catch (Exception e) {
                e.printStackTrace();
            }
        }
    }
}