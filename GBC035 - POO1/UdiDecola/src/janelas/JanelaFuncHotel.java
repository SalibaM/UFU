package janelas;

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

public class JanelaFuncHotel extends JFrame {
    public JanelaFuncHotel() {
    	setMinimumSize(new Dimension(530, 400));
    	
        JPanel panel = new JPanel();
        getContentPane().add(panel, BorderLayout.CENTER);
        panel.setLayout(null);
        
        JLabel lblMenu = new JLabel("Menu do Funcionário Hotel");
        lblMenu.setFont(new Font("Tahoma", Font.PLAIN, 20));
        lblMenu.setHorizontalAlignment(SwingConstants.CENTER);
        lblMenu.setBounds(10, 94, 494, 33);
        panel.add(lblMenu);
        
        JButton btnCadastrar = new JButton("Cadastrar");
        btnCadastrar.setBounds(189, 158, 140, 23);
        panel.add(btnCadastrar);
        
        btnCadastrar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                JanelaFuncHotelCad janelaFuncHotelCad = new JanelaFuncHotelCad();
                janelaFuncHotelCad.setVisible(true);
            }
        });
    }
}