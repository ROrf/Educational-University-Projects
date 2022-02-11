import java.util.Scanner;
public class CoolNumbersRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter a beginning and ending number:: ");
		CoolNumbers test = new CoolNumbers(keyboard.nextLine());
		System.out.println(test);
	}
}
