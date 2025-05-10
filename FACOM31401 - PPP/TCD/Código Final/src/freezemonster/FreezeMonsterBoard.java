package freezemonster;

import freezemonster.sprite.Gosma;
import freezemonster.sprite.Monster;
import freezemonster.sprite.Ray;
import freezemonster.sprite.Woody;
import spriteframework.AbstractBoard;
import spriteframework.sprite.BadSprite;
import spriteframework.sprite.Player;

import java.awt.*;
import java.awt.event.KeyEvent;
import java.util.LinkedList;
import java.util.Random;

public class FreezeMonsterBoard extends AbstractBoard {
    private Ray raio;
    private Random random;
    private int deaths = 0;

    @Override
    protected Player createPlayer() {
        return new Woody();
    }

    @Override
    protected void createBadSprites() {
        badSprites = new LinkedList<>();
        random = new Random();

        for (int i = 0; i < Commons.NUMBER_OF_MONSTERS_TO_DESTROY; i++) {
            int x = random.nextInt(Commons.BOARD_WIDTH - 100) + 50;
            int y = random.nextInt(Commons.BOARD_HEIGHT / 2) + 20;
            badSprites.add(new Monster(x, y));
        }
    }

    @Override
    protected void createOtherSprites() {
        raio = new Ray(0, 0, 0); // dx=0 para movimento vertical
        raio.die();
    }

    private void drawRaio(Graphics g) {
        if (raio.isVisible()) {
            g.drawImage(raio.getImage(), raio.getX(), raio.getY(), this);
        }
    }

    @Override
    protected void drawOtherSprites(Graphics g) {
        drawRaio(g);
        drawGosmas(g);
    }

    @Override
    protected void update() {
        checkGameStatus();
        updatePlayer();
        updateRay();
        updateMonstersAndGosmas();
    }

    private void checkGameStatus() {
        if (deaths == Commons.NUMBER_OF_MONSTERS_TO_DESTROY) {
            endGame("Game won!");
        }
    }

    private void updatePlayer() {
        for (Player player : players) {
            player.act();
            checkPlayerCollision(player);
        }
    }

    private void updateRay() {
        if (raio != null && !raio.isDestroyed()) {
            raio.act(); // Usa o método act() da classe Ray

            // Verifica colisões
            checkRayCollisions();

            // Verifica se saiu da tela
            if (raio.getY() < Commons.BORDER_TOP) {
                raio.setDying(true);
            }
        }
    }

    private void updateMonstersAndGosmas() {
        for (BadSprite bad : badSprites) {
            Monster monster = (Monster) bad;

            if (monster.isVisible() && !monster.isDying()) {
                monster.act();
                tryToShootGosma(monster);
                updateGosma(monster);
            }
        }
    }

    private void tryToShootGosma(Monster monster) {
        if (random.nextInt(100) < 2 && monster.getGosma().isDestroyed()) {
            monster.getGosma().setDestroyed(false);
            monster.getGosma().setX(monster.getX());
            monster.getGosma().setY(monster.getY());
        }
    }

    private void updateGosma(Monster monster) {
        Gosma gosma = monster.getGosma();
        if (!gosma.isDestroyed()) {
            gosma.act();

            // Verifica se gosma saiu da tela
            if (gosma.getY() > Commons.BOARD_HEIGHT) {
                gosma.setDestroyed(true);
            }
        }
    }

    private void checkPlayerCollision(Player player) {
        for (BadSprite bad : badSprites) {
            Monster monster = (Monster) bad;

            // Colisão com monstro
            if (monster.isVisible() && player.getRect().intersects(monster.getRect())) {
                player.die();
                endGame("Game Over! Monster collision!");
            }

            // Colisão com gosma
            if (!monster.getGosma().isDestroyed() &&
                    player.getRect().intersects(monster.getGosma().getRect())) {
                player.die();
                monster.getGosma().setDestroyed(true);
                endGame("Game Over! Hit by gosma!");
            }
        }
    }

    private void checkRayCollisions() {
        if (raio == null || raio.isDestroyed() || raio.hasHit()) return;

        for (BadSprite bad : badSprites) {
            Monster monster = (Monster) bad;

            // colisão raio com monstro
            if (monster.isVisible() && !monster.isDying() && raio.getRect().intersects(monster.getRect())) {
                monster.die();
                deaths++;
                raio.die();
                raio.markAsHit();
                break;
            }
            // colisão raio com gosma
            else if (monster.isVisible() && !monster.getGosma().isDestroyed() && raio.getRect().intersects(monster.getGosma().getRect())) {
                raio.die();
                raio.markAsHit();
                monster.getGosma().die();
                break;
            }
        }
    }

    private void endGame(String message) {
        inGame = false;
        timer.stop();
        this.message = message;
    }

    @Override
    protected void processOtherSprites(Player player, KeyEvent e) {
        if (e.getKeyCode() == KeyEvent.VK_SPACE && inGame) {
            // Só dispara se não houver raio ativo
            if (raio == null || raio.isDying() || raio.isDestroyed()) {
                Woody woody = (Woody) player;
                int direction = woody.getDirecaoWoody();

                raio = new Ray(
                        player.getX() + player.getImageWidth()/2 - Commons.RAY_WIDTH/2,
                        player.getY(),
                        direction
                );

                raio.setDying(false);
            }
        }
    }

    private void drawGosmas(Graphics g) {
        for (BadSprite bad : badSprites) {
            Monster monster = (Monster) bad;
            Gosma gosma = monster.getGosma();
            if (!gosma.isDestroyed()) {
                g.drawImage(gosma.getImage(), gosma.getX(), gosma.getY(), this);
            }
        }
    }
}
