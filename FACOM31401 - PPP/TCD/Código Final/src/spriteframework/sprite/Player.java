package spriteframework.sprite;

import javax.swing.ImageIcon;

import spriteframework.Commons;
import java.awt.Image;
import java.awt.event.KeyEvent;

// classe abstrata
public abstract class Player extends Sprite {
    protected int width;

    public Player() {
        loadImage();
		getImageDimensions();
		resetState();
    }

    protected abstract void loadImage();

    // template method para movimento
    public final void act() {
        moveX();  // Movimento em X (comum a todos)
        moveY();  // Movimento em Y (implementação específica)
        checkBounds();
    }

    private void moveX() {
        x += dx;
    }

    // método hook para Y (subclasses implementam se necessário)
    protected void moveY() {
        // Default: não faz nada (para naves que só se movem em X)
    }

    public final void checkBounds() {
        checkBoundsX();
        checkBoundsY();
    }

    public void checkBoundsX(){
        if (x <= 2)
            x = 2;
    }

    //método hook para Y
    protected void checkBoundsY(){
    }

    public void keyPressed(KeyEvent e) {
        int key = e.getKeyCode();
        if (key == KeyEvent.VK_LEFT)  dx = -2;
        if (key == KeyEvent.VK_RIGHT) dx = 2;
        // Teclas para Y são tratadas nas subclasses
    }

    public void keyReleased(KeyEvent e) {
        int key = e.getKeyCode();
        if (key == KeyEvent.VK_LEFT || key == KeyEvent.VK_RIGHT)
            dx = 0;
        // Teclas para Y são tratadas nas subclasses
    }

    protected void resetState() {
        setVisible(true);
    }
}
