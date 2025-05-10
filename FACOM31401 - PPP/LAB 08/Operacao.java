public class Operacao extends ExpressaoAritmetica {
   private ExpressaoAritmetica op1;
   private ExpressaoAritmetica op2;
   private char operador;

   public Operacao(ExpressaoAritmetica op1, char operador, ExpressaoAritmetica op2) {
       this.op1 = op1;
       this.op2 = op2;
       this.operador = operador;
   }

   @Override
   public int getResultado() throws IllegalArgumentException  {
       switch (operador) {
           case '+': return op1.getResultado() + op2.getResultado();
           case '-': return op1.getResultado() - op2.getResultado();
           case '*': return op1.getResultado() * op2.getResultado();
           case '/': return op1.getResultado() / op2.getResultado();
           default: throw new IllegalArgumentException("Não é um operador válido.");
   }}

   @Override
   public String toString() {
       return "(" + op1 + " " + operador + " " + op2 + ")";
   }
}
