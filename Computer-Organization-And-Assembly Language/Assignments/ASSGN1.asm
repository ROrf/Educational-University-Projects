********************************************
*
* Name: Ryan Orf
* Due Date: 02/12/21
*
* This program will add data1 and data3 and subtract data2
*
*
*                                Table to be filled out
*     Step    |    PC         |   Register A |   Memory $B003 |   NZVC    |
*     ----------------------------------------------------------------------------
*       1     |    c003       |   $0A        |   $00          |   0000    |
*       2     |    c006       |   $FB        |   $00          |   1001    |
*       3     |    c009       |   $15        |   $00          |   0001    |
*       4     |    c00c       |   $15        |   $15          |   0001    |
*
********************************************
* data location starts at $B000
		ORG		$B000
DATA1		FCB		10		declare 1-byte variable DATA1 and initialize it with 10
DATA2		FCB		15		declare 1-byte variable DATA2 and initialize it with 15
DATA3		FCB		$1A		declare 1-byte variable DATA3 and initialize it with $1A
RESULT		RMB		1		declare 1-byte variable RESULT

* main program starts at $C000
		ORG		$C000

		LDAA		DATA1		load A with DATA1
		SUBA		DATA2		subtract DATA2 from A
		ADDA		DATA3		add DATA3 to A
		STAA		RESULT		store A in RESULT
		STOP				stops the processor
		END				Tells the Assembler that we're done

