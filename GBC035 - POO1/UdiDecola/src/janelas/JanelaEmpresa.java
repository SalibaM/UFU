package janelas;

import javax.swing.JButton;
import javax.swing.JFrame;
import javax.swing.JLabel;
import javax.swing.JPanel;
import javax.swing.SwingConstants;
import java.awt.BorderLayout;
import java.awt.Font;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

public class JanelaEmpresa extends JFrame {

    public JanelaEmpresa() {
        JPanel panel = new JPanel();
        getContentPane().add(panel, BorderLayout.CENTER);
        panel.setLayout(null);

        JLabel lblMenu = new JLabel("Menu de Empresas");
        lblMenu.setFont(new Font("Tahoma", Font.PLAIN, 20));
        lblMenu.setHorizontalAlignment(SwingConstants.CENTER);
        lblMenu.setBounds(10, 74, 494, 47);
        panel.add(lblMenu);

        JButton btnHotel = new JButton("Hotel");
        btnHotel.setBounds(189, 143, 140, 23);
        panel.add(btnHotel);
        btnHotel.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                abrirJanelaHotel();
            }
        });

        JButton btnCompAerea = new JButton("Companhia Aérea");
        btnCompAerea.setBounds(189, 178, 140, 23);
        panel.add(btnCompAerea);
        btnCompAerea.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                abrirJanelaCompanhiaAerea();
            }
        });
    }

    private void abrirJanelaHotel() {
        JanelaHotel janelaHotel = new JanelaHotel();
        janelaHotel.setVisible(true);
    }

    private void abrirJanelaCompanhiaAerea() {
        JanelaCompanhiaAerea janelaCompanhiaAerea = new JanelaCompanhiaAerea();
        janelaCompanhiaAerea.setVisible(true);
    }
}