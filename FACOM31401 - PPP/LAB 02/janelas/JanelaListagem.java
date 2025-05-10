package janelas;

import classes.MaterialBibliografico;

import javax.swing.*;
import java.awt.event.*;

@SuppressWarnings("serial")
public class JanelaListagem extends JFrame {

	public JanelaListagem() {
		
		this.setTitle("Listagem");									// nome da janela
		this.setDefaultCloseOperation(DO_NOTHING_ON_CLOSE);			// x não fecha a janela
		this.setSize(550, 250);										// tamanho da janela
		this.setResizable(false);									// tamanho fixo		
		this.setLocationRelativeTo(null); 							// centralizar a janela
				
		JTextArea materialCadastrado = new JTextArea();				// lista todo material cadastrado
		materialCadastrado.setText(MaterialBibliografico.listarMaterialBibliografico());		
			
		this.addWindowListener(new WindowAdapter() {
			@Override
			public void windowClosing(WindowEvent e) {
				setVisible(false);									// deixa a janela invisível	
				dispose();											// destrói a janela
				new JanelaLivro();									// chama a janela de livros
		}});
		
		this.add(materialCadastrado);								// adicionando o conteúdo na janela
		this.setVisible(true);										// janela visível
	}
}
