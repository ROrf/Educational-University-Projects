import java.util.ArrayList;
import java.util.Scanner;

public class WordsRunner {
	public static void main(String[] args) {
		Scanner kb = new Scanner(System.in);
		String ans = "yes";
		while(ans.equals("yes")||ans.equals("y")) {
			System.out.println("Enter a word :: ");
			Word test = new Word(kb.next());
			System.out.println(test);
			System.out.println("Would you like to enter another word?");
			ans = kb.next();
		}
		String cases = "";
		ans = "yes";
		int number = 0;
		String name = "classic";
		while(ans.equals("yes")||ans.equals("y")) {
			System.out.println("Enter a word :: ");
			cases += kb.next() + " ";
			number++;
			System.out.println("Would you like to enter another number?");
			ans = kb.next();
		}
		 	Words test2 = new Words(name, number);
	       	for(int i = 0; i < number; i++) {
	       		Word2 tester = new Word2(cases.split(" ")[i]);
	       		test2.addWords(tester);
	       	}
	       	System.out.println(test2);
	       	System.out.println("word with 2 vowels = "+test2.countWordsWithXVowels(2));
	       	System.out.println("word with 3 vowels = "+test2.countWordsWithXVowels(3));
	       	System.out.println("word with 4 vowels = "+test2.countWordsWithXVowels(4));
	       	System.out.println("word with 2 chars = "+test2.countWordsWithXChars(2));
	       	System.out.println("word with 3 chars = "+test2.countWordsWithXChars(3));
	       	System.out.println("word with 4 chars = "+test2.countWordsWithXChars(4));
	       	System.out.println("word with 5 chars = "+test2.countWordsWithXChars(5));
	       	System.out.println("word with the most characters == " + test2.mostChar());
	        System.out.println("word with the least characters == " + test2.leastChar());
	       	int vowelsRemoved = test2.removeWordsWithXChars(3);
	       	System.out.println("\nafter removing words with 3 chars");
	       	System.out.println(test2);
	        System.out.println("\nnumber of vowels in the words removed == " + vowelsRemoved);
	}
}
