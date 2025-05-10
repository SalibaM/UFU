package janelas;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class JanelaPrincipal extends JFrame {
   public JanelaPrincipal() {
       this.setTitle("Produtos");
       this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
       this.setSize(550, 150);
       this.setResizable(false);
       this.setLocationRelativeTo(null);

       JButton botaoAdicionar = new JButton("Adicionar");
       botaoAdicionar.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               setVisible(false);
               dispose();
               new JanelaAdicionar();
       }});
       JButton botaoVisualizar = new JButton("Visualizar");
       botaoVisualizar.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               setVisible(false);
               dispose();
               new JanelaVisualizar();
       }});
       JButton botaoAtualizar = new JButton("Atualizar");
       botaoAtualizar.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               setVisible(false);
               dispose();
               new JanelaAtualizar();
       }});
       JButton botaoDeletar = new JButton("Deletar");
       botaoDeletar.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               setVisible(false);
               dispose();
               new JanelaDeletar();
       }});
       JButton botaoEstoque = new JButton("Estoque");
       botaoEstoque.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               setVisible(false);
               dispose();
               new JanelaEstoque();
       }});

       JPanel panelBotao = new JPanel();
       panelBotao.add(botaoAdicionar);
       panelBotao.add(botaoVisualizar);
       panelBotao.add(botaoAtualizar);
       panelBotao.add(botaoDeletar);
       panelBotao.add(botaoEstoque);

       JLabel labelTitulo = new JLabel("Boas-vindas ao JDBC de Produtos!");
       JPanel panelTexto = new JPanel();
       panelTexto.add(labelTitulo);

       JPanel panelPrincipal = new JPanel(new BorderLayout());
       panelPrincipal.add(panelTexto, BorderLayout.PAGE_START);
       panelPrincipal.add(panelBotao, BorderLayout.PAGE_END);

       this.getContentPane().add(panelPrincipal);
       this.setVisible(true);
   }
   public static void main(String[] args) {
       new JanelaPrincipal();
   }
}
