package linux;
import biblioteca.*;

public class LinFactory implements GUIFactory {
   public Button createButton() { return new LinButton(); }
   public Checkbox createCheckbox() { return new LinCheckbox(); }
   public Scrollbar createScrollbar() { return new LinScrollbar(); }
}
