
public class Factorial {
	private long sum = 1, fact;
	public Factorial() {
		sum = getSum();
	}
	public Factorial(long input) {
		fact = input;
		getSum();
	}
	public void getFactorial(long input) {
		fact = input;
	}
	public long getSum() {
		for (long i = fact; i >= 1; i = i - 1) {
			sum = sum * i;
		}
		return sum;
	}
	public String toString() {
		return "factorial of " + fact + " is " + sum;
	}
	
}
