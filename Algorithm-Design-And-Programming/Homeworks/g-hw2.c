//Ryan Orf
//rconzc
#include<stdio.h> //imports standard input/output header for implementation of printf and scanf

void printAtBats(int atBats[], int batter); //prototypes for functions
void calculateBattingAverage(int atBats[], float avg[], int index);
void calculateSluggingPercentage(int atBats[], float pct[], int index);
void printResult(float avg[], float pct[]);
void doCalculations(int atBats1[], int atBats2[], int atBats3[], float battingAvg[], float sluggingPct[]);
float avg[3] = {0,0,0}; //global variables float arrays have a size of 3 to account for 3 batters, with all indexes instantiated to 0 so I do not encounter an uninstatiated error. Global because these two arrays are used within several functions, and I would like to access/manipulate them in more than just one
float pct[3] = {0,0,0}; //(refer to above, same concept only holds slugging percentages as opposed to batting averages

int main(void) //main function, program starts here
{
    /*int batter1[100], batter2[100], batter3[100]; //I would assume the user would not elect to test more than 100 hits per batter, and since I had to declare the arrays with a size, I chose 100. I also could have prompted the user for how many hits they would input for each batter, but the assignment asks to use -1 as an exit case, so I went with this option. I believe the other would be more viable however
    printf("\n**NOTE: Please hit enter after every input**\n"); //note before inputting numbers for the user. You could type them all on one line, but with my format, it would appear confusing as I print something after each entry
    for(int i = 1; i < 4; i++) //for loop from 1 to 3 to test each batter
    {
        int inputArray[100]; //input array accepts the user's input, also declared with size 100 so as not to rush into any issues
        for(int i = 0; i < 100; i++) //for loop that goes through each index of the input array
        {
            inputArray[i] = 0; //instantiates each index of the array as 0 to prevent uninstantiation errors (although this may be unnecessary because I believe all indexes are automatically set to 0 in C, but better safe than sorry!
        }
        int typeOfHit = 0, position = 0; //declared and instantiated for input purposes, both can and will be changed, so they need not be static
        printf("Enter data for Batter #%d\n", i); //indicate which batter the data is being used for
        while(typeOfHit>=0) //ensures the data is an at bat, and since typeOfHit == 0, it will run at least once
        {
            scanf("%d", &typeOfHit); //accepts user input for the type of hit
            while(typeOfHit<-1 || typeOfHit > 4) //checks to see if the input data is an option for a type of hit
            {
                printf("That is not an acceptable input. Try again\n"); //reenter case, asks for another input
                scanf("%d", &typeOfHit); //input in the case of an unacceptable input prior
            }
            inputArray[position] = typeOfHit; //sets the position of the array to the number corresponding to the type of hit
            if(typeOfHit == -1) //if to check if the type of hit was the exit case, -1
            {
                break; //break will exit for loop, meaning no more entries will be accepted
            }
            position++; //moves on to the next position of the array
            printf("Enter another at bat if you wish, or -1 to exit\n"); //prompts user for another input
        }
        switch(i) //necessary depending on which iteration of the outer for loop
        {
            case 1: //case 1 corresponds with batter 1
                for(int i = 0; i < 100; i++) //for loop that runs through each index of the array
                {
                    batter1[i] = inputArray[i]; //the value at that index is then transferred over to the array batter1 as inputArray will be changed in the next iteration
                }
                break; //ends case so as not to continue and give incorrect data
            case 2: //case 2 corresponds with batter 2
                for(int i = 0; i < 100; i++) //same as case 1
                {
                    batter2[i] = inputArray[i]; //same as case 1 only with batter 2
                }
                break; //same reason for break
            case 3: //case 3 corresponds with batter 3
                for(int i = 0; i < 100; i++) //same as prior cases
                {
                    batter3[i] = inputArray[i]; //same as prior cases only with batter 3
                }
                break; //same reason for break
        }
    }*/
    int batter1[] = {0,1,0,1,2,0,0,0,0,-1}; //declares and instantiates batter arrays. Earlier I implemented a method of input, but after asking, I was told to simply declare the arrays to the test case
    int batter2[] = {3,0,1,0,0,4,0,0,1,0,0,0,0,0,-1};
    int batter3[] = {0,0,0,4,2,0,0,0,0,0,1,-1};
    printAtBats(batter1, 1); //calls function to print the at bats of batter 1
    printAtBats(batter2, 2); //calls function to print the at bats of batter 2
    printAtBats(batter3, 3); // calls function to print the at bats of batter 3
    doCalculations(batter1, batter2, batter3, avg, pct); //calls do calculations with the 3 batter arrays and the so far unused avg and pct to obtain the batting averages and slugging percentages
    printResult(avg, pct); //cakks function to prints the averages and percentages of the three batters
}

