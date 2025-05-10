package jdbc.main.db;

import java.sql.*;


public class DBPopulation {

	public static void main(String[] args) {
		new DBPopulation().launch();
	}

	public void launch() {
		String driver = "org.apache.derby.jdbc.EmbeddedDriver";
		DBSupermercadoConnection dbConnection = new DBSupermercadoConnection(driver);

		Connection conn = null;
		Statement stmt;
		PreparedStatement psInsert;
		ResultSet produtos;

		String printLine = "  __________________________________________________";


		// JDBC code sections
		// Beginning of Primary DB access section
		// ## BOOT DATABASE SECTION ##
		try {
			conn = dbConnection.getSupermercadoConnection();
			if (conn == null)
				return;

			// ## INITIAL SQL SECTION ##
			// Create a statement to issue simple commands.
			stmt = conn.createStatement();

			// Prepare the insert statement to use
			psInsert = conn.prepareStatement("insert into "
					+ "Produto(codigo, descricao, precoBrutoVendaUnitario, estoque) " + "values (?, ?, ?, ?)");

			// Insert the text entered into the WISH_ITEM table

			psInsert.setInt(1, 1);
			psInsert.setString(2, "Chinelo de Dedo");
			psInsert.setDouble(3, 25.0);
			psInsert.setDouble(4, 10);

			psInsert.executeUpdate();

			psInsert.setInt(1, 2);
			psInsert.setString(2, "Pantufa");
			psInsert.setDouble(3, 30.0);
			psInsert.setDouble(4, 5);

			psInsert.executeUpdate();

			// Seleciona todas as linhas em produtos
			produtos = stmt.executeQuery(
					"select codigo, descricao, precoBrutoVendaUnitario, estoque from Produto order by descricao");

			// Loop through the ResultSet and print the data
			System.out.println(printLine);
			while (produtos.next()) {
				System.out.println("Cod: " + produtos.getInt(1) + ", Desc: " + produtos.getString(2) + ", Preco: "
						+ produtos.getDouble(3) + ", Estoque: " + produtos.getDouble(4));
			}
			System.out.println(printLine);
			// Close the resultSet
			produtos.close();

			// Release the resources (clean up )
			psInsert.close();
			stmt.close();
			conn.close();
			System.out.println("Closed connection");

			// ## DATABASE SHUTDOWN SECTION ##
			/***
			 * In embedded mode, an application should shut down Derby. Shutdown throws the
			 * XJ015 exception to confirm success.
			 ***/
			if (driver.equals("org.apache.derby.jdbc.EmbeddedDriver")) {
				boolean gotSQLExc = false;
				try {
					DriverManager.getConnection("jdbc:derby:;shutdown=true");
				} catch (SQLException se) {
					if (se.getSQLState().equals("XJ015")) {
						gotSQLExc = true;
					}
				}
				if (!gotSQLExc) {
					System.out.println("Database did not shut down normally");
				} else {
					System.out.println("Database shut down normally");
				}
			}

			// Beginning of the primary catch block: prints stack trace
		} catch (Throwable e) {
			/*
			 * Catch all exceptions and pass them to the Throwable.printStackTrace method
			 */
			System.out.println(" . . . exception thrown:");
			e.printStackTrace(System.out);
		}
	}

	/*** Check for WISH_LIST table ****/

}
