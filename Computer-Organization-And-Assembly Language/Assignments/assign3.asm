**************************************
*
* Name: Ryan Orf
* Date: 03/07/21
* Lab3
*
* Program description: This program will divide REMAINDER by
* DIVISOR by subtracting DIVISOR from REMAINDER the correct
* number of times. However, in order to test whether the number
* is prime, we must use REMAINDER values ranging from 2 to N-1.
* If, for any DIVISOR value REMAINDER equals zero, PRIME is set
* to $00, or else PRIME will remain $01 as it was initialized.
*
* Pseudocode:
*
*
* unsigned int n = 251;
* unsigned int prime;
* unsigned int divisor;
* unsigned int the_remainder;
*
* prime = 1;
* divisor = 2;
* if(n == 1){
*	prime = 0;
* }
* else{
* 	while(divisor < n){
*		the_remainder = n;
*		while(the_remainder >= divisor){
*			the_remainder = the_remainder - divisor;
*		}
*		if(the_remainder == 0){
*			prime = 0;
*		}
*		divisor = divisor + 1;
*	}
* }
*
**************************************

* start of data section

	ORG $B000
N	FCB	251	unsigned int n = 251;
    
	ORG $B010
PRIME	RMB       1	unsigned int prime; 
DIVISOR	RMB	1	unsigned int divisor;
REMAINDER	RMB	1	unsigned int the_remainder;  

* define any other variables that you might need here

	ORG $C000
* start of your program
	LDAA	#$01
	STAA	PRIME	prime = 1;
	LDAA	#$02
	STAA	DIVISOR	divisor = 2;
IF	LDAA	N	if(n == 1){
	CMPA	#$01
	BNE	ELSE
THEN	CLR	PRIME	prime = 0;
	BRA	ENDIF	}
ELSE	BRA	WHILE	else{
WHILE	LDAA	DIVISOR	while(divisor < n){
	CMPA	N
	BHS	ENDWHILE
	LDAB	N
	STAB	REMAINDER	the_remainder = n;
WHILE1	LDAB	REMAINDER	while(the_remainder >= divisor){
	CMPB	DIVISOR	
	BLO	ENDWHILE1
	SUBB	DIVISOR	the_remainder = the_remainder - divisor;
	STAB	REMAINDER
	BRA	WHILE1
ENDWHILE1	BRA	IF1	}
IF1	LDAB	REMAINDER	if(remainder == 0){
	CMPB	#$00
	BNE	ENDIF1
THEN1	CLR	PRIME	prime = 0;
ENDIF1	INC	DIVISOR	} divisor = divisor + 1;
	BRA	WHILE	
ENDWHILE	BRA	ENDIF	}
ENDIF	STOP		}
	
