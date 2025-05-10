package janelas;
import database.*;
import javax.swing.*;
import java.awt.event.*;
import java.awt.*;
import java.sql.*;

public class JanelaDeletar extends JFrame {
   public JanelaDeletar() {
       this.setTitle("Deletar Produto");
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
           }
       });

       JLabel labelId = new JLabel("ID: ");
       JTextField textId = new JTextField(10);

       JPanel panelInfo = new JPanel();
       panelInfo.add(labelId);
       panelInfo.add(textId);

       JButton botaoDeletar = new JButton("Deletar produto");
       botaoDeletar.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               Connection conexao = Conexao.abrirConexao();

               if (conexao == null) {
                   throw new RuntimeException("Erro ao conectar com o banco de dados.");
               }

               ProdutoDAO produtosDAO = new ProdutoDAO(conexao);

               try {
                   produtosDAO.removerProduto(Integer.parseInt(textId.getText()));
                   JOptionPane.showMessageDialog(null, "Produto " + Integer.parseInt(textId.getText()) + " deletado com sucesso.");
               } catch (SQLException ex) {
                   JOptionPane.showMessageDialog(null, "Erro ao deletar o produto.");
               } finally {
                   Conexao.fecharConexao();
               }
           }});

       JPanel panelBotao = new JPanel();
       panelBotao.add(botaoDeletar);

       JPanel panelPrincipal = new JPanel(new BorderLayout());
       panelPrincipal.add(panelInfo, BorderLayout.CENTER);
       panelPrincipal.add(panelBotao, BorderLayout.PAGE_END);

       this.getContentPane().add(panelPrincipal);
       this.setVisible(true);
   }
}
