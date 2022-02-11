import java.util.ArrayList;
public class ArrayListFunHouse {
	private ArrayList<Integer> original, composite, factors;
	public ArrayListFunHouse() {
		factors = getFactors();
		composite = getComposites();
	}
	public ArrayListFunHouse(ArrayList<Integer> input) {
		original = input;
		getFactors();
		getComposites();
	}
	public void getArray(ArrayList<Integer> input) {
		original = input;
	}
	public ArrayList<Integer> getFactors(){
		factors = new ArrayList<Integer>();
		for(int i = 0; i < original.size(); i++) {
			for(int x = 1; x <= original.get(i); x++) {
				if((original.get(i)%x) == 0 && x != 1 && x != original.get(i)) {
					factors.add(x); //problem
				}
			}
		}
		return factors;
	}
	public ArrayList<Integer> getComposites(){
		composite = new ArrayList<Integer>();
		for(int i = 0; i < original.size(); i++) {
			int facts = 0;
			for(int x = 1; x <= original.get(i); x++) {
				if(original.get(i)%x == 0) {
					facts++;
				}
			}
			if(facts > 2) {
				composite.add(original.get(i)); //problem
			}
		}
		return composite;
	}
	public String toString() {
		return factors + "\n\nOriginal List\n" + original + "\nComposite List\n" + composite;
	}
}
