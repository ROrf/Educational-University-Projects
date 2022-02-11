
public class TriangleOne {
	private String wrd, end = "";
	public TriangleOne() {
		end = getString();
	}
	public TriangleOne(String word) {
		wrd = word;
		getString();
	}
	public void getWord(String word) {
		wrd = word;
	}
	public String getString() {
		for (int i = wrd.length(); i >= 0; i = i - 1) {
			end = end + wrd.substring(0, i) + "\n";
		}
		return end;
	}
	public String toString() {
		return end;
	}
}
