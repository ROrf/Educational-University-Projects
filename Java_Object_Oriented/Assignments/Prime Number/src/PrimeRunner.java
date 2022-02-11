import java.util.Scanner;
public class PrimeRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter a number:: ");
		Prime test = new Prime(keyboard.nextInt());
		System.out.println(test);
	}
}
