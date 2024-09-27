package janelas;

import tratadores.TrataBotaoCompanhiaAerea;
import tratadores.TrataBotaoTrecho;
import tratadores.TrataBotaoVoo;

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

public class JanelaCompanhiaAerea extends JFrame {
    public JanelaCompanhiaAerea() {
    	setMinimumSize(new Dimension(530, 400));

        JPanel panel = new JPanel();
        getContentPane().add(panel, BorderLayout.CENTER);
        panel.setLayout(null);

        JLabel lblMenu = new JLabel("Menu da Companhia Aérea");
        lblMenu.setFont(new Font("Tahoma", Font.PLAIN, 20));
        lblMenu.setHorizontalAlignment(SwingConstants.CENTER);
        lblMenu.setBounds(10, 63, 494, 58);
        panel.add(lblMenu);

        // para acessar o cadastro da companhia aérea
        JButton btnCadCompanhiaAerea = new JButton("Companhia Aérea");
        btnCadCompanhiaAerea.setBounds(189, 132, 140, 23);
        panel.add(btnCadCompanhiaAerea);
        btnCadCompanhiaAerea.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                abrirJanelaCompanhiaAereaCad();
            }
        });

        // para acessar o cadastro do trecho
        JButton btnCadTrecho = new JButton("Trecho");
        btnCadTrecho.setBounds(189, 166, 140, 23);
        panel.add(btnCadTrecho);
        btnCadTrecho.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                abrirJanelaTrecho();
            }
        });

        // para acessar o cadastro do voo
        JButton btnCadVoo = new JButton("Voo");
        btnCadVoo.setBounds(189, 200, 140, 23);
        panel.add(btnCadVoo);
        btnCadVoo.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                abrirJanelaVoo();
            }
        });
    }

    private void abrirJanelaCompanhiaAereaCad() {
        JanelaCompanhiaAereaCad janelaCompanhiaAereaCad = new JanelaCompanhiaAereaCad();
        janelaCompanhiaAereaCad.setVisible(true);
    }

    private void abrirJanelaTrecho() {
        JanelaTrecho janelaTrecho = new JanelaTrecho();
        janelaTrecho.setVisible(true);
    }

    private void abrirJanelaVoo() {
        JanelaVoo janelaVoo = new JanelaVoo();
        janelaVoo.setVisible(true);
    }
}