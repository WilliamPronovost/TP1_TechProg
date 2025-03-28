#pragma once
#include <stddef.h>

typedef struct item Item;

struct item{
<<<<<<< HEAD
	char* name;
=======
	char* name[512];
>>>>>>> ad51f1c3877bed44b6ed3815d935811eb4231952
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
<<<<<<< HEAD
};
void* allocate(size_t size);
=======
}; 

>>>>>>> ad51f1c3877bed44b6ed3815d935811eb4231952

void monprojet_add(Inventory* inventory, Item* item);

void monprojet_delete(Inventory* inventory, Item* item);

void monprojet_sort(Inventory* inventory);

<<<<<<< HEAD
Item* monprojet_findByPosition(Inventory* inventory, int position);

Item* monprojet_findByName(Inventory* inventory, char* name[512]);

void monprojet_showItem(Inventory* inventory, Item* item);

=======
Slot* monprojet_findByPosition(Inventory* inventory, int position);

Item* monprojet_findByName(Inventory* inventory, char* name[512]);

>>>>>>> ad51f1c3877bed44b6ed3815d935811eb4231952



