import java.util.ArrayList;

public class ExpressionSolver {
	private ArrayList<String> original;
	private int total = 0;
	public ExpressionSolver() {
		total = getTotal();
	}
	public ExpressionSolver(ArrayList<String> input) {
		original = input;
		getTotal();
	}
	public void getArrayList(ArrayList<String> input) {
		original = input;
	}
	public int getTotal() {
		int z = 0;
		for(int x = 0; x < original.size(); x++) {
				if(original.get(x).equals("*")) {
						original.set(x, Integer.toString((Integer.parseInt(original.get(x - 1)) * (Integer.parseInt(original.get(x + 1))))));
						original.remove(x - 1);
						original.remove(x);
						original.add(Integer.toString(0));
						original.add(Integer.toString(0));
				}
				if(original.get(x).equals("/")) {
						original.set(x, Integer.toString((Integer.parseInt(original.get(x - 1)) / (Integer.parseInt(original.get(x + 1))))));
						original.remove(x - 1);
						original.remove(x);
						original.add(Integer.toString(0));
						original.add(Integer.toString(0));
				}
		}
		for(int y = 0; y < original.size(); y++) {
			if(original.get(y).equals("+")) {
					total = total + (Integer.parseInt(original.get(y - 1)) + (Integer.parseInt(original.get(y + 1))));
					z++;
			if(original.get(y).equals("-")) {
					total = total + (Integer.parseInt(original.get(y - 1)) - (Integer.parseInt(original.get(y + 1))));
					z++;
			}
		}
	}
		if(z == 0) {
			total = Integer.parseInt(original.get(0));
		}
		return total;
	}
	public String toString() {
		return("Total = " + total);
	}
}
