package visitor;
import java.util.List;

public class TotalMultVisitor implements NumberVisitor {
   int totalMult = 0;

   @Override
   public void visit(TwoElement twoElement) {
       int mult = twoElement.a * twoElement.b;
       System.out.println("Adding " + twoElement.a + "*" + twoElement.b + "=" + mult + " to total");
       totalMult += mult;
   }

   @Override
   public void visit(ThreeElement threeElement) {
       int mult = threeElement.a * threeElement.b * threeElement.c;
       System.out.println("Adding " + threeElement.a + "*" + threeElement.b + "*" + threeElement.c + "=" + mult + " to total");
       totalMult += mult;
   }

   @Override
   public void visit(List<NumberElement> elementList) {
       for(NumberElement ne : elementList) {
           ne.accept(this);
       }
   }

   public int getTotalMult() {
       return totalMult;
   }
}
