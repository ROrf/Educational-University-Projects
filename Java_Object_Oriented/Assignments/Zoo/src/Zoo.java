import java.util.ArrayList;
public class Zoo {
	 String name; 
	    double area; 
	    int sizeOfZoo = 0;
	    ArrayList<Animal> animals = new ArrayList<Animal>();


	    public Zoo(String name, double area) { 
	        this.name = name; 
	        this.area = area;

	    }   

	        public void addAnimal(Animal ann) {
	        animals.add(ann); 
	    } 

	        public int getSizeOfZoo() {
	                return animals.size();
	        }
	        public String getName(int input) {
	        	return animals.get(input).name;
	        }
}
