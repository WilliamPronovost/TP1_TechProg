#include "TP1.h"
#pragma once

void monprojet_add(Inventory* inventory, Item* item){

	Slot* s= allocate(sizeof(Slot));;
	s->data = item;
	if (inventory->first == NULL) {
		inventory->first = s;
		inventory->last = s;
		return;
	}
	s->prev = inventory->last;
	inventory->last->next = s;
	inventory->count++;
}
void monprojet_delete(Inventory* inventory, Item* item){
	
	Slot* current = inventory->first;
	while(current != NULL){
		if(current->data == item){
			current->prev->next = current->next;
			current->next->prev = current->prev;
			current = NULL;
			inventory->count--;
			break;
		}
		current = current->next;
	}
}
void monprojet_sort(Inventory* inventory){
	Item* temp;
	Slot* current; 
	Slot* next;
	int swap = 0;
	for (int i = 1; i < inventory->count; i++) {
		current = monprojet_findByPosition(inventory, i);
		next = monprojet_findByPosition(inventory, i + 1);
		if (current->data->value > next->data->value) {
			swap = 1;
			temp = current->data;
			current->data = next->data;
			next->data = temp;
		}
		if (i == inventory->count - 1 && swap == 1) {
			swap = 0;
			i = 0;
		}
	}
}
Item* monprojet_findByPosition(Inventory* inventory, int position){
	if (position > inventory->count || position < 1) {
		return;
	}
	Slot* curr = inventory->first;
	for (int i = 1; i < position; i++) {
		curr = curr->next;
	}
	return curr->data;
}
Item* monprojet_findByName(Inventory* inventory, char* name[512]){
	Slot* currNode = inventory->first;
	while (currNode->data->name != name) {
		currNode = currNode->next;
		if (currNode == NULL) {
			return;
		}

	}
	return currNode->data;
}
void monprojet_showItem(Inventory* inventory, Item* item)
{
	Slot* current = inventory->first;
	Slot* last = inventory->last;
	Slot* nextItem = current->next;
	while (current != NULL) {
		Item* currentItem = current->data;
		printf("% s: % d\n", currentItem->name, currentItem->value);
		current = current->next;
	}
}
