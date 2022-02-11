import java.util.Scanner;
public class TriangleOneRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter a word:: ");
		TriangleOne test = new TriangleOne(keyboard.nextLine());
		System.out.println(test);
	}
}
