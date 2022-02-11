public class Mammal{ //super class, since humans and dogs are mammals
	protected String name; //protected so they can be used in the toStrings of the other classes
	protected String sex;
	protected double wt;
	public Mammal(String nickname, double weight, String gender){ //what implemented methods call to get names, weights, and sexes
		name = nickname;
		wt = weight;
		sex = gender;
	}
	public void setName(String name) { //getters and setters
		this.name = name;
	}
	public String getSex() {
		return sex;
	}
	public void setSex(String sex) {
		this.sex = sex;
	}
	public double getWt() {
		return wt;
	}
	public void setWt(double wt) {
		this.wt = wt;
	}
}
