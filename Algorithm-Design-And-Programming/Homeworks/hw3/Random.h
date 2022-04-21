#ifndef _Random_h
#define _Random_h

/************************************************************************/
/* SetSeed() - Sets the initial seed for the sequence of random numbers */
/* Proving the same constant seed will result in the same sequence of   */
/* random numbers, except for the special value -1.  If you pass -1 to  */
/* this function, it will set the seed to a unique value so that each   */
/* time the program is run, a different sequence of random numbers will */
/* be generated.                                                        */
/************************************************************************/
int SetSeed(int seed);

/************************************************************************/
/* RollD6() - Returns a random integer from 1 through 6 inclusive.      */
/************************************************************************/
int RollD6();

#endif
