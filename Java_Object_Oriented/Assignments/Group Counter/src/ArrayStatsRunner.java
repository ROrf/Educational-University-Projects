import java.util.Scanner;
import java.util.Arrays;
public class ArrayStatsRunner {
	public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("How many numbers do you want to enter?");
        double num = input.nextDouble();
        double array[] = new double[(int) num];
        System.out.println("Enter the " + (int)num + " numbers now.");
        for (int i = 0 ; i < array.length; i++) {
           array[i] = input.nextDouble();
        }
        System.out.println("How many sizes would you like to count?");
        double nums = input.nextDouble();
        double size[] = new double[(int) nums];
        System.out.println("Enter the " + (int)nums + " numbers now.");
        for(int x = 0; x < size.length; x++) {
        	size[x] = input.nextDouble();
        }
        ArrayStats test = new ArrayStats(array, size);
        System.out.println(test);
	}
}
//sample input: 1 1 1 2 1 1 3 3 3 3 3 3 3 3 3 3 4 4 4 5 4 4 4 6