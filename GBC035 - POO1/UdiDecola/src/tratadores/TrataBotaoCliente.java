package tratadores;

import janelas.JanelaCliente;
import janelas.JanelaClienteCad;
import janelas.JanelaClienteRem;
import janelas.JanelaMain;
import janelas.JanelaClienteCon;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JFrame;

import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class TrataBotaoCliente implements ActionListener {
    private JanelaClienteCad janelaClienteCad;
    private JanelaClienteCon janelaClienteCon;
    private JanelaClienteRem janelaClienteRem;
    private JanelaMain janelaMain;
    private JanelaCliente janelaCliente;
    private JButton botao1;
	

    public TrataBotaoCliente(JButton botao1, JanelaClienteCad janelaClienteCad, JanelaCliente janelaCliente) {
        this.botao1 = botao1;
        this.janelaClienteCad = janelaClienteCad;
        this.janelaCliente = janelaCliente;
    }

    public TrataBotaoCliente(JButton botao1, JanelaClienteCon janelaClienteCon, JanelaCliente janelaCliente) {
        this.botao1 = botao1;
        this.janelaClienteCon = janelaClienteCon;
        this.janelaCliente = janelaCliente;
    }

    public TrataBotaoCliente(JButton botao1, JanelaClienteRem janelaClienteRem, JanelaCliente janelaCliente) {
        this.botao1 = botao1;
        this.janelaClienteRem = janelaClienteRem;
        this.janelaCliente = janelaCliente;
    }
    
    public TrataBotaoCliente(JButton botao1, JanelaCliente janelaCliente) {
    	this.botao1 = botao1;
        this.janelaCliente = janelaCliente;
    }

    public void actionPerformed(ActionEvent e) {
        JButton botao = (JButton) e.getSource();

        if (botao.getText().equals("Cadastrar")) {
            if (janelaClienteCad != null) {
                janelaClienteCad.setSize(450, 350);
                janelaClienteCad.setLocationRelativeTo(null);
                janelaClienteCad.setVisible(true);
                janelaClienteCad.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                janelaCliente.dispose();
            }
        } else if (botao.getText().equals("Consultar")) {
            if (janelaClienteCon != null) {
                janelaClienteCon.setSize(450, 350);
                janelaClienteCon.setLocationRelativeTo(null);
                janelaClienteCon.setVisible(true);
                janelaClienteCon.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                janelaCliente.dispose();
            }
        } else if (botao.getText().equals("Remover")) {
            if (janelaClienteRem != null) {
                janelaClienteRem.setSize(450, 350);
                janelaClienteRem.setLocationRelativeTo(null);
                janelaClienteRem.setVisible(true);
                janelaClienteRem.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                janelaCliente.dispose();
            }
        } else if (botao.getText().equals("Cliente")) {
            if (janelaCliente != null) {
                janelaCliente.setSize(450, 350);
                janelaCliente.setLocationRelativeTo(null);
                janelaCliente.setVisible(true);
                janelaCliente.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
                janelaCliente.dispose();
            }
        }
    }
}
