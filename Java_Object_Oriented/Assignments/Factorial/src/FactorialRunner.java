import java.util.Scanner;
public class FactorialRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter an integer:: ");
		Factorial test = new Factorial(keyboard.nextLong());
		System.out.println(test);
	}
}
