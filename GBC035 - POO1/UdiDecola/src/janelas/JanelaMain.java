package janelas;

import tratadores.TrataBotaoCliente;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import javax.swing.SwingUtilities;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import javax.swing.JButton;

public class JanelaMain extends JFrame {
	public JanelaMain() {
		setMinimumSize(new Dimension(530, 400));

		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);

		JButton btnEmpresa = new JButton("Empresa");
		btnEmpresa.setBounds(178, 166, 140, 23);
		panel.add(btnEmpresa);
		btnEmpresa.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				abrirJanelaEmpresa();
			}
		});

		JButton btnCliente = new JButton("Cliente");
		btnCliente.setBounds(178, 132, 140, 23);
		panel.add(btnCliente);
		btnCliente.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				abrirJanelaCliente();
			}
		});

		JButton btnFuncionario = new JButton("Funcionário");
		btnFuncionario.setBounds(178, 200, 140, 23);
		panel.add(btnFuncionario);

		JLabel lblNewLabel = new JLabel("Bem-vindo ao UdiDecola!");
		lblNewLabel.setFont(new Font("Tahoma", Font.PLAIN, 22));
		lblNewLabel.setBounds(123, 73, 268, 35);
		panel.add(lblNewLabel);
		btnFuncionario.addActionListener(new ActionListener() {
			public void actionPerformed(ActionEvent e) {
				abrirJanelaFuncionario();
			}
		});
	}

	private void abrirJanelaEmpresa() {
		JanelaEmpresa janelaEmpresa = new JanelaEmpresa();
		janelaEmpresa.pack();
		janelaEmpresa.setSize(530, 400);
		janelaEmpresa.setVisible(true);
	}

	private void abrirJanelaCliente() {
		JanelaCliente janelaCliente = new JanelaCliente();
		janelaCliente.pack();
		janelaCliente.setSize(530, 400);
		janelaCliente.setVisible(true);
	}

	private void abrirJanelaFuncionario() {
		JanelaFuncionario janelaFuncionario = new JanelaFuncionario();
		janelaFuncionario.pack();
		janelaFuncionario.setSize(530, 400);
		janelaFuncionario.setVisible(true);
	}

	public static void main(String[] args) {
		java.awt.EventQueue.invokeLater(new Runnable() {
			public void run() {
				new JanelaMain().setVisible(true);
			}
		});
	}
}