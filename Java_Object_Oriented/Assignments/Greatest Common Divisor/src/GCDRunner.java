import java.util.Scanner;
public class GCDRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter two numbers:: ");
		GCD test = new GCD(keyboard.nextLine());
		System.out.println(test);
	}
}
