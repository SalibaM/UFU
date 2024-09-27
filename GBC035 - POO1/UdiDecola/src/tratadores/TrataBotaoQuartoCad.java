package tratadores;

import javax.swing.JOptionPane;
import tcd.DadosQuarto;
import tcd.Quarto;
import janelas.JanelaQuartoCad;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import java.awt.event.ActionEvent;

public class TrataBotaoQuartoCad implements ActionListener{
    private JanelaQuartoCad janelaQuartoCad;
    private JButton botaoConcluir;
    private Quarto q1;
    private DadosQuarto d1;
    
    public TrataBotaoQuartoCad(JButton botaoConcluir, JanelaQuartoCad janelaQuartoCad) {
        this.botaoConcluir = botaoConcluir;
        this.janelaQuartoCad = janelaQuartoCad;
        this.d1 = new DadosQuarto();
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botaoConcluir) {
        	q1 = new Quarto(
        			janelaQuartoCad.getDiariaSemDes(),
        			janelaQuartoCad.getDes(),
        			janelaQuartoCad.getQnt(),
        			janelaQuartoCad.getTipo()
        			);
        	d1.inicializar();
        	d1.cadastrarQuarto(q1);
        	JOptionPane.showMessageDialog(null, "Operação concluída com sucesso", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            janelaQuartoCad.dispose();
        }
    }
}