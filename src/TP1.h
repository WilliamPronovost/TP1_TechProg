#pragma once
#include <stddef.h>

typedef struct item Item;

struct item{
	char* name;
	int value;
};

typedef struct slot Slot;

struct slot{
	Item* data;
	Slot* prev;
	Slot* next;
};

typedef struct inventory Inventory;

struct inventory{
	Slot* first;
	Slot* last;
	int count; 	
};
void* allocate(size_t size);

void monprojet_add(Inventory* inventory, Item* item);

void monprojet_delete(Inventory* inventory, Item* item);

void monprojet_sort(Inventory* inventory);

Item* monprojet_findByPosition(Inventory* inventory, int position);

Item* monprojet_findByName(Inventory* inventory, char* name[512]);

void monprojet_showItem(Inventory* inventory, Item* item);





