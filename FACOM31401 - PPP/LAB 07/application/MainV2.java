package application;
import biblioteca.GUIFactory;
import windows.WinFactory;
import macos.MacFactory;
import linux.LinFactory;

public class MainV2 {
   public static void main(String[] args) {
       GUIFactory factory;

       String os = System.getProperty("os.name").toLowerCase();
       if(os.contains("win")) {
           factory = new WinFactory();
       } else if(os.contains("mac")) {
           factory = new MacFactory();
       } else {
           factory = new LinFactory();
       }

       Application app = new Application(factory);
       app.renderUI();
   }
}
