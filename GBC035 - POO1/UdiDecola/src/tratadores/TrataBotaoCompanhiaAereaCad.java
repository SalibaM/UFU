package tratadores;

import javax.swing.JOptionPane;
import tcd.DadosCompanhiaAerea;
import tcd.CompanhiaAerea;
import janelas.JanelaCompanhiaAereaCad;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class TrataBotaoCompanhiaAereaCad implements ActionListener{
    private JanelaCompanhiaAereaCad janelaCompanhiaAereaCad;
    private JButton botaoConcluir;
    private DadosCompanhiaAerea d1;
    private JLabel label;
    private CompanhiaAerea comp1;
    
    public TrataBotaoCompanhiaAereaCad(JButton botaoConcluir, JanelaCompanhiaAereaCad janelaCompanhiaAereaCad) {
        this.botaoConcluir = botaoConcluir;
        this.janelaCompanhiaAereaCad = janelaCompanhiaAereaCad;
        this.d1 = new DadosCompanhiaAerea();
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botaoConcluir) {
        	comp1 = new CompanhiaAerea(
        			janelaCompanhiaAereaCad.getCnpj(),
        			janelaCompanhiaAereaCad.getNomeOf(),
        			janelaCompanhiaAereaCad.getNomeDiv(),
        			janelaCompanhiaAereaCad.getLog(),
        			janelaCompanhiaAereaCad.getDiaC(),
        			janelaCompanhiaAereaCad.getMesC(),
        			janelaCompanhiaAereaCad.getAnoC(),
        			janelaCompanhiaAereaCad.getNum(),
        			janelaCompanhiaAereaCad.getBairro(),
        			janelaCompanhiaAereaCad.getCid(),
        			janelaCompanhiaAereaCad.getUf(),
        			janelaCompanhiaAereaCad.getCep()
        			);
        	d1.inicializar();
			d1.cadastrarCompanhiaAerea(comp1);
			JOptionPane.showMessageDialog(null, "Operação concluída com sucesso", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            janelaCompanhiaAereaCad.dispose();
        }
    }
}