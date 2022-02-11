
public class Test {
	 public static void main(String[] args) {

         Zoo nozha = new Zoo("nozha", 100);
         Animal lion = new Animal("lion","fine","20","male");
         nozha.addAnimal(lion); 

         Animal tiger = new Animal("tiger","ssc","30","female");
         nozha.addAnimal(tiger);
         
         Animal elephant = new Animal("elephant", "fine", "45", "male");
         nozha.addAnimal(elephant);
         System.out.println("Number of animals in zoo: " + nozha.getSizeOfZoo());
         System.out.println(nozha.getName(2));
     }
}
