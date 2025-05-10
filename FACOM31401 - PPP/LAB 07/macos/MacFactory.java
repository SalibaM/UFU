package macos;
import biblioteca.*;

public class MacFactory implements GUIFactory {
   public Button createButton() { return new MacButton(); }
   public Checkbox createCheckbox() { return new MacCheckbox(); }
   public Scrollbar createScrollbar() { return new MacScrollbar(); }
}
