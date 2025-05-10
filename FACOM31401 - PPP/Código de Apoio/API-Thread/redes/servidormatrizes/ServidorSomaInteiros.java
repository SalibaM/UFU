package servidormatrizes;

import java.io.IOException;
import java.net.ServerSocket;
import java.net.Socket;
import java.net.InetAddress;
import java.io.DataInputStream;
import java.io.DataOutputStream;

public class ServidorSomaInteiros {
    ServerSocket servidor;
	Socket conexao;
    DataInputStream input;
    DataOutputStream output;
	
	
	public static void main (String args[]) {
	   new ServidorSomaInteiros();
   }
   
   public ServidorSomaInteiros () {
	   try {
		   ServerSocket servidor = new ServerSocket(12345,10);
		   System.out.println("Aguardando conexao...");
		   Socket conexao = servidor.accept(); 
		   System.out.println("Recebi conexao de "+conexao.getInetAddress().toString());
		   input = new DataInputStream(conexao.getInputStream());
		   output = new DataOutputStream(conexao.getOutputStream());
System.out.println("Esperando Inteiro!!");		   
		   int x1 = input.readInt();
System.out.println("Esperando Inteiro!!");		   
		   int x2 = input.readInt();
//System.out.println("Esperando 2s!");		   
//Thread.sleep(2000);
		   output.writeInt(x1+x2);
		   System.out.println("Mandei " + (x1+x2) + "!");
		   output.close();
		   input.close();
		   conexao.close();
		   servidor.close();
	   }
	   catch (Exception e) {
		   e.printStackTrace();
	   }
   }
}
