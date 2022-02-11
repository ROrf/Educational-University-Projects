import java.util.ArrayList;

public class Number {
	ArrayList<Integer> numbers = new ArrayList<Integer>();
	int num = 0;
	String oddEven, perfect;
	public Number(ArrayList<Integer> input) {
		numbers = input;
		int i = 0;
		for(i = 0; i < numbers.size() - 1; i++) {
			num = numbers.get(i);
			oddOrEven();
			isPerfect();
			toString();
		}
		num = numbers.get(i);
		oddOrEven();
		isPerfect();
	}
	public void getArrayList(ArrayList<Integer> input) {
		numbers = input;
	}
	public String oddOrEven() {
		if(num%2 == 0) {
			oddEven = " is not odd.\n";
		}
		else {
			oddEven = " is odd.\n";
		}
		return oddEven;
	}
	public String isPerfect() {
		int divisors = 0;
		for(int i = 1; i < num; i++) {
			if(num%i == 0) {
				divisors += i;
			}
		}
		if(num == divisors) {
			perfect = " is perfect.\n";
		}
		else {
			perfect = " is not perfect.\n";
		}
		return perfect;
	}
	public String toString() {
		System.out.println(num + oddEven + num + perfect);
		return "";
	}
}
