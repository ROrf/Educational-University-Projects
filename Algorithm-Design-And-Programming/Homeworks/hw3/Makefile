# Makefile
# By Jim Ries
# 11/6/2019
BONUS=0

play : main.o DandDCharacter.o libRandom.a
	cc -o play main.o DandDCharacter.o -lRandom -L.

Random.o : Random.c Random.h
	cc -c Random.c

libRandom.a : Random.o
	ar rs libRandom.a Random.o

DandDCharacter.o : DandDCharacter.c DandDCharacter.h
	cc -c DandDCharacter.c

main.o : main.c
	cc -c -DBONUS=$(BONUS) main.c

clean :
	@rm -f *.o
	@rm -f *.a
	@rm -f play
	@rm -f *.character
	@echo Clean as a whistle!
