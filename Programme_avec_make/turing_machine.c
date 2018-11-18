#include "Projet_Turing.h"

int turing_machine (vect_tape init_tape, vect_rule rule_list, int cur_state, int verbose){
	int head_pos, i, n;
	char rule_found;
	head_pos = 5;
	while(1){
		rule_found = 0;
		for (i = 0; i < rule_list.nb_elem; i++){ // on compare l'état courrant a toutes les règles connues
			if (cur_state == rule_list.p[i].cur_state && init_tape.p[head_pos] == rule_list.p[i].symbol){ // si on a une règle pour l'état et le symbole courrant
				rule_found = 1;
				init_tape.p[head_pos] = rule_list.p[i].new_symbol;
				if (rule_list.p[i].direction) // pour déplacement droite
					head_pos++;
				else	// pour déplacement gauche
					head_pos--;
				cur_state = rule_list.p[i].new_state; //nouvel état
				break;
			}
		}
		if(!rule_found){
			printf("\nNo rule found for the current state : %d , job is done.", cur_state);
			printf("\nExited with :\n");
			for(int n = 5; n > 0; n--){
				if (init_tape.p[n-1] == 1)
					printf("%d ", init_tape.p[n-1]);
			}
			for (n = 0; n < init_tape.nb_elem-1; n ++){
				printf("%d ", init_tape.p[n+5]);
			};
			printf("\n");
			return 0; // si aucune règle n'est trouvée pour l'état spécifié, sortie de programme.
		}
		if (verbose == 1){
			printf("state is : %d. Head is at position %d \n", cur_state, head_pos);
			printf("current tape is : "); // affichage de la situation
			for(int n = 5; n > 0; n--){
				if (init_tape.p[n-1] == 1)
					printf("%d ", init_tape.p[n-1]);
			}
			for (int n = 0; n < init_tape.nb_elem-1; n ++){
				printf("%d ", init_tape.p[n+5]);
			};
			printf("\n");
		}
	}
}