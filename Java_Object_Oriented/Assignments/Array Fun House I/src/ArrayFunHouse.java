
public class ArrayFunHouse {
	private int[] arr, nu;
	private int sum1, sum2, four, nine, seven1, seven2;
	public ArrayFunHouse() {
		sum1 = getSum1();
		sum2 = getSum2();
		four = getFour();
		nine = getNine();
		seven1 = getSeven1();
		nu = getNu();
		seven2 = getSeven2();
	}
	public ArrayFunHouse(int[] input) {
		arr = input;
		getSum1();
		getSum2();
		getFour();
		getNine();
		getSeven1();
		nu = new int[arr.length - seven1];
		getNu();
		seven2 = getSeven2();
	}
	public void getArray(int[] input){
		arr = input;
	}
	public int getSum1() {
		for(int i = 3; i <= 6; i++) {
			sum1 = sum1 + arr[i];
		}
		return sum1;
	}
	public int getSum2() {
		for(int i = 2; i <= 9; i++) {
			sum2 = sum2 + arr[i];
		}
		return sum2;
	}
	public int getFour() {
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] == 4) {
				four++;
			}
		}
		return four;
	}
	public int getNine() {
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] == 9) {
				nine++;
			}
		}
		return nine;
	}
	public int getSeven1() {
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] == 7) {
				seven1++;
			}
		}
		return seven1;
	}
	public int[] getNu() {
		int x = 0;
		for(int i = 0; i < arr.length; i++) {
			if(arr[i] != 7) {
				nu[x] = arr[i];
				x++;
			}
		}
		return nu;
	}
	public int getSeven2() {
		for(int i = 0; i < nu.length; i++) {
			if(nu[i] == 7) {
				seven2++;
			}
		}
		return seven2;
	}
	public String toString() {
		int x = 0, y = 0;
		for(int i = 0; i < arr.length; i++) {
			if(x == 0) {
				System.out.print("[" + arr[i]);
				x++;
			}
			else {
				System.out.print(", " + arr[i]);
			}
		}
		System.out.print("]\n sum of spots 3-6 = " + sum1 + "\nsum of spots 2-9 = " + sum2 + "\n# of 4s = " + four + "\n# of 9s = " + nine + "\n# of 7s = " + seven1 + "\nnew array with all 7s removed =  [");
		for(int i = 0; i < nu.length; i++) {
			if (y == 0) {
				System.out.print(nu[i]);
				y++;
			}
			else {
			System.out.print(", " + nu[i]);
			}
		}
		return ("]\n# of 7s = " + seven2);
	}
}
