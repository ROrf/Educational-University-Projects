import java.util.Scanner;
public class TicTacToeRunner {
	private static int x, y, z;
	public TicTacToeRunner(int tie, int xwin, int owin) { //constructor for keeping the running total
		x = x + xwin;
		y = y + owin;
		z = tie + tie;
		System.out.println("Number of wins:: " + x + ". Number of losses:: " + y + ". Number of ties:: " + z + ".");
	}
	public static void main(String args[]) {
		String start;
		int replay = 1; //must be 1 for replay feature
		while(replay == 1) { //will keep going as long as you want to play
			TicTacToe prog = new TicTacToe(); //calls other class
			Scanner kb = new Scanner(System.in);
			System.out.println("\nWould you like to play another game?");
			replay = 0; //this is to make sure replay is only yes or no
			while(replay != 2 && replay != 1) { //loops through utnil clear yes or no
				start = kb.next();
				if(start.equals("yes")) {
					replay = 1; //will keep going
				}
				else if(start.equals("no")) {
					replay = 2; //will end right away
				}
				else {
					System.out.println("\nThat is not an acceptable response! Please either respond 'yes' or 'no'.");
				}
			}
		}
		if(replay == 2) { //little goodbye message
			System.out.println("\nGame over! Better luck next time, coward!");
		}
	}
}
