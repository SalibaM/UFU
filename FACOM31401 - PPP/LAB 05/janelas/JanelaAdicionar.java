package janelas;
import database.*;
import classes.Produto;
import javax.swing.*;
import java.awt.*;
import java.awt.event.*;
import java.sql.*;

public class JanelaAdicionar extends JFrame {
   public JanelaAdicionar() {
       this.setTitle("Adicionar Produto");
       this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
       this.setSize(550, 250);
       this.setResizable(false);
       this.setLocationRelativeTo(null);

       this.addWindowListener(new WindowAdapter() {
           @Override
           public void windowClosing(WindowEvent e) {
               setVisible(false);
               dispose();
               new JanelaPrincipal();
       }});

       JLabel labelNome = new JLabel("Nome: ");
       JLabel labelDescricao = new JLabel("Descrição: ");
       JLabel labelPreco = new JLabel("Preço: ");
       JLabel labelQuantidade = new JLabel("Quantidade: ");

       JTextField textNome = new JTextField(40);
       JTextField textDescricao = new JTextField(40);
       JTextField textPreco = new JTextField(10);
       JTextField textQuantidade = new JTextField(10);

       JPanel panelInfo = new JPanel();
       panelInfo.add(labelNome);
       panelInfo.add(textNome);
       panelInfo.add(labelDescricao);
       panelInfo.add(textDescricao);
       panelInfo.add(labelPreco);
       panelInfo.add(textPreco);
       panelInfo.add(labelQuantidade);
       panelInfo.add(textQuantidade);

       JButton botaoAdicionar = new JButton("Adicionar produto");
       botaoAdicionar.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               Connection conexao = Conexao.abrirConexao();
               if (conexao == null) {
                   throw new RuntimeException("Erro ao conectar com o banco de dados.");
               }

               ProdutoDAO produtoDAO = new ProdutoDAO(conexao);
               Produto produto = new Produto(
                       0, textNome.getText(),
                       textDescricao.getText(),
                       Double.parseDouble(textPreco.getText()),
                       Integer.parseInt(textQuantidade.getText()));

               try {
                   int novoId = produtoDAO.inserirProduto(produto);
                   if(novoId != -1) {
                       produto.setId(novoId);
                       JOptionPane.showMessageDialog(null, "Produto " + produto.getId() + " adicionado com sucesso.");
                       textNome.setText("");
                       textDescricao.setText("");
                       textPreco.setText("");
                       textQuantidade.setText("");
                   }
               } catch (SQLException sqle) {
                   JOptionPane.showMessageDialog(null, "Erro ao adicionar o produto.");
               } finally {
                   Conexao.fecharConexao();
               }
       }});

       JPanel panelBotao = new JPanel();
       panelBotao.add(botaoAdicionar);

       JPanel panelPrincipal = new JPanel(new BorderLayout());
       panelPrincipal.add(panelInfo, BorderLayout.CENTER);
       panelPrincipal.add(panelBotao, BorderLayout.PAGE_END);

       this.getContentPane().add(panelPrincipal);
       this.setVisible(true);
   }
}
