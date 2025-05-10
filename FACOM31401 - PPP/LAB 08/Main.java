public class Main {
   public static void main(String[] args) {

       // a) 0
       ExpressaoAritmetica e1 = new Numero(0);
       System.out.println("Expressão: " + e1.toString());
       System.out.println("Resultado: " + e1.getResultado());

       // b) 1 + 2
       ExpressaoAritmetica e2 = new Operacao(new Numero(1), '+', new Numero(2));
       System.out.println("Expressão: " + e2.toString());
       System.out.println("Resultado: " + e2.getResultado());

       // c) 1 * (2 + 3)
       ExpressaoAritmetica e3 = new Operacao(new Numero(1), '*', new Operacao(new Numero(2), '+', new Numero(3)));
       System.out.println("Expressão: " + e3.toString());
       System.out.println("Resultado: " + e3.getResultado());

       // d) (2 * 3) + (4 / (5 - 3))
       ExpressaoAritmetica e4 = new Operacao(new Operacao(new Numero(2), '*', new Numero(3)), '+', new Operacao(new Numero(4), '/', new Operacao(new Numero(5), '-', new Numero(3))));
       System.out.println("Expressão: " + e4.toString());
       System.out.println("Resultado: " + e4.getResultado());

}}
