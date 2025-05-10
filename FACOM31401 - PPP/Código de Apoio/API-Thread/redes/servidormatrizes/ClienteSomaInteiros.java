package servidormatrizes;
import java.io.IOException;
import java.net.Socket;
import java.net.InetAddress;
import java.io.DataInputStream;
import java.io.DataOutputStream;

public class ClienteSomaInteiros {
    Socket conexao;
    DataInputStream input;
    DataOutputStream output;
	
	
	public static void main (String args[]) {
	   new ClienteSomaInteiros();
   }
   
   public ClienteSomaInteiros () {
	   try {
		   Socket conexao = new Socket(InetAddress.getByName("127.0.0.1"), 12345); 
		   input = new DataInputStream(conexao.getInputStream());
		   output = new DataOutputStream(conexao.getOutputStream());
System.out.println("Esperando 2s!");		   
Thread.sleep(5000);
		   output.writeInt(1);
System.out.println("Mandei 1 para o Servidor");		   
System.out.println("Esperando 2s!");		   
		   Thread.sleep(5000);		   
		   //output.writeInt(1);
		   System.out.println("Mandei 1 para o Servidor");
		   
		   System.out.println("1+1="+input.readInt());
		   
		   output.close();
		   input.close();
		   conexao.close();
	   }
	   catch (Exception e) {
		   
	   }
   }
}
