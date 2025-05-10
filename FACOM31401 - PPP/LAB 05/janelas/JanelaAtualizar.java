package janelas;
import classes.Produto;
import database.*;
import javax.swing.*;
import java.awt.event.*;
import java.sql.*;
import java.awt.*;

public class JanelaAtualizar extends JFrame {
   public JanelaAtualizar() {
       this.setTitle("Atualizar Produto");
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

       JLabel labelId = new JLabel("ID: ");
       JTextField textId = new JTextField(10);

       JPanel panelId = new JPanel();
       panelId.add(labelId);
       panelId.add(textId);

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

       JButton botaoAtualizar = new JButton("Atualizar produto");
       botaoAtualizar.addActionListener(new ActionListener() {
           @Override
           public void actionPerformed(ActionEvent e) {
               int idAlvo;
               try {
                   idAlvo = Integer.parseInt(textId.getText());
               } catch (NumberFormatException ex) {
                   JOptionPane.showMessageDialog(null, "ID inválido.");
                   return;
               }

               Produto produto = new Produto(
                       idAlvo,
                       textNome.getText(),
                       textDescricao.getText(),
                       Double.parseDouble(textPreco.getText()),
                       Integer.parseInt(textQuantidade.getText())
               );

               Connection conexao = Conexao.abrirConexao();
               if (conexao == null) {
                   throw new RuntimeException("Erro ao conectar com o banco de dados.");
               }

               ProdutoDAO produtoDAO = new ProdutoDAO(conexao);
               try {
                   produtoDAO.atualizarProduto(produto);
                   JOptionPane.showMessageDialog(null, "Produto " + produto.getId() + " atualizado com sucesso.");
               } catch (SQLException sqle) {
                   JOptionPane.showMessageDialog(null, "Erro ao atualizar o produto.");
               } finally {
                   Conexao.fecharConexao();
               }
       }});

       JPanel panelBotao = new JPanel();
       panelBotao.add(botaoAtualizar);
       JPanel panelPrincipal = new JPanel(new BorderLayout());
       panelPrincipal.add(panelId, BorderLayout.PAGE_START);
       panelPrincipal.add(panelInfo, BorderLayout.CENTER);
       panelPrincipal.add(panelBotao, BorderLayout.PAGE_END);

       this.getContentPane().add(panelPrincipal);
       this.setVisible(true);
}}
