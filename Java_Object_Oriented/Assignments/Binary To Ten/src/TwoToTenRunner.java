import java.util.Scanner;
public class TwoToTenRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter a number in binary:: ");
		TwoToTen test = new TwoToTen(keyboard.nextLine());
		System.out.println(test);
	}
}
