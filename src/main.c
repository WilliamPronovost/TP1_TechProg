////Bonne pratique, pour les includes systemes toujours utiliser <> et "" pour les includes de votre projet.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "TP1.h"

int main(int argc, char** argv){

	int max = 10;
	int min = 0;
	int rd_num = rand() % (max - min + 1) + min;
	FILE* fptr;
	fptr = fopen("tp1_data.csv", "r");
	if(fptr == NULL){
		return -1;
	}
	char line[256];
	int index = 0;
	char* names[256] = { 0 };
	int values[256] = { 0 };
	while(fgets(line, sizeof(line), fptr)){
		char* p;
		p = strtok(line, ", "); //not needed(name, )
		if(p){
			printf("%s\ ", p); 
		}
		p = strtok(NULL, ", "); //name of the item
		names[index] = p;
		p = strtok(NULL, ", "); //not needed(value, )
		if (p) {
			printf("%s\ ", p);
		}
		p = strtok(NULL, ", "); //value of the item
		values[index] = strtol(p, NULL, 10);
		index++;
		for (int i = 0; i < 1; i++) {
			printf("%s ", names[i]);
			printf("%d\n", values[i]);

		}
		
	}
	
}