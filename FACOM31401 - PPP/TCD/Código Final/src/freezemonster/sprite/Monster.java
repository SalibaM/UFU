package freezemonster.sprite;

import freezemonster.Commons;
import spriteframework.sprite.BadSprite;
import spriteframework.sprite.BadnessBoxSprite;

import java.awt.*;
import java.util.LinkedList;
import java.util.Random;
import javax.swing.ImageIcon;

public class Monster extends BadnessBoxSprite {
    private Gosma gosma;
    private ImageIcon congeladoImg;
    private Random rand = new Random();

    public Monster(int x, int y) {
        initMonster(x, y);
        getImageDimensions();
    }

    private void initMonster(int x, int y) {
        this.x = x;
        this.y = y;

        dx = rand.nextInt(2) - 1; // Valores: -1, 0 ou 1
        dy = rand.nextInt(2) - 1; // Valores: -1, 0 ou 1

        if (dx == 0 && dy == 0) {
            //garante que vai andar para alguma direção
            dx = 1;
        }

        // Define os caminhos das imagens
        int monsterType = rand.nextInt(9) + 1;
        String monsterPath = String.format("/freezemonster/images/monster%d.png", monsterType);
        String congeladoPath = String.format("/freezemonster/images/monster%dbg.png", monsterType);

        ImageIcon imgM = new ImageIcon(this.getClass().getResource(monsterPath));
        Image monsterImg = imgM.getImage().getScaledInstance(Commons.MONSTER_WIDTH, Commons.MONSTER_HEIGHT, Image.SCALE_SMOOTH);
        setImage(monsterImg);

        ImageIcon imgC = new ImageIcon(getClass().getResource(congeladoPath));
        Image congeladoImg = imgC.getImage().getScaledInstance(Commons.MONSTER_WIDTH, Commons.MONSTER_HEIGHT, Image.SCALE_SMOOTH);
        setCongeladoImg(new ImageIcon(congeladoImg));

        this.gosma = new Gosma(x, y);
    }

    @Override
    public void die() {
        setImage(congeladoImg.getImage());
        gosma.die();
        setDying(true);
        dx = 0;
        dy = 0;
    }

    @Override
    public void act() {
        x += dx;
        y += dy;

        // Limites horizontais
        if (x <= Commons.BORDER_LEFT) {
            x = Commons.BORDER_LEFT;
            dx = -dx;
        } else if (x + getImageWidth() > Commons.BOARD_WIDTH - Commons.BORDER_RIGHT) {
            x = Commons.BOARD_WIDTH - Commons.BORDER_RIGHT - getImageWidth();
            dx = -dx;
        }

        // Limites verticais
        if (y <= Commons.BORDER_TOP) {
            y = Commons.BORDER_TOP;
            dy = -dy;
        } else if (y + getImageHeight() > Commons.BOARD_HEIGHT - Commons.BORDER_BOTTOM) {
            y = Commons.BOARD_HEIGHT - Commons.BORDER_BOTTOM - getImageHeight();
            dy = -dy;
        }
    }

    @Override
    public LinkedList<BadSprite> getBadnesses() {
        LinkedList<BadSprite> aGosma = new LinkedList<>();
        aGosma.add(gosma);
        return aGosma;
    }

    public Random getRand() {
        return rand;
    }

    public void setRand(Random rand) {
        this.rand = rand;
    }

    public ImageIcon getCongeladoImg() {
        return congeladoImg;
    }

    public void setCongeladoImg(ImageIcon congeladoImg) {
        this.congeladoImg = congeladoImg;
    }

    public Gosma getGosma() {
        return gosma;
    }

    public void setGosma(Gosma gosma) {
        this.gosma = gosma;
    }
}