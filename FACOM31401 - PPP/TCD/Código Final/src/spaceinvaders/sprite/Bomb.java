package spaceinvaders.sprite;

import spriteframework.sprite.BadSprite;

import javax.swing.ImageIcon;

public class Bomb extends BadSprite {
    private boolean destroyed;

    public Bomb(int x, int y) {
        initBomb(x, y);
    }

    private void initBomb(int x, int y) {
        setDestroyed(true);

        this.x = x;
        this.y = y;

        ImageIcon bombImg = new ImageIcon(this.getClass().getResource("/spaceinvaders/images/bomb.png"));
        setImage(bombImg.getImage());
    }

    public void setDestroyed(boolean destroyed) {
        this.destroyed = destroyed;
    }

    @Override
    public boolean isDestroyed() {
        return destroyed;
    }
}
