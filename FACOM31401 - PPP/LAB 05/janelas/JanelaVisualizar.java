package janelas;
import classes.Produto;
import database.*;
import javax.swing.*;
import javax.swing.table.*;
import java.awt.event.*;
import java.awt.*;
import java.sql.*;
import java.util.List;

public class JanelaVisualizar extends JFrame {
   DefaultTableModel tabelaModelo;
   public JanelaVisualizar() {
       this.setTitle("Visualizar Produto");
       this.setDefaultCloseOperation(JFrame.DO_NOTHING_ON_CLOSE);
       this.setSize(550, 550);
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

       tabelaModelo = new DefaultTableModel();
       tabelaModelo.addColumn("ID");
       tabelaModelo.addColumn("Nome");
       tabelaModelo.addColumn("Descrição");
       tabelaModelo.addColumn("Preço");
       tabelaModelo.addColumn("Quantidade");

       JTable tabela = new JTable(tabelaModelo);
       JScrollPane scrollPane = new JScrollPane(tabela);
       add(scrollPane, BorderLayout.CENTER);

       listarProdutos();
       this.setVisible(true);
   }

   private void listarProdutos() {
       tabelaModelo.setRowCount(0);

       try (Connection conn = Conexao.abrirConexao()) {
           ProdutoDAO produtoDAO = new ProdutoDAO(conn);
           List<Produto> produtos = produtoDAO.selecionarProdutos();
           if(produtos == null) {
               JOptionPane.showMessageDialog(null, "Não há produtos cadastrados.");
           } else {
               for (Produto produto : produtos) {
                   tabelaModelo.addRow(new Object[]{
                           produto.getId(), produto.getNome(), produto.getDescricao(), produto.getPreco(), produto.getQuantidade()
                   });
               }
           }
       } catch (SQLException e) {
           JOptionPane.showMessageDialog(this, "Erro ao listar os produtos.");
       }
   }
}
