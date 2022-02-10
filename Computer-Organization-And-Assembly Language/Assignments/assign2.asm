**************************************
*
* Name: Ryan Orf
* Date: Wednesday, February 24, 2021
* Lab2
*
* Program description: Dividing a dividend by a divisor to obtain a quotient and remainder
*
* Pseudocode:
*
* unsigned int dividend = 201;
* unsigned int divisor = 6;
*
* unsigned int quotient;
* unsigned int the_remainder; // had to use the_remainder because remainder is a built-in function
* unsigned int number; //a variable to hold the value of dividend after each loop iteration since dividend cannot be changed
*
* 	quotient = 0;
* 	the_remainder = 0;
*	number = dividend
*	if(divisor==0) {
*		quotient = 255;
*		the_remainder = 255;
*	}
*	else {
*		while(number >= divisor) {
*			quotient++;
*			number -= divisor;
*		}
*		if(number > 0) {
*			the_remainder = number;
*		}
*	}
**************************************

* start of data section

	ORG $B000
DIVIDEND	FCB     201         The dividend -> unsigned int dividend = 201;
DIVISOR	FCB       6         The divisor. -> unsigned int divisor = 6;

	ORG $B010
QUOTIENT	RMB       1         The quotient. -> unsigned int quotient;
REMAINDER	RMB       1         The remainder. -> unsigned int the_remainder;
* define any other variables that you might need here
NUMBER		RMB       1         The value of the dividend after each loop iteration. -> unsigned int number;

	ORG $C000
* start of your program
	CLR	QUOTIENT	quotient = 0;
	CLR	REMAINDER	the_remainder = 0;
	LDAA	DIVIDEND	using register A to load in the value of DIVIDEND that way it can be stored in NUMBER
	STAA	NUMBER		number = dividend;
IF	LDAA	DIVISOR	if(divisor==0) {
	CMPA	#0
	BNE	ELSE		does not execute the THEN condition if the divisor does not equal 0
THEN	LDAB	#$FF		using register B to load the hex value of 255 that way it can be stored in QUOTIENT and REMAINDER if DIVISOR == 0. We only need to do this once.	
	STAB	QUOTIENT	quotient = 255;
	STAB	REMAINDER	the_remainder = 255;
	BRA	ENDIF		}
ELSE	BRA	WHILE		else {	(since the labels such as ELSE do not execute any code, I have to branch to the next label in order for the code to assemble)
WHILE	LDAA	NUMBER		while(number >= divisor) {
	CMPA	DIVISOR
	BLO	ENDWHILE	ends the while loop if NUMBER < DIVISOR
	INC	QUOTIENT	quotient++;
	LDAB	NUMBER		number -= divisor; NUMBER - DIVISOR -> NUMBER
	SUBB	DIVISOR
	STAB	NUMBER
	BRA	WHILE		continues to the next iteration of the while loop
ENDWHILE	BRA	IF1	}
IF1	LDAA	NUMBER		if(number > 0) {
	CMPA	#0
	BLS	ENDIF1		does not execute the THEN1 condition if the divisor is less than or equal to 0
THEN1	LDAB	NUMBER		the_remainder = number;
	STAB	REMAINDER
ENDIF1	BRA	ENDIF		}
ENDIF	STOP			}
