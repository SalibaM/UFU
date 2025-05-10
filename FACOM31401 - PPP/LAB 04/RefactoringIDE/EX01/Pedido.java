package RefactoringIDE.EX01;

import java.util.*;

public class Pedido {
    private String cliente;
    private List<Double> itens;

    public Pedido(String cliente, List<Double> itens) {
        this.cliente = cliente;
        this.itens = itens;
    }

    public void processarPedido() {
        System.out.println("Processando pedido para o cliente: " + cliente);
        double subtotal = getSubtotal();
        double desconto = getDesconto(subtotal);
        double imposto = getImposto(subtotal, desconto);
        double total = getTotal(subtotal, desconto, imposto);
        // Exibição do recibo
        System.out.println("Subtotal: R$" + subtotal);
        System.out.println("Desconto: R$" + desconto);
        System.out.println("Imposto: R$" + imposto);
        System.out.println("Total: R$" + total);

    }

    private double getSubtotal() {
        // Cálculo do subtotal
        double subtotal = 0;
        for (double item : itens) {
            subtotal += item;
        }
        return subtotal;
    }

    private static double getDesconto(double subtotal) {
        // Cálculo do desconto
        double desconto = 0;
        if (subtotal > 100) {
            desconto = subtotal * 0.1;
        }
        return desconto;
    }

    private static double getImposto(double subtotal, double desconto) {
        // Cálculo do imposto
        double imposto = (subtotal - desconto) * 0.08;
        return imposto;
    }

    private static double getTotal(double subtotal, double desconto, double imposto) {
        // Cálculo do total final
        double total = subtotal - desconto + imposto;
        return total;
    }
}
