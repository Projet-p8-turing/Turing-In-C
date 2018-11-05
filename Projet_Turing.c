/*                        ****** Zone Nicolas ******                        */
#include<stdio.h>
#include<stdlib.h>
#define TAILLEMAX 2000


char * init (char * file_name){
	FILE * file;
	int i, nb, taille;
	char init_tape[TAILLEMAX], c;
	file = fopen(file_name, "r"); //charge le fichier
	if (file == NULL){
		printf("Error loading the file %s . Does it exist ?\n", file_name); //fichier pas chargé...
	}else {
		fseek(file, -1L, SEEK_END);
		taille =ftell(file);
		fseek(file, 0L, SEEK_SET);
		for (i =0; i < taille; i ++){
			fscanf(file, "%c", &c);
			fseek(file, 0L, SEEK_CUR);
			init_tape[i] = c;
		}
		for(i = 0; i < taille; i++){
			printf("%c ", init_tape[i]);
		}
		fclose(file);
	}
}	

char size_increase (char * init_tape){
	static char tmp[sizeof(init_tape)/sizeof(char) * 2];
	for (int i = 0; i<(sizeof(init_tape)/sizeof(char)); i++){
		tmp[i] = init_tape[i];
		
	}
	return * tmp;
}
// attention deux fichiers .tm a passer : le ruban et les règles. Tout input DOIT ETRE BINAIRE -> convertir






/*                       ****** Zone Katy ******                       */













/*                        ****** Main ******                        */


int main (int argc, char **argv[]){
	int head_pos = 0;//position tete de lecture
	char * init_tape = init(argv[1]);//  init de l'état initial
	
	//size_increase(init_tape); // test pour augmenter la taille du ruban fais un segfault
	return 0;
}	