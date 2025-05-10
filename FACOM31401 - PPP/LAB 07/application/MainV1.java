package application;
import biblioteca.GUIFactory;
import windows.WinFactory;
import macos.MacFactory;

public class MainV1 {
   public static void main(String[] args) {
       GUIFactory factory;

       String os = System.getProperty("os.name").toLowerCase();
       if(os.contains("win")) {
           factory = new WinFactory();
       } else {
           factory = new MacFactory();
       }

       Application app = new Application(factory);
       app.renderUI();
   }
}
