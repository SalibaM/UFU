package janelas;

import classes.Agenda;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

@SuppressWarnings("serial")
public class JanelaAgenda extends JFrame {
	
	public JTextField campoNome, campoTelefone, campoEndereco;
	public JButton botaoProcurar, botaoApagar, botaoCadastrar;
	
	public JanelaAgenda() {
		// CRIANDO A JANELA
		this.setTitle("Agenda Telefônica"); 					// nome da janela
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE); 	// programa encerra no x
		this.setSize(400, 250); 								// tamanho da janela
		this.setResizable(false); 								// tamanho fixo
		this.setLocationRelativeTo(null); 						// centraliza a janela
		
		// CRIANDO OS LABELS
		JLabel labelCabecalho = new JLabel("INSIRA OS DADOS");
		JLabel labelNome = new JLabel("Nome: ");
		JLabel labelTelefone = new JLabel("Telefone: ");
		JLabel labelEndereco = new JLabel("Endereço: ");
		
		// CRIANDO OS CAMPOS DE TEXTO
		campoNome = new JTextField(25);
		campoTelefone = new JTextField(25);
		campoEndereco = new JTextField(25);
		
		// CRIANDO OS BOTÕES E ADICIONANDO OS TRATAMENTOS
		botaoProcurar = new JButton("Procurar");
		botaoProcurar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new JanelaPesquisa();
		}});
		
		botaoApagar = new JButton("Apagar");
		botaoApagar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				new JanelaApaga();
		}});
		
		botaoCadastrar = new JButton("Cadastrar");
		botaoCadastrar.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				JOptionPane.showMessageDialog(null, 
						new String(Agenda.cadastrarContato(
								campoNome.getText(),
								campoTelefone.getText(),
								campoEndereco.getText()
				)));
				campoNome.setText("");
				campoTelefone.setText("");
				campoEndereco.setText("");
		}});
		
		// CRIANDO OS PANELS
		// panel com o cabeçalho
		JPanel panelCabecalho = new JPanel();
		panelCabecalho.add(labelCabecalho, BorderLayout.PAGE_START);		
		
		// panel para o cadastro
		JPanel panelDados = new JPanel();
		panelDados.add(labelNome);
		panelDados.add(campoNome);
		panelDados.add(labelTelefone);
		panelDados.add(campoTelefone);
		panelDados.add(labelEndereco);
		panelDados.add(campoEndereco);
		
		// panel com os botões
		JPanel panelBotoes = new JPanel();
		panelBotoes.add(botaoProcurar);
		panelBotoes.add(botaoApagar);
		panelBotoes.add(botaoCadastrar);
		
		// panel com os demais panels
		JPanel panelPrincipal = new JPanel(new BorderLayout());
		panelPrincipal.add(panelCabecalho, BorderLayout.PAGE_START);
		panelPrincipal.add(panelDados, BorderLayout.CENTER);
		panelPrincipal.add(panelBotoes, BorderLayout.PAGE_END);
		
		// CONFIGURAÇÕES FINAIS DA JANELA
		this.getContentPane().add(panelPrincipal);				// adiciona o panel principal
		this.setVisible(true);									// janela visível
	}
	
	public static void main(String[] args) {
		new JanelaAgenda();
	}
}
