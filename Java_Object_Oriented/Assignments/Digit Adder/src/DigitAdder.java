
public class DigitAdder {
	private int digit, og, cnt;
	public DigitAdder() {
		cnt = getSum();
	}
	public DigitAdder(int input) {
		og = input;
		getSum();
	}
	public void getDigit(int input) {
		og = input;
	}
	public int getSum() {
		cnt = 0;
		digit = og;
		while (digit > 0) {
			cnt ++;
			digit = digit / 10;
		}
		return cnt;
	}
	public String toString() {
		return og + " contains " + cnt + " digits";
	}
}
