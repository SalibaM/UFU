package janelas;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JTextField;
import javax.swing.SwingConstants;

import tratadores.TrataBotaoQuartoCad;
import tratadores.TrataBotaoTrechoCad;

import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JComboBox;
import java.awt.Font;

public class JanelaQuartoCad extends JFrame {
	private JTextField textFieldDiariaSemDes;
	private JTextField textFieldDes;
	private JTextField textFieldQnt;
	private JComboBox<String> comboTipo;

	@SuppressWarnings({ "rawtypes", "unchecked" })
	public JanelaQuartoCad() {
		setMinimumSize(new Dimension(530, 400));
		
		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);

		JLabel lblInfo = new JLabel("Informações do Quarto");
		lblInfo.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblInfo.setHorizontalAlignment(SwingConstants.CENTER);
		lblInfo.setBounds(10, 46, 494, 26);
		panel.add(lblInfo);

		JLabel lblDiariaSemDes = new JLabel("Valor da diária:");
		lblDiariaSemDes.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblDiariaSemDes.setBounds(156, 124, 77, 14);
		lblDiariaSemDes.setHorizontalAlignment(SwingConstants.LEFT);
		panel.add(lblDiariaSemDes);

		// ler o valor da diária sem desconto
		textFieldDiariaSemDes = new JTextField();
		textFieldDiariaSemDes.setBounds(278, 121, 77, 20);
		panel.add(textFieldDiariaSemDes);
		textFieldDiariaSemDes.setColumns(10);

		JLabel lblDes = new JLabel("Valor do desconto:");
		lblDes.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblDes.setHorizontalAlignment(SwingConstants.LEFT);
		lblDes.setBounds(156, 155, 96, 14);
		panel.add(lblDes);

		// ler o valor do desconto
		textFieldDes = new JTextField();
		textFieldDes.setColumns(10);
		textFieldDes.setBounds(278, 152, 77, 20);
		panel.add(textFieldDes);

		JLabel lblQnt = new JLabel("Quantidade:");
		lblQnt.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblQnt.setHorizontalAlignment(SwingConstants.LEFT);
		lblQnt.setBounds(156, 183, 66, 14);
		panel.add(lblQnt);

		// ler a quantidade
		textFieldQnt = new JTextField();
		textFieldQnt.setColumns(10);
		textFieldQnt.setBounds(278, 180, 77, 20);
		panel.add(textFieldQnt);

		JLabel lblTipo = new JLabel("Tipo de quarto:");
		lblTipo.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblTipo.setHorizontalAlignment(SwingConstants.LEFT);
		lblTipo.setBounds(156, 215, 77, 14);
		panel.add(lblTipo);

		// definir o tipo de quarto
		// não sei como tirar os warnings dessa parte
		comboTipo = new JComboBox();
		comboTipo.setMaximumRowCount(4);
		comboTipo.setBounds(255, 211, 100, 22);
		panel.add(comboTipo);
		comboTipo.addItem("Single");
		comboTipo.addItem("Duplo");
		comboTipo.addItem("Triplo");
		comboTipo.addItem("Luxo");

		// chamar o construtor, salvar no arraylist e voltar para a main
		JButton btnFinalizar = new JButton("Concluir");
		btnFinalizar.setBounds(415, 327, 89, 23);
		panel.add(btnFinalizar);
		
		TrataBotaoQuartoCad trataBotao = new TrataBotaoQuartoCad(btnFinalizar, this);
		btnFinalizar.addActionListener(trataBotao);

	}
	
	public double getDiariaSemDes() {
		String DiariaSemDes = textFieldDiariaSemDes.getText();
		return Double.parseDouble(DiariaSemDes);
	}
	
	public double getDes() {
		String textDes = textFieldDes.getText();
		return Double.parseDouble(textDes);
	}
	
	public int getQnt() {
		String textQnt = textFieldQnt.getText();
		return Integer.parseInt(textQnt);
	}
	
	public String getTipo() {
		return (String) comboTipo.getSelectedItem();
	}
	
	
}