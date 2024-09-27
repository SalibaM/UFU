package tratadores;

import javax.swing.JOptionPane;
import tcd.DadosHotel;
import tcd.Hotel;
import janelas.JanelaHotelCad;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class TrataBotaoHotelCad implements ActionListener{
    private JanelaHotelCad janelaHotelCad;
    private JButton botaoConcluir;
    private JLabel label;
    private Hotel h1;
    private DadosHotel d1;
    
    public TrataBotaoHotelCad(JButton botaoConcluir, JanelaHotelCad janelaHotelCad) {
        this.botaoConcluir = botaoConcluir;
        this.janelaHotelCad = janelaHotelCad;
        this.d1 = new DadosHotel();
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botaoConcluir) {
        	h1 = new Hotel(
        			janelaHotelCad.getCnpj(),
        			janelaHotelCad.getNomeOf(),
        			janelaHotelCad.getNomeDiv(),
        			janelaHotelCad.getLog(),
        			janelaHotelCad.getDiaC(),
        			janelaHotelCad.getMesC(),
        			janelaHotelCad.getAnoC(),
        			janelaHotelCad.getNum(),
        			janelaHotelCad.getBairro(),
        			janelaHotelCad.getCid(),
        			janelaHotelCad.getUf(),
        			janelaHotelCad.getCep(),
        			janelaHotelCad.getEst(),
        			janelaHotelCad.getPet(),
        			janelaHotelCad.getQuarto(),
        			janelaHotelCad.getDiv(),
        			janelaHotelCad.getDesc(),
        			janelaHotelCad.getHoraCheckIn(),
        			janelaHotelCad.getMinCheckIn(),
        			0,
        			janelaHotelCad.getHoraCheckOut(),
        			janelaHotelCad.getMinCheckOut(),
        			0
        			);
        	d1.inicializar();
        	d1.cadastrarHotel(h1);
        	JOptionPane.showMessageDialog(null, "Operação concluída com sucesso", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            janelaHotelCad.dispose();
        }
    }
}