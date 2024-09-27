package tratadores;

import janelas.JanelaFuncionario;
import janelas.JanelaFuncionarioCad;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class TrataBotaoFuncionario implements ActionListener{
    private JanelaFuncionarioCad janelaFuncionarioCad;
    private JanelaFuncionario janelaFuncionario;
    private JButton botao1;
    private JLabel label;
    
    public TrataBotaoFuncionario(JButton botao1, JanelaFuncionarioCad janelaFuncionarioCad, JanelaFuncionario janelaFuncionario) {
        this.botao1 = botao1;
        this.janelaFuncionarioCad = janelaFuncionarioCad;
        this.janelaFuncionario = janelaFuncionario;
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botao1) {
            janelaFuncionarioCad.setSize(450, 350);
            janelaFuncionarioCad.setLocationRelativeTo(null); // Centraliza a janela na tela
            janelaFuncionarioCad.setVisible(true);
            janelaFuncionario.dispose();
        }
    }
}