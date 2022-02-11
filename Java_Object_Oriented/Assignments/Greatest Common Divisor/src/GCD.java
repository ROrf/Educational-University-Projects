
public class GCD {
	private int one, two, gcd = 0;
	public GCD() {
		gcd = getGCD();
	}
	public GCD(String input) {
		one = Integer.parseInt(input.split(" ")[0]);
		two = Integer.parseInt(input.split(" ")[1]);
		getGCD();
	}
	public void getNum(String input) {
		one = Integer.parseInt(input.split(" ")[0]);
		two = Integer.parseInt(input.split(" ")[1]);
	}
	public int getGCD() {
		for (int i = two; i >= one; i = i - 1) {
			if (one%i == 0 && two%i == 0) {
				if (i > gcd) {
					gcd = i;
				}
			}
		}
		return gcd;
	}
	public String toString() {
		return "the gcd of " + one + " and " + two + " is " + gcd;
	}
}
