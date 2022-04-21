//Ryan Orf
//rconzc
#include<stdio.h>
#include<stdlib.h>

double getScore(int key[], int ans[], int size);
void getData(FILE * fp, char *data, int size);

int main(void)
{
    int studNum, keyNum, ans[40], key[40];
    char last[11], first[12], tempNum[8], tempAns[40], blank[4], buffer[256];
    double score;
    FILE * fp;
    fp = fopen("lab9.txt", "r");
    if(fp == NULL)
    {
        printf("***Error: File 'lab9.txt' could not be found***\n");
    }
    else
    {
        while(!feof(fp))
        {
            getData(fp, tempNum, sizeof(tempNum));
            studNum = atoi(tempNum);
            getData(fp, blank, sizeof(blank));
            if(!feof(fp))
            {
                getData(fp, tempNum, sizeof(tempNum));
                keyNum = atoi(tempNum);
                getData(fp, last, sizeof(last));
                getData(fp, first, sizeof(first));
                getData(fp, tempAns, 40);
                for(int i = 0; i < 40; i++)
                {
                    ans[i] = (int)tempAns[i] - '0';
                }
            }
            if(studNum == 99999999)
            {
                for(int i = 0; i < 40; i++)
                {
                    key[i] = ans[i];
                }
                printf("\n***New key=%s%s%d\n\t", first, last, keyNum);
                for(int i = 0; i < 40; i++)
                {
                    printf("%d", key[i]);
                }
                printf("\n");
            }
            else
            {
                score = getScore(key, ans, 40);
                printf("\n%s%s:\n\t", first, last);
                for(int i = 0; i < 40; i++)
                {
                    printf("%d", ans[i]);
                }
                printf("\n\tScore=%lf\n", score);
            }
           fgets(buffer, 255, fp); 
        }
    }
    fclose(fp);
}

void getData(FILE * fp, char *data, int size)
{
    int i;
    for(i = 0; i < size; i++)
    {
        data[i] = fgetc(fp);
    }
    data[i] = '\0';
}

double getScore(int key[], int ans[], int size)
{
    double score = 0;
    for(int i = 0; i < size; i++)
    {
        if(ans[i] == key[i])
        {
            score += 2.5;
        }
    }
    return score;
}
