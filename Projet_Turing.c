//                        ****** Zone Nicolas ******                        //
#include<stdio.h>
#include<stdlib.h>
#define TAILLEMAX 10000

void init (char * file_name){
	FILE * file;
	file = fopen(file_name, "r"); //charge le fichier
	if (file == NULL){
		printf("Error loading the file %s . Does it exist ?\n", file_name); //fichier pas chargé...
	}else {
		char init_tape[TAILLEMAX];
		fgets(init_tape, TAILLEMAX, file); //lis la première ligne et la stocke dans init_tape
		printf("%s \n", init_tape);
	}
	
}



int main (int argc, char *argv[]){
	init(argv[1]);
	return 0;
}








//                       ****** Zone Katy ******                       //






//dllddl






//                        ****** Main ******                        //
