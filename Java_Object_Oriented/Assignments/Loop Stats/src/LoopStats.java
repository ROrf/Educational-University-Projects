
public class LoopStats {
	private int start, stop, sum, even, odd;
	public LoopStats() {
		sum = getSum();
		even = getEven();
		odd = getOdd();
	}
	public LoopStats(String input) {
		start = Integer.parseInt(input.split(" ")[0]);
		stop = Integer.parseInt(input.split(" ")[1]);
		getSum();
		getEven();
		getOdd();
	}
	public void getStart(String input) {
		start = Integer.parseInt(input.split(" ")[0]);
		stop = Integer.parseInt(input.split(" ")[1]);
	}
	public int getSum() {
		for (int i = start; i <= stop; i = i + 1) {
			sum = sum + i;
		}
		return sum;
	}
	public int getOdd() {
		for (int i = start; i <= stop; i = i + 1) {
			if (i%2 == 1) {
				odd = odd + 1;
			}
		}
		return odd;
	}
	public int getEven() {
		for (int i = start; i <= stop; i = i + 1) {
			if (i%2 == 0) {
				even = even + 1;
			}
		}
		return even;
	}
	public String toString() {
		return start + " " + stop + "\ntotal " + sum + "\neven count " + even + "\nodd count " + odd;
	}
}
