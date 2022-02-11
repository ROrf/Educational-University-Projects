
public class Toy {
	public String name;
	public int stock;
	public Toy(String nm, int input) {
		this.name = nm;
		this.stock = input;
	}
	public Toy(String nm) {
		this.name = nm;
	}
	public String toString() {
		return name + " " + stock;
	}
}
