package tratadores;

import javax.swing.JOptionPane;
import tcd.DadosTrecho;
import tcd.Trechos;
import janelas.JanelaTrechoCad;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import java.awt.event.ActionEvent;

public class TrataBotaoTrechoCad implements ActionListener{
    private JanelaTrechoCad janelaTrechoCad;
    private JButton botaoConcluir;
    private Trechos t1;
    private DadosTrecho d1;
    
    public TrataBotaoTrechoCad(JButton botaoConcluir, JanelaTrechoCad janelaTrechoCad) {
        this.botaoConcluir = botaoConcluir;
        this.janelaTrechoCad = janelaTrechoCad;
        this.d1 = new DadosTrecho(); // Inicialize DadosTrecho
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botaoConcluir) {
        	t1 = new Trechos(
        			janelaTrechoCad.getCod(),
        			janelaTrechoCad.getOrigem(),
        			janelaTrechoCad.getDestino(),
        			janelaTrechoCad.getHoraSaida(),
        			janelaTrechoCad.getMinSaida(),
        			0,
        			janelaTrechoCad.getHoraChegada(),
        			janelaTrechoCad.getMinChegada(),
        			0,
        			janelaTrechoCad.getComp()
        			);
        	d1.inicializar();
        	d1.cadastrarTrecho(t1);
        	JOptionPane.showMessageDialog(null, "Operação concluída com sucesso", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            janelaTrechoCad.dispose();
        }
    }
}