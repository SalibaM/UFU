package janelas;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JButton;
import javax.swing.SwingConstants;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JanelaVoo extends JFrame {
	public JanelaVoo() {
    	setMinimumSize(new Dimension(530, 400));
		
		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);
		
		JLabel lblMenu = new JLabel("Menu de Voo");
		lblMenu.setFont(new Font("Tahoma", Font.PLAIN, 20));
		lblMenu.setHorizontalAlignment(SwingConstants.CENTER);
		lblMenu.setBounds(10, 94, 494, 33);
		panel.add(lblMenu);
		
		JButton btnCadastrar = new JButton("Cadastrar");
		btnCadastrar.setBounds(189, 158, 140, 23);
		panel.add(btnCadastrar);
		
		// Adicione um ouvinte de eventos ao botão "Cadastrar"
        btnCadastrar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // Crie e exiba uma instância de janelaVooCad quando o botão "Cadastrar" for pressionado
                JanelaVooCad vooCad = new JanelaVooCad();
                vooCad.setVisible(true);
            }
        });

        setSize(450, 200);
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setLocationRelativeTo(null);
        setVisible(true);
	}
}