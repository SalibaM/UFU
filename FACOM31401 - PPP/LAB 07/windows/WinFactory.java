package windows;
import biblioteca.*;

public class WinFactory implements GUIFactory {
   public Button createButton() { return new WinButton(); }
   public Checkbox createCheckbox() { return new WinCheckbox(); }
   public Scrollbar createScrollbar() { return new WinScrollbar(); }
}
