package janelas;

import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

@SuppressWarnings("serial")
public class JanelaTeclado extends JFrame {
	
	public JTextField campoVisor;
	public JButton botao1, botao2, botao3, botao4, botao5, botao6, botao7, botao8, botao9, botao0;
	public JButton botaoAsterisco, botaoHashtag, botaoSend, botaoEnd;
		
	public JanelaTeclado() {
		// CRIANDO A JANELA
		this.setTitle("Teclado Numérico");							// nome da janela
		this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);		// programa encerra no x
		this.setSize(300, 350);										// tamanho da janela
		this.setResizable(false);									// tamanho fixo 
		this.setLocationRelativeTo(null); 							// centralizar a janela
		
		// CRIANDO O VISOR
		campoVisor = new JTextField(20);
		
		// CRIANDO OS BOTÕES E ADICIONANDO OS TRATAMENTOS
		// adiciona o 1
		botao1 = new JButton("1");
		botao1.setPreferredSize(new Dimension(15, 15));
		botao1.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "1");
		}});
		
		// adiciona o 2
		botao2 = new JButton("2");
		botao2.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "2");
		}});
		
		// adiciona o 3
		botao3 = new JButton("3");
		botao3.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "3");
		}});
		
		// adiciona o 4
		botao4 = new JButton("4");
		botao4.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "4");
		}});
		
		// adiciona o 5
		botao5 = new JButton("5");
		botao5.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "5");
		}});
		
		// adiciona o 6
		botao6 = new JButton("6");
		botao6.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "6");
		}});
		
		// adiciona o 7
		botao7 = new JButton("7");
		botao7.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "7");
		}});
		
		// adiciona o 8
		botao8 = new JButton("8");
		botao8.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "8");
		}});
		
		// adiciona o 9
		botao9 = new JButton("9");
		botao9.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "9");
		}});
		
		// adiciona o 0
		botao0 = new JButton("0");
		botao0.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "0");
		}});
		
		// adiciona o *
		botaoAsterisco = new JButton("*");
		botaoAsterisco.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "*");
		}});
		
		// adiciona a #
		botaoHashtag = new JButton("#");
		botaoHashtag.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText(campoVisor.getText() + "#");
		}});
		
		// imprime o conteúdo do visor
		botaoSend = new JButton("send");
		botaoSend.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				System.out.println(campoVisor.getText());
		}});
		
		// limpa o visor
		botaoEnd = new JButton("end");
		botaoEnd.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				campoVisor.setText("");
		}});
				
		// CRIANDO PANELS E ADICIONANDO OS COMPONENTES
		// panel com o visor
		JPanel panelVisor = new JPanel();
		panelVisor.add(campoVisor);
		
		// panel com os números, asterisco e hashtag
		JPanel panelTeclado = new JPanel();
		panelTeclado.add(botao1);
		panelTeclado.add(botao2);
		panelTeclado.add(botao3);
		panelTeclado.add(botao4);
		panelTeclado.add(botao5);
		panelTeclado.add(botao6);
		panelTeclado.add(botao7);
		panelTeclado.add(botao8);
		panelTeclado.add(botao9);
		panelTeclado.add(botaoAsterisco);
		panelTeclado.add(botao0);
		panelTeclado.add(botaoHashtag);
		panelTeclado.setLayout(new GridLayout(4, 3));
		
		// panel com os botões SEND e END
		JPanel panelFuncoes = new JPanel();
		panelFuncoes.add(botaoSend);
		panelFuncoes.add(botaoEnd);
		
		// panel com os demais panels
		JPanel panelPrincipal = new JPanel(new BorderLayout());
		panelPrincipal.add(panelVisor, BorderLayout.PAGE_START);
		panelPrincipal.add(panelTeclado, BorderLayout.CENTER);
		panelPrincipal.add(panelFuncoes, BorderLayout.PAGE_END);
		
		// CONFIGURAÇÕES FINAIS DA JANELA
		this.getContentPane().add(panelPrincipal);					// adicional panel principal na janela
		this.setVisible(true); 										// janela visível
	}
	
	public static void main(String[] args) {		
		new JanelaTeclado();
	}
}
