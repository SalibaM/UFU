package freezemonster.sprite;

import freezemonster.Commons;
import spriteframework.sprite.Player;

import java.awt.Image;
import java.awt.event.KeyEvent;
import javax.swing.ImageIcon;

public class Woody extends Player {
    private int width;
    private int direcaoWoody; // 1 = esq, 2 = dir, 3 = cima, 4 = baixo

    public Woody() {
        super();
        setVisible(true);
        loadImage();
        getImageDimensions();
        resetState();
    }

    @Override
    protected void loadImage() {
        ImageIcon img = new ImageIcon(this.getClass().getResource("/freezemonster/images/woody.png"));
        Image woodyImg = img.getImage().getScaledInstance(Commons.PLAYER_WIDTH, Commons.PLAYER_HEIGHT, Image.SCALE_SMOOTH);
        width = woodyImg.getWidth(null);
        setImage(woodyImg);
        getImageDimensions();
    }

    // hook method
    @Override
    protected void moveY() {
        y += dy;
    }

    // hook method
    @Override
    protected void checkBoundsY(){
        if (y <= Commons.BORDER_TOP)
            y = Commons.BORDER_TOP;
        if (y >= Commons.BOARD_HEIGHT - Commons.PLAYER_HEIGHT) // Use PLAYER_HEIGHT (60)
            y = Commons.BOARD_HEIGHT - Commons.PLAYER_HEIGHT;
    }

    @Override
    public void keyPressed(KeyEvent e) { 
        super.keyPressed(e);
        int key = e.getKeyCode();
        if (key == KeyEvent.VK_UP) {
            dy = -2;
            direcaoWoody = 3; // Cima
        }
        if (key == KeyEvent.VK_DOWN) {
            dy = 2;
            direcaoWoody = 4; // Baixo
        }
        if (key == KeyEvent.VK_LEFT) {
            direcaoWoody = 1; // Esquerda
        }
        if (key == KeyEvent.VK_RIGHT) {
            direcaoWoody = 2; // Direita
        }
    }

    @Override
    public void keyReleased(KeyEvent e) { 
        super.keyReleased(e);
        int key = e.getKeyCode();
        if (key == KeyEvent.VK_UP || key == KeyEvent.VK_DOWN)
            dy = 0;
    }

    @Override
    protected void resetState() {
        setX(Commons.BOARD_WIDTH / 2 - (Commons.PLAYER_WIDTH/2));
        setY(Commons.BOARD_HEIGHT - Commons.PLAYER_HEIGHT - 20);
    }

    public int getDirecaoWoody() {
        return direcaoWoody;
    }
}
