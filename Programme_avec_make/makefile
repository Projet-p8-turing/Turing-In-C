cc=gcc
SRC= main.c init.c rule_generator.c turing_machine.c
OBJ = $(SRC: .c = .o)
CFLAGS= -Wall

turing_machine : $(OBJ) Projet_Turing.h
		$(CC) -o $@ $(OBJ)

%.o : %.c
		$(CC) -c $< $(CFLAGS)

clean : 
		rm *.o *~core
