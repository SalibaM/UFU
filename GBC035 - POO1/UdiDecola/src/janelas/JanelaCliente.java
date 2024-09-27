package janelas;

import tratadores.TrataBotaoCliente;
import tratadores.TrataBotaoClienteCon;
import tratadores.TrataBotaoClienteRem;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.BorderLayout;
import java.awt.Dimension;

import javax.swing.JButton;
import javax.swing.SwingConstants;
import javax.swing.JLabel;
import java.awt.Font;

public class JanelaCliente extends JFrame {
    public JanelaClienteCad janelaClienteCad;
    public JanelaClienteCon janelaClienteCon;
    public JanelaClienteRem janelaClienteRem;
    
    public JanelaCliente() {
    	setMinimumSize(new Dimension(530, 400));
        
        JPanel panel = new JPanel();
        getContentPane().add(panel, BorderLayout.CENTER);
        panel.setLayout(null);
        
        JLabel lblMenu = new JLabel("Menu do Cliente");
        lblMenu.setFont(new Font("Tahoma", Font.PLAIN, 20));
        lblMenu.setHorizontalAlignment(SwingConstants.CENTER);
        lblMenu.setBounds(10, 41, 494, 40);
        panel.add(lblMenu);
        
        janelaClienteCad = new JanelaClienteCad();
        janelaClienteCad.setSize(530,400);
        janelaClienteCon = new JanelaClienteCon();
        janelaClienteCon.setSize(530,200);
        janelaClienteRem = new JanelaClienteRem();
        janelaClienteRem.setSize(530,200);
        
        JButton btnCadastrar = new JButton("Cadastrar");
        
        TrataBotaoCliente tratador = new TrataBotaoCliente(btnCadastrar, getJanelaClienteCad(), this);
        btnCadastrar.addActionListener(tratador);
        btnCadastrar.setHorizontalAlignment(SwingConstants.CENTER);
        btnCadastrar.setBounds(189, 136, 140, 23);
        btnCadastrar.addActionListener(tratador);
        panel.add(btnCadastrar);
        // para ver se o cliente existe ou não
        // imprime os dados se existir
        // avisa ao lado do botão caso o cpf não tenha sido encontrado
        
        JButton btnConsultar = new JButton("Consultar");
        btnConsultar.setHorizontalAlignment(SwingConstants.CENTER);
        btnConsultar.setBounds(189, 170, 140, 23);
        panel.add(btnConsultar);
        
        TrataBotaoCliente tratador2 = new TrataBotaoCliente(btnConsultar, getJanelaClienteCon(), this);
        btnConsultar.addActionListener(tratador2);
        btnConsultar.setBounds(189, 170, 140, 23);
        btnConsultar.addActionListener(tratador2);
        panel.add(btnConsultar);
        
        // para remover o cliente
        // avisa ao lado do botão que o cliente foi removido (cpf encontrado)
        // avisa ao lado do botão que o cliente não existe (cpf não encontrado)
        JButton btnRemover = new JButton("Remover");
        btnRemover.setHorizontalAlignment(SwingConstants.CENTER);
        btnRemover.setBounds(189, 204, 140, 23);
        panel.add(btnRemover);
        
        TrataBotaoCliente tratador3 = new TrataBotaoCliente(btnRemover, getJanelaClienteRem(), this);
        btnRemover.addActionListener(tratador3);
        btnRemover.setBounds(189, 204, 140, 23);
        btnRemover.addActionListener(tratador3);
        panel.add(btnRemover);
    }

    public JanelaClienteCad getJanelaClienteCad() {
        return janelaClienteCad;
    }

    public JanelaClienteCon getJanelaClienteCon() {
        return janelaClienteCon;
    }

    public JanelaClienteRem getJanelaClienteRem() {
        return janelaClienteRem;
    }
}