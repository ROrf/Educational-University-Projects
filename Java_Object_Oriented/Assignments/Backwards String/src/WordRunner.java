import java.util.Scanner;
public class WordRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter a word:: ");
		Word test = new Word(keyboard.nextLine());
		System.out.println(test);
	}
}
