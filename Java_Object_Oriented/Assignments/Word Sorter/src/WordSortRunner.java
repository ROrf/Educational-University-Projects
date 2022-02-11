import java.util.Scanner;
import java.util.Arrays;
public class WordSortRunner {
	public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        String silly = input.nextLine();
        Scanner fun = new Scanner(silly);
        Scanner scanner = new Scanner(silly);
        input.close();
        int x = 0;
        while(fun.hasNext()) {
        	x++;
        	fun.next();
        }
        fun.close();
        String array[] = new String[x];
        for(int i = 0; i < x; i++) {
        	array[i] = scanner.next();
        }
        WordSort test = new WordSort(array);
        System.out.println(test);
	}
}
