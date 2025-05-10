package RefactoringManual.EX01;

import java.util.*;

public class Pedido {
    private String cliente;
    private List<Double> itens;

    public Pedido(String cliente, List<Double> itens) {
        this.cliente = cliente;
        this.itens = itens;
    }

    // Cálculo do subtotal
    public double calcularSubtotal() {
        double subtotal = 0;
        for(double item : itens) {
            subtotal += item;
        }
        return subtotal;
    }

    // Cálculo do desconto
    public double calcularDesconto() {
        double desconto = 0;
        if(calcularSubtotal() > 100) {
            desconto = calcularSubtotal() * 0.1;
        }
        return desconto;
    }

    // Cálculo do imposto
    public double calcularImposto() {
        double imposto = (calcularSubtotal() - calcularDesconto()) * 0.08;
        return imposto;
    }

    // Cálculo do total final
    public double calcularTotalFinal() {
        double total = calcularSubtotal() - calcularDesconto() + calcularImposto();
        return total;
    }

    public void processarPedido() {
        System.out.println("Processando pedido para o cliente: " + cliente);
        System.out.println("Subtotal: R$" + calcularSubtotal());
        System.out.println("Desconto: R$" + calcularDesconto());
        System.out.println("Imposto: R$" + calcularDesconto());
        System.out.println("Total: R$" + calcularTotalFinal());
    }
}
