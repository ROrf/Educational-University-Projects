**************************************
*
* Name: Ryan Orf
* Date: 04/14/21
* Lab5
*
* Program description: This program will loop through a table and call 
* a subroutine through each iteration to calculate whether the number at
* the current index is prime or not. The tables N and PRIME are looped
* through using pointers, and a third pointer, LOCATION, serves the purpose
* of maintaining the address of the current number, as the X-register is used
* in the main program to access N, and the contents of the X-register will
* change when values are returned. Values are passed to the subroutine using 
* call-by-value in-register. In the subroutine, dynamic local variables NUM, PRIMEVAL,
* DIVISOR, and REMAINDER are declared by opening holes on the stack. NUM is initialized
* to the passed-in parameter value (the number we are testing each time). The subroutine
* then divides REMAINDER by DIVISOR by subtracting DIVISOR from REMAINDER the correct
* number of times. However, in order to test whether the number is prime, we must
* use REMAINDER values ranging from 2 to NUM-1. If, for any DIVISOR value REMAINDER
* equals zero, PRIMEVAL is set to $00, or else PRIMEVAL will remain $01 as it was
* initialized. Finally, the subroutine will return the value of PRIMEVAL using call-
* by-value over-the-stack. After the main program has received the return value,
* the return value is stored in the current index of the table PRIME using a pointer,
* and the program increments the pointer to move to the next element in the table PRIME.
* The same must be done to N so we can test the next number, so we load LOCATION into
* the X-register, which is a pointer containing the memory address of N, and increments
* the pointer(s) to move to the next element in the table N for the next iteration of the
* while loop. The while loop will exit once the sentinel value is reached.
* 
*
* Pseudocode of Main Program:
*
*
* unsigned int N[] = {1, 2, 11, 14, 31, 32, 37, 241, 251, 252, 255};
* #define SENTIN 255
* unsigned int PRIME[10];
* unsigned int *location;
*
* unsigned int *nPointer;
* nPointer = &N[0];
* unsigned int *primePointer;
* primePointer = &PRIME[0];
* location = nPointer;
* while(*nPointer != SENTIN){
* 	*primePointer = cPrime(*nPointer);
* 	primePointer++;
* 	location++;
* 	nPointer = location;
* }
*
*---------------------------------------
*
* Pseudocode Subroutine
*
*	
* int cPrime(int value){
* 	int num, primeval, divisor, the_remainder;
* 	num = value;
* 	primeval = 1;
* 	divisor = 2;
* 	if(num == 1){
* 		primeval = 0;
* 	}
*	else{
*		while(divisor < num){
* 			the_remainder = num;
* 			while(the_remainder >= divisor){
* 				the_remainder = the_remainder - divisor;
* 			}
* 			if(the_remainder == 0){
* 				primeval = 0;
* 			}
* 			divisor = divisor + 1;
* 		}
* 	}
* 	return primeval;
* }
*
***************************************
* start of data section

	ORG $B000
N	FCB     1, 2, 11, 14, 31, 32, 37, 241, 251, 252, $FF	unsigned int N[] = {1, 2, 11, 14, 31, 32, 37, 241, 251, 252, 255}     
SENTIN	EQU	$FF	#define SENTIN 255
    
	ORG $B010
PRIME	RMB       10	unsigned int PRIME[10];

* define any other variables that you might need here
* remember that your subroutine must not access any of these variables, including
* N and PRIME
LOCATION	RMB	2	unsigned int *location;

	ORG $C000
	LDS	#$01FF		initialize stack pointer
* start of your program
	LDX	#N	unsigned int *nPointer; nPointer = &N[0];
	LDY	#PRIME	unsigned int *primePointer; primePointer = &PRIME[0];
	STX	LOCATION	location = nPointer;
WHILE	LDAA	0,X	while(*nPointer != SENTIN){
	CMPA	#SENTIN
	BEQ	ENDWHILE
	JSR	CPRIME	*primePointer = cPrime(*nPointer);
	PULA
	STAA	0,Y
	INY		primePointer++;
	LDX	LOCATION	location++; nPointer = location;
	INX
	STX	LOCATION
	BRA	WHILE
ENDWHILE	STOP		}



* NOTE: NO STATIC VARIABLES ALLOWED IN SUBROUTINE


	ORG $D000
* start of your subroutine 
CPRIME	PULX
	DES
	PSHX
	DES		int num, primeval, divisor, the_remainder;
	DES
	DES
	DES
	TSX
	STAA	0,X	num = value;
	LDAA	#$01
	STAA	1,X	primeval = 1;
	LDAA	#$02
	STAA	2,X	divisor = 2;
IF	LDAA	0,X	if(num == 1){
	CMPA	#$01
	BNE	ELSE
THEN	LDAA	#$00	
	STAA	1,X	primeval = 0;
	BRA	ENDIF	}
ELSE	BRA	WHILE1	else{
WHILE1	LDAA	2,X	while(divisor < num){
	CMPA	0,X
	BHS	ENDWHILE1
	LDAB	0,X
	STAB	3,X	the_remainder = num;
WHILE2	LDAB	3,X	while(the_remainder >= divisor){
	CMPB	2,X
	BLO	ENDWHILE2
	SUBB	2,X	the_remainder = the_remainder - divisor;
	STAB	3,X
	BRA	WHILE2
ENDWHILE2	BRA	IF1
IF1	LDAB	3,X	if(the_remainder == 0){
	CMPB	#$00
	BNE	ENDIF1
THEN1	LDAB	#$00	
	STAB	1,X	primeval = 0;
ENDIF1	INC	2,X	divisor = divisor + 1;
	BRA	WHILE1
ENDWHILE1	BRA	ENDIF	}
ENDIF	LDAA	1,X	}
	STAA	6,X
	INS
	INS
	INS
	INS
	RTS	return primeval; 
