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

int main(int argc, char** argv) {
	heap = (uint8_t*)malloc(HEAP_SIZE);
	assert(heap != NULL);

	srand(time(NULL));

	int max = 10;
	int min = 0;
	char* fiole = "fiole";
	int fioleValue = 25;
	int rd_num = rand() % (max - min + 1) + min;
	FILE* fptr;
	fptr = fopen("tp1_data.csv", "r");
	if (fptr == NULL) {
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
		newItem->name = strdup(p);
		p = strtok(NULL, ", "); //not needed(value, )

		p = strtok(NULL, ", "); //value of the item
		newItem->value = strtol(p, NULL, 10);
		index++;
		printf("%s: %d\n", newItem->name, newItem->value);
		monprojet_add(&inventory, newItem);
		monprojet_showItem(&inventory, newItem);
		monprojet_sort(&inventory);
	    monprojet_delete(&inventory, newItem);
	}
	
	//for (int i = 0; i < index; i++) {
	//	printf("%s ", names[i]);
	//	printf("%d\n", values[i]);
	//}
	//printf("Le nombre d'objets dans l'inventaire (incluant la fiole) est de: ");
	//printf("%d\n", rd_num + 1);
	//printf("Items choisis: \n");
	printf("%s ", fiole);
	printf("%d\n", fioleValue);
	//for (int i = 0; i < rd_num; i++) {
	//	int itemList = values[ (rand() % index)];
	//	printf("%d\n", itemList);
	//}
	
}