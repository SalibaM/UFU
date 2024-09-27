package janelas;

import tratadores.TrataBotaoTrecho;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JButton;
import javax.swing.SwingConstants;
import javax.swing.JLabel;
import java.awt.Font;

public class JanelaTrecho extends JFrame {
	public JanelaTrecho() {
    	setMinimumSize(new Dimension(530, 400));

		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);
		
		JLabel lblMenu = new JLabel("Menu do Trecho");
		lblMenu.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblMenu.setHorizontalAlignment(SwingConstants.CENTER);
		lblMenu.setBounds(10, 94, 494, 33);
		panel.add(lblMenu);
		
		JanelaTrechoCad janelaTrechoCad = new JanelaTrechoCad();
		
		JButton btnCadastrar = new JButton("Cadastrar");
		
		TrataBotaoTrecho tratador = new TrataBotaoTrecho(btnCadastrar, janelaTrechoCad, this);
		btnCadastrar.addActionListener(tratador);
		btnCadastrar.setBounds(189, 158, 140, 23);
		btnCadastrar.addActionListener(tratador);
		panel.add(btnCadastrar);
	}
	
}