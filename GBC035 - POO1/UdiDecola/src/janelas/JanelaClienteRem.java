package janelas;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.Font;

import javax.swing.JTextField;
import javax.swing.SwingConstants;

import tratadores.TrataBotaoClienteCad;
import tratadores.TrataBotaoClienteRem;

import javax.swing.JLabel;
import javax.swing.JButton;

public class JanelaClienteRem extends JFrame {
	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	private JTextField textFieldNome;

	public JanelaClienteRem() {
		setMinimumSize(new Dimension(530, 200));

		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);

		JLabel lblInfo = new JLabel("Remover cliente");
		lblInfo.setBounds(10, 11, 494, 61);
		lblInfo.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblInfo.setHorizontalAlignment(SwingConstants.CENTER);
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
		// se exitir: printar do lado do botão que o cliente foi removido, remover do arraylist e voltar para a main
		// se não existir: printar do lado do botão que o cliente não existe e voltar para a main 
		JButton btnRemover = new JButton("Remover");
		btnRemover.setBounds(189, 130, 140, 23);
		panel.add(btnRemover);
		
		TrataBotaoClienteRem trataBotao = new TrataBotaoClienteRem(btnRemover, this);
		btnRemover.addActionListener(trataBotao);
		
	}
	
	public String getCpf() {
        return textFieldNome.getText();
    }
}