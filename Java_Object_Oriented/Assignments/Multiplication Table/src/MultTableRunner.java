import java.util.Scanner;
public class MultTableRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter a number and how many times you want that number to be multiplied:: ");
		MultTable test = new MultTable(keyboard.nextLine());
		System.out.println(test);
	}
}
