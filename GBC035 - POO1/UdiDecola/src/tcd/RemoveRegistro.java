package tcd;

public class RemoveRegistro {
	private DadosCliente aux;
	
    public boolean removerClienteBanco(String cpf) {
    	if (aux.consultarCliente(cpf)) {
    		aux.removerCliente(cpf);
    		return true;
    	} else return false;
    }
}