package jdbc.main.db;

import java.sql.*;

public class DBListing {

	public static void main(String[] args) {
		new DBListing().launch();
	}

	public void launch() {
		String driver = "org.apache.derby.jdbc.EmbeddedDriver";
		DBSupermercadoConnection dbConnection = new DBSupermercadoConnection(driver);

		Connection conn = null;
		Statement stmt;
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
			// Call utility method to check if table exists.
			// Create the table if needed

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

	public boolean checkConnection(Connection conTst) throws SQLException {
		try {
			Statement s = conTst.createStatement();
			// não faz nada porque 1 != 3, mas ao menos executa o comando
			s.execute("update Produto set descricao = '1' where 1=3");
		} catch (SQLException sqle) {
			String theError = (sqle).getSQLState();
			// System.out.println(" Utils GOT: " + theError);
			/** If table exists will get - WARNING 02000: No row was found **/
			if (theError.equals("42X05")) // Table does not exist
			{
				return false;
			} else if (theError.equals("42X14") || theError.equals("42821")) {
				System.out.println("Incorrect table definition. Drop table WISH_LIST and rerun this program");
				throw sqle;
			} else {
				System.out.println("Unhandled SQLException");
				throw sqle;
			}
		}
		System.out.println("Checking Connection: ok - table exists");
		return true;
	}

	/** END getWishItem ***/

	/*** Check for WISH_LIST table ****/

}
