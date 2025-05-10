package nonvisitor;

public class TwoElement implements NumberElement {
   int a;
   int b;

   public TwoElement(int a, int b) {
       this.a = a;
       this.b = b;
   }

   @Override
   public int sum() {
       int sum = a + b;
       return sum;
   }
}
