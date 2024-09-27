package janelas;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextArea;

import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JTextField;
import javax.swing.SwingConstants;

import tratadores.TrataBotaoClienteCad;
import tratadores.TrataBotaoClienteCon;

import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JanelaClienteCon extends JFrame {
	private JTextField textFieldNome;
	private TrataBotaoClienteCon trataBotaoClienteCon;

	public JanelaClienteCon() {
		setMinimumSize(new Dimension(530, 200));

		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);

		JLabel lblInfo = new JLabel("Buscar cliente");
		lblInfo.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblInfo.setHorizontalAlignment(SwingConstants.CENTER);
		lblInfo.setBounds(10, 11, 494, 61);
		panel.add(lblInfo);

		JLabel lblCpf = new JLabel("Digite o CPF do cliente:");
		lblCpf.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCpf.setBounds(116, 83, 111, 14);
		lblCpf.setHorizontalAlignment(SwingConstants.LEFT);
		panel.add(lblCpf);

		// ler o cpf
		textFieldNome = new JTextField();
		textFieldNome.setBounds(237, 80, 154, 20);
		panel.add(textFieldNome);
		textFieldNome.setColumns(10);
		
		// busca no arraylist um cliente com o mesmo cpf
		// se exitir: chamar a janela com os dados (JanelaClienteDados)
		// se não existir: printar do lado do botão que o cliente não existe e voltar para a main
		JButton btnBuscar = new JButton("Buscar");
        btnBuscar.setBounds(189, 130, 140, 20);
        panel.add(btnBuscar);

        TrataBotaoClienteCon trataBotao = new TrataBotaoClienteCon(btnBuscar, this);
		btnBuscar.addActionListener(trataBotao);
	}
	
	public String getCpf() {
        return textFieldNome.getText();
    }
}