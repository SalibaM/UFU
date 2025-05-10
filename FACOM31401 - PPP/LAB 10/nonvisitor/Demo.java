package nonvisitor;

public class Demo {
   public static void main(String[] args) {
       TwoElement two1 = new TwoElement(3, 3);
       TwoElement two2 = new TwoElement(2, 7);
       ThreeElement three1 = new ThreeElement(3, 4, 5);

       System.out.println("Soma:");
       System.out.println(two1.a + "+" + two1.b + "=" + two1.sum());
       System.out.println(two2.a + "+" + two2.b + "=" + two2.sum());
       System.out.println(three1.a + "+" + three1.b + "+" + three1.c + "=" + three1.sum());

  
       int totalSum = 0;
       totalSum += two1.sum();
       totalSum += two2.sum();
       totalSum += three1.sum();
       System.out.println("\nSoma total: " + totalSum);
   }
}
