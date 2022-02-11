import java.util.ArrayList;
import java.util.Scanner;
import java.util.Scanner;
public class ArrayListFunHouseRunner {
	public static void main(String args[]) {
		Scanner kb = new Scanner(System.in);
		String equation = kb.nextLine();
		kb.close();
		Scanner math = new Scanner(equation);
		ArrayList<Integer> equal = new ArrayList<Integer>();
			while(math.hasNextInt()) {
				equal.add(math.nextInt());
			}
		ArrayListFunHouse test = new ArrayListFunHouse(equal);
		System.out.println(test);
	}
}
