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

public class JanelaQuarto extends JFrame {
    public JanelaQuarto() {
    	setMinimumSize(new Dimension(530, 400));
        JPanel panel = new JPanel();
        getContentPane().add(panel, BorderLayout.CENTER);
        panel.setLayout(null);
        
        JLabel lblMenu = new JLabel("Menu do Quarto");
        lblMenu.setFont(new Font("Tahoma", Font.PLAIN, 20));
        lblMenu.setHorizontalAlignment(SwingConstants.CENTER);
        lblMenu.setBounds(10, 94, 494, 33);
        panel.add(lblMenu);
        
        JanelaQuartoCad janelaQuartoCad = new JanelaQuartoCad();
        
        JButton btnCadastrar = new JButton("Cadastrar");
        
        // Adicione um ouvinte de ação ao botão "Cadastrar"
        btnCadastrar.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // Criar e exibir a janela JanelaQuartoCad
                JanelaQuartoCad janelaQuartoCad = new JanelaQuartoCad();
                janelaQuartoCad.setVisible(true);
            }
        });
        
        btnCadastrar.setBounds(189, 158, 140, 23);
        panel.add(btnCadastrar);
    }
}