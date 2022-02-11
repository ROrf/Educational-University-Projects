import java.util.Scanner;
import java.util.Arrays;
import java.io.File;
import java.io.FileNotFoundException;

public class WordSortTwoRunner {
	public static void main(String args[]) throws FileNotFoundException {
		Scanner kb = new Scanner(new File("wordsorttwo"));
		int silly = kb.nextInt();
		kb.nextLine();
		String[] array = new String[silly];
	    for(int i = 0; i < silly; i++) {
	    	array[i] = kb.nextLine();
	    }
	    kb.close();
	    WordSortTwo test = new WordSortTwo(array, silly);
	    System.out.println(test);
	}
}
