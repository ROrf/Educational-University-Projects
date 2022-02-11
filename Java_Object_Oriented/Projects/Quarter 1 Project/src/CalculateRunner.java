import java.util.Scanner; //allows us to import information via the keyboard
public class CalculateRunner { 
	public static void main(String args[]) { //every class needs either a main method or to refer to a main method
		Scanner keyboard = new Scanner(System.in); //initializes keyboard as our Scanner object variable
		System.out.println("Enter a number to end the series:: "); //input statement for tidiness
		Calculate test = new Calculate(keyboard.nextInt()); //calls Calculate(int input) method using our input
		System.out.println(test); //prints the results of the program to our display
	}

}
