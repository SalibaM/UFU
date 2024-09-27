package tratadores;

import janelas.JanelaFuncHotel;
import janelas.JanelaFuncHotelCad;
import java.awt.event.ActionListener;
import javax.swing.JFrame;
import java.awt.FlowLayout;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class TrataBotaoFuncHotel implements ActionListener{
    private JanelaFuncHotelCad janelaFuncHotelCad;
    private JanelaFuncHotel janelaFuncHotel;
    private JButton botao1;
    private JLabel label;
    
    public TrataBotaoFuncHotel(JButton botao1, JanelaFuncHotelCad janelaFuncHotelCad, JanelaFuncHotel janelaFuncHotel) {
        this.botao1 = botao1;
        this.janelaFuncHotelCad = janelaFuncHotelCad;
        this.janelaFuncHotel = janelaFuncHotel;
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botao1) {
            janelaFuncHotelCad.setSize(450, 350);
            janelaFuncHotelCad.setLocationRelativeTo(null); // Centraliza a janela na tela
            janelaFuncHotelCad.setVisible(true);
            janelaFuncHotel.dispose();
        }
    }
}