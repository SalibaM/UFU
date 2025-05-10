package spaceinvaders;

import spriteframework.AbstractBoard;
import spriteframework.MainFrame;

import java.awt.EventQueue;

public class SpaceInvadersGame extends MainFrame {

	public SpaceInvadersGame () {
		super("Space Invaders");
	}

	@Override
	protected  AbstractBoard createBoard() {
		return new SpaceInvadersBoard();
	}

	public static void main(String[] args) {

		EventQueue.invokeLater(() -> {

			new SpaceInvadersGame();
		});
	}

}
