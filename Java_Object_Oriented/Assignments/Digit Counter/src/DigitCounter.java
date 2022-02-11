
public class DigitCounter {
	private int digit, og, sum;
	public DigitCounter() {
		sum = getSum();
	}
	public DigitCounter(int input) {
		og = input;
		getSum();
	}
	public void getDigit(int input) {
		og = input;
	}
	public int getSum() {
		sum = 0;
		digit = og;
		while (digit > 0) {
			sum = sum + (digit % 10);
			digit = (digit / 10);
		}
		return sum;
	}
	public String toString() {
		return sum + " is the sum of the digits of " + og;
	}
}
