import java.util.ArrayList;
public class NumberAnalyzer {
	ArrayList<Integer> numbers = new ArrayList<Integer>();
	int num, oddCount = 0, evenCount = 0, perfectCount = 0;
	public NumberAnalyzer(ArrayList<Integer> input) {
		numbers = input;
		for(int i = 0; i < numbers.size(); i++) {
			num = numbers.get(i);
			oddCount();
			evenCount();
			perfectCount();
		}
	}
	public void getNumbers(ArrayList<Integer> input) {
		numbers = input;
	}
	public int oddCount() {
		if(num%2 == 1) {
			oddCount++;
		}
		return oddCount;
	}
	public int evenCount() {
		if(num%2 == 0) {
			evenCount++;
		}
		return evenCount;
	}
	public int perfectCount() {
		int divisors = 0;
		for(int i = 1; i < num; i++) {
			if(num%i == 0) {
				divisors += i;
			}
		}
		if(num == divisors) {
			perfectCount++;
		}
		return perfectCount;
	}
	public String toString() {
		return numbers + "\nodd count = " + oddCount + "\neven count = " + evenCount + "\nperfect count = " + perfectCount;
	}
}
