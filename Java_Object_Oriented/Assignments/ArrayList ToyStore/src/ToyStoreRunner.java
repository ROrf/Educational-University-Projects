import java.util.Scanner;
public class ToyStoreRunner {
	public static void main(String[] args) {
			Scanner kb = new Scanner(System.in);
			System.out.println("What toy are you looking for?");
			String nm = kb.nextLine();
			System.out.println("How many " + nm + " toys are in stock?");
			int stock = kb.nextInt();
			Toy tst = new Toy(nm, stock);
			System.out.println(tst);
			System.out.println("What is the name of your toystore?");
			kb.nextLine();
			String toy = kb.nextLine();
			String ans = "yes";
			int number = 0;
			String inv = "";
			while(ans.equals("yes")||ans.equals("y")) {
				System.out.println("Enter a toy :: ");
				inv += kb.next() + " ";
				number++;
				System.out.println("Would you like to enter another toy?");
				ans = kb.next();
			}
			ToyStore test = new ToyStore(toy, number);
		    for(int i = 0; i < number; i++) {
		       	Toy tester = new Toy(inv.split(" ")[i]);
		       	test.addToy(tester);
		    }
			System.out.println("Welcome to " + toy + " Toy Store!");
			System.out.println(test);
			System.out.println(test.getQuantities());
			System.out.println("max == " + test.getMax());
	}
}
