
public class Histogram {
	public int[] hist, nums;
	public Histogram() {
		nums = getNums();
	}
	public Histogram(int[] input) {
		hist = input;
		nums = new int[10];
		getNums();
	}
	public void getHistogram(int[] input) {
		hist = input;
	}
	public int[] getNums() {
		for(int i = 0; i < hist.length; i++) {
			if(hist[i] == 0) {
				nums[0]++;
			}
			else if (hist[i] == 1) {
				nums[1]++;
			}
			else if (hist[i] == 2) {
				nums[2]++;
			}
			else if (hist[i] == 3) {
				nums[3]++;
			}
			else if (hist[i] == 4) {
				nums[4]++;
			}
			else if (hist[i] == 5) {
				nums[5]++;
			}
			else if (hist[i] == 6) {
				nums[6]++;
			}
			else if (hist[i] == 7) {
				nums[7]++;
			}
			else if (hist[i] == 8) {
				nums[8]++;
			}
			else if (hist[i] == 9) {
				nums[9]++;
			}
		}
		return nums;
	}
	public String toString() {
		for(int i = 0; i <= 9; i++) {
			System.out.println(i + " - " + nums[i]);
		}
		return "";
	}
}
