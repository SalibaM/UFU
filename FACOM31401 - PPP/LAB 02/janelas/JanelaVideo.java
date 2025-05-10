package janelas;

import classes.MaterialBibliografico;
import classes.Video;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

// ALTERAÇÃO: criada nova classe JanelaVideo
// TODO: programação não encerra no x

@SuppressWarnings("serial")
public class JanelaVideo extends JFrame implements ActionListener {

	public JTextField campoTitulo;
	public JTextField campoAno;
	public JTextField campoAutor;
	public JTextField campoDuracao;
	
	public JButton botaoIncluir;
	public JButton botaoLivros;
	public JButton botaoRevistas;
	public JButton botaoListagem;
	
	public JanelaVideo() {
		
		this.setTitle("Vídeos");									// nome da janela
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		// encerrar o programa no x
		this.setSize(550, 250);										// tamanho da janela
		this.setResizable(false);									// tamanho fixo	
		this.setLocationRelativeTo(null); 							// centralizar a janela
		
		JLabel labelTitulo = new JLabel("Título: ");
		JLabel labelAno = new JLabel("Ano: ");
		JLabel labelAutor = new JLabel("Autor: ");
		JLabel labelDuracao = new JLabel("Duração: ");
		
		campoTitulo = new JTextField(31);
		campoAno = new JTextField(5);
		campoAutor = new JTextField(31);
		campoDuracao = new JTextField(5);
		
		// TODO: tratamento
		botaoIncluir = new JButton("Incluir");
		botaoIncluir.addActionListener(this);
		botaoLivros = new JButton("Livros");
		botaoLivros.addActionListener(this);
		botaoRevistas = new JButton("Revistas");
		botaoRevistas.addActionListener(this);
		botaoListagem = new JButton("Listagem");
		botaoListagem.addActionListener(this);
		
		JPanel panelCadastro = new JPanel();
		panelCadastro.add(labelTitulo);
		panelCadastro.add(campoTitulo);
		panelCadastro.add(labelAno);
		panelCadastro.add(campoAno);
		panelCadastro.add(labelAutor);
		panelCadastro.add(campoAutor);
		panelCadastro.add(labelDuracao);
		panelCadastro.add(campoDuracao);
		
		JPanel panelBotoes = new JPanel();
		panelBotoes.add(botaoIncluir);
		panelBotoes.add(botaoLivros);
		panelBotoes.add(botaoRevistas);
		panelBotoes.add(botaoListagem);
		
		JPanel panelPrincipal = new JPanel(new BorderLayout());
		panelPrincipal.add(panelCadastro, BorderLayout.CENTER);
		panelPrincipal.add(panelBotoes, BorderLayout.PAGE_END);
		
		this.getContentPane().add(panelPrincipal);
		this.setVisible(true);
		
	}
	
	// TODO: transformar isso em uma classe
	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == botaoIncluir) {
			try {
				MaterialBibliografico.adicionarMaterialBibliografico(
						new Video(campoTitulo.getText(),
								Integer.parseInt(campoAno.getText()),
								campoAutor.getText(),
								Integer.parseInt(campoDuracao.getText())));
				JOptionPane.showMessageDialog(null, "Vídeo incluído.");
			} catch(IllegalArgumentException error) {
				JOptionPane.showMessageDialog(null, "Não foi possível incluir este livro.");
			}
			
			campoTitulo.setText("");
			campoAno.setText("");
			campoAutor.setText("");
			campoDuracao.setText("");
			
		} else if(e.getSource() == botaoLivros) {
			this.setVisible(false);
			this.dispose();
			new JanelaLivro();
		} else if(e.getSource() == botaoRevistas) {
			this.setVisible(false);
			this.dispose();
			new JanelaRevista();
		} else if(e.getSource() == botaoListagem) {
			this.setVisible(false);
			this.dispose();
			new JanelaListagem();
		}
		
	}
}
