package janelas;

import tratadores.TrataBotaoHotel;
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

public class JanelaHotel extends JFrame {
    public JanelaHotel() {
    	setMinimumSize(new Dimension(530, 400));
    	
        JPanel panel = new JPanel();
        getContentPane().add(panel, BorderLayout.CENTER);
        panel.setLayout(null);
        
        JLabel lblMenu = new JLabel("Menu do Hotel");
        lblMenu.setFont(new Font("Tahoma", Font.PLAIN, 20));
        lblMenu.setHorizontalAlignment(SwingConstants.CENTER);
        lblMenu.setBounds(10, 94, 494, 58);
        panel.add(lblMenu);
        
        JanelaHotelCad janelaHotelCad = new JanelaHotelCad();
        
        // para acessar o cadastro do hotel
        JButton btnCadHotel = new JButton("Hotel");
        
        TrataBotaoHotel tratador = new TrataBotaoHotel(btnCadHotel, janelaHotelCad, this);
        btnCadHotel.addActionListener(tratador);
        btnCadHotel.setBounds(189, 158, 140, 23);
        btnCadHotel.addActionListener(tratador);
        panel.add(btnCadHotel);
        
        // para acessar o cadastro do quarto
        JButton btnCadQuarto = new JButton("Quarto");
        btnCadQuarto.setBounds(189, 192, 140, 23);
        panel.add(btnCadQuarto);
        
        // Adicione um ouvinte de ação ao botão "Quarto"
        btnCadQuarto.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                // Criar e exibir a janela JanelaQuarto
                JanelaQuarto janelaQuarto = new JanelaQuarto();
                janelaQuarto.setVisible(true);
            }
        });
    }
}