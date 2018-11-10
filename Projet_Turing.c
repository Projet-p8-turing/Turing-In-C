/*                        ****** Zone Nicolas ******                        */
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#define TAILLEMAX 2000
struct rule {
	int cur_state;
	int symbol;
	int new_symbol;
	int direction;
	int new_state;
};
typedef struct rule rule;

struct vect {
	int nb_elem;
	rule *p;
};
typedef struct vect vect;

vect init (char * file_tape){ //return un char
	FILE * file;
	int i, taille;
	char init_tape[TAILLEMAX], c;
	vect output_tape;

	file = fopen(file_tape, "r"); //charge le fichier
	if (file == NULL){
		printf("Error loading the file %s. Does it exist ?\n", file_tape); //fichier pas chargé...
	}else {
		fseek(file, -1L, SEEK_END);
		taille =ftell(file);
		fseek(file, 0L, SEEK_SET);
		for (i =0; i < taille; i ++){
			fscanf(file, "%c", &c);
			fseek(file, 0L, SEEK_CUR);
			init_tape[i] = c;
		}
		printf("Entered inital tape is : ");
		for(i = 0; i < taille; i++){
			printf("%c ", init_tape[i]);
		}
		printf("\n");
		fclose(file);
	}
	output_tape.nb_elem = i+1;
	output_tape.p = malloc(sizeof(init_tape));
	return output_tape;
}	

char size_increase (char * init_tape){
	static char tmp[sizeof(init_tape)/sizeof(char) * 2];
	for (int i = 0; i<(sizeof(init_tape)/sizeof(char)); i++){
		tmp[i] = init_tape[i];
		
	}
	return * tmp;
}

vect rule_generator (char * file_rule){
	int line_number = 0;
	int ligne;
	char tmp;
	vect output_rules;
	FILE * file;
	file = fopen(file_rule, "r");

	for(tmp = getc(file); tmp != EOF; tmp = getc(file)){
		if ( tmp == '\n')
			line_number++;
	}
	output_rules.p = malloc(line_number*sizeof(rule));
	assert(output_rules.p);
	output_rules.nb_elem = line_number;
	rewind(file);
	for (ligne = 0; ligne < line_number; ligne++ ){
		fscanf(file, "%d %d %d %d %d", &output_rules.p[ligne].cur_state, &output_rules.p[ligne].symbol, &output_rules.p[ligne].new_symbol, &output_rules.p[ligne].direction, &output_rules.p[ligne].new_state);
		printf("put %d in cur_state\n", output_rules.p[ligne].direction );
	}
	fclose(file);
	return output_rules;
}

/*                       ****** Zone Katy ******                       */













/*                        ****** Main ******                        */


int main (int argc, char *argv[]){
	//int head_pos = 0;//position tete de lecture
	vect init_tape = init(argv[1]);//  init de l'état initial
	vect rule_list = rule_generator(argv[2]);
	printf("symbole : %d \n", rule_list.p[1].symbol);
	//size_increase(init_tape); // test pour augmenter la taille du ruban fais un segfault
	return 0;
}	