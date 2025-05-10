package janelas;
import database.*;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class JanelaEstoque extends JFrame {
   public JanelaEstoque() {
       this.setTitle("Estoque");
       this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
       this.setSize(550, 150);
       this.setResizable(false);
       this.setLocationRelativeTo(null);

       this.addWindowListener(new WindowAdapter() {
           @Override
           public void windowClosing(WindowEvent e) {
               setVisible(false);
               dispose();
               new JanelaPrincipal();
       }});

       JLabel labelId = new JLabel("ID: ");
       JLabel labelQuantidade = new JLabel("Quantidade: ");

       JTextField textId = new JTextField(10);
       JTextField textQuantidade = new JTextField(10);

       JPanel panelInfo = new JPanel();
       panelInfo.add(labelId);
       panelInfo.add(textId);
       panelInfo.add(labelQuantidade);
       panelInfo.add(textQuantidade);

       JButton botaoComprar = new JButton("Comprar");
       botaoComprar.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               Connection conexao = Conexao.abrirConexao();
               if (conexao == null) {
                   throw new RuntimeException("Erro ao conectar com o banco de dados.");
               }

               ProdutoDAO produtoDAO = new ProdutoDAO(conexao);
               try {
                   produtoDAO.aumentarEstoque(Integer.parseInt(textId.getText()), Integer.parseInt(textQuantidade.getText()));
                   JOptionPane.showMessageDialog(null, "Estoque atualizado com sucesso.");
               } catch (SQLException sqle) {
                   JOptionPane.showMessageDialog(null, "Erro ao atualizar o estoque.");
               } finally {
                   Conexao.fecharConexao();
               }
       }});

       JButton botaoVender = new JButton("Vender");
       botaoVender.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               Connection conexao = Conexao.abrirConexao();
               if (conexao == null) {
                   throw new RuntimeException("Erro ao conectar com o banco de dados.");
               }

               ProdutoDAO produtoDAO = new ProdutoDAO(conexao);
               try {
                   produtoDAO.diminuirEstoque(Integer.parseInt(textId.getText()), Integer.parseInt(textQuantidade.getText()));
                   JOptionPane.showMessageDialog(null, "Estoque atualizado com sucesso.");
               } catch (SQLException sqle) {
                   JOptionPane.showMessageDialog(null, "Erro ao atualizar o estoque.");
               } finally {
                   Conexao.fecharConexao();
               }
       }});

       JPanel panelBotao = new JPanel();
       panelBotao.add(botaoComprar);
       panelBotao.add(botaoVender);

       JPanel panelPrincipal = new JPanel(new BorderLayout());
       panelPrincipal.add(panelInfo, BorderLayout.PAGE_START);
       panelPrincipal.add(panelBotao, BorderLayout.PAGE_END);

       this.getContentPane().add(panelPrincipal);
       this.setVisible(true);
   }
}
