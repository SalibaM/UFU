package tratadores;

import javax.swing.JOptionPane;
import tcd.DadosVoo;
import tcd.Voos;
import janelas.JanelaVooCad;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import java.awt.event.ActionEvent;

public class TrataBotaoVooCad implements ActionListener{
    private JanelaVooCad janelaVooCad;
    private JButton botaoConcluir;
    private Voos v1;
    private DadosVoo d1;
    
    public TrataBotaoVooCad(JButton botaoConcluir, JanelaVooCad janelaVooCad) {
        this.botaoConcluir = botaoConcluir;
        this.janelaVooCad = janelaVooCad;
        this.d1 = new DadosVoo();
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botaoConcluir) {
        	v1 = new Voos(
        			janelaVooCad.getDiaVoo(),
                	janelaVooCad.getMesVoo(),
                	janelaVooCad.getAnoVoo(),
                	janelaVooCad.getHoraSaida(),
                	janelaVooCad.getMinSaida(),
                	0,
                	janelaVooCad.getHoraChegada(),
                	janelaVooCad.getMinChegada(),
                	0,
                	janelaVooCad.getVagas(),
                	janelaVooCad.getPreco()
        			);
        	d1.inicializar();
        	d1.cadastrarVoos(v1);
        	JOptionPane.showMessageDialog(null, "Operação concluída com sucesso", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            janelaVooCad.dispose();
        }
    }
}