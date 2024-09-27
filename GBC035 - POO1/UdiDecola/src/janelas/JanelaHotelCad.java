package janelas;

import tratadores.TrataBotaoHotelCad;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JTextField;
import javax.swing.SwingConstants;

import tratadores.TrataBotaoHotel;

import javax.swing.JLabel;
import javax.swing.JButton;
import javax.swing.JCheckBox;
import java.awt.Font;

public class JanelaHotelCad extends JFrame {
	private JTextField textFieldNomeOf;
	private JTextField textFieldLog;
	private JTextField textFieldBairro;
	private JTextField textFieldNum;
	private JTextField textFieldUf;
	private JTextField textFieldDiaC;
	private JTextField textFieldMesC;
	private JTextField textFieldAnoC;
	private JTextField textFieldCid;
	private JTextField textFieldCep;
	private JTextField textFieldNomeDiv;
	private JTextField textFieldCnpj;
	private JTextField textFieldEst;
	private JTextField textFieldQuarto;
	private JTextField textFieldMinCheckIn;
	private JTextField textFieldHoraCheckIn;
	private JTextField textFieldHoraCheckOut;
	private JTextField textFieldMinCheckOut;
	private JTextField textFieldDiv;
	private JTextField textFieldDesc;
	private JCheckBox checkBoxAcPet;

	public JanelaHotelCad() {
		setMinimumSize(new Dimension(530, 400));

		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);

		JLabel lblInfo = new JLabel("Informações do Hotel");
		lblInfo.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblInfo.setHorizontalAlignment(SwingConstants.CENTER);
		lblInfo.setBounds(10, 11, 494, 26);
		panel.add(lblInfo);

		JLabel lblNomeOf = new JLabel("Nome oficial:");
		lblNomeOf.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblNomeOf.setBounds(61, 48, 61, 14);
		lblNomeOf.setHorizontalAlignment(SwingConstants.LEFT);
		panel.add(lblNomeOf);

		// ler o nome oficial
		textFieldNomeOf = new JTextField();
		textFieldNomeOf.setBounds(132, 45, 317, 20);
		panel.add(textFieldNomeOf);
		textFieldNomeOf.setColumns(10);

		JLabel lblNomeDiv = new JLabel("Nome de divulgação:");
		lblNomeDiv.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblNomeDiv.setHorizontalAlignment(SwingConstants.LEFT);
		lblNomeDiv.setBounds(61, 73, 104, 14);
		panel.add(lblNomeDiv);

		// ler o nome de divulgação
		textFieldNomeDiv = new JTextField();
		textFieldNomeDiv.setColumns(10);
		textFieldNomeDiv.setBounds(172, 70, 277, 20);
		panel.add(textFieldNomeDiv);

		JLabel lblLog = new JLabel("Logradouro:");
		lblLog.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblLog.setBounds(61, 101, 59, 14);
		panel.add(lblLog);

		// ler o logradouro
		textFieldLog = new JTextField();
		textFieldLog.setBounds(132, 98, 215, 20);
		panel.add(textFieldLog);
		textFieldLog.setColumns(10);

		JLabel lblNum = new JLabel("Número:");
		lblNum.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblNum.setBounds(357, 101, 41, 14);
		panel.add(lblNum);

		// ler o número
		textFieldNum = new JTextField();
		textFieldNum.setBounds(408, 98, 41, 20);
		panel.add(textFieldNum);
		textFieldNum.setColumns(10);

		JLabel lblBairro = new JLabel("Bairro:");
		lblBairro.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblBairro.setBounds(61, 129, 32, 14);
		panel.add(lblBairro);

		// ler o bairro
		textFieldBairro = new JTextField();
		textFieldBairro.setBounds(103, 126, 104, 20);
		panel.add(textFieldBairro);
		textFieldBairro.setColumns(10);

		JLabel lblCid = new JLabel("Cidade:");
		lblCid.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCid.setBounds(217, 129, 37, 14);
		panel.add(lblCid);

		// ler a cidade
		textFieldCid = new JTextField();
		textFieldCid.setColumns(10);
		textFieldCid.setBounds(264, 126, 107, 20);
		panel.add(textFieldCid);

		JLabel lblUf = new JLabel("UF:");
		lblUf.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblUf.setBounds(381, 129, 17, 14);
		panel.add(lblUf);

