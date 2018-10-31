/*                        ****** Zone Nicolas ******                        */
#include<stdio.h>
#include<stdlib.h>
#define TAILLEMAX 10000

int binary_convertor (char c){
	int binary = 0, i = 1, remainder;
	while (c > 0){
		remainder = c % 2;
		binary = binary + (i * remainder);
		c = c / 2;
		i = i *10;
	}
	return binary;
}

void init (char * file_name){
	FILE * file;
	file = fopen(file_name, "r"); //charge le fichier
	if (file == NULL){
		printf("Error loading the file %s . Does it exist ?\n", file_name); //fichier pas chargé...
	}else {
		int init_tape[TAILLEMAX];
		for (int i = 0; (fgetc(file) != EOF); i++){
			init_tape[i] = binary_convertor(fgetc(file));
			printf("%d \n", init_tape[i] );
		}



		//fgets(init_tape, TAILLEMAX, file); //lis la première ligne et la stocke dans init_tape
		//printf("%s \n", init_tape);
	}
	
}


// attention deux fichiers .tm a passer : le ruban et les règles. Tout input DOIT ETRE BINAIRE -> convertir






/*                       ****** Zone Katy ******                       */













/*                        ****** Main ******                        */


int main (int argc, char *argv[]){
	init(argv[1]);
	return 0;
}	