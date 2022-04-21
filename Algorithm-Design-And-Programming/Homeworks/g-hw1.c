//Ryan Orf
//rconzc
#include<stdio.h> //standard input/output pack

float getRating(unsigned int row, unsigned int column) //separate float method, which receives argument parameters unsigned int row and column to be implemented in the return statement
{
    float rating[5][7] = {{3.0,3.5,4.5,5.0,4.5,5.0},{4.0,5.0,4.5,4.0},{5.0,5.0,4.0,3.5},{5.0, 5.0}, {3.0, 3.0, 5.0}}; //float matrix, declared with a set length of 5 rows and 7 columns, and with initialized values for the star ratings except the averages
    for(int i = 0; i < 6; i++) //for loop that adds the total of all the star ratings for that artist, with the upper limit differing depending on which artist (as some have more album ratings than others)
    {
        rating[0][6] += rating[0][i];
    }
    rating[0][6] = rating[0][6] / 6; //divides the total by the number of albums to obtain the average
    for(int i = 0; i < 4; i++)
    {
        rating[1][4] += rating[1][i];
    }
    rating[1][4] = rating[1][4] / 4;
    for(int i = 0; i < 4; i++)
    {
        rating[2][4] += rating[2][i];
    }
    rating[2][4] = rating[2][4] / 4;
    for(int i = 0; i < 3; i++)
    {
        rating[4][3] += rating[4][i];
    }
    rating[4][3] = rating[4][3] / 3;
    return rating[row][column]; //return statement will return the float value with the
}

int main(void) //main method, void with no return
{
    int again = 1; //again is our control int variable that determines ehther we continue or not, declared and initialized as 1 so no matter what the user goes through the while at least once
    while(again != 0) //while loop that will continue the process as long as the user inputs a nonzero integer value when prompted
    {
        unsigned int artist; //declared artist number, determining which artist we choose from the list, and unsigned int in accord with the argument parameters of the getRating method
        unsigned int album; //declared album number, determing which album we choose from the list, unsigned int for same reason
        printf("\nSelect an artist:\n1. Bruce Springsteen\n2. Steve Earle\n3. The Clash\n4. The Sex Pistols\n5. P.J. Harvey\n"); //prints list in desired format
        scanf("%d", &artist); //reads in an integer value assigned to artist given by the user 
        while(artist < 1 || artist > 5) //loop that ensures the integer the user inputs is on the list, i.e. between 1 and 5, hence the or(||)
        {
            printf("\n** Please enter a selection from 1 to 5 **\n"); //warning statement prompting the user to input another value for artist, formatted as shown on the rubric
            scanf("%d", &artist);
        }
        switch (artist) //switch case that will provide different album lists given which artist is selected
        {
            case 1: //corresponds with the choice of option 1 on the artist list, Bruce Springsteen
                printf("\nSelect an album:\n1. Greetings fro Asbury Park\n2. The Wild, The Innocent, and The E-Street Shuffle\n3. Born to Run\n4. Darkness On The Edge Of Town\n5. The River\n6. Nebraska\n7. All Albums by this Artist\n"); //displays new list for all album options available for Bruce Springsteen, as well as the All Albums option that will output the average star ratings for all his albums
                scanf("%d", &album); //intakes an integer value initiated to album given by the user
                while(album < 1 || album > 7) //loop to verify that the user-prompted integer value is one that can be used, in this case between 1 and 7
                {
                    printf("\n** Please enter a selection from 1 to 7 **\n");
                    scanf("%d", &album);
                }
                break; //breaks case so the switch case does not continue unintentionally and lead to an undesirable output

            case 2: //new case for option 2 on the artist list
                printf("\nSelect an album:\n1. Copperhead Road\n2. I Feel Alright\n3. El Corazon\n4. Trascendental Blues\n5. All Albums by this Artist\n");
                scanf("%d", &album);
                while(album < 1 || album > 5)
                {
                    printf("\n** Please enter a selection from 1 to 5 **\n");
                    scanf("%d", &album);
                }
                break;

            case 3:
                printf("\nSelect an album:\n1. The Clash\n2. London Calling\n3. Sandinista\n4. Combat Rock\n5. All Albums by this Artist\n");
                scanf("%d", &album);
                while(album < 1 || album > 5)
                {
                    printf("\n** Please enter a selection from 1 to 5 **\n");
                    scanf("%d", &album);
                }
                break;

            case 4:
                printf("\nSelect an album:\n1. Never Mind The Bollocks, Here's the Sex Pistols\n2. All Albums by this Artist\n");
                scanf("%d", &album);
                while(album < 1 || album > 2)
                {
                    printf("\n** Please enter a selection from 1 to 2 **\n");
                    scanf("%d", &album);
                }
                break;
                
            case 5:
                printf("\nSelect an album:\n1. Dry\n2. Rid of Me\n3. Stories From the City, Stories From the Sea\n4. All Albums by this Artist\n");
                scanf("%d", &album);
                while(album < 1 || album > 4)
                {
                    printf("\n** Please enter a selection from 1 to 4 **\n");
                    scanf("%d", &album);
                }
                break;
            case ' ': //case to ignore spaces, indents, and new lines
            case '\n':
            case '\t':
                break;
            default: //default case that does absolutely nothing and really isn't needed
                break;
        }   
            printf("\n*** Stars = %.1f ***\n", getRating(--artist, --album)); //prints the desired star rating by calling the getRating class. Both artist and album are decremented because the list is supposed to start at 1, but matrix and array values start at 0
            printf("\nEnter 0 to exit or any other number to continue...\n"); //prompt for the user to enter an integer, with nonzero equating to another iteration of the loop and with zero ending the loop, and therefore, the entire program
            scanf("%d", &again); //records input of the user and assigns that integer value to again, our control loop variable
    }
}
