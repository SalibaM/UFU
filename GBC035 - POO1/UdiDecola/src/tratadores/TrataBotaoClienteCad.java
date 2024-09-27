package tratadores;

import javax.swing.JOptionPane;
import tcd.InsereRegistro;
import tcd.DadosCliente;
import janelas.JanelaClienteCad;
import tcd.Cliente;
import java.awt.event.ActionListener;
import javax.swing.JButton;
import java.awt.event.ActionEvent;
import java.time.LocalDate;

public class TrataBotaoClienteCad implements ActionListener {
	private JanelaClienteCad janelaClienteCad;
	private JButton botaoConcluir;
	private Cliente c1;
	private DadosCliente d1;
	LocalDate hoje = LocalDate.now(); // Usado para data do cadastro em construtor

	public TrataBotaoClienteCad(JButton botaoConcluir, JanelaClienteCad janelaClienteCad) {
		this.botaoConcluir = botaoConcluir;
		this.janelaClienteCad = janelaClienteCad;
		this.d1 = new DadosCliente();
	}

	public void actionPerformed(ActionEvent e) {
		if (e.getSource() == botaoConcluir) {
			c1 = new Cliente(
					janelaClienteCad.getNome(), 
					janelaClienteCad.getLog(), 
					janelaClienteCad.getNum(),
					janelaClienteCad.getBairro(), 
					janelaClienteCad.getCid(), 
					janelaClienteCad.getUf(),
					janelaClienteCad.getCep(), 
					janelaClienteCad.getCpf(), 
					janelaClienteCad.getDiaN(),
					janelaClienteCad.getMesN(), 
					janelaClienteCad.getAnoN(), 
					hoje.getDayOfMonth(), 
					hoje.getMonthValue(),
					hoje.getYear(),
					janelaClienteCad.getEmail(), 0);
			d1.inicializar();
			d1.cadastrarCliente(c1);
			InsereRegistro.inserirClienteBanco(
					janelaClienteCad.getNome(), 
					janelaClienteCad.getLog(), 
					janelaClienteCad.getNum(),
					janelaClienteCad.getBairro(), 
					janelaClienteCad.getCid(), 
					janelaClienteCad.getUf(),
					janelaClienteCad.getCep(), 
					janelaClienteCad.getCpf(), 
					janelaClienteCad.getDiaN(),
					janelaClienteCad.getMesN(), 
					janelaClienteCad.getAnoN(), 
					hoje.getDayOfMonth(), 
					hoje.getMonthValue(),
					hoje.getYear(), 
					janelaClienteCad.getEmail(), 0);
			JOptionPane.showMessageDialog(null, "Operação concluída com sucesso", "Sucesso", JOptionPane.INFORMATION_MESSAGE);

			janelaClienteCad.dispose();
		}
	}
}