		// ler o estado (sigla)
		textFieldUf = new JTextField();
		textFieldUf.setBounds(408, 126, 41, 20);
		panel.add(textFieldUf);
		textFieldUf.setColumns(10);

		JLabel lblCep = new JLabel("CEP:");
		lblCep.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCep.setBounds(61, 156, 23, 14);
		panel.add(lblCep);

		// ler o cep
		textFieldCep = new JTextField();
		textFieldCep.setColumns(10);
		textFieldCep.setBounds(93, 153, 104, 20);
		panel.add(textFieldCep);

		JLabel lblCnpj = new JLabel("CNPJ:");
		lblCnpj.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCnpj.setBounds(207, 156, 32, 14);
		panel.add(lblCnpj);

		// ler o cnpj
		textFieldCnpj = new JTextField();
		textFieldCnpj.setColumns(10);
		textFieldCnpj.setBounds(243, 153, 104, 20);
		panel.add(textFieldCnpj);

		textFieldDiaC = new JTextField();
		textFieldDiaC.setBounds(150, 184, 50, 20);
		panel.add(textFieldDiaC);
		textFieldDiaC.setColumns(10);
		
		textFieldMesC = new JTextField();
		textFieldMesC.setColumns(10);
		textFieldMesC.setBounds(217, 184, 50, 20);
		panel.add(textFieldMesC);
		
		textFieldAnoC = new JTextField();
		textFieldAnoC.setColumns(10);
		textFieldAnoC.setBounds(277, 184, 50, 20);
		panel.add(textFieldAnoC);


		JLabel lblEstrelas = new JLabel("Estrelas:");
		lblEstrelas.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblEstrelas.setBounds(369, 156, 46, 14);
		panel.add(lblEstrelas);

		// ler o número de estrelas
		textFieldEst = new JTextField();
		textFieldEst.setBounds(417, 153, 32, 20);
		panel.add(textFieldEst);
		textFieldEst.setColumns(10);

		JLabel lblQuarto = new JLabel("Nº Quartos:");
		lblQuarto.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblQuarto.setBounds(355, 187, 67, 14);
		panel.add(lblQuarto);

		// ler o número de quartos
		textFieldQuarto = new JTextField();
		textFieldQuarto.setColumns(10);
		textFieldQuarto.setBounds(417, 184, 32, 20);
		panel.add(textFieldQuarto);

		JLabel lblNewLabel = new JLabel("/");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(264, 187, 17, 14);
		panel.add(lblNewLabel);
		
		JLabel lblNewLabel_1 = new JLabel("/");
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setBounds(200, 187, 17, 14);
		panel.add(lblNewLabel_1);
		
		textFieldHoraCheckIn = new JTextField();
		textFieldHoraCheckIn.setColumns(10);
		textFieldHoraCheckIn.setBounds(118, 212, 22, 20);
		panel.add(textFieldHoraCheckIn);
		
		textFieldMinCheckIn = new JTextField();
		textFieldMinCheckIn.setColumns(10);
		textFieldMinCheckIn.setBounds(150, 212, 22, 20);
		panel.add(textFieldMinCheckIn);
		
		textFieldHoraCheckOut = new JTextField();
		textFieldHoraCheckOut.setColumns(10);
		textFieldHoraCheckOut.setBounds(254, 212, 22, 20);
		panel.add(textFieldHoraCheckOut);
		
		textFieldMinCheckOut = new JTextField();
		textFieldMinCheckOut.setColumns(10);
		textFieldMinCheckOut.setBounds(287, 212, 22, 20);
		panel.add(textFieldMinCheckOut);
		
		JLabel lblNewLabel_2 = new JLabel(":");
		lblNewLabel_2.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_2.setBounds(123, 215, 46, 14);
		panel.add(lblNewLabel_2);
		
		JLabel lblNewLabel_2_1 = new JLabel(":");
		lblNewLabel_2_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_2_1.setBounds(254, 215, 55, 14);
		panel.add(lblNewLabel_2_1);

		// conferir se aceita pet ou não
		checkBoxAcPet = new JCheckBox("Hotel Pet Friendly");
		checkBoxAcPet.setFont(new Font("Tahoma", Font.PLAIN, 11));
		checkBoxAcPet.setHorizontalAlignment(SwingConstants.RIGHT);
		checkBoxAcPet.setBounds(338, 211, 111, 23);
		panel.add(checkBoxAcPet);

