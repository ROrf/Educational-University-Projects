import java.util.ArrayList;
public class ToyStore {
	private ArrayList<Toy> store = new ArrayList<Toy>();
	public String storeName, maximum;
	public int stock, num;
	public ToyStore(String input, int in) {
		this.storeName = input;
		this.num = in;
	}
	public void addToy(Toy ty) {
		store.add(ty);
	}
	public String getToy(int input) {
    	return store.get(input).name;
    }
	public String getQuantities() {
		System.out.print("[");
		int max = 0;
		for(int i = 0; i < store.size(); i++) {
			int count = 1;
			for(int j = i + 1; j < store.size(); j++) {
				if(store.get(i).name.equals(store.get(j).name)) {
					count++;
					store.remove(j);
					j--;
				}
			}
			if(i != store.size() - 1) {
				System.out.print(store.get(i).name + " " + count + ", ");
			}
			else {
				System.out.print(store.get(i).name + " " + count + "]");
			}
			if(count>max) {
				max = count;
				maximum = store.get(i).name;
			}
		}
		return "";
	}
	public String getMax() {
		return maximum;
	}
	public String toString() {
		return "";
	}
	
}
