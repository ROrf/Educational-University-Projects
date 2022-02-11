
public class NumberShifter {
	private int[] initial, seven;
	public NumberShifter() {
		seven = getSeven();
	}
	public NumberShifter(int[] input) {
		initial = input;
		seven = new int[initial.length];
		getSeven();
	}
	public void getNumber(int[] input) {
		initial = input;
	}
	public int[] getSeven() {
		int eger = 0;
		for(int i = 0; i < initial.length; i++) {
			if(initial[i] == 7) {
				seven[eger] = initial[i];
				eger++;
			}
		}
		for(int x = 0; x < initial.length; x++) {
			if(initial[x] != 7) {
				seven[eger] = initial[x];
				eger++;
			}
		}
		return seven;
	}
	public String toString() {
		System.out.print("[" + seven[0]);
		for(int i = 1; i < seven.length; i++) {
			System.out.print(", " + seven[i]);
		}
		return "]";
	}
}
