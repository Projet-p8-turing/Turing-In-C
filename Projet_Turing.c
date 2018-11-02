/*                        ****** Zone Nicolas ******                        */
#include<stdio.h>
#include<stdlib.h>
#define TAILLEMAX 10000


char * init (char * file_name){
	FILE * file;
	file = fopen(file_name, "r"); //charge le fichier
	if (file == NULL){
		printf("Error loading the file %s . Does it exist ?\n", file_name); //fichier pas chargé...
	}else {
		static char init_tape[10];
		printf("Initial State is : ");
		for (int i = 0; (fgetc(file) != EOF); i++){
			init_tape[i] = fgetc(file);
			printf("%c ", init_tape[i] );
		}
		printf("\n");
		return init_tape;
	}
}	

char * size_increase (char * init_tape){
	static char tmp[sizeof(init_tape)/sizeof(char) * 2];
	for (int i = 0; i<(sizeof(init_tape)/sizeof(char)); i++){
		tmp[i] = init_tape[i];
		
	}
	return tmp;
}
// attention deux fichiers .tm a passer : le ruban et les règles. Tout input DOIT ETRE BINAIRE -> convertir






/*                       ****** Zone Katy ******                       */













/*                        ****** Main ******                        */


int main (int argc, char *argv[]){
	char *init_tape; // pointeur tableau état initial
	int head_pos = 0;//position tete de lecture
	init_tape = init(argv[1]);//  init de l'état initial
	size_increase(init_tape); // test pour augmenter la taille du ruban
	return 0;
}	