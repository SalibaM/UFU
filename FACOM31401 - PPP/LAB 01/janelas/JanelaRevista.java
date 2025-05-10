package janelas;

import classes.MaterialBibliografico;
import classes.Revista;

import javax.swing.*;
import java.awt.event.*;
import java.awt.*;

@SuppressWarnings("serial")
public class JanelaRevista extends JFrame implements ActionListener {
	
	public JTextField campoTitulo;
	public JTextField campoOrganizacao;
	public JTextField campoVolume;
	public JTextField campoNumero;
	public JTextField campoAno;
	
	public JButton botaoIncluir;
	public JButton botaoLivros;
	public JButton botaoListagem;
		
	public JanelaRevista() {

		this.setTitle("Revistas");									// nome da janela
		this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE); 		// x não fecha a janela		
		this.setSize(550, 250);										// tamanho da janela
		this.setResizable(false);									// tamanho fixo		
		this.setLocationRelativeTo(null); 							// centralizar a janela
				
		JLabel labelTitulo = new JLabel("Título: ");
		JLabel labelOrganizacao = new JLabel("Org.: ");
		JLabel labelVolume = new JLabel("Vol.: ");
		JLabel labelNumero = new JLabel("Nro.: ");
		JLabel labelAno = new JLabel("Ano: ");
		
		campoTitulo = new JTextField(42);
		campoOrganizacao = new JTextField(42);
		campoVolume = new JTextField(5);
		campoNumero = new JTextField(5);
		campoAno = new JTextField(5);
		
		botaoIncluir = new JButton("Incluir");
		botaoIncluir.addActionListener(this);						// tratamento adicionado
		botaoLivros = new JButton("Livros");
		botaoLivros.addActionListener(this);						// tratamento adicionado
		botaoListagem = new JButton("Listagem");
		botaoListagem.addActionListener(this);						// tratamento adicionado
		
		JPanel panelCadastro = new JPanel();						// contém os campos para o cadastro
		panelCadastro.add(labelTitulo);
		panelCadastro.add(campoTitulo);
		panelCadastro.add(labelOrganizacao);
		panelCadastro.add(campoOrganizacao);
		panelCadastro.add(labelVolume);
		panelCadastro.add(campoVolume);
		panelCadastro.add(labelNumero);
		panelCadastro.add(campoNumero);
		panelCadastro.add(labelAno);
		panelCadastro.add(campoAno);
		
		JPanel panelBotoes = new JPanel();							// contém os botões 
		panelBotoes.add(botaoIncluir);
		panelBotoes.add(botaoLivros);
		panelBotoes.add(botaoListagem);
		
		JPanel panelPrincipal = new JPanel(new BorderLayout());		// contém os containers criados acima
		panelPrincipal.add(panelCadastro, BorderLayout.CENTER);		// formatação do layout
		panelPrincipal.add(panelBotoes, BorderLayout.PAGE_END);		// formatação do layout
			
		this.addWindowListener(new WindowAdapter() {				// tratando o defaultCloseOperation
			@Override
		    public void windowClosing(WindowEvent e) {
				setVisible(false);									// deixa a janela invisível	
				dispose();											// destrói a janela
				new JanelaLivro();									// chama a janela de livros
		}});
		
		this.getContentPane().add(panelPrincipal);					// adicionando os containers na janela
		this.setVisible(true);										// deixando a janela visível
	}

	@Override
	public void actionPerformed(ActionEvent e) {
		if(e.getSource() == botaoIncluir) {							// botão INCLUIR:
			try {													// cadastra a revista
				MaterialBibliografico.adicionarMaterialBibliografico(
						new Revista(campoTitulo.getText(), 
								campoOrganizacao.getText(), 
								Integer.parseInt(campoVolume.getText()), 
								Integer.parseInt(campoNumero.getText()), 
								Integer.parseInt(campoAno.getText()))
				);
				JOptionPane.showMessageDialog(null, "Revista incluída.");
				
			} catch(IllegalArgumentException error) {
				JOptionPane.showMessageDialog(null, "Não foi possível incluir esta revista.");
			}
						
			campoTitulo.setText("");
			campoOrganizacao.setText("");
			campoVolume.setText("");
			campoNumero.setText("");
			campoAno.setText("");
			
		} else if(e.getSource() == botaoLivros) {					// botão LIVROS:
			this.setVisible(false);									// esconde a janela
			this.dispose();											// destroi a janela	
			new JanelaLivro();										// chama a janela de livros
			
		} else if(e.getSource() == botaoListagem) {					// botão LISTAGEM:
			this.setVisible(false);									// esconde a janela
			this.dispose();											// destroi a janela
			new JanelaListagem();									// chama a janela de listagem
		}
	}
}