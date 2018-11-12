/*                        ****** Zone Nicolas ******                        */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<unistd.h>
#include <string.h>
#define TAILLEMAX 2000

struct rule {
	int cur_state;
	int symbol;
	int new_symbol;
	int direction;
	int new_state;
};
typedef struct rule rule;

struct vect_rule {
	int nb_elem;
	rule *p;
};
typedef struct vect_rule vect_rule;

struct vect_tape{
	int nb_elem;
	char *p;
};
typedef struct vect_tape vect_tape;

vect_tape init (char * file_tape){ //return un char
	FILE * file;
	int i, taille;
	char init_tape[TAILLEMAX], c;
	vect_tape output_tape;
	
	file = fopen(file_tape, "r"); //charge le fichier
	if (file == NULL){
		printf("Error loading the file : %s. Does it exist ?\n", file_tape); //fichier pas chargé...
		exit(0);
	}else {
		fseek(file, -1L, SEEK_END);
		taille =ftell(file);
		fseek(file, 0L, SEEK_SET);
		for (i =0; i < taille; i ++){
			fscanf(file, "%c", &c);
			fseek(file, 0L, SEEK_CUR);
			init_tape[i] = atoi(&c);      // atoi(&c)
		}	
		output_tape.nb_elem = i+1;
		output_tape.p = malloc(output_tape.nb_elem * sizeof(char));
		for(i = 0; i < output_tape.nb_elem; i++){
			output_tape.p[i] = init_tape[i];
		}
	}
	fclose(file);
	return output_tape;
}

vect_rule rule_generator (char * file_rule){
	int line_number = 0;
	int ligne;
	char tmp;
	vect_rule output_rules;
	FILE * file;
	file = fopen(file_rule, "r");

	for(tmp = getc(file); tmp != EOF; tmp = getc(file)){
		if ( tmp == '\n')
			line_number++;
	}
	output_rules.p = malloc(line_number*sizeof(rule));
	assert(output_rules.p);
	output_rules.nb_elem = line_number;
	fseek(file, 0, SEEK_SET);
	for (ligne = 0; ligne < line_number; ligne++ ){
		fscanf(file, "%d %d %d %d %d", &output_rules.p[ligne].cur_state, &output_rules.p[ligne].symbol, &output_rules.p[ligne].new_symbol, &output_rules.p[ligne].direction, &output_rules.p[ligne].new_state);
	}
	fclose(file);
	return output_rules;
}

int turing_machine (vect_tape init_tape, vect_rule rule_list, int cur_state){
	int head_pos;
	char rule_found;

	head_pos = 0;

	while(1){
		//sleep(1);
		rule_found = 0;
		for (int i = 0; i < rule_list.nb_elem; i++){
			if (cur_state == rule_list.p[i].cur_state && init_tape.p[head_pos] == rule_list.p[i].symbol){
				rule_found = 1;
				init_tape.p[head_pos] = rule_list.p[i].new_symbol;
				if (rule_list.p[i].direction)
					head_pos++;
				else
					head_pos--;
				cur_state = rule_list.p[i].new_state;
				break;
			}
		}
		printf("cur_state %d head at : %d \n", cur_state, head_pos);
		if(!rule_found)
			return 0; // On a fini
		printf("current tape is : ");
		for (int n = 0; n < init_tape.nb_elem; n ++){
			printf("%d ", init_tape.p[n]);
		};
		printf("\n");
	}
}

// trouver un moyen pour que si la tete arrive a la fin on s'arrete et on repart dans l'autre sens. Utiliser des char plutot que des int ? Alors si 0 -> fin du tape

/*                       ****** Zone Katy ******                       */




/*                        ****** Main ******                        */


int main (int argc, char *argv[]){
	vect_tape init_tape = init(argv[1]);//  init de l'état initial
	if (argc != 4 || !strcmp(argv[1], "-help")){
		printf("Usage : %s tape_file rule_file initial_state \n\nRule must be pattern : current_state found_symbol new_symbol movement_direction new_state WITH SPACES. \nTape pattern must be a a chain of boolean numbers not separated by anything. \nThe machine will end anytime it detects a symbol for which it doesn't know any rule to apply.\n", argv[0]);
		exit(0);
	}
	printf("initial tape is : ");
	for (int n = 0; n < init_tape.nb_elem; n ++){
		printf("%d ", init_tape.p[n]);
	};
	printf("\n");

	vect_rule rule_list = rule_generator(argv[2]);
	turing_machine(init_tape, rule_list, atoi(argv[3]));
	return 0;
}