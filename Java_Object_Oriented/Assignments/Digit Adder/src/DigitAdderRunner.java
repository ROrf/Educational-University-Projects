import java.util.Scanner;
public class DigitAdderRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter an integer:: ");
		DigitAdder test = new DigitAdder(keyboard.nextInt());
		System.out.println(test);
	}
}
