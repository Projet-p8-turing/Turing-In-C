#include "Projet_Turing.h"

int main (int argc, char *argv[]){
	int verbose, n;
	vect_tape init_tape;
	vect_rule rule_list;

	if(argv[4] && !strcmp(argv[4], "-v"))
		verbose = 1;
	else{
		printf("Note : call with -v for detailed processing.\n\n");
		verbose = 0;
	}
	if (argc < 4|| argc > 5 || !strcmp(argv[1], "-help")){
		printf("Usage : %s <tape_file> <rule_file> <initial_state> <-v> (last argument is optional and enables verbose mode)\n\nRule pattern must be : current_state found_symbol new_symbol movement_direction(where 0 is left and 1 is right) new_state WITH SPACES. \nTape pattern must be a a chain of boolean numbers not separated by anything. The \'2\' symbol will represent blank spaces, rules must be set accordingly. \n\nHead starting position is at the begining of tape. The machine will halt anytime it detects a symbol for which it doesn't know any rule to apply.\n", argv[0]);
		exit(0);
	}
	init_tape = init(argv[1]); // recupération du ruban demandé
	printf("initial call done with : ");
	for (n = 0; n <= init_tape.nb_elem-2; n ++){ //affiche le ruban inital
		printf("%d ", init_tape.p[n+5]);
	};
	printf("\n");
	rule_list = rule_generator(argv[2]); // recupération des règles de traitement
	printf("Processing...\n\n");
	turing_machine(init_tape, rule_list, atoi(argv[3]), verbose); // processing
	return 0;
}