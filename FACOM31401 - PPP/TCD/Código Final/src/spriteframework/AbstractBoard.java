package spriteframework;


import javax.swing.JPanel;
import javax.swing.Timer;

import spriteframework.sprite.BadSprite;
import spriteframework.sprite.Player;
import freezemonster.Commons;

import java.awt.Color;
import java.awt.Dimension;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.RenderingHints;
import java.awt.Toolkit;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.KeyAdapter;
import java.awt.event.KeyEvent;
import java.util.LinkedList;


public abstract class AbstractBoard extends JPanel {

    protected Dimension d;
    
    //define sprites
//    private List<Alien> aliens;
    protected LinkedList<Player> players;
    
    protected LinkedList<BadSprite> badSprites;
    
//    private Shot shot;
//    
    // define global control vars   
//    private int direction = -1;
//    private int deaths = 0;

    private int numberPlayers;  // to do - future use
    protected boolean inGame = true;
//    private String explImg = "src/images/explosion.png";
    protected String message = "Game Over";

    protected Timer timer;

    // Frozen Spots
    //  void initBoard()
    // 
    // HotSpots
    protected abstract void createBadSprites();
    protected abstract void createOtherSprites();
    protected abstract void drawOtherSprites(Graphics g);
    protected abstract void update();
    protected abstract void processOtherSprites(Player player, KeyEvent e);

    public AbstractBoard() {

        initBoard();
        createPlayers();
		        numberPlayers = 1;
		        badSprites = new LinkedList<BadSprite>();
		        createBadSprites();
		        createOtherSprites();
		//        shot = new Shot();
    }

    private void initBoard() {

    	addKeyListener(new TAdapter());
    	setFocusable(true);
    	d = new Dimension(Commons.BOARD_WIDTH, Commons.BOARD_HEIGHT);
    	setBackground(Color.black);

    	timer = new Timer(Commons.DELAY, new GameCycle());
    	timer.start();

    	createPlayers();
    	numberPlayers = 1;
    	badSprites = new LinkedList<BadSprite>();
    	createBadSprites();
    	createOtherSprites();
		//        shot = new Shot();
    }



    protected abstract Player createPlayer();

    // fábrica abstrata
    protected void createPlayers() {
        players = new LinkedList<Player>();
        players.add(createPlayer());  // delega a criação para as subclasses
    }



   public Player getPlayer(int i) {
	   if (i >=0 && i<players.size())
		   return players.get(i);
	   return null;
   }
   
    private void drawBadSprites(Graphics g) {

        for (BadSprite bad : badSprites) {

            if (bad.isVisible()) {

                g.drawImage(bad.getImage(), bad.getX(), bad.getY(), this);
            }

            if (bad.isDying()) {

                bad.die();
            }
            if (bad.getBadnesses()!= null) {
            	for (BadSprite badness: bad.getBadnesses()) {
            		if (!badness.isDestroyed()) {
            			g.drawImage(badness.getImage(), badness.getX(), badness.getY(), this);
            		}
            	}
            }
        }
    }

    private void drawPlayers(Graphics g) {
    	for (Player player: players) {
    		if (player.isVisible()) {
    			g.drawImage(player.getImage(), player.getX(), player.getY(), this);
    		}

    		if (player.isDying()) {

    			player.die();
    			inGame = false;
    		}
    	}
    }





    @Override
    public void paintComponent(Graphics g) {
        super.paintComponent(g);
        doDrawing(g);
    }

    public void doDrawing(Graphics g1) { // Template Method
        Graphics2D g = (Graphics2D) g1;
        g.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
                RenderingHints.VALUE_ANTIALIAS_ON);

        g.setRenderingHint(RenderingHints.KEY_RENDERING,
                RenderingHints.VALUE_RENDER_QUALITY);
        g.setColor(Color.black);
        g.fillRect(0, 0, d.width, d.height);


        if (inGame) {
            drawBadSprites(g);
            drawPlayers(g);
            drawOtherSprites(g);
        } else {
            if (timer.isRunning()) {
                timer.stop();
            }
            gameOver(g);
        }
        Toolkit.getDefaultToolkit().sync();
    }

    private void gameOver(Graphics g) {
        // Fundo semi-transparente
        g.setColor(new Color(0, 0, 0, 200)); // Preto com transparência
        g.fillRect(0, 0, Commons.BOARD_WIDTH, Commons.BOARD_HEIGHT);

        // Caixa de mensagem
        g.setColor(new Color(0, 32, 48));
        int boxHeight = 100;
        g.fillRect(50, Commons.BOARD_HEIGHT / 2 - boxHeight/2,
                Commons.BOARD_WIDTH - 100, boxHeight);

        // Borda
        g.setColor(Color.white);
        g.drawRect(50, Commons.BOARD_HEIGHT / 2 - boxHeight/2,
                Commons.BOARD_WIDTH - 100, boxHeight);

        // Texto
        Font font = new Font("Helvetica", Font.BOLD, 24);
        FontMetrics fm = g.getFontMetrics(font);

        g.setColor(Color.white);
        g.setFont(font);

        // Centraliza o texto
        int textX = (Commons.BOARD_WIDTH - fm.stringWidth(message)) / 2;
        int textY = Commons.BOARD_HEIGHT / 2 + fm.getAscent()/2;

        g.drawString(message, textX, textY);
    }



    private void doGameCycle() {

        update();
        repaint();
    }



	private class GameCycle implements ActionListener {

        @Override
        public void actionPerformed(ActionEvent e) {

            doGameCycle();
        }
    }

    private class TAdapter extends KeyAdapter {

        @Override
        public void keyReleased(KeyEvent e) {
            for (Player player: players)
                 player.keyReleased(e);
        }

        @Override
        public void keyPressed(KeyEvent e) {
        	for (Player player: players) {
                player.keyPressed(e);

                processOtherSprites(player, e); // hotspot
        	}
        }
    }
}
