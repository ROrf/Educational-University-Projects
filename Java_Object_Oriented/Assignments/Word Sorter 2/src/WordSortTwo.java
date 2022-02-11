import java.util.Arrays;
import java.util.Scanner;

public class WordSortTwo {
	private String[] initial, order, indiv;
	private int number, oops;
	public WordSortTwo() {
		order = getOrder();
	}
	public WordSortTwo(String[] input, int num) {
		initial = input;
		number = num;
		order = new String[initial.length];
		getOrder();
	}
	public void getWordSort(String[] input, int num) {
		initial = input;
		number = num;
	}
	public String[] getOrder() {
		for(int x = 0; x < number; x++) {
			oops = 0;
			Scanner ayy = new Scanner(initial[x]);
			Scanner use = new Scanner(initial[x]);
			while(ayy.hasNext()) {
				oops++;
			}
			ayy.close();
			indiv = new String[oops];
			for(int m = 0; m < oops; m++) {
				indiv[m] = use.next();
			}
			use.close();
			Arrays.sort(indiv);
			for(int i = 0; i < oops; i++) {
				order[x] = indiv[i] + "\n";
			}
		}
		return order;
	}
	public String toString() {
		for(int i = 0; i < order.length; i++) {
			System.out.println(order[i]);
		}
		return "huh";
	}
}
