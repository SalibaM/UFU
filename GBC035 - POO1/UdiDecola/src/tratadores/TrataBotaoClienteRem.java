package tratadores;

import javax.swing.JOptionPane;
import janelas.JanelaClienteRem;
import tcd.DadosCliente;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import java.awt.event.ActionEvent;

public class TrataBotaoClienteRem implements ActionListener{
    private JanelaClienteRem janelaClienteRem;
    private JButton botao1;
    private DadosCliente d1;
    private boolean test;
    
    public TrataBotaoClienteRem(JButton botao1, JanelaClienteRem janelaClienteRem) {
        this.botao1 = botao1;
        this.janelaClienteRem = janelaClienteRem;
        this.d1 = new DadosCliente();
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botao1) {
        	test = d1.removerCliente(janelaClienteRem.getCpf());
            if(test == true) {
                JOptionPane.showMessageDialog(null, "Cliente removido com sucesso!", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            } else {
                JOptionPane.showMessageDialog(null, "Cliente não encontrado ou falha na remoção.", "Falha", JOptionPane.INFORMATION_MESSAGE);
            }
            janelaClienteRem.dispose();
        }
    }
}