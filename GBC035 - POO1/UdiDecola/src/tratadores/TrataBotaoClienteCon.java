package tratadores;

import javax.swing.JOptionPane;
import tcd.DadosCliente;
import janelas.JanelaClienteCon;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import java.awt.event.ActionEvent;

public class TrataBotaoClienteCon implements ActionListener{
    private JanelaClienteCon janelaClienteCon;
    private JButton botao1;
    private DadosCliente d1;
    private boolean test;
    
    
    public TrataBotaoClienteCon(JButton botao1, JanelaClienteCon janelaClienteCon) {
        this.botao1 = botao1;
        this.janelaClienteCon = janelaClienteCon;
        this.d1 = new DadosCliente();
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botao1) {
        	test = d1.consultarCliente(janelaClienteCon.getCpf());
        	if(test == true) {
        		JOptionPane.showMessageDialog(null, "Cliente encontrado com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
        	} else {
        		JOptionPane.showMessageDialog(null, "Cliente não encontrado.", "Falha", JOptionPane.INFORMATION_MESSAGE);
        	}
            janelaClienteCon.dispose();            
        }
    }
}