void printAtBats(int atBats[], int batter) //no return, print at bats function, takes in the batter array and the number batter
{
    printf("\nPlayer %d at-bats:\n", batter); //used for convenience sake to obtain same formatting as example without conditionals
    for(int i = 0; i < 100; i++) //loops through each index of array. Note that I use 100, as in accord with my input code that I commented out. I chose not to change any of the rest of my code, as it works perfectly fine
    {
        if(atBats[i] == -1) //checks for exit case, which is part of the array, so as to end the loop and not include it within the at bats data
        {
            break; //breaks for reason stated above
        }
        printf("%d ", atBats[i]); //prints the at bats on one line, hence no new line
    }
    printf("\n"); //prints a new line for formatting sake
}
void doCalculations(int atBats1[], int atBats2[], int atBats3[], float battingAvg[], float sluggingPct[]) //no return, function will do calculations by calling two other functions, accepting batter arrays, avg array, and pct array as parameters as the calculations are being done to obtain the averages and percentages of these three batters
{
    calculateBattingAverage(atBats1, battingAvg, 0); //calls for batting average with index 0, indicating batter 1
    calculateSluggingPercentage(atBats1, sluggingPct, 0); //calls for slugging percentage with index 0, indicating batter 1
    calculateBattingAverage(atBats2, battingAvg, 1); //calls indicating batter 2... 
    calculateSluggingPercentage(atBats2, sluggingPct, 1);
    calculateBattingAverage(atBats3, battingAvg, 2);
    calculateSluggingPercentage(atBats3, sluggingPct, 2);
}
void calculateBattingAverage(int atBats[], float avg[], int index) //void function, calculates batting averages, accepts parameters of the batter, the averages array it will modify, and the index of where to include the average in avg. In hindsight, I probably don't need to call avg since avg is global, but the example does so I did just to follow JimR's instructions as closely as possible
{
    float hits = 0.0; //hits is a variable that will keep track of the number of hits. hits was declared a float because if hits was an integer, the value of the average would be 0, since integer math rounds down. Therefore, at least one variable had to be a float, hence hits, instantiated to 0.0
    int i; //declared outside for loop because I use i to keep track of the number of hits as opposed to creating another variable
    for(i = 0; i < 100; i++) //for loop goes through each index
    {
        if(atBats[i] == -1) //exit case -1
        {
            break; //breaks in the case of -1 so it is not included in the math and ends the array so it does not continue since there are 'technically' 100 spots
        }
        if(atBats[i] > 0) //conditional if checks to see if the hit (value of the index we are checking) is a hit, denoted as 1, 2, 3, or 4
        {
            hits++; //increments hits by one, since any of these count as one hit
        }
    }
    avg[index] = hits/i; //derives the average using the given formula on the instructions, setting the index (which is the batter) to the average
}
void calculateSluggingPercentage(int atBats[], float pct[], int index) //this function is almost a clone to the batting average function, the difference being this one finds the slugging percentage
{
    float bases = 0.0; //declared a float to avoid integer math with every index being 0
    int i; //declared outside for loop to be implemented outside of for loop
    for(i = 0; i < 100; i++) //goes through each index
    {
        if(atBats[i] == -1) //checks for exit case
        {
            break; //breaks to end loop, so as not to include -1 in math or go past -1 in the array
        }
        bases += atBats[i]; //rather than incrementing, we must add the number of bases they got, and since 0 indicates no bases, we do not need another conditional
    }
    pct[index] = bases/i; //uses formula given for calculating slugging percentage
}
void printResult(float avg[], float pct[]) //void function, prints the averages and percentages as desired
{
    printf("\nBatting Averages:\n"); //has two new lines, one before and one after, for superficial purposes of looking cleaner
    printf("\tPlayer 1: %.3f\n", avg[0]); //displays average of batter 1, tabbed over as in the example and only providing 3 decimal places
    printf("\tPlayer 2: %.3f\n", avg[1]); //same with batter 2
    printf("\tPlayer 3: %.3f\n", avg[2]); //same with batter 3
    printf("\nSlugging Percentages:\n"); //two new lines, outputs slugging percentages
    printf("\tPlayer 1: %.3f\n", pct[0]); //displays percentage of batter 1, tabbed over as in the example and only providing 3 decimal places
    printf("\tPlayer 2: %.3f\n", pct[1]); //same with batter 2
    printf("\tPlayer 3: %.3f\n", pct[2]); //same with batter 3
}
