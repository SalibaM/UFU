package janelas;

import classes.Contato;
import classes.Agenda;

import javax.swing.*;
import java.awt.event.*;

@SuppressWarnings("serial")
public class JanelaApaga extends JFrame {

	JTextField campoTelefone;
	JButton botaoApagar;
	
	public JanelaApaga() {
		// CRIANDO A JANELA
		this.setTitle("Apagar Contato");				// nome da janela
		this.setSize(300, 100);							// tamanho da janela
		this.setResizable(false);						// tamanho fixo
		this.setLocationRelativeTo(null);				// janela centralizada
		
		// CRIANDO OS COMPONENTES
		JLabel labelTelefone = new JLabel("Telefone: ");
		campoTelefone = new JTextField(12);
		botaoApagar = new JButton("Pesquisar");
		
		// ADICIONANDO TRATAMENTO DO BOTÃO
		botaoApagar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Contato contato = Agenda.apagarContato(campoTelefone.getText());
				if(contato == null) {
					JOptionPane.showMessageDialog(null, "Contato não encontrado.");
				} else {
					JOptionPane.showMessageDialog(null, "Contato excluído.");
				}
		}});

		// CRIANDO O PANEL
		JPanel panel = new JPanel();
		panel.add(labelTelefone);
		panel.add(campoTelefone);
		panel.add(botaoApagar);

		// CONFIGURAÇÕES FINAIS DA JANELA
		this.getContentPane().add(panel);				// panel adicionado
		this.setVisible(true);							// janela visível
	}
}
