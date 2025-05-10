package janelas;

import classes.MaterialBibliografico;
import classes.Livro;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

@SuppressWarnings("serial")
public class JanelaLivro extends JFrame implements ActionListener {
	
	public JTextField campoTitulo;
	public JTextField campoAutor;
	public JTextField campoAno;
	
	public JButton botaoIncluir;
	public JButton botaoRevistas;
	public JButton botaoListagem;
		
	public JanelaLivro() {

		this.setTitle("Livros");									// nome da janela
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		// encerrar o programa no x
		this.setSize(550, 250);										// tamanho da janela
		this.setResizable(false);									// tamanho fixo	
		this.setLocationRelativeTo(null); 							// centralizar a janela
				
		JLabel labelTitulo = new JLabel("Título: ");
		JLabel labelAutor = new JLabel("Autor: ");
		JLabel labelAno = new JLabel("Ano: ");
		
		campoTitulo = new JTextField(41);
		campoAutor = new JTextField(41);
		campoAno = new JTextField(5);
		
		botaoIncluir = new JButton("Incluir");
		botaoIncluir.addActionListener(this);						// tratamento adicionado
		botaoRevistas = new JButton("Revistas");
		botaoRevistas.addActionListener(this);						// tratamento adicionado
		botaoListagem = new JButton("Listagem");
		botaoListagem.addActionListener(this);						// tratamento adicionado
		
		JPanel panelCadastro = new JPanel();						// contém os campos para o cadastro
		panelCadastro.add(labelTitulo);
		panelCadastro.add(campoTitulo);
		panelCadastro.add(labelAutor);
		panelCadastro.add(campoAutor);
		panelCadastro.add(labelAno);
		panelCadastro.add(campoAno);
		
		JPanel panelBotoes = new JPanel();							// contém os botões
		panelBotoes.add(botaoIncluir);
		panelBotoes.add(botaoRevistas);
		panelBotoes.add(botaoListagem);
		
		JPanel panelPrincipal = new JPanel(new BorderLayout());		// contém os containers criados acima
		panelPrincipal.add(panelCadastro, BorderLayout.CENTER);		// formatação da janela
		panelPrincipal.add(panelBotoes, BorderLayout.PAGE_END);		// formatação da janela
				
		// configurações finais da janela
		this.getContentPane().add(panelPrincipal);					// adicionando os containers na janela
		this.setVisible(true);										// deixando a janela visível
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == botaoIncluir) {							// botão INCLUIR:
			try {													// cadastra o livro
				MaterialBibliografico.adicionarMaterialBibliografico(
						new Livro(campoTitulo.getText(), 
								campoAutor.getText(), 
								Integer.parseInt(campoAno.getText())));
				JOptionPane.showMessageDialog(null, "Livro incluído.");
				
			} catch(IllegalArgumentException error) {
				JOptionPane.showMessageDialog(null, "Não foi possível incluir este livro.");
			}
			
			campoTitulo.setText("");
			campoAutor.setText("");
			campoAno.setText("");
			
		} else if(e.getSource() == botaoRevistas) {					// botão REVISTAS:
			this.setVisible(false); 								// esconde a janela
			this.dispose();											// destroi a janela
			new JanelaRevista();									// chama a janela de revistas
			
		} else if(e.getSource() == botaoListagem) {					// botão LISTAGEM:
			this.setVisible(false); 								// esconde a janela
			this.dispose();											// destroi a janela
			new JanelaListagem();									// chama a janela de listagem
		}
	}
	
	public static void main(String[] args) {		
		new JanelaLivro();
	}
}