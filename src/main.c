
////Bonne pratique, pour les includes systemes toujours utiliser <> et "" pour les includes de votre projet.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
#include <assert.h>
#include "TP1.h"

#define HEAP_SIZE 1024 * 1024
static uint8_t* heap = NULL;
static size_t heap_top = 0;
void* allocate(size_t size) {
	size_t old_top = heap_top;
	heap_top += size;
	assert(heap_top <= HEAP_SIZE);
	return &heap[old_top];
}

int main(int argc, char** argv){
	heap = malloc(HEAP_SIZE);
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
	char* p;
	Inventory inventory = { 0 };
	while (fgets(line, sizeof(line), fptr)) {
		Item* newItem = allocate(sizeof(Item));
		p = strtok(line, ", "); //not needed(name, )
		p = strtok(NULL, ", "); //name of the item
		if (newItem != NULL) {
		newItem->name = strdup(p);
		}
		p = strtok(NULL, ", "); //not needed(value, )

		p = strtok(NULL, ", "); //value of the item
		if (newItem != NULL) {
		newItem->value = strtol(p, NULL, 10);
		}
		index++;
		if (newItem != NULL) {
		printf("%s: %d\n", newItem->name, newItem->value);
		monprojet_add(&inventory, newItem);
		monprojet_showItem(&inventory, newItem);
		monprojet_sort(&inventory);
	    monprojet_delete(&inventory, newItem);
		}
	}
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