package application;
import biblioteca.*;

public class Application {
   private Button button;
   private Checkbox checkbox;
   private Scrollbar scrollbar;

   public Application(GUIFactory gui) {
       button = gui.createButton();
       checkbox = gui.createCheckbox();
       scrollbar = gui.createScrollbar();
   }

   public void renderUI() {
       button.paint();
       checkbox.paint();
       scrollbar.paint();
   }
}
