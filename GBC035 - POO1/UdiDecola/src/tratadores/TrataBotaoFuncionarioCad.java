package tratadores;

import javax.swing.JOptionPane;
import tcd.DadosFuncionario;
import tcd.Funcionario;
import janelas.JanelaFuncionarioCad;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import javax.swing.JLabel;

public class TrataBotaoFuncionarioCad implements ActionListener{
    private JanelaFuncionarioCad janelaFuncionarioCad;
    private JButton botaoConcluir;
    private Funcionario f1;
    private DadosFuncionario d1;
    
    public TrataBotaoFuncionarioCad(JButton botaoConcluir, JanelaFuncionarioCad janelaFuncionarioCad) {
        this.botaoConcluir = botaoConcluir;
        this.janelaFuncionarioCad = janelaFuncionarioCad;
        this.d1 = new DadosFuncionario();
    }
    
    public void actionPerformed(ActionEvent e) {
        if (e.getSource() == botaoConcluir) {
        	f1 = new Funcionario(
        			janelaFuncionarioCad.getNome(),
        			janelaFuncionarioCad.getLog(),
        			janelaFuncionarioCad.getNum(),
        			janelaFuncionarioCad.getBairro(),
        			janelaFuncionarioCad.getCid(),
        			janelaFuncionarioCad.getUf(),
        			janelaFuncionarioCad.getCep(),
        			janelaFuncionarioCad.getCpf(),
        			janelaFuncionarioCad.getDiaN(),
        			janelaFuncionarioCad.getMesN(),
        			janelaFuncionarioCad.getAnoN(),
        			janelaFuncionarioCad.getTrab()
        			);
        	d1.inicializar();
        	d1.cadastrarFuncionario(f1);
        	JOptionPane.showMessageDialog(null, "Operação concluída com sucesso", "Sucesso", JOptionPane.INFORMATION_MESSAGE);
            janelaFuncionarioCad.dispose();
        }
    }
}