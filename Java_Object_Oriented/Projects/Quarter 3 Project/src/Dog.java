public class Dog extends Mammal implements Talkable{ //also refers to Mammal for name, weight, and sex
	private int hunger, fun, cleanliness, loyalty;
	public Dog(String nickname, double weight, String gender) { //constructor
		super(nickname, weight, gender);
		hunger = 50; //base stats for all dogs start at 50 for everything
		fun = 50;
		cleanliness = 50;
		loyalty = 50;
	}
	public void setHunger(int stomach) { //getters and setters
		hunger = hunger += stomach;
		if(hunger < 0) { //ensures stats never go beyond 0 or 100 (I know the lab is 1-100, but I like to include 0 to express completeness
			hunger = 0;
		}
		if(hunger > 100) {
			hunger = 100;
		}
		if(stomach > 0) {
			wt--; //changes the weight as you would by eating or exercising/ starving
		}
		if(stomach < 0) {
			wt++;
		}
		Loyalty(); //hunger and fun call Loyalty since they are the only two that can affect loyalty
	}
	public int getHunger() {
		return hunger;
	}
	public void setFun(int swell) {
		fun += swell;
		if(fun < 0) {
			fun = 0;
		}
		if(fun > 100) {
			fun = 100;
		}
		Loyalty();
	}
	public int getFun() {
		return fun;
	}
	public void setCleanliness(int clean) {
		cleanliness += clean;
		if(cleanliness < 0) {
			cleanliness = 0;
		}
		if(cleanliness > 100) {
			cleanliness = 100;
		}
	}
	public int getCleanliness() {
		return cleanliness;
	}
	private void Loyalty(){ //private so no outside sources could ever affect Loyalty, only hunger and fun
		if(fun >= (100 - hunger)){
			loyalty = fun;
		}
		else if(fun < (100 - hunger)){ 
			loyalty = (100 - hunger);
		}
	}
	public int getLoyalty() {
		return loyalty;
	}
	public String toString(){ //prints out all stats for dogs
		return "\nName :: " + name + "\tSex :: " + sex + "\tWeight :: " + wt + " lbs" + "\nHunger Level :: " + getHunger() + "\tFun Level :: " + getFun() + "\tCleanliness Level :: " + getCleanliness() + "\tLoyalty Level :: " + getLoyalty();
	}
	public void talk(){ //the only real customization I did (besides the numbers)
		if(hunger > 70 && hunger < 85) { //I have the dogs say different things depending on their mood
			System.out.println("Bark!");
		}
		else if(hunger >= 85) {
			System.out.println("Grrrrrrr!");
		}
		else if(loyalty >= 75) {
			System.out.println("*Pants in glee*");
		}
		else {
			System.out.println("Roof Roof!");
		}
	}
}
