
public class Word {
	private String word, back = "";
	private char first, last;
	public Word() {
		back = getBack();
	}
	public Word(String input) {
		word = input;
		first = input.charAt(0);
		last = input.charAt(input.length() - 1);
		getBack();
	}
	public void getWord(String input) {
		word = input;
		first = input.charAt(0);
		last = input.charAt(input.length() - 1);
	}
	public String getBack() {
		for (int i = word.length() - 1; i >= 0; i = i - 1) {
			back = back + word.charAt(i);
		}
		return back;
	}
	public String toString() {
		return first + "\n" + last + "\n" + back + "\n" + word;
	}
}
