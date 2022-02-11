import java.util.ArrayList;
import java.util.Scanner;
public class ExpressionSolverRunner {
	public static void main(String args[]) {
		Scanner kb = new Scanner(System.in);
		String equation = kb.nextLine();
		kb.close();
		Scanner math = new Scanner(equation);
		ArrayList<String> equal = new ArrayList<String>();
			while(math.hasNext()) {
				equal.add(math.next());
			}
		ExpressionSolver test = new ExpressionSolver(equal);
		System.out.println(test);
	}
}
