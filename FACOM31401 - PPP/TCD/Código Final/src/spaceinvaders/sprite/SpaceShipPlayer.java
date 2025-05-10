package spaceinvaders.sprite;

import spaceinvaders.Commons;

import javax.swing.*;
import java.awt.event.KeyEvent;

// nova classe player, com implementação própria para space invaders
public class SpaceShipPlayer extends spriteframework.sprite.Player {
    public SpaceShipPlayer() {
        super();
        loadImage();
        getImageDimensions();
        resetState();
    }

    @Override
    public void checkBoundsX(){
        super.checkBoundsX();
        if (x >= Commons.BOARD_WIDTH - 2 * width)
            x = Commons.BOARD_WIDTH - 2 * width;
    }

    @Override
    protected void loadImage() {
        ImageIcon playerImg = new ImageIcon(this.getClass().getResource("/spaceinvaders/images/player.png"));
        width = playerImg.getImage().getWidth(null);
        setImage(playerImg.getImage());
    }

    @Override
    public void keyPressed(KeyEvent e) {
        int key = e.getKeyCode();

        if (key == KeyEvent.VK_LEFT) {
            dx = -2;
        }

        if (key == KeyEvent.VK_RIGHT) {
            dx = 2;
        }
    }

    public void keyReleased(KeyEvent e) {
        int key = e.getKeyCode();

        if (key == KeyEvent.VK_LEFT) {
            dx = 0;
        }

        if (key == KeyEvent.VK_RIGHT) {
            dx = 0;
        }
    }

    @Override
    protected void resetState() {
        setX(Commons.BOARD_WIDTH / 2);
        setY(Commons.BOARD_HEIGHT - 100);
        setX(Commons.INIT_PLAYER_X);
        setY(Commons.INIT_PLAYER_Y);
    }
}
