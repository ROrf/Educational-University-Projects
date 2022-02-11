import java.util.ArrayList;
import java.util.Collections;

public class NumberSearch {
	private int[] initial, sort;
	private int num1, num2;
	public NumberSearch() {
		num2 = getNum();
	}
	public NumberSearch(int[] input, int system) {
		initial = input;
		num1 = system;
		sort = new int[initial.length];
		getNum();
	}
	public void getNumber(int[] input, int system) {
		initial = input;
		num1 = system;
	}
	public int getNum() {
		sort = initial;
		ArrayList<Integer> hit;
		hit = new ArrayList<Integer>();
		for(int i = 0; i < sort.length; i++) {
			hit.add(sort[i]);
		}
		Collections.sort(hit);
		int sum = Collections.binarySearch(hit, num1);
		if(sum >= 0) {
			num2 = hit.get(sum + 1);
			System.out.println(num2);
		}
		else {
			num2 = hit.get((sum * (-1)) - 1);
		}
		return num2;
	}
	public String toString() {
		System.out.print("[" + initial[0]);
		for(int i = 1; i < initial.length; i++) {
			System.out.print(", " + initial[i]);
		}
		 System.out.print("]\n");
		 return ("The next largest value after " + num1 + " is " + num2);
	}
}
