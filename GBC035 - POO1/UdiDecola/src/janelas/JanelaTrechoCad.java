package janelas;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JTextField;
import javax.swing.SwingConstants;

import tratadores.TrataBotaoTrechoCad;
import tratadores.TrataBotaoVooCad;

import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.Font;

public class JanelaTrechoCad extends JFrame {
	private JTextField textFieldCod;
	private JTextField textFieldDest;
	private JTextField textFieldSaida;
	private JTextField textFieldHoraSaida;
	private JTextField textFieldMinSaida;
	private JTextField textFieldComp;
	private JTextField textFieldHoraChegada;
	private JTextField textFieldMinChegada;
	private JTextField textFieldOrigem;

	public JanelaTrechoCad() {
    	setMinimumSize(new Dimension(530, 400));

		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);

		JLabel lblInfo = new JLabel("Informações do Trecho");
		lblInfo.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblInfo.setHorizontalAlignment(SwingConstants.CENTER);
		lblInfo.setBounds(10, 37, 494, 26);
		panel.add(lblInfo);

		JLabel lblCod = new JLabel("Código do trecho:");
		lblCod.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCod.setBounds(57, 108, 89, 14);
		lblCod.setHorizontalAlignment(SwingConstants.LEFT);
		panel.add(lblCod);

		// ler o código
		textFieldCod = new JTextField();
		textFieldCod.setBounds(150, 105, 98, 20);
		panel.add(textFieldCod);
		textFieldCod.setColumns(10);

		JLabel lblOrigem = new JLabel("Origem:");
		lblOrigem.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblOrigem.setHorizontalAlignment(SwingConstants.LEFT);
		lblOrigem.setBounds(57, 139, 41, 14);
		panel.add(lblOrigem);

		// ler a origem
		textFieldOrigem = new JTextField();
		textFieldOrigem.setColumns(10);
		textFieldOrigem.setBounds(104, 136, 125, 20);
		panel.add(textFieldOrigem);

		JLabel lblDest = new JLabel("Destino:");
		lblDest.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblDest.setBounds(267, 139, 41, 14);
		panel.add(lblDest);

		// ler o destino
		textFieldDest = new JTextField();
		textFieldDest.setBounds(318, 136, 125, 20);
		panel.add(textFieldDest);
		textFieldDest.setColumns(10);

		// ler o horário de saída
		textFieldHoraSaida = new JTextField();
		textFieldHoraSaida.setBounds(145, 167, 30, 20);
		panel.add(textFieldHoraSaida);
		textFieldHoraSaida.setColumns(10);
				
		JLabel lblNewLabel = new JLabel(":");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(145, 170, 70, 14);
		panel.add(lblNewLabel);
				
		textFieldMinSaida = new JTextField();
		textFieldMinSaida.setColumns(10);
		textFieldMinSaida.setBounds(185, 167, 30, 20);
		panel.add(textFieldMinSaida);

		JLabel lblCheg = new JLabel("Horário de chegada:");
		lblCheg.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCheg.setBounds(263, 170, 98, 14);
		panel.add(lblCheg);

		// ler o horário de chegada
		textFieldHoraChegada = new JTextField();
		textFieldHoraChegada.setColumns(10);
		textFieldHoraChegada.setBounds(371, 167, 30, 20);
		panel.add(textFieldHoraChegada);
				
		JLabel lblNewLabel_1 = new JLabel(":");
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setBounds(385, 170, 46, 14);
		panel.add(lblNewLabel_1);
				
		textFieldMinChegada = new JTextField();
		textFieldMinChegada.setColumns(10);
		textFieldMinChegada.setBounds(413, 167, 30, 20);
		panel.add(textFieldMinChegada);

		JLabel lblComp = new JLabel("Companhia aérea:");
		lblComp.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblComp.setBounds(57, 201, 89, 14);
		panel.add(lblComp);

		// ler o nome da companhia aérea
		textFieldComp = new JTextField();
		textFieldComp.setBounds(155, 198, 288, 20);
		panel.add(textFieldComp);
		textFieldComp.setColumns(10);
		
		JButton btnConcluir = new JButton("Concluir");
		btnConcluir.addActionListener(new TrataBotaoTrechoCad(btnConcluir, this)); // Associe o botão ao tratador
		btnConcluir.setBounds(381, 327, 123, 23);
		panel.add(btnConcluir);
		
		TrataBotaoTrechoCad trataBotao = new TrataBotaoTrechoCad(btnConcluir, this);
		btnConcluir.addActionListener(trataBotao);
		
		JLabel lblSaida = new JLabel("Horário de saída:");
		lblSaida.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblSaida.setBounds(57, 170, 82, 14);
		panel.add(lblSaida);

	}
	
	public String getCod() {
		return textFieldCod.getText();
	}
	
	public String getOrigem() {
		return textFieldOrigem.getText();
	}
	
	public String getDestino() {
		return textFieldDest.getText();
	}
	
	public String getComp() {
		return textFieldComp.getText();
	}
	
	public int getHoraSaida() {
		String HoraSaidaText = textFieldHoraSaida.getText();
		return Integer.parseInt(HoraSaidaText);
	}
	
	public int getMinSaida() {
		String MinSaidaText = textFieldMinSaida.getText();
		return Integer.parseInt(MinSaidaText);
	}
	
	//segundo setado como 0
	
	public int getHoraChegada() {
		String HoraChegadaText = textFieldHoraChegada.getText();
		return Integer.parseInt(HoraChegadaText);
	}
	
	public int getMinChegada() {
		String MinChegadaText = textFieldMinChegada.getText();
		return Integer.parseInt(MinChegadaText);
	}
	
	//segundo setado como 0
	
}