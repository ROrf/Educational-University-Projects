import java.util.ArrayList;
public class Word {
	ArrayList<Character> letters = new ArrayList<Character>();
	int vowels, chars;
	String word;
	public Word(String input) {
		for(int i = 0; i < input.length(); i++) {
			letters.add(input.charAt(i));
		}
		word = input;
		numVowels();
		numChars();
	}
	public void getLetters(String input) {
		for(int i = 0; i < input.length(); i++) {
			letters.add(input.charAt(i));
		}
	}
	public int numVowels() {
		for(int i = 0; i < letters.size(); i++) {
			char letter = letters.get(i);
			String check = "aeiouAEIOU";
			for(int j = 0; j < check.length(); j++) {
				if(letter == check.charAt(j)) {
					vowels++;
				}
			}
		}
		return vowels;
	}
	public int numChars() {
		chars = letters.size();
		return chars;
	}
	public String toString() {
		return "\n" + word + "\nnum vowels == " + vowels + "\nnum chars == " + chars;
				
	}
}
