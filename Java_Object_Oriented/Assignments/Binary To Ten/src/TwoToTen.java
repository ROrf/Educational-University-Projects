
public class TwoToTen {
	private double base = 0;
	private String binary;
	private int num = 0;
	public TwoToTen() {
		base = getBase();
	}
	public TwoToTen(String input) {
		binary = input;
		getBase();
	}
	public void getBinary(String input) {
		binary = input;
	}
	public double getBase() {
		for (int i = binary.length() - 1; i >= 0; i = i - 1) { 
			if (binary.charAt(i) == '1') {
				base = base + Math.pow(2, num);
			}
			num = num + 1;
		}
		return base;
	}
	public String toString() {
		return binary + " == " + (int)base;
	}
}
