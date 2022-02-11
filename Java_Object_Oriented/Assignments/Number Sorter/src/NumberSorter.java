import java.util.ArrayList;
import java.util.Collections;

public class NumberSorter {
	private int in;
	private int[] arr;
	public NumberSorter() {
		arr = getArr();
	}
	public NumberSorter(int input) {
		in = input;
		int test = in;
		int y = 0;
		while (test > 0){
			y++;
			test = test / 10;
		}
		arr = new int[y];
		getArr();
	}
	public void getNum(int input) {
		in = input;
	}
	public int[] getArr() {
		ArrayList<Integer> hit;
		hit = new ArrayList<Integer>();
		int i = 0;
		int x = 0;
		while(in > 0) {
			x = in%10;
			arr[i] = x;
			i++;
			in = in/10;
		}
		for(int m = 0; m < arr.length; m++) {
			hit.add(arr[m]);
		}
		Collections.sort(hit);
		for(int q = 0; q < arr.length; q++) {
			arr[q] = hit.get(q);
		}
		return arr;
	}
	public String toString() {
		for(int i = 0; i < arr.length; i++) {
			System.out.print(arr[i] + " ");
		}
		return "";
	}
}
