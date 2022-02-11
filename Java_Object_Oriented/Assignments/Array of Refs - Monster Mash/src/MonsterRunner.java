
import java.util.Arrays;
import java.util.Scanner;

public class MonsterRunner {

	public static void main(String[] args){
		Monster[] monsters;
		Scanner kb = new Scanner(System.in);
		
		System.out.println("How many monsters?");
		int size = kb.nextInt();
		monsters = new Monster[size];
		
		for(int i = 0; i < size; i++){
			Monster m = new Monster();
			System.out.println("Enter the height: ");
			m.setHeight(kb.nextInt());
			System.out.println("Enter the weight: ");
			m.setWeight(kb.nextInt());
			System.out.println("Enter the age: ");
			m.setAge(kb.nextInt());
			monsters[i] = m;
		}
		kb.close();
		Monster smallest = null, largest = null;
		System.out.println("HERD :: " + Arrays.toString(monsters));
		for(Monster m : monsters){
			
			if(largest == null){
				largest = m;
			}
			else{
				if(m.isSmaller(largest)){
					
				}
				else{
					largest = m;
				}
			}
			if(smallest == null){
				smallest = m;
			}
			else{
				if(m.isLarger(smallest)){
					
				}
				else{
					smallest = m;
				}
			}
		}
		
		System.out.println("SMALLEST :: " + smallest);
		System.out.println("LARGEST :: " + largest);
		Arrays.sort(monsters);
		System.out.println("NEW HERD :: " + Arrays.toString(monsters));
		
	}
	
}
