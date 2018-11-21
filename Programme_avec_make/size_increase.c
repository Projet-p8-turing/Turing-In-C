#include "Projet_Turing.h"

vect_tape size_increase(vect_tape init_tape){
	int i;
	vect_tape output;

	output.nb_elem = TAILLEMAX*2; 
	output.p = malloc(output.nb_elem * sizeof(char));
	for( i = 0; i<(TAILLEMAX *2); i++){
		output.p[i] = init_tape.p[i];
	}
	free(init_tape.p);
	return output;
}