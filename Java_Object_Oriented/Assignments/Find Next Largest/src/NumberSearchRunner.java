import java.util.Scanner;
public class NumberSearchRunner {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		String silly = input.nextLine();
		String oops = input.nextLine();
		Scanner fun = new Scanner(silly);
		Scanner scanner = new Scanner(silly);
		int noom = Integer.parseInt(oops);
		input.close();
		int x = 0;
		while(fun.hasNext()) {
			x++;
			fun.next();
		}
		fun.close();
		int array[] = new int[x];
		for(int i = 0; i < x; i++) {
			array[i] = scanner.nextInt();
		}
		NumberSearch test = new NumberSearch(array, noom);
		System.out.println(test);
	}
}
