package janelas;

import tratadores.TrataBotaoFuncionario;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JButton;
import javax.swing.SwingConstants;
import javax.swing.JLabel;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JanelaFuncionario extends JFrame {
    public JanelaFuncionario() {
    	setMinimumSize(new Dimension(530, 400));
    	
        JPanel panel = new JPanel();
        getContentPane().add(panel, BorderLayout.CENTER);
        panel.setLayout(null);
        
        JLabel lblMenu = new JLabel("Menu do Funcionario");
        lblMenu.setBounds(2, 94, 509, 58);
        lblMenu.setFont(new Font("Tahoma", Font.PLAIN, 20));
        lblMenu.setHorizontalAlignment(SwingConstants.CENTER);
        panel.add(lblMenu);
        
        JanelaFuncionarioCad janelaFuncionarioCad = new JanelaFuncionarioCad();
        
        // para acessar o cadastro do funcionário
        JButton btnCadFunc = new JButton("Padrão");
        btnCadFunc.setBounds(189, 158, 140, 23);
        
        TrataBotaoFuncionario tratador = new TrataBotaoFuncionario(btnCadFunc, janelaFuncionarioCad, this);
        btnCadFunc.addActionListener(tratador);
        btnCadFunc.addActionListener(tratador);
        panel.add(btnCadFunc);
        
        // para acessar o cadastro do funcionário hotel
        JButton btnCadFuncHotel = new JButton("Hotel");
        btnCadFuncHotel.setBounds(189, 192, 140, 23);
        panel.add(btnCadFuncHotel);
        
        // Adicione um ouvinte de ação ao botão "Hotel"
        btnCadFuncHotel.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // Criar e exibir a janela JanelaFuncHotel
                JanelaFuncHotel janelaFuncHotel = new JanelaFuncHotel();
                janelaFuncHotel.setVisible(true);
            }
        });
    }
}