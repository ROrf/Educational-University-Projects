
public class VowelCounter {
	private String s, end = "";
	private char var;
	private int num;
	public VowelCounter() {
		s = getString();
	}
	public VowelCounter(String string) {
		s = string;
		getString();
	}
	public void getString(String string) {
		s = string;
	}
	public String getString() {
		for (int i = 0; i < s.length(); i = i + 1){
			if (s.charAt(i) == 'a' || s.charAt(i) == 'e' || s.charAt(i) == 'i' || s.charAt(i) == 'o' || s.charAt(i) == 'u' || s.charAt(i) == 'A' || s.charAt(i) == 'E' || s.charAt(i) == 'I' || s.charAt(i) == 'O' || s.charAt(i) == 'U') {
				var = (char)(num + 48);
				num = num + 1;
				if (num > 9) {
					num = 0;
				}
			}
			else {
				var = s.charAt(i);
			}
			end = end + var;
		}
		return end;
	}
		public String toString() {
			return end;
		}
}
