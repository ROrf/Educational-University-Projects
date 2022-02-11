
public class Calculate {
	private String series = "", twinprimes = ""; //will store the physical series and twin primes at work, and initialized at "" so they do not read null on the first run in the for loop
	private int bound; //will store how many times the series will run as an integer 
	private double sum; //will store the sum of the series as a double so we can view decimal places
	public Calculate() { //default constructor of the Calculate class
		series = getSeries(); //calls method getSeries() to retrieve the value of the series
		sum = getSum(); //calls method getSum() to retrieve the value of the sum of the series
		twinprimes = getTwins(); //calls method getTwins() to retrieve the value of the twin primes
	}
	public Calculate(int input) { //constructor using our input as a parameter
		bound = input; //retrieves our input value and stores it as variable bound to be public
		getSeries();
		getSum(); //calling these methods again to run them so we can get values for series, twinprimes, and sum
		getTwins();
	}
	public void getInput(int input) { //method to retrieve our input (with our input as a parameter)
		bound = input; //retrieves our input value and stores it as variable bound to be public
	}
	public String getSeries() { //method to calculate the series output
		for (int i = 1; i <= bound; i = i + 1) { //will run the for loop until the bound is passed
			if (i == 1) { //created to better suit the outline, so it wouldn't print "1/1" for i = 1
				series = series + "1";
			}
			else {
				series = series + " + " + "1/" + i; //shows the work 'physically' by continually adding to itself with each loop
			}
		}
		return series; //must return a string, returns full series, placed after for loop to include the whole series 
	}
	public double getSum() { //method to calculate the sum of the series, which will be output
		for (double i = 1; i <= bound; i = i + 1) {
			sum = sum + (1 / i); //continually adds value of series until the bound is reached
		}
		return sum; //must return an integer, returns sum
	}
	public String getTwins() { //method to calculate all the different twin primes
		for (int i = 3; i <= 1000; i = i + 1) { //will run numbers between 1 and 1000, as the outline asks
			int counter = 0; //creates the integer counter in the for loop since it's only needed in the loop. also resets the counter to 0 with every run through
			int num = i; //creates the integer num in the for loop since it's only needed in the loop
	         for(num = i; num>=3; num = num - 1) { //runs every number from i to 3 to divide by to test for prime numbers
	            if(i%num == 0) { //runs if the number can be fully divided by test value
	            	 counter = counter + 1; //adds one to counter if the number can be divided by the tested value without a remainder
	            }
	          }
	         for(num = (i - 2); num>=3; num = num - 1) { //runs every number from i to 3 to divide by to test for prime numbers
		            if((i - 2)%num == 0) { //runs if the number can be fully divided by test value
		            	 counter = counter + 1; //adds one to counter if the number can be divided by the tested value without a remainder
		            }
		          }
	          if (counter == 2){ //only runs if both numbers only have 2 multiples, because that is the definition of a prime number (in this case, both would add 1 since the number 1 can't be tested)
	        	  twinprimes = twinprimes + "(" + (i - 2) + "," + i + ") "; //adds the twin prime numbers in the correct format to twinprimes
	          }	
		}
		return twinprimes; //must return a string, returns full twin prime numbers
	}
	public String toString() { //method to return our output to be displayed on the console
		return "Series:: " + series + "\nSum of Series:: " + sum + "\nTwin Primes:: " + twinprimes; //will output all of the information we want to know nicely on three separate lines
	}
}
