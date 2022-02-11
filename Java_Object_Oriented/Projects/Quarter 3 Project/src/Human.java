import java.util.ArrayList;
import java.util.Scanner;
public class Human extends Mammal implements Talkable { //refers to Mammal for name, weight, and sex
public ArrayList<Dog> dogs = new ArrayList<Dog>(); //used to store dogs of each owner, as instructed
	private double money; //I based my calculations for dog food price based off of real word dog food costs, hence the need for a double
	private int dogNum, dogFood, feedTimes;
	public Human(String nickname, double weight, String gender, double dollars, int numDogs, int food) { //constructor
		super(nickname, weight, gender); //calls Mammal for this information
		money = dollars;
		dogNum = numDogs;
		dogFood = food;
		Scanner kb = new Scanner(System.in);
		for (int i = 0; i < dogNum; i++) { //creates the dog objects using user input
			System.out.println("Enter Dog #" + (i + 1) + "'s name :: ");
			String whatICallYa = kb.next();
			System.out.println("Enter " + whatICallYa + "'s weight :: ");
			int fatty = kb.nextInt();
			System.out.println("Enter "  + whatICallYa + "'s sex :: ");
			String maleOrFemale = kb.next();
            dogs.add(new Dog(whatICallYa, fatty, maleOrFemale)); //calls constructor of Dog
        }
		for(int j = 0; j < dogs.size(); j++) { //prints out characteristics of each dog upon establishment so users know their starting stats
			Dog dogTest = dogs.get(j);
			System.out.println(dogTest);
		}
	}
	public void walks(){ //walks the dog
		for(int i=0;i<dogs.size();i++)
        {
            Dog rufus=dogs.get(i);
            rufus.setFun(10); 
            rufus.setHunger(8); 
            rufus.setCleanliness(-10);
            System.out.println(rufus);
        }
	}
	public void feeds(){ //feeds the dog
		if(dogFood > 0) { //can only feed the dog if you have dog food
			for(int i=0;i<dogs.size();i++)
        	{
            	Dog rufus=dogs.get(i);
            	rufus.setFun(5); 
            	rufus.setHunger(-10); 
            	rufus.setCleanliness(-10);
            	System.out.println(rufus);
        	}
			feedTimes++;
			if(feedTimes%3==0) { //implemented so the human doesn't have access to infinite dog food
				dogFood -= dogNum;
			}
		}
		if(dogFood <= 0) { //decreases all stats if dog is starving aka there is no dog food
			for(int i=0;i<dogs.size();i++)
        	{
            	Dog rufus=dogs.get(i);
            	rufus.setFun(-5); 
            	rufus.setHunger(10); 
            	System.out.println(rufus);
        	}
		}
	}
	public void bathes(){ //bathe the dog
		for(int i=0;i<dogs.size();i++)
        {
            Dog rufus=dogs.get(i);
            rufus.setFun(-10); 
            rufus.setHunger(10); 
            rufus.setCleanliness(25);
            System.out.println(rufus);
        }
	}
	public void goToWork(){ //earns you a lot of money, but decreases all of dogs stats as well
		for(int i=0;i<dogs.size();i++)
        {
            Dog rufus=dogs.get(i);
            rufus.setFun(-10); 
            rufus.setHunger(10); 
            rufus.setCleanliness(-5);
            System.out.println(rufus);
        }
		money += (2.56 * 2 * dogNum);
	}
	public void passTheTime(){ //every human passes the time at the end of a day
		for(int i=0;i<dogs.size();i++)
        {
            Dog rufus=dogs.get(i);
            rufus.setFun(-10); 
            rufus.setHunger(10);
            rufus.setCleanliness(-5);
            System.out.println(rufus);
        }
		money += (1.28 * dogNum);
	}
	public void buysFood(){ //so the human can buy more food if they run out
		for(int i=0;i<dogs.size();i++)
        {
            Dog rufus=dogs.get(i);
            rufus.setFun(10); 
            rufus.setHunger(5); 
            rufus.setCleanliness(-5);
            System.out.println(rufus);
        }
		money -= (2.56 * dogNum);
	}
	public String toString(){ //prints the characteristics of the human
		return "\nName :: " + name + "\tSex :: " + sex + "\tWeight :: " + wt + " lbs" + "\nBank Account :: $" + money + "\tBags of Dog Food :: " + dogFood + "\tNumber of Dogs :: " + dogNum;
	}
	public void talk(){  //says "I love my dogs!" every time (since this is what the lab is about) and then calls the talk method of Dog for each dog
		System.out.println("\nI love my dogs!");
		for(int i = 0; i < dogs.size(); i++) {
			Dog dogTest = dogs.get(i);
			dogTest.talk();
		}
	}
}
