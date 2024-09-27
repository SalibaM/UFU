package janelas;

import javax.swing.JFrame;
import javax.swing.JPanel;
import javax.swing.JTextField;
import javax.swing.SwingConstants;

import tratadores.TrataBotaoCliente;
import tratadores.TrataBotaoClienteCad;
import tratadores.TrataBotaoClienteCon;
import tratadores.TrataBotaoCompanhiaAereaCad;

import javax.swing.JLabel;
import javax.swing.JButton;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.BorderLayout;
import java.awt.Dimension;

public class JanelaClienteCad extends JFrame {
    private JTextField textFieldNome;
    private JTextField textFieldLog;
    private JTextField textFieldBairro;
    private JTextField textFieldNum;
    private JTextField textFieldUf;
    private JTextField textFieldDiaN;
    private JTextField textFieldMesN;
    private JTextField textFieldAnoN;
    private JTextField textFieldEmail;
    private JTextField textFieldCid;
    private JTextField textFieldCep;
    private JTextField textFieldCpf;
    private JanelaCliente janelaCliente;
    private TrataBotaoCliente trataBotaoClienteCad;

    public JanelaClienteCad() {
    	setMinimumSize(new Dimension(530, 400));
    	
    	this.janelaCliente = janelaCliente;
    	
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

        textFieldNome = new JTextField();
        textFieldNome.setBounds(89, 71, 376, 20);
        panel.add(textFieldNome);
        textFieldNome.setColumns(10);

        JLabel lblLog = new JLabel("Logradouro:");
        lblLog.setFont(new Font("Tahoma", Font.PLAIN, 11));
        lblLog.setBounds(48, 105, 59, 14);
        panel.add(lblLog);

        textFieldLog = new JTextField();
        textFieldLog.setBounds(116, 102, 190, 20);
        panel.add(textFieldLog);
        textFieldLog.setColumns(10);

        JLabel lblNum = new JLabel("Número:");
        lblNum.setFont(new Font("Tahoma", Font.PLAIN, 11));
        lblNum.setBounds(373, 102, 41, 14);
        panel.add(lblNum);

        textFieldNum = new JTextField();
        textFieldNum.setBounds(424, 99, 41, 20);
        panel.add(textFieldNum);
        textFieldNum.setColumns(10);

        JLabel lblBairro = new JLabel("Bairro:");
        lblBairro.setFont(new Font("Tahoma", Font.PLAIN, 11));
        lblBairro.setBounds(48, 133, 32, 14);
        panel.add(lblBairro);

        textFieldBairro = new JTextField();
        textFieldBairro.setBounds(89, 130, 119, 20);
        panel.add(textFieldBairro);
        textFieldBairro.setColumns(10);

        JLabel lblCid = new JLabel("Cidade:");
        lblCid.setFont(new Font("Tahoma", Font.PLAIN, 11));
        lblCid.setBounds(218, 133, 37, 14);
        panel.add(lblCid);

        textFieldCid = new JTextField();
        textFieldCid.setColumns(10);
        textFieldCid.setBounds(265, 130, 122, 20);
        panel.add(textFieldCid);

        JLabel lblUf = new JLabel("UF:");
        lblUf.setFont(new Font("Tahoma", Font.PLAIN, 11));
        lblUf.setBounds(397, 133, 17, 14);
        panel.add(lblUf);

        textFieldUf = new JTextField();
        textFieldUf.setBounds(424, 130, 41, 20);
        panel.add(textFieldUf);
        textFieldUf.setColumns(10);

        JLabel lblCep = new JLabel("CEP:");
        lblCep.setFont(new Font("Tahoma", Font.PLAIN, 11));
        lblCep.setBounds(48, 164, 23, 14);
        panel.add(lblCep);

        textFieldCep = new JTextField();
        textFieldCep.setColumns(10);
        textFieldCep.setBounds(81, 161, 119, 20);
        panel.add(textFieldCep);

        JLabel lblCpf = new JLabel("CPF:");
        lblCpf.setFont(new Font("Tahoma", Font.PLAIN, 11));
        lblCpf.setBounds(313, 164, 23, 14);
        panel.add(lblCpf);

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

        JLabel lblCad = new JLabel("Data de nascimento:");
        lblCad.setFont(new Font("Tahoma", Font.PLAIN, 11));
        lblCad.setBounds(48, 192, 99, 14);
        panel.add(lblCad);

        JLabel lblEmail = new JLabel("E-mail:");
        lblEmail.setFont(new Font("Tahoma", Font.PLAIN, 11));
        lblEmail.setBounds(48, 223, 32, 14);
        panel.add(lblEmail);

        textFieldEmail = new JTextField();
        textFieldEmail.setBounds(89, 220, 376, 20);
        panel.add(textFieldEmail);
        textFieldEmail.setColumns(10);
        
        JButton btnFinalizar = new JButton("Concluir");
        btnFinalizar.setBounds(415, 327, 89, 23);
        panel.add(btnFinalizar);
        
        TrataBotaoClienteCad trataBotao = new TrataBotaoClienteCad(btnFinalizar, this);
		btnFinalizar.addActionListener(trataBotao);
        // Aqui estão os métodos getNome(), getLog(), etc.
    }
    
    
    // Métodos getter para obter os valores dos campos de texto
    public String getNome() {
        return textFieldNome.getText();
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

    public String getEmail() {
        return textFieldEmail.getText();
    }

    public String getCid() {
        return textFieldCid.getText();
    }

    public String getCep() {
        return textFieldCep.getText();
    }

    public String getCpf() {
        return textFieldCpf.getText();
    }
 
}