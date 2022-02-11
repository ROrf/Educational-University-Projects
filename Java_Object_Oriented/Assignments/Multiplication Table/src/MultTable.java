
public class MultTable {
	private String num = "";
	private int num1, num2;
	public MultTable() {
		num = getTable();
	}
	public MultTable(String nums) {
		num1 = Integer.parseInt(nums.split(" ")[0]);
		num2 = Integer.parseInt(nums.split(" ")[1]);
		getTable();
	}
	public void getNums(String nums) {
		num1 = Integer.parseInt(nums.split(" ")[0]);
		num2 = Integer.parseInt(nums.split(" ")[1]);
	}
	public String getTable() {
		for (int i = 1; i <= num2; i = i + 1) {
			num = num + i + "\t" + (num1 * i) + "\n";
		}
		return num;
	}
	public String toString() {
		return num;
	}
}
