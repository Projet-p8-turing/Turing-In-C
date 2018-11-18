#include "Projet_Turing.h"

vect_tape init (char * file_tape){ 
	FILE * file;
	int i, taille;
	char init_tape[TAILLEMAX], c;
	vect_tape output_tape;
	
	memset(init_tape, 2, TAILLEMAX);
	file = fopen(file_tape, "r"); //charge le fichier
	if (file == NULL){   // traitement si erreur de chargement
		printf("Error loading the file : %s. Either it was missplled or it does not exist.\n", file_tape); 
		exit(0);
	}else { // met chaque caractère trouvé dans un tableau
		fseek(file, 0L, SEEK_END);
		taille =ftell(file);
		if (taille == 0){
			printf("This tape file is empty, aborting...\n");
			exit(0);
		}
		fseek(file, 0L, SEEK_SET);
		for (i =0; i < taille; i ++){
			fscanf(file, "%c", &c);
			fseek(file, 0L, SEEK_CUR);
			init_tape[i] = atoi(&c); 
		}	
		output_tape.nb_elem = i+1;
		output_tape.p = malloc(output_tape.nb_elem * sizeof(char));
		for(i = 0; i < output_tape.nb_elem; i++){
			output_tape.p[i+5] = init_tape[i];
		}
	}
	fclose(file);
	return output_tape;
}