import java.util.Scanner;
public class VowelCounterRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter a string:: ");
		VowelCounter test = new VowelCounter(keyboard.nextLine());
		System.out.println(test);
	}
}
