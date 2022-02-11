import java.util.Scanner;
public class FibonacciRunner {
	public static void main(String args[]) {
		Scanner input = new Scanner(System.in);
		System.out.println("Enter the sample size and the number in the sequence you would like to compute:: ");
		Fibonacci test = new Fibonacci(input.nextInt(), input.nextInt());
		System.out.println(test);
	}
}
