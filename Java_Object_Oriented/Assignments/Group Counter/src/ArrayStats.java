
public class ArrayStats {
	private double[] arr, count, nu;
	private double sum;
	public ArrayStats() {
		nu = getNu();
	}
	public ArrayStats(double[] array, double[] size) {
		arr = array;
		count = size;
		nu = new double[count.length];
		getNu();
	}
	public void getArrayStats(double[] array, double[] size) {
		arr = array;
		count = size;
	}
	public double[] getNu() {
		for(int i = 0; i < arr.length; i++) {
			for(int x = 0; x < count.length; x++) {
				sum = 0;
				if(count[x] == 1) { 
					if(i == 0) {
						nu[x]++;
					}
					else if (i > 0){
						if(arr[i] != arr[i-1]) {
							nu[x]++;
						}
					}
				}
				else if (count[x] > 1 && i <= arr.length - count[x] - 1) { 
						if(arr[i] != arr[i + (int)count[x]]){ 
							for(int y = 0; y < count[x]; y++) {
								sum = sum + arr[i + y]; 
							}
							sum = sum / count[x];
							if (sum == arr[i]) {
								nu[x]++;
							}
						}
				}
			}
		}
		return nu;
	}
	public String toString() {
		int x = 0;
		for(int i = 0; i < arr.length; i++) {
			if(x == 0) {
				System.out.print("[" + (int)arr[i]);
				x++;
			}
			else {
				System.out.print(", " + (int)arr[i]);
			}
		}
		System.out.print("]\n");
		for(int y = 0; y < count.length; y++) {
			System.out.print("size " + (int)count[y] + " count == " + (int)nu[y] + "\n");
		}
		return "";
	}
}
