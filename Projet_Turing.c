/*                        ****** Zone Nicolas ******                        */
#include<stdio.h>
#include<stdlib.h>
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
	float *p;
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
// attention deux fichiers .tm a passer : le ruban et les règles. Tout input DOIT ETRE BINAIRE -> convertir

vect rule_generator (char * file_rule){
	FILE * file;
	file = fopen(file_rule, "r");
	vect output_rules;
	int line_number = 0;
	char tmp;
	rule rule_list[line_number];
	int ligne;

	for(tmp = getc(file); tmp != EOF; tmp = getc(file)){
		if ( tmp == '\n')
			line_number++;
	}
	output_rules.nb_elem = line_number;
	output_rules.p = malloc(line_number*sizeof(rule));
	for (ligne = 1; ligne < line_number; ligne++ ){
		fscanf(file, "%d %d %d %d %d", &rule_list[ligne].cur_state, &rule_list[ligne].symbol, &rule_list[ligne].new_symbol, &rule_list[ligne].direction, &rule_list[ligne].new_state);
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
	printf("%c \n", rule_list.p[1].symbol);
	//size_increase(init_tape); // test pour augmenter la taille du ruban fais un segfault
	return 0;
}	