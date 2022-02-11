import java.util.Scanner;
public class LoopStatsRunner {
	public static void main(String args[]) {
		Scanner keyboard = new Scanner(System.in);
		System.out.println("Enter two numbers:: ");
		LoopStats test = new LoopStats(keyboard.nextLine());
		System.out.println(test);
	}
}
