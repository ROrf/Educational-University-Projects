import java.util.Scanner;
public class NumberSorterRunner {
	public static void main(String args[]) {
		Scanner kb = new Scanner(System.in);
		int l = kb.nextInt();
		NumberSorter test = new NumberSorter(l);
		System.out.println(test);
	}
}
