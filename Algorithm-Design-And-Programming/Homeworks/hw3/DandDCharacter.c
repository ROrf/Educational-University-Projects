//Ryan Orf
//rconzc
//starter code retrieved from starter linked on canvas
#include<stdio.h> //headers
#include<string.h>
#include<stdlib.h>
#include<time.h> //header for what I used for rolling dice
#include "Random.h" //did not work for me for some reason so I improvised
#include "DandDCharacter.h"

//***SIDE NOTE: This may be something I accidentally did, but my program had an error originally in DandDCharacter.h, so if that is the case, then the player name does not have a semicolon. It may have been me, or it may have already been like that, I do not know, but please be aware. THANKS!***

char * getAncestry(int selection) //function that returns type of ancestry based off the "enum" numeric value
{
    switch (selection) //switch for enums
    {
        case human: //uses enum values as opposed to normal integers
            return "human"; //will return here and end function
            break;
        case elf:
            return "elf";
            break;
        case halfling: 
            return "halfling";
            break;
        case dwarf: 
            return "dwarf";
            break;
        case half_elf:
            return "half_elf";
            break;
        case half_orc:
            return "half_orc";
            break;
        default: //need the default
            break; //overcautious break
    }
    return "human"; //returns human just in case although should never have this problem, yet a return at the end is required
}

int enumAncestry(int selection) //int function to return enum corresponding with input int
{
    int retNum = human; //declares and intializes to human (0) 
    switch (selection) //switch for numbers
    {
        case 0:
            retNum = human; //corresponding enums with integers
            break;
        case 1: 
            retNum = elf;
            break;
        case 2: 
            retNum = halfling;
            break;
        case 3: 
            retNum = dwarf;
            break;
        case 4:
            retNum = half_elf;
            break;
        case 5:
            retNum = half_orc;
            break;
        default: //default again just in case, this time it makes sure retNum is the base value (human)
            retNum = human;
            break;
    }
    return retNum; //returns the int
}

int rollTheDice() //int function for rolling dice
{
    int rolls[4]; //int array for all 4 rolls
    int roll; //typically I do not declare int variables outside for loops, however I for some reason encountered a problem when trying to compile, as I guess this is not a version of C99 or higher
    for(roll = 0; roll < 4; roll++)
    {
        rolls[roll] = (rand() % 6) + 1; //randomizes "roll" value between 1 and 6
    }
    int i;
    for(i = 0; i < 4; i++) //outer loop for bubble sort
    {
        int j;
        for(j = 0; j < 4; j++) //inner loop for bubble sort
        {
            if(rolls[j] > rolls[j+1]) //if value is larger than the next
            {
                int hold = rolls[j]; //temp variable for bubble sort
                rolls[j] = rolls[j+1]; //the bubble sort
                rolls[j+1] = hold;
            }
        }
    }
    int final = rolls[1] + rolls[2] + rolls[3]; //adds the highest 3 rolls
    return final; //returns the sum of the highest 3
}

void GenerateCharacter(Character * pCharacter) //generate function
{
    srand(time(NULL)); //randomizes time so the rolls are truly random
    pCharacter->strength = rollTheDice(); //calls rollTheDice for each
    pCharacter->dexterity = rollTheDice();
    pCharacter->constitution = rollTheDice();
    pCharacter->intelligence = rollTheDice();
    pCharacter->wisdom = rollTheDice();
    pCharacter->charisma = rollTheDice();
    int selection = -1; //must be lower than 0 or greather than 5
    while(selection < 0 || selection > 5) //error-checking
    {
        printf("\nSelect an ancestry from this list:\n0) human\n1) elf\n2) halfling\n3) dwarf\n4) half_elf\n5) half_orc\n");
        printf("Enter a selection: ");
        scanf("%d", &selection); //had to split this up because I encountered severe problems when I had more on the scanf than just the value
        printf("\n");
        if(selection < 0 || selection > 5) //prints error message
        {
            printf("*** Error: selection must be 0-5***\n");
        }
    }
    pCharacter->ancestry = enumAncestry(selection); //calls enumAncestry to change from a normal integer to an enum
    char name[256]; //no name will be > 256
    printf("Please Enter Your Character's Name (no spaces): ");
    scanf("%s", name);
    printf("\n");
    strcpy(pCharacter->charname, name); //copies string value
    printf("Please Enter Your Name (no spaces): ");
    scanf("%s", name);
    printf("\n");
    strcpy(pCharacter->playername, name);
}

void DisplayCharacter(Character * pCharacter) //display function
{
    printf("\nName: %.50s\nBy: %.50s\nStrength: %d\nDexterity: %d\nConstitution: %d\nIntelligence: %d\nWisdom: %d\nCharisma: %d\nAncestry: %.50s\n", pCharacter->charname, pCharacter->playername, pCharacter->strength, pCharacter->dexterity, pCharacter->constitution, pCharacter->intelligence, pCharacter->wisdom, pCharacter->charisma, getAncestry(pCharacter->ancestry)); //displays character, with proper formatting including the 50 max name length display
}

void SaveCharacter(Character * pCharacter) //save function
{
    char filename[256];
    printf("Enter a name of file to save (please type .character or another desired extension if wanted): ");
    scanf("%s", filename); //custom file name
    printf("\n");
    FILE * filePtr; //file pointer
    if((filePtr = fopen(filename, "w")) == NULL) //checking to see if file exists after opening file
    {
        printf("\nFile could not be opened\n"); //error message
        exit(EXIT_FAILURE); //exits program before seg fault
    }
    else //only if file exists
    {
        fprintf(filePtr, "%s %s %d %d %d %d %d %d %d\n", pCharacter->charname, pCharacter->playername, pCharacter->strength, pCharacter->dexterity, pCharacter->constitution, pCharacter->intelligence, pCharacter->wisdom, pCharacter->charisma, pCharacter->ancestry); //writes data with spaces in between each
    }
    fclose(filePtr); //closes file, very important
}

void LoadCharacter(Character * pCharacter, char * filename) //load function
{
    FILE * filePtr;
    if((filePtr = fopen(filename, "r")) == NULL) //all same as before
    {
        printf("\nFile could not be opened\n");
        exit(EXIT_FAILURE);
    }
    else
    {
        int ancest; //used for enum (you will see soon)
        fscanf(filePtr, "%s", pCharacter->charname); //individually reads in values and sets them to correct variable
        fscanf(filePtr, "%s", pCharacter->playername);
        fscanf(filePtr, "%d", &pCharacter->strength);
        fscanf(filePtr, "%d", &pCharacter->dexterity);
        fscanf(filePtr, "%d", &pCharacter->constitution);
        fscanf(filePtr, "%d", &pCharacter->intelligence);
        fscanf(filePtr, "%d", &pCharacter->wisdom);
        fscanf(filePtr, "%d", &pCharacter->charisma);
        fscanf(filePtr, "%d", &ancest);
        pCharacter->ancestry = enumAncestry(ancest); //converts int to enum
    }
    fclose(filePtr); //closes file (again)
}

int DisplayMenu() //menu function
{
    int selection= -1; //defaulted to -1
    while(selection < 1 || selection > 5) //error-checking
    {
        printf("\nMain Menu\n---------\n1) Generate a New Character\n2) Save Current Character\n3) Load a Previously Saved Character\n4) Display Current Character\n5) Exit\n");
        printf("Enter a selection: ");
        scanf("%d", &selection); 
        printf("\n");
        if(selection < 1 || selection > 5) //error message
        {
            printf("\n*** Error: selection must be 1-5 ***");
        }
    }
    return selection; //returns your menu selection
}
