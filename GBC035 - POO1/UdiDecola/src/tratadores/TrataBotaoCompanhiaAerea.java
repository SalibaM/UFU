package tratadores;

import janelas.JanelaCompanhiaAerea;
import janelas.JanelaCompanhiaAereaCad;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class TrataBotaoCompanhiaAerea implements ActionListener{
    private JanelaCompanhiaAereaCad janelaCompanhiaAereaCad;
    private JanelaCompanhiaAerea janelaCompanhiaAerea;
    private JButton botao1;
    private JLabel label;
    
    public TrataBotaoCompanhiaAerea(JButton botao1, JanelaCompanhiaAereaCad janelaCompanhiaAereaCad, JanelaCompanhiaAerea janelaCompanhiaAerea) {
        this.botao1 = botao1;
        this.janelaCompanhiaAereaCad = janelaCompanhiaAereaCad;
        this.janelaCompanhiaAerea = janelaCompanhiaAerea;
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botao1) {
            janelaCompanhiaAereaCad.setSize(450, 350);
            janelaCompanhiaAereaCad.setLocationRelativeTo(null); // Centraliza a janela na tela
            janelaCompanhiaAereaCad.setVisible(true);
            janelaCompanhiaAerea.dispose();
        }
    }
}