package tratadores;

import javax.swing.JOptionPane;
import tcd.DadosFuncHotel;
import tcd.FuncHotel;
import janelas.JanelaFuncHotelCad;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import java.awt.event.ActionEvent;

public class TrataBotaoFuncHotelCad implements ActionListener{
    private JanelaFuncHotelCad janelaFuncHotelCad;
    private JButton botaoConcluir;
    private FuncHotel h1;
    private DadosFuncHotel d1;
    
    public TrataBotaoFuncHotelCad(JButton botaoConcluir, JanelaFuncHotelCad janelaFuncHotelCad) {
        this.botaoConcluir = botaoConcluir;
        this.janelaFuncHotelCad = janelaFuncHotelCad;
        this.d1 = new DadosFuncHotel();
        
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botaoConcluir) {
        	h1 = new FuncHotel(
        			janelaFuncHotelCad.getNome(),
        			janelaFuncHotelCad.getLog(),
        			janelaFuncHotelCad.getNum(),
        			janelaFuncHotelCad.getBairro(),
        			janelaFuncHotelCad.getCid(),
        			janelaFuncHotelCad.getUf(),
        			janelaFuncHotelCad.getCep(),
        			janelaFuncHotelCad.getCpf(),
        			janelaFuncHotelCad.getDiaN(),
        			janelaFuncHotelCad.getMesN(),
        			janelaFuncHotelCad.getAnoN(),
        			janelaFuncHotelCad.getTrab(),
        			janelaFuncHotelCad.getBonusSal()
        			);
        	d1.inicializar();
        	d1.cadastrarFuncHotel(h1);
        	JOptionPane.showMessageDialog(null, "Operação concluída com sucesso", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            janelaFuncHotelCad.dispose();
        }
    }
}