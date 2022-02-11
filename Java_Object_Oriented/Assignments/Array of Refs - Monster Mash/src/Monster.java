
public class Monster implements Comparable<Monster>{

	private int age, wt, ht;
	public void setHeight(int h){
		ht = h;
	}
	
	public int getHeight(){
		return ht;
	}
	
	public void setWeight(int w){
		wt = w;
	}
	
	public int getWeight(){
		return wt;
	}
	
	public void setAge(int a){
		age = a;
	}
	
	public int getAge(){
		return age;
	}
	
	
	public boolean isSmaller(Monster m){
		return ht < m.getHeight();
	}
	
	public boolean isLarger(Monster m){
		return ht > m.getHeight();
	}
	
	public String toString(){
		return ht + " " + wt + " " + age;
	}

	@Override
	public int compareTo(Monster m) {
		
		if(ht < m.getHeight())
			return -1;
		if(ht > m.getHeight())
			return 1;
		if(wt < m.getWeight())
			return -1;
		if(wt > m.getWeight())
			return 1;
		if(age < m.getAge())
			return -1;
		if(age > m.getAge())
			return 1;
		return 0;
	}
	
}
