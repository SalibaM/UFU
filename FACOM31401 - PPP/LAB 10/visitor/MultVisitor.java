package visitor;
import java.util.List;

public class MultVisitor implements NumberVisitor {
   @Override
   public void visit(TwoElement twoElement) {
       int mult = twoElement.a * twoElement.b;
       System.out.println(twoElement.a + "*" + twoElement.b + "=" + mult);
   }

   @Override
   public void visit(ThreeElement threeElement) {
       int mult = threeElement.a * threeElement.b * threeElement.c;
       System.out.println(threeElement.a + "*" + threeElement.b + "*" + threeElement.c + "=" + mult);
   }

   @Override
   public void visit(List<NumberElement> elementList) {
       for(NumberElement ne : elementList) {
           ne.accept(this);
       }
   }
}
