import java.util.Arrays;

public class WordSort {
	private String[] initial, order;
	public WordSort() {
		order = getOrder();
	}
	public WordSort(String[] input) {
		initial = input;
		order = new String[initial.length];
		getOrder();
	}
	public void getWordSort(String[] input) {
		initial = input;
	}
	public String[] getOrder() {
		Arrays.sort(initial);
		for(int i = 0; i < initial.length; i++) {
			order[i] = initial[i];
		}
		return order;
	}
	public String toString() {
		for(int i = 0; i < order.length; i++) {
			System.out.println("word " + i + " :: " + order[i]);
		}
		return "";
	}
}
