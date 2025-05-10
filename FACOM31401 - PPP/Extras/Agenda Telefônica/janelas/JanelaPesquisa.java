package janelas;

import classes.Contato;
import classes.Agenda;

import javax.swing.*;
import java.awt.event.*;

@SuppressWarnings("serial")
public class JanelaPesquisa extends JFrame {

	JTextField campoTelefone;
	JButton botaoPesquisar;
	
	public JanelaPesquisa() {
		// CRIANDO A JANELA
		this.setTitle("Pesquisar Contato");				// nome da janela
		this.setSize(300, 100);							// tamanho da janela
		this.setResizable(false);						// tamanho fixo
		this.setLocationRelativeTo(null);				// janela centralizada
		
		// CRIANDO OS COMPONENTES
		JLabel labelTelefone = new JLabel("Telefone: ");
		campoTelefone = new JTextField(12);
		botaoPesquisar = new JButton("Pesquisar");
		
		// ADICIONANDO TRATAMENTO DO BOTÃO
		botaoPesquisar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				Contato contato = Agenda.procurarContato(campoTelefone.getText());
				if(contato == null) {
					JOptionPane.showMessageDialog(null, "Contato não encontrado.");
				} else {
					JOptionPane.showMessageDialog(null, contato.toString());
				}
		}});

		// CRIANDO O PANEL
		JPanel panel = new JPanel();
		panel.add(labelTelefone);
		panel.add(campoTelefone);
		panel.add(botaoPesquisar);

		// CONFIGURAÇÕES FINAIS DA JANELA
		this.getContentPane().add(panel);				// panel adicionado
		this.setVisible(true);							// janela visível
	}
}
