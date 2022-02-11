
public class Fibonacci {
	private int size, spot, num;
	private int[] fib;
	public Fibonacci() {
		num = getNum();
	}
	public Fibonacci(int sample, int input) {
		size = sample;
		spot = input - 1;
		fib = new int[size];
		getNum();
	}
	public void getFibonacci(int sample, int input) {
		size = sample;
		spot = input - 1;
	}
	public int getNum() {
		fib[0] = 1;
		fib[1] = 1;
		for(int i = 0; i < size; i++) {
			if (i > 1) {
				fib[i] = fib[i - 1] + fib[i - 2];
			}
		}
		if (spot >= 0 && spot < size) {
			num = fib[spot];
		}
		else {
			num = -1;
		}
		return num;
	}
	public String toString() {
		return num + " ";
	}
}
