package tratadores;

import janelas.JanelaQuarto;
import janelas.JanelaQuartoCad;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class TrataBotaoQuarto implements ActionListener{
    private JanelaQuartoCad janelaQuartoCad;
    private JanelaQuarto janelaQuarto;
    private JButton botao1;
    private JLabel label;
    
    public TrataBotaoQuarto(JButton botao1, JanelaQuartoCad janelaQuartoCad, JanelaQuarto janelaQuarto) {
        this.botao1 = botao1;
        this.janelaQuartoCad = janelaQuartoCad;
        this.janelaQuarto = janelaQuarto;
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botao1) {
            janelaQuartoCad.setSize(450, 350);
            janelaQuartoCad.setLocationRelativeTo(null); // Centraliza a janela na tela
            janelaQuartoCad.setVisible(true);
            janelaQuarto.dispose();
        }
    }
}