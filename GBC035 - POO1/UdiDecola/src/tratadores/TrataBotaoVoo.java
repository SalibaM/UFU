package tratadores;

import janelas.JanelaVoo;
import janelas.JanelaVooCad;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class TrataBotaoVoo implements ActionListener{
    private JanelaVooCad janelaVooCad;
    private JanelaVoo janelaVoo;
    private JButton botao1;
    private JLabel label;
    
    public TrataBotaoVoo(JButton botao1, JanelaVooCad janelaVooCad, JanelaVoo janelaVoo) {
        this.botao1 = botao1;
        this.janelaVooCad = janelaVooCad;
        this.janelaVoo = janelaVoo;
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botao1) {
            janelaVoo.setSize(450, 350);
            janelaVoo.setLocationRelativeTo(null); // Centraliza a janela na tela
            janelaVoo.setVisible(true);
            janelaVoo.dispose();
        }
    }
}