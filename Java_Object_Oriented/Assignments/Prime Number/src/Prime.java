
public class Prime {
	private int num;
	private String prime;
	public Prime() {
		prime = getPrime();
	}
	public Prime(int input) {
		num = input;
		getPrime();
	}
	public void getNum(int input) {
		num = input;
	}
	public String getPrime() {
		int counter = 0;
        for(int i = num; i>=3; i = i - 1) { 
           if(num%i == 0) { 
           	 counter = counter + 1; 
           }
         }
        if (counter == 1) {
        	prime = " is ";
        }
        else {
        	prime = " is not ";
        }
        return prime;
	}
	public String toString() {
		return num + prime + "prime.";
	}
}
