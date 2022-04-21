#ifndef _DandDCharacter
/*****************************************************************************
  DandDCharacter.h
  By Jim Ries
  Version 1.0, September 16, 2019
  Version 1.1, November 6, 2019
 *****************************************************************************/
#define _DandDCharacter

// Data types
typedef enum _Ancestry 
{
  human, elf, halfling, dwarf, half_elf, half_orc
}Ancestry;

typedef struct _Character
{
    int strength;
    int dexterity;
    int constitution;
    int intelligence;
    int wisdom;
    int charisma;

    Ancestry ancestry;
    char charname[256];
    char playername[256];
}Character;

// Functions
void GenerateCharacter(Character * pCharacter);               // Fills out the Character with newly generated data
void DisplayCharacter(Character * pCharacter);                // Displays the Character to the screen
void SaveCharacter(Character * pCharacter);                   // Saves the Character to disk
void LoadCharacter(Character * pCharacter, char * filename);  // Loads the Character from disk
int DisplayMenu();                                            // Returns the # of the menu item chosen

#endif  // _DandDCharacter
