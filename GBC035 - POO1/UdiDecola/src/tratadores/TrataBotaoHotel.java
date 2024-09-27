package tratadores;

import janelas.JanelaHotel;
import janelas.JanelaHotelCad;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class TrataBotaoHotel implements ActionListener{
    private JanelaHotelCad janelaHotelCad;
    private JanelaHotel janelaHotel;
    private JButton botao1;
    private JLabel label;
    
    public TrataBotaoHotel(JButton botao1, JanelaHotelCad janelaHotelCad, JanelaHotel janelaHotel) {
        this.botao1 = botao1;
        this.janelaHotelCad = janelaHotelCad;
        this.janelaHotel = janelaHotel;
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botao1) {
            janelaHotelCad.setSize(450, 350);
            janelaHotelCad.setLocationRelativeTo(null); // Centraliza a janela na tela
            janelaHotelCad.setVisible(true);
            janelaHotel.dispose();
        }
    }
}