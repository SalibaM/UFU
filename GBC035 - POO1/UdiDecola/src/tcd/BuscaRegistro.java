package tcd;

public class BuscaRegistro {
	private DadosCliente aux;

	public boolean buscarClienteBanco(String cpf) {
        return aux.consultarCliente(cpf);      
    }
}