package janelas;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JTextField;
import javax.swing.SwingConstants;

import tratadores.TrataBotaoVooCad;

import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.Font;

public class JanelaVooCad extends JFrame {
	private JTextField textFieldHoraChegada;
	private JTextField textFieldMinChegada;
	private JTextField textFieldVaga;
	private JTextField textFieldPreco;
	private JTextField textFieldMinSaida;
	private JTextField textFieldHoraSaida;
	private JTextField textFieldDiaVoo;
	private JTextField textFieldMesVoo;
	private JTextField textFieldAnoVoo;

	public JanelaVooCad() {
    	setMinimumSize(new Dimension(530, 400));

		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);

		JLabel lblInfo = new JLabel("Informações do Voo");
		lblInfo.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblInfo.setHorizontalAlignment(SwingConstants.CENTER);
		lblInfo.setBounds(10, 11, 494, 26);
		panel.add(lblInfo);

		textFieldDiaVoo = new JTextField();
		textFieldDiaVoo.setColumns(10);
		textFieldDiaVoo.setBounds(215, 95, 50, 20);
		panel.add(textFieldDiaVoo);
		
		JLabel lblNewLabel = new JLabel("/");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(247, 98, 46, 14);
		panel.add(lblNewLabel);
		
		textFieldMesVoo = new JTextField();
		textFieldMesVoo.setColumns(10);
		textFieldMesVoo.setBounds(275, 95, 50, 20);
		panel.add(textFieldMesVoo);
		
		JLabel lblNewLabel_1 = new JLabel("/");
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setBounds(308, 98, 46, 14);
		panel.add(lblNewLabel_1);
		
		textFieldAnoVoo = new JTextField();
		textFieldAnoVoo.setColumns(10);
		textFieldAnoVoo.setBounds(335, 95, 50, 20);
		panel.add(textFieldAnoVoo);

		JLabel lblCheg = new JLabel("Horário de chegada:");
		lblCheg.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCheg.setBounds(139, 157, 104, 14);
		panel.add(lblCheg);

		// ler o horário de chegada
		textFieldHoraChegada = new JTextField();
		textFieldHoraChegada.setColumns(10);
		textFieldHoraChegada.setBounds(315, 154, 30, 20);
		panel.add(textFieldHoraChegada);
		
		JLabel lblNewLabel_2_1 = new JLabel(":");
		lblNewLabel_2_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_2_1.setBounds(318, 157, 67, 14);
		panel.add(lblNewLabel_2_1);
		
		textFieldMinChegada = new JTextField();
		textFieldMinChegada.setBounds(355, 154, 30, 20);
		panel.add(textFieldMinChegada);
		textFieldMinChegada.setColumns(10);

		JLabel lblSaida = new JLabel("Horário de saída:");
		lblSaida.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblSaida.setHorizontalAlignment(SwingConstants.LEFT);
		lblSaida.setBounds(139, 126, 104, 14);
		panel.add(lblSaida);

		// ler o horário de saída
		textFieldHoraSaida = new JTextField();
		textFieldHoraSaida.setColumns(10);
		textFieldHoraSaida.setBounds(315, 123, 30, 20);
		panel.add(textFieldHoraSaida);
		
		JLabel lblNewLabel_2 = new JLabel(":");
		lblNewLabel_2.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_2.setBounds(318, 126, 67, 14);
		panel.add(lblNewLabel_2);
		
		textFieldMinSaida = new JTextField();
		textFieldMinSaida.setColumns(10);
		textFieldMinSaida.setBounds(355, 123, 30, 20);
		panel.add(textFieldMinSaida);

		JLabel lblVaga = new JLabel("Nº de assentos disponíveis:");
		lblVaga.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblVaga.setBounds(139, 188, 137, 14);
		panel.add(lblVaga);

		// ler o número de assentos disponíveis
		textFieldVaga = new JTextField();
		textFieldVaga.setBounds(331, 185, 54, 20);
		panel.add(textFieldVaga);
		textFieldVaga.setColumns(10);

		JLabel lblPreco = new JLabel("Valor da passagem:");
		lblPreco.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblPreco.setBounds(139, 219, 104, 14);
		panel.add(lblPreco);

		// ler o valor da passagem
		textFieldPreco = new JTextField();
		textFieldPreco.setColumns(10);
		textFieldPreco.setBounds(331, 216, 54, 20);
		panel.add(textFieldPreco);

		JButton btnConcluir = new JButton("Concluir");
		btnConcluir.addActionListener(new TrataBotaoVooCad(btnConcluir, this)); // Associe o botão ao tratador
		btnConcluir.setBounds(381, 327, 123, 23);
		panel.add(btnConcluir);
		
		TrataBotaoVooCad trataBotao = new TrataBotaoVooCad(btnConcluir, this);
		btnConcluir.addActionListener(trataBotao);
		
		JLabel lblData = new JLabel("Data do voo:");
		lblData.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblData.setBounds(139, 98, 66, 14);
		panel.add(lblData);
	}
	
	public int getHoraSaida() {
		String HoraSaidaText = textFieldHoraSaida.getText();
		return Integer.parseInt(HoraSaidaText);
	}
	
	public int getMinSaida() {
		String MinSaidaText = textFieldMinSaida.getText();
		return Integer.parseInt(MinSaidaText);
	}
	
	//segundo setado como zero
	
	public int getHoraChegada() {
		String HoraChegadaText = textFieldHoraChegada.getText();
		return Integer.parseInt(HoraChegadaText);
	}
	
	public int getMinChegada() {
		String MinChegadaText = textFieldMinChegada.getText();
		return Integer.parseInt(MinChegadaText);
	}
	
	//segundo setado como zero
	
	public int getDiaVoo() {
		String DiaVooText = textFieldDiaVoo.getText();
		return Integer.parseInt(DiaVooText);
	}
	
	public int getMesVoo() {
		String MesVooText = textFieldMesVoo.getText();
		return Integer.parseInt(MesVooText);
	}
	
	public int getAnoVoo() {
		String AnoVooText = textFieldAnoVoo.getText();
		return Integer.parseInt(AnoVooText);
	}
	
	public int getVagas() {
		String VagasText = textFieldVaga.getText();
		return Integer.parseInt(VagasText);
	}
	
	public double getPreco() {
		String PrecoText = textFieldPreco.getText();
		return Double.parseDouble(PrecoText);
	}
	
}