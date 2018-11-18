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

vect_tape init (char * file_tape);
vect_rule rule_generator (char * file_rule);
int turing_machine (vect_tape init_tape, vect_rule rule_list, int cur_state, int verbose);