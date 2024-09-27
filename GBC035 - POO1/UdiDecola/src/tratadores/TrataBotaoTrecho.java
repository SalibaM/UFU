package tratadores;

import janelas.JanelaTrecho;
import janelas.JanelaTrechoCad;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class TrataBotaoTrecho implements ActionListener{
    private JanelaTrechoCad janelaTrechoCad;
    private JanelaTrecho janelaTrecho;
    private JButton botao1;
    private JLabel label;
    
    public TrataBotaoTrecho(JButton botao1, JanelaTrechoCad janelaTrechoCad, JanelaTrecho janelaTrecho) {
        this.botao1 = botao1;
        this.janelaTrechoCad = janelaTrechoCad;
        this.janelaTrecho = janelaTrecho;
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botao1) {
            janelaTrechoCad.setSize(450, 350);
            janelaTrechoCad.setLocationRelativeTo(null); // Centraliza a janela na tela
            janelaTrechoCad.setVisible(true);
            janelaTrecho.dispose();
        }
    }
}