#include <stdlib.h>
#include <time.h>

int SetSeed(int seed)
{
    if ((-1)==seed)
    {
        time_t cur;
        time(&cur);
        seed = (int)cur;
    }
    
    srandom((unsigned int) seed);
}

int RollD6()
{
    long rand = (random() % 6) + 1;

    return (int)rand;
}