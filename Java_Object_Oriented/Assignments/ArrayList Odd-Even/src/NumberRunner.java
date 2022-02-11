import java.util.ArrayList;
import java.util.Scanner;
import java.util.Scanner;
public class NumberRunner {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String ans = "yes";
		ArrayList<Integer> numbers = new ArrayList<Integer>();
		while(ans.equals("yes")||ans.equals("y")) {
			System.out.println("Enter a number :: ");
			numbers.add(kb.nextInt());
			System.out.println("Would you like to enter another number?");
			ans = kb.next();
		}
		Number test = new Number(numbers);
		System.out.println(test);
		ans = "yes";
		ArrayList<Integer> nums = new ArrayList<Integer>();
		while(ans.equals("yes")||ans.equals("y")) {
			System.out.println("Enter a number :: ");
			nums.add(kb.nextInt());
			System.out.println("Would you like to enter another number?");
			ans = kb.next();
		}
		NumberAnalyzer test2 = new NumberAnalyzer(nums);
		System.out.println(test2);
	}
}
