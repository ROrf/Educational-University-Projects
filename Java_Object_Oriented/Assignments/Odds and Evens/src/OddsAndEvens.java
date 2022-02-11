
public class OddsAndEvens {
	private int[] arr, odd, even;
	public OddsAndEvens(){
		odd = getOddsAndEvens();
	}
	public OddsAndEvens(int[] input) {
		arr = input;
		odd = new int[arr.length];
		even = new int[arr.length];
		getOddsAndEvens();
	}
	public void getArray(int[] input) {
		arr = input;
	}
	public int[] getOddsAndEvens() {
		int x = 0, y = 0;
		for (int i = 0 ; i < arr.length; i++ ) {
			if (arr[i]%2 == 1) {
				odd[x] = arr[i];
				x++;
			}
			else if (arr[i]%2 == 0) {
	          even[y] = arr[i];
	          y++;
	        }
		}
		return odd;
	}
	public String toString() {
		int i = 0, x = 0, y = 0;
		System.out.print("Odds - [");
		for(i = 0; i < odd.length - 1; i++) {
			if(odd[i] != 0) {
				if (x == 0) {
					System.out.print(odd[i]);
					x++;
				}
				else {
					System.out.print(", " + odd[i]);
				}
			}
		}
		System.out.print("]\nEvens - [");
		for(i = 0; i < even.length - 1; i++) {
			if(even[i] != 0) {
				if (y == 0) {
					System.out.print(even[i]);
					y++;
				}
				else {
					System.out.print(", " + even[i]);
				}
			}
		}
		System.out.print("]");
		return " ";
	}
}
