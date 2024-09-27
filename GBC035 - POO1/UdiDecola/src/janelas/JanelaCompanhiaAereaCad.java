package janelas;

import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JTextField;
import javax.swing.SwingConstants;

import tratadores.TrataBotaoCompanhiaAereaCad;
import tratadores.TrataBotaoQuartoCad;

import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.Font;

public class JanelaCompanhiaAereaCad extends JFrame {
	private JTextField textFieldNomeOf;
	private JTextField textFieldLog;
	private JTextField textFieldBairro;
	private JTextField textFieldNum;
	private JTextField textFieldUf;
	private JTextField textFieldAnoC;
	private JTextField textFieldDiaC;
	private JTextField textFieldMesC;
	private JTextField textFieldCid;
	private JTextField textFieldCep;
	private JTextField textFieldNomeDiv;
	private JTextField textFieldCnpj;

	public JanelaCompanhiaAereaCad() {
    	setMinimumSize(new Dimension(530, 400));

		JPanel panel = new JPanel();
		getContentPane().add(panel, BorderLayout.CENTER);
		panel.setLayout(null);

		JLabel lblInfo = new JLabel("Informações da Companhia Aérea");
		lblInfo.setFont(new Font("Tahoma", Font.PLAIN, 14));
		lblInfo.setHorizontalAlignment(SwingConstants.CENTER);
		lblInfo.setBounds(10, 11, 494, 26);
		panel.add(lblInfo);

		JLabel lblNomeOf = new JLabel("Nome oficial:");
		lblNomeOf.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblNomeOf.setBounds(61, 77, 61, 14);
		lblNomeOf.setHorizontalAlignment(SwingConstants.LEFT);
		panel.add(lblNomeOf);

		// ler o nome oficial
		textFieldNomeOf = new JTextField();
		textFieldNomeOf.setBounds(132, 74, 317, 20);
		panel.add(textFieldNomeOf);
		textFieldNomeOf.setColumns(10);

		JLabel lblNomeDiv = new JLabel("Nome de divulgação:");
		lblNomeDiv.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblNomeDiv.setHorizontalAlignment(SwingConstants.LEFT);
		lblNomeDiv.setBounds(61, 105, 104, 14);
		panel.add(lblNomeDiv);

		// ler o nome de divulgação
		textFieldNomeDiv = new JTextField();
		textFieldNomeDiv.setColumns(10);
		textFieldNomeDiv.setBounds(172, 102, 277, 20);
		panel.add(textFieldNomeDiv);

		JLabel lblLog = new JLabel("Logradouro:");
		lblLog.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblLog.setBounds(61, 136, 59, 14);
		panel.add(lblLog);

		// ler o logradouro
		textFieldLog = new JTextField();
		textFieldLog.setBounds(132, 133, 215, 20);
		panel.add(textFieldLog);
		textFieldLog.setColumns(10);

		JLabel lblNum = new JLabel("Número:");
		lblNum.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblNum.setBounds(357, 136, 41, 14);
		panel.add(lblNum);

		// ler o número
		textFieldNum = new JTextField();
		textFieldNum.setBounds(408, 133, 41, 20);
		panel.add(textFieldNum);
		textFieldNum.setColumns(10);

		JLabel lblBairro = new JLabel("Bairro:");
		lblBairro.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblBairro.setBounds(61, 167, 32, 14);
		panel.add(lblBairro);

		// ler o bairro
		textFieldBairro = new JTextField();
		textFieldBairro.setBounds(103, 164, 104, 20);
		panel.add(textFieldBairro);
		textFieldBairro.setColumns(10);

		JLabel lblCid = new JLabel("Cidade:");
		lblCid.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCid.setBounds(217, 167, 37, 14);
		panel.add(lblCid);

		// ler a cidade
		textFieldCid = new JTextField();
		textFieldCid.setColumns(10);
		textFieldCid.setBounds(264, 164, 107, 20);
		panel.add(textFieldCid);

		JLabel lblUf = new JLabel("UF:");
		lblUf.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblUf.setBounds(381, 167, 17, 14);
		panel.add(lblUf);

		// ler o estado (sigla)
		textFieldUf = new JTextField();
		textFieldUf.setBounds(408, 164, 41, 20);
		panel.add(textFieldUf);
		textFieldUf.setColumns(10);

		JLabel lblCep = new JLabel("CEP:");
		lblCep.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCep.setBounds(61, 195, 23, 14);
		panel.add(lblCep);

		// ler o cep
		textFieldCep = new JTextField();
		textFieldCep.setColumns(10);
		textFieldCep.setBounds(94, 192, 104, 20);
		panel.add(textFieldCep);

		JLabel lblCnpj = new JLabel("CNPJ:");
		lblCnpj.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblCnpj.setBounds(315, 195, 32, 14);
		panel.add(lblCnpj);

		// ler o cnpj
		textFieldCnpj = new JTextField();
		textFieldCnpj.setColumns(10);
		textFieldCnpj.setBounds(345, 192, 104, 20);
		panel.add(textFieldCnpj);

		textFieldDiaC = new JTextField();
		textFieldDiaC.setBounds(150, 223, 50, 20);
		panel.add(textFieldDiaC);
		textFieldDiaC.setColumns(10);
		
		JLabel lblNewLabel = new JLabel("/");
		lblNewLabel.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel.setBounds(196, 226, 17, 14);
		panel.add(lblNewLabel);
		
		textFieldMesC = new JTextField();
		textFieldMesC.setColumns(10);
		textFieldMesC.setBounds(210, 223, 50, 20);
		panel.add(textFieldMesC);
		
		JLabel lblNewLabel_1 = new JLabel("/");
		lblNewLabel_1.setHorizontalAlignment(SwingConstants.CENTER);
		lblNewLabel_1.setBounds(258, 226, 17, 14);
		panel.add(lblNewLabel_1);
		
		textFieldAnoC = new JTextField();
		textFieldAnoC.setColumns(10);
		textFieldAnoC.setBounds(272, 223, 50, 20);
		panel.add(textFieldAnoC);

		// chamar o construtor, salvar no arraylist e voltar para a main
		JButton btnFinalizar = new JButton("Concluir");
		btnFinalizar.setBounds(415, 327, 89, 23);
		panel.add(btnFinalizar);
		
		TrataBotaoCompanhiaAereaCad trataBotao = new TrataBotaoCompanhiaAereaCad(btnFinalizar, this);
		btnFinalizar.addActionListener(trataBotao);
		
		JLabel lblNewLabel_2 = new JLabel("Data de criação:");
		lblNewLabel_2.setFont(new Font("Tahoma", Font.PLAIN, 11));
		lblNewLabel_2.setBounds(61, 226, 79, 14);
		panel.add(lblNewLabel_2);
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
	
	public int getNum() {
		String numText = textFieldNum.getText();
        return Integer.parseInt(numText);
	}
	
	public String getUf() {
		return textFieldUf.getText();
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

    public String getCnpj() {
        return textFieldCnpj.getText();
    }
    
    public String getNomeDiv() {
    	return textFieldNomeDiv.getText();
    }
}