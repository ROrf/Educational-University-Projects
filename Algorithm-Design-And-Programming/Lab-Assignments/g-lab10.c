//Ryan Orf
//rconzc
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _players
{
    char lastName[16], firstName[16], team[16];
    int year;
    float ba, obp, slug;
}Players;

void printPlayers(Players players[], int count, int ad);
void sortBattingAvg(Players players[], int count);
void sortOnBase(Players players[], int count);
void sortSlug(Players players[], int count);
int filterYear(Players players[], int count);
void filterFront(Players players[], int count, int filteryear);

int main(int argc, char *argv[])
{
    FILE * fp;
    Players players[24];
    int count = 0;
    int filteryear = 0, choice = 0, ad = 0;
    if(argc == 1)
    {
        printf("Syntax: ./a.out inputfile [filter year]\n");
        exit(EXIT_FAILURE);

    }
    else
    {
        if(argc == 3)
        {
            if(!(strcmp(argv[2], "2017")) || !(strcmp(argv[2], "2018")) || !(strcmp(argv[2], "2019")))
            {
                if(!(strcmp(argv[2], "2017")))
                {
                    filteryear = 2017;
                }
                else if(!(strcmp(argv[2], "2018")))
                {
                    filteryear = 2018;
                }
                else if(!(strcmp(argv[2], "2019")))
                {
                    filteryear = 2019;
                }
                else
                {
                    filteryear = 0;
                }
            }
            else
            {
                printf("**Error: Invalid filter specified. No filter set.\n");
            }
        }
        fp = fopen(argv[1], "r");
        if(fp)
        {
            while(!feof(fp))
            {
                if(fscanf(fp, "%s %s %d %s %f %f %f", players[count].lastName, players[count].firstName, &(players[count].year), players[count].team, &(players[count].ba), &(players[count].obp), &(players[count].slug)) == 7)
                {
                    count++;
                }
            }
            fclose(fp);
            printf("*** THANKS MADI! ***\n");
            printf("**Initially: \n");
            if(filteryear == 0)
            {
                printPlayers(players, count, ad);
            }
            else
            {
                filterFront(players, count, filteryear);
                count = 5;
                printPlayers(players, count, ad);

            }
            while(choice != 6)
            {
                printf("\n*************************\n* Menu                  *\n*************************\n1. Print Player Records\n2. Sort by Batting Average\n3. Sort by On-base Percentage\n4. Sort by Slugging Percentage\n5. Filter by Year\n6. Exit\n**7. Toggle ascending/descending sort\n");
                scanf("%d", &choice);
                while(choice < 1 || choice > 7)
                {
                    printf("Choices must be 1-7. Try again\n");
                    scanf("%d", &choice);
                }
                switch (choice)
                {
                    case 1:
                        if(filteryear > 0)
                        {
                            count = 5;
                        }
                        printPlayers(players, count, ad);
                        break;
                    case 2:
                        if(filteryear > 0)
                        {
                            count = 5;
                        }
                        sortBattingAvg(players, count);
                        break;
                    case 3:
                        if(filteryear > 0)
                        {
                            count = 5;
                        }
                        sortOnBase(players, count);
                        break;
                    case 4:
                        if(filteryear > 0)
                        {
                            count = 5;
                        }
                        sortSlug(players, count);
                        break;
                    case 5:
                        filteryear = filterYear(players, count);
                        if(filteryear > 0)
                        {
                            count = 15;
                            filterFront(players, count, filteryear);
                        }
                        if(filteryear == 0)
                        {
                            count = 15;
                        }
                        break;
                    case 6:
                        break;
                    case 7:
                        if(ad == 0)
                        {
                            ad = 1;
                            printf("Toggled to ascending order\n");
                        }
                        else
                        {
                            ad = 0;
                            printf("Toggled to descending order\n");
                        }
                        break;
                    default:
                        break;
                }
                //while
            }
            printf("\nThanks!\n");
        }
        else
        {
            printf("Could not open %s\n", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
}

void printPlayers(Players players[], int count, int ad)
{
    printf("      First Name\tLast Name             Team  Year       BA      OBP     SLUG\n");
    if(ad == 1)
    {
        for(int i = count - 1; i >= 0; i--)
        {
            printf("%16s %16s %16s %5d %3f %3f %3f\n", players[i].firstName, players[i].lastName, players[i].team, players[i].year, players[i].ba, players[i].obp, players[i].slug);
        }
    }
    else
    {
        for(int i = 0; i < count; i++)
        {
            printf("%16s %16s %16s %5d %3f %3f %3f\n", players[i].firstName, players[i].lastName, players[i].team, players[i].year, players[i].ba, players[i].obp, players[i].slug);
        }
    }
}

void sortBattingAvg(Players players[], int count)
{
    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - 1; j++)
        {
            Players hold;
            if(players[j].ba < players[j+1].ba)
            {
                hold = players[j];
                players[j] = players[j+1];
                players[j+1] = hold;
            }
        }
    }
}

void sortOnBase(Players players[], int count)
{
    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - 1; j++)
        {
            Players hold;
            if(players[j].obp < players[j+1].obp)
            {
                hold = players[j];
                players[j] = players[j+1];
                players[j+1] = hold;
            }
        }
    }
}

void sortSlug(Players players[], int count)
{
    for(int i = 0; i < count - 1; i++)
    {
        for(int j = 0; j < count - 1; j++)
        {
            Players hold;
            if(players[j].slug < players[j+1].slug)
            {
                hold = players[j];
                players[j] = players[j+1];
                players[j+1] = hold;
            }
        }
    }
}

int filterYear(Players players[], int count)
{
    int fy = 0;
    printf("Enter the filter year: ");
    scanf("%d", &fy);
    if(fy > 2016 && fy < 2020)
    {
        return fy;
    }
    else
    {
        printf("\n**Error: Invalid filter specified. No filter set.\n");
        fy = 0;
    }
    return fy;
}

void filterFront(Players players[], int count, int filteryear)
{
    for(int i = 0; i < count; i++)
    {
        for(int j = 0; j < count; j++)
        {
            Players hold;
            if(players[j].year != filteryear && players[j+1].year == filteryear)
            {
                hold = players[j];
                players[j] = players[j+1];
                players[j+1] = hold;
            }
        }
    }
}
