import java.util.Scanner;
public class TicTacToe {
	private int spot, xwin, owin, tie;
	private boolean winner = false; //needs to be false or else it will automatically choose a winner
	private String player = "X"; //starts the first player as X
	private String[] gameboard = new String[9]; //tic-tac-toe is a 3x3
	public TicTacToe() { //constructor
		getInitial(); //creates the array and the original grid
	}
	public void getInitial() { //method only run through once, makes the grid
		for(int i = 0; i < gameboard.length; i++) {
			gameboard[i] = "B"; //B is for blank, needed something besides X and O
		}
		int x = 0; //number to loop through array
		for(int y = 0; y < 3; y++) { //loops through columns
			for(int z = 0; z < 3; z++) { //loops through rows
				System.out.print(gameboard[x]);
				x++;
			}
			System.out.print("\n"); //spacing for columns
		}
		System.out.print("\n"); //spacing for appeal
		getTurn(); //calls getTurn method so Player 1 can have his first turn
	}
	public void gameOver() {
		if(gameboard[0].equals("X") && gameboard[1].equals("X") && gameboard[2].equals("X")) { //and so begins the long line of if statements. i tried this several other ways but this is the only way I could get to work
			System.out.println("Player 1 won the game!");	
			winner = true; //will end game
			xwin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin); //will call Runner constructor that keeps a running total of wins, losses, and ties
		}
		if(gameboard[3].equals("X") && gameboard[4].equals("X") && gameboard[5].equals("X")) { //checks by rows first for Xs
			System.out.println("Player 1 won the game!");
			winner = true;
			xwin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		if(gameboard[6].equals("X") && gameboard[7].equals("X") && gameboard[8].equals("X")) {
			System.out.println("Player 1 won the game!");
			winner = true;
			xwin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		if(gameboard[0].equals("X") && gameboard[3].equals("X") && gameboard[6].equals("X")) { //checks by columns for Xs
			System.out.println("Player 1 won the game!");
			winner = true;
			xwin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		if(gameboard[1].equals("X") && gameboard[4].equals("X") && gameboard[7].equals("X")) {
			System.out.println("Player 1 won the game!");	
			winner = true;
			xwin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		if(gameboard[2].equals("X") && gameboard[5].equals("X") && gameboard[8].equals("X")) {
			System.out.println("Player 1 won the game!");	
			winner = true;
			xwin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		if(gameboard[0].equals("X") && gameboard[4].equals("X") && gameboard[8].equals("X")) { //checks diagonals for Xs
			System.out.println("Player 1 won the game!");	
			winner = true;
			xwin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		if(gameboard[2].equals("X") && gameboard[4].equals("X") && gameboard[6].equals("X")) {
			System.out.println("Player 1 won the game!");	
			winner = true;
			xwin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		if(gameboard[0].equals("O") && gameboard[1].equals("O") && gameboard[2].equals("O")) { //same process but for Os
			System.out.println("Player 2 won the game!");	
			winner = true;
			owin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		if(gameboard[3].equals("O") && gameboard[4].equals("O") && gameboard[5].equals("O")) {
			System.out.println("Player 2 won the game!");	
			winner = true;
			owin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		if(gameboard[6].equals("O") && gameboard[7].equals("O") && gameboard[8].equals("O")) {
			System.out.println("Player 2 won the game!");
			winner = true;
			owin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
			}
		if(gameboard[0].equals("O") && gameboard[3].equals("O") && gameboard[6].equals("O")) {
			System.out.println("Player 2 won the game!");		
			winner = true;
			owin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
			}
		if(gameboard[1].equals("O") && gameboard[4].equals("O") && gameboard[7].equals("O")) {
			System.out.println("Player 2 won the game!");	
			winner = true;
			owin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		if(gameboard[2].equals("O") && gameboard[5].equals("O") && gameboard[8].equals("O")) {
			System.out.println("Player 2 won the game!");	
			winner = true;
			owin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		if(gameboard[0].equals("O") && gameboard[4].equals("O") && gameboard[8].equals("O")) {
			System.out.println("Player 2 won the game!");
			winner = true;
			owin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
			}
		if(gameboard[2].equals("O") && gameboard[4].equals("O") && gameboard[6].equals("O")) {
			System.out.println("Player 2 won the game!");	
			winner = true;
			owin++;
			TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
		}
		else if(gameboard[0].equals("X") || gameboard[0].equals("O")) { //long list of if statements for if nobody wins and all spots are taken
			if(gameboard[1].equals("X") || gameboard[1].equals("O")) {
				if(gameboard[2].equals("X") || gameboard[2].equals("O")) {
					if(gameboard[3].equals("X") || gameboard[3].equals("O")) {
						if(gameboard[4].equals("X") || gameboard[4].equals("O")) {
							if(gameboard[5].equals("X") || gameboard[5].equals("O")) {
								if(gameboard[6].equals("X") || gameboard[6].equals("O")) {
									if(gameboard[7].equals("X") || gameboard[7].equals("O")) {
										if(gameboard[8].equals("X") || gameboard[8].equals("O")) {
											if(winner == false) { //ensures that it does not run even if there is a winner
												System.out.println("Neither player won the game!");
												winner = true;
												tie++;
												TicTacToeRunner test = new TicTacToeRunner(tie, xwin, owin);
											}
										}
									}
								}
							}
						}
					}
				}
			}
		}
		while(winner == false) { //will keep calling until there is a definitive winner, or if it's a tie
			getTurn();
		}
	}
	public void getTurn() { //method to determine each move 
			while(spot < 1 || spot > 9 || gameboard[spot-1].equals("X") || (gameboard[spot-1].equals("O"))) { //loops until you choose a blank(B) spot
				Scanner input = new Scanner(System.in);
				System.out.println("Enter a spot that has not already been marked");
				spot = input.nextInt(); //will find the next integer input
				if(spot < 1 || spot > 9 || gameboard[spot-1].equals("X") || gameboard[spot-1].equals("O")) { //if a non-valid spot is chosen
					System.out.println("That is not an acceptable space. Please try again!");
				}
			}
			if(player.equals("X")) { //alternates players each time
				gameboard[spot - 1] = player;
				player = "O";
			}
			else if(player.equals("O")) {
				gameboard[spot - 1] = player;
				player = "X";
			}
			int num = 0; //number established for looping through the array
			for(int i = 0; i < 3; i++) { //loops through columns
				for(int x = 0; x < 3; x++) { //loops through rows
					System.out.print(gameboard[num]);
					num++;
				}
				System.out.print("\n"); //spacing to jump to next column
			}
			System.out.print("\n"); //spacing for appeal
			gameOver(); //calls the method to see if the game is over yet
	}
}
