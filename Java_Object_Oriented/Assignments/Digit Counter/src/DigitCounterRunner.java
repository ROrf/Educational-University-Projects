import java.util.Scanner;
public class DigitCounterRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter an integer:: ");
		DigitCounter test = new DigitCounter(keyboard.nextInt());
		System.out.println(test);
	}
}
