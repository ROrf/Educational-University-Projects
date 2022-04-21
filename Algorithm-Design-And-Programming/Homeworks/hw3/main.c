//Ryan Orf
//rconzc
//starter code retrieved from starter linked on canvas 
#include <stdio.h> //headers
#include <string.h>
#include <malloc.h>
#include "Random.h"
#include "DandDCharacter.h" 

int main(int argc, char * argv[]) //main with proper arguments for cmdline
{
    Character *pCharacter = malloc(sizeof(Character)); //allocating space
    char *filename = malloc(256*sizeof(char)); //also allocating space
    pCharacter->strength = 0; //intializing values to 0 or ""
    pCharacter->dexterity = 0;
    pCharacter->constitution = 0;
    pCharacter->intelligence = 0;
    pCharacter->wisdom = 0;
    pCharacter->charisma = 0;
    pCharacter->ancestry = human;
    strcpy(pCharacter->charname, ""); //copies value of string (in these cases the default nothing ("")
    strcpy(pCharacter->playername, "");
    if(argc>1) //if you want to try to open a file via cmdline
    {
        strcpy(filename, argv[1]);
        LoadCharacter(pCharacter, filename); //must call if cmdline's used
    } 
    printf("\nI am attempting the bonus!\n*** PLEASE READ: If you save a file without the extension as shown in the example, the extension is not automatically added. Keep this in mind when you try to load a file. Thanks! ***\n"); //bonus and warning messages
    int select = DisplayMenu(); //always calls at least once
    while(select != 5) //while exit option is not input
    {
       switch (select) //calls different functions depending on input
       {
           case 1: //calls generate
               GenerateCharacter(pCharacter);
               break;
           case 2: //calls save
               SaveCharacter(pCharacter);
               break;
           case 3: //calls load and also asks for filename because the given prototype in the header requires char * filename as an argument
               printf("\nEnter name of file to load (extension will automatically be .character): ");
               scanf("%s", filename);
               printf("\n");
               LoadCharacter(pCharacter, filename);
               break;
           case 4: //calls display
               DisplayCharacter(pCharacter);
               break;
           default: //nothing in default, but have to have one
               break; //better safe than sorry with this break
       }
       select = DisplayMenu(); //calls menu again to avoid infinite loop
    }
    printf("\n\nThanks for playing!!\n"); //thanks message
    free(filename); //deallocating space in reverse order as allocated
    free(pCharacter); //also deallocating space
}
