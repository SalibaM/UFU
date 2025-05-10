package nonvisitor;

public class ThreeElement implements NumberElement {
   int a;
   int b;
   int c;

   public ThreeElement(int a, int b, int c) {
       this.a = a;
       this.b = b;
       this.c = c;
   }

   @Override
   public int sum() {
       int sum = a + b + c;
       return sum;
   }
}
