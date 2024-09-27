package janelas;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JTextField;
import javax.swing.SwingConstants;

import tratadores.TrataBotaoFuncHotelCad;
import tratadores.TrataBotaoQuartoCad;

import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.Font;

public class JanelaFuncHotelCad extends JFrame {
	private JTextField textFieldNome;
	private JTextField textFieldLog;
	private JTextField textFieldBairro;
	private JTextField textFieldNum;
	private JTextField textFieldUf;
	private JTextField textFieldAnoN;
	private JTextField textFieldDiaN;
	private JTextField textFieldMesN;
	private JTextField textFieldCid;
	private JTextField textFieldCep;
	private JTextField textFieldCpf;
	private JTextField textFieldTrab;
	private JTextField textFieldBonusSal;

	public JanelaFuncHotelCad() {
		setMinimumSize(new Dimension(530, 400));

		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);

		JLabel lblInfo = new JLabel("Informações pessoais");
		lblInfo.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblInfo.setHorizontalAlignment(SwingConstants.CENTER);
		lblInfo.setBounds(10, 11, 494, 43);
		panel.add(lblInfo);

		JLabel lblNome = new JLabel("Nome:");
		lblNome.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblNome.setBounds(48, 74, 31, 14);
		lblNome.setHorizontalAlignment(SwingConstants.LEFT);
		panel.add(lblNome);

		// ler o nome
		textFieldNome = new JTextField();
		textFieldNome.setBounds(89, 71, 376, 20);
		panel.add(textFieldNome);
		textFieldNome.setColumns(10);

		JLabel lblLog = new JLabel("Logradouro:");
		lblLog.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblLog.setBounds(48, 105, 59, 14);
		panel.add(lblLog);

		// ler o logradouro
		textFieldLog = new JTextField();
		textFieldLog.setBounds(116, 102, 190, 20);
		panel.add(textFieldLog);
		textFieldLog.setColumns(10);

		JLabel lblNum = new JLabel("Número:");
		lblNum.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblNum.setBounds(373, 102, 41, 14);
		panel.add(lblNum);

		// ler o número
		textFieldNum = new JTextField();
		textFieldNum.setBounds(424, 99, 41, 20);
		panel.add(textFieldNum);
		textFieldNum.setColumns(10);		

		JLabel lblBairro = new JLabel("Bairro:");
		lblBairro.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblBairro.setBounds(48, 133, 32, 14);
		panel.add(lblBairro);
		
		// ler o bairro
		textFieldBairro = new JTextField();
		textFieldBairro.setBounds(89, 130, 119, 20);
		panel.add(textFieldBairro);
		textFieldBairro.setColumns(10);

		JLabel lblCid = new JLabel("Cidade:");
		lblCid.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCid.setBounds(218, 133, 37, 14);
		panel.add(lblCid);

		// ler a cidade
		textFieldCid = new JTextField();
		textFieldCid.setColumns(10);
		textFieldCid.setBounds(265, 130, 122, 20);
		panel.add(textFieldCid);

		JLabel lblUf = new JLabel("UF:");
		lblUf.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblUf.setBounds(397, 133, 17, 14);
		panel.add(lblUf);

		// ler o estado (sigla)
		textFieldUf = new JTextField();
		textFieldUf.setBounds(424, 130, 41, 20);
		panel.add(textFieldUf);
		textFieldUf.setColumns(10);

		JLabel lblCep = new JLabel("CEP:");
		lblCep.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCep.setBounds(48, 164, 23, 14);
		panel.add(lblCep);
		
		// ler o cep
		textFieldCep = new JTextField();
		textFieldCep.setColumns(10);
		textFieldCep.setBounds(81, 161, 119, 20);
		panel.add(textFieldCep);

		JLabel lblCpf = new JLabel("CPF:");
		lblCpf.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCpf.setBounds(313, 164, 23, 14);
		panel.add(lblCpf);
		
		// ler o cpf
		textFieldCpf = new JTextField();
		textFieldCpf.setColumns(10);
		textFieldCpf.setBounds(346, 161, 119, 20);
		panel.add(textFieldCpf);

		textFieldDiaN = new JTextField();
		textFieldDiaN.setBounds(157, 189, 50, 20);
		panel.add(textFieldDiaN);
		textFieldDiaN.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("/");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(204, 192, 17, 14);
		panel.add(lblNewLabel);
		
		textFieldMesN = new JTextField();
		textFieldMesN.setColumns(10);
		textFieldMesN.setBounds(218, 189, 50, 20);
		panel.add(textFieldMesN);
		
		JLabel lblNewLabel_1 = new JLabel("/");
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setBounds(264, 192, 17, 14);
		panel.add(lblNewLabel_1);
		
		textFieldAnoN = new JTextField();
		textFieldAnoN.setColumns(10);
		textFieldAnoN.setBounds(278, 189, 50, 20);
		panel.add(textFieldAnoN);
		
		JLabel lblTrab = new JLabel("Carteira de trabalho:");
		lblTrab.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblTrab.setBounds(48, 223, 104, 14);
		panel.add(lblTrab);
		
		// ler a carteira de trabalho
		textFieldTrab = new JTextField();
		textFieldTrab.setColumns(10);
		textFieldTrab.setBounds(156, 220, 99, 20);
		panel.add(textFieldTrab);
		
		JLabel lblBonusSal = new JLabel("Bônus salarial:");
		lblBonusSal.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblBonusSal.setBounds(265, 223, 69, 14);
		panel.add(lblBonusSal);
		
		// ler o bônus salarial
		textFieldBonusSal = new JTextField();
		textFieldBonusSal.setBounds(344, 220, 121, 20);
		panel.add(textFieldBonusSal);
		textFieldBonusSal.setColumns(10);
		
		// chamar o construtor, salvar no arraylist e voltar para a main
		JButton btnFinalizar = new JButton("Concluído");
		btnFinalizar.setBounds(415, 327, 89, 23);
		panel.add(btnFinalizar);
		
		TrataBotaoFuncHotelCad trataBotao = new TrataBotaoFuncHotelCad(btnFinalizar, this);
		btnFinalizar.addActionListener(trataBotao);
		
		JLabel lblNascimento = new JLabel("Data de nascimento:");
		lblNascimento.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblNascimento.setBounds(48, 192, 99, 14);
		panel.add(lblNascimento);
	}
	
	public String getNome() {
		return textFieldNome.getText();
	}
	
	public String getLog() {
		return textFieldNome.getText();
	}

	public String getBairro() {
		return textFieldNome.getText();
	}
	
	public int getNum() {
		String numText = textFieldNum.getText();
        return Integer.parseInt(numText);
	}
	
	public String getUf() {
		return textFieldNome.getText();
	}
	
	public int getDiaN() {
    	String DiaNText = textFieldDiaN.getText();
    	return Integer.parseInt(DiaNText);
    }
    
    public int getMesN() {
    	String MesNText = textFieldMesN.getText();
    	return Integer.parseInt(MesNText);
    }
    
    public int getAnoN() {
    	String AnoNText = textFieldAnoN.getText();
    	return Integer.parseInt(AnoNText);
    }
    
	public String getCid() {
		return textFieldNome.getText();
	}
	
	public String getCep() {
		return textFieldNome.getText();
	}
	
	public String getCpf() {
		return textFieldNome.getText();
	}
	
	public String getTrab() {
		return textFieldNome.getText();
	}
	
	public double getBonusSal() {
		String BonusSal = textFieldBonusSal.getText();
		return Double.parseDouble(BonusSal);
	}
}