		JLabel lblDiv = new JLabel("Mensagem de divulgação:");
		lblDiv.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblDiv.setBounds(61, 244, 126, 14);
		panel.add(lblDiv);

		// ler a mensagem de divulgação
		textFieldDiv = new JTextField();
		textFieldDiv.setBounds(192, 241, 257, 20);
		panel.add(textFieldDiv);
		textFieldDiv.setColumns(10);

		JLabel lblDesc = new JLabel("Descrição:");
		lblDesc.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblDesc.setBounds(61, 275, 52, 14);
		panel.add(lblDesc);

		// ler a descrição
		textFieldDesc = new JTextField();
		textFieldDesc.setBounds(123, 272, 326, 20);
		panel.add(textFieldDesc);
		textFieldDesc.setColumns(10);

		// chamar o construtor, salvar no arraylist e voltar para a main
		JButton btnFinalizar = new JButton("Concluído");
		TrataBotaoHotelCad tratador = new TrataBotaoHotelCad(btnFinalizar, this);
		btnFinalizar.addActionListener(tratador);
		btnFinalizar.setBounds(415, 327, 89, 23);
		btnFinalizar.addActionListener(tratador);
		panel.add(btnFinalizar);
	
		
		JLabel lblCheckIn = new JLabel("Check-In:");
		lblCheckIn.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCheckIn.setBounds(61, 215, 50, 14);
		panel.add(lblCheckIn);
		
		JLabel lblCheckOut = new JLabel("Check-Out:");
		lblCheckOut.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCheckOut.setBounds(191, 215, 63, 14);
		panel.add(lblCheckOut);
		
		JLabel lblCriação = new JLabel("Data de criação:");
		lblCriação.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCriação.setBounds(61, 187, 79, 14);
		panel.add(lblCriação);
	}
	
	public String getNomeOf() {
		return textFieldNomeOf.getText();
	}
	
	public String getLog() {
		return textFieldLog.getText();
	}
	
	public String getBairro() {
		return textFieldBairro.getText();
	}
	
	public int getDiaC() {
    	String DiaCText = textFieldDiaC.getText();
    	return Integer.parseInt(DiaCText);
    }
    
    public int getMesC() {
    	String MesCText = textFieldMesC.getText();
    	return Integer.parseInt(MesCText);
    }
    
    public int getAnoC() {
    	String AnoCText = textFieldAnoC.getText();
    	return Integer.parseInt(AnoCText);
    }
    
    public String getCid() {
		return textFieldCid.getText();
	}
	
    public String getCep() {
		return textFieldCep.getText();
	}
	
    public String getNomeDiv() {
		return textFieldNomeDiv.getText();
	}
	
    public String getCnpj() {
		return textFieldCnpj.getText();
	}
	
	public int getEst() {
		String EstText = textFieldEst.getText();
		return Integer.parseInt(EstText);
	}
	
	public int getQuarto() { //QTD QUARTOS
		String QuartoText = textFieldQuarto.getText();
		return Integer.parseInt(QuartoText);
	}
	
	public int getHoraCheckIn() {
		String HoraCheckInText = textFieldHoraCheckIn.getText();
		return Integer.parseInt(HoraCheckInText);
	}
	
	public int getMinCheckIn() {
		String MinCheckInText = textFieldMinCheckIn.getText();
		return Integer.parseInt(MinCheckInText);
	}
	
	//segundos serão setados como zero
	
	public int getHoraCheckOut() {
		String HoraCheckOutText = textFieldHoraCheckOut.getText();
		return Integer.parseInt(HoraCheckOutText);
	}
	
	public int getMinCheckOut() {
		String MinCheckOutText = textFieldMinCheckOut.getText();
		return Integer.parseInt(MinCheckOutText);
	}
	
	//segundos serão setados como zero
	
	public String getDesc() {
		return textFieldDesc.getText();
	}
	
	public int getNum() {
		String NumText = textFieldNum.getText();
		return Integer.parseInt(NumText);
	}
	
	public String getUf() {
		return textFieldUf.getText();
	}
	
	public boolean getPet() {
		return checkBoxAcPet.isSelected() ? true : false;
		//retorna 1 se tiver selecionado e 0 se nao.
	}
	
	public String getDiv() {
		return textFieldDiv.getText();
	}
}
	
	
	