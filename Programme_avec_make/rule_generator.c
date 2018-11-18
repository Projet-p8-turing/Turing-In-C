#include "Projet_Turing.h"

vect_rule rule_generator (char * file_rule){
	int line_number = 0;
	int ligne;
	char tmp;
	vect_rule output_rules;
	FILE * file;
	file = fopen(file_rule, "r");

	for(tmp = getc(file); tmp != EOF; tmp = getc(file)){ // recupère le nombre de lignes (donc de règles) dans le fichier
		if ( tmp == '\n')
			line_number++;
	}
	output_rules.p = malloc(line_number*sizeof(rule));
	assert(output_rules.p);
	output_rules.nb_elem = line_number;
	fseek(file, 0, SEEK_SET);
	for (ligne = 0; ligne < line_number; ligne++ ){ // chaque 5 élément trouvé forme une règle.
		fscanf(file, "%d %d %d %d %d", &output_rules.p[ligne].cur_state, &output_rules.p[ligne].symbol, &output_rules.p[ligne].new_symbol, &output_rules.p[ligne].direction, &output_rules.p[ligne].new_state);
	}
	fclose(file);
	return output_rules;
}