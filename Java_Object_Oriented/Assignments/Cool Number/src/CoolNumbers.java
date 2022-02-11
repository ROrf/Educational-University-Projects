
public class CoolNumbers {
	private int start, end, num, count = 0;
	private boolean cool;
	public CoolNumbers() {
		count = countCoolNumbers();
	}
	public CoolNumbers(String hello) {
		start = Integer.parseInt(hello.split(" ")[0]);
		end = Integer.parseInt(hello.split(" ")[1]);
		countCoolNumbers();
	}
	public void getNumbers(String hello) {
		start = Integer.parseInt(hello.split(" ")[0]);
		end = Integer.parseInt(hello.split(" ")[1]);
	}
	public boolean isCoolNum() {
			if (num%3 == 1 && num%4 == 1 && num%5 == 1 && num%6 == 1) {
				cool = true;
			}
			else {
				cool = false;
			}
		return cool;
	}
	public int countCoolNumbers() {
		for (int i = start; i <= end; i = i + 1) {
			num = i;
			isCoolNum();
			if (cool == true) {
				count = count + 1;
			}
		}
		return count;
	}
	public String toString() {
		return count + " cool numbers between " + start + " - " + end;
	}
}
