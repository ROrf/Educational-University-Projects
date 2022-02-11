import java.util.ArrayList;
import java.util.Scanner;
public class Runner {
	public static void main(String[] args){
		Scanner kb = new Scanner(System.in); //use Scanner a lot to get most my data
		System.out.println("How many humans are in your society? :: ");
		int size = kb.nextInt();
		ArrayList<Human> mammals =  new ArrayList<Human>(); //arraylist used for convenience in calling Human later
		for(int i = 0; i < size; i++){
			System.out.println("\nWhat is the name of Human #" + (i + 1) + "? :: ");
			String name = kb.next();
			System.out.println("What is " + name + "'s sex? :: ");
			String sex = kb.next();
			System.out.println("What is " + name + "'s weight? :: ");
			double weight = kb.nextDouble();
			int numDogs = (int)(4 * Math.random() + 1); //randomizes number of dogs each human has from 1 to 4
			int food = numDogs;
			double dollars = 2.56 * numDogs;
			Human humanTest = new Human(name, weight, sex, dollars, numDogs, food); //calls Human constructor
			mammals.add(humanTest); //adds to arraylist as will be used later
			System.out.println("\n" + humanTest.toString()); //prints original stats of each human
		}
		String ans = "yes";
		while(ans.equals("yes") || ans.equals("YES") || ans.equals("Yes") || ans.equals("y") || ans.equals("Y")) { //loops until you don't wanna keep playing
			String answer = "yes";
			while(answer.equals("yes") || answer.equals("YES") || answer.equals("Yes") || answer.equals("y") || answer.equals("Y")) { //loops until you're done for the day
				int humanSpot = 0;
				boolean nameTrue = false;
				while(nameTrue == false) { //used since I used Scanner so you can only call a Human who's name you inputted earlier
					System.out.println("Enter the name of a human in the population :: ");
					String popName = kb.next();
					for(int j = 0; j < mammals.size(); j++) {
						if(mammals.get(j).name.equals(popName)) {
							nameTrue = true;
							humanSpot = j;
						}
					}
				}
				System.out.println("Would you like to walk, feed, bathe, work, buy, nothing, or quit? :: "); //gives key phrases
				String action = kb.next(); //lines below this one are used to ensure you can only do the actions previously listed
				while(action.equals("walk") == false && action.equals("feed") == false && action.equals("bathe") == false && action.equals("work") == false && action.equals("buy") == false && action.equals("nothing") == false && action.equals("quit") == false) {
					System.out.println("You did not perform an acceptable action. Please try again :: ");
					action = kb.next();
				}
				if(action.equals("walk")) { //a bunch of if statements to call corresponding methods
					Human humanTest = mammals.get(humanSpot);
					humanTest.walks();
					System.out.println(humanTest.toString());
				}
				else if(action.equals("feed")) {
					Human humanTest = mammals.get(humanSpot);
					humanTest.feeds();
					System.out.println(humanTest.toString());
				}
				else if(action.equals("bathe")) {
					Human humanTest = mammals.get(humanSpot);
					humanTest.bathes();
					System.out.println(humanTest.toString());
				}
				else if(action.equals("work")) {
					Human humanTest = mammals.get(humanSpot);
					humanTest.goToWork();
					System.out.println(humanTest.toString());
				}
				else if(action.equals("buy")) {
					Human humanTest = mammals.get(humanSpot);
					humanTest.buysFood();
					System.out.println(humanTest.toString());
				}
				else if(action.equals("quit")) {
					System.exit(0); //exits program, sending a message saying no error was found due to the exit
				}
				else {
				} //asks before ending day
				System.out.println("\nWould you like to do anything else with " + mammals.get(humanSpot).name + " or another human? :: ");
				answer = kb.next();
			}
			for(int i = 0; i < size; i++) { //all humans pass time, loops through all humans
				Human humanTest = mammals.get(i);
				humanTest.passTheTime();
				System.out.println(humanTest.toString());
				humanTest.talk();
			}
			System.out.println("\nWould you like to continue this simulation? :: "); //end case
			ans = kb.next();
		}
		kb.close();
	}
}
