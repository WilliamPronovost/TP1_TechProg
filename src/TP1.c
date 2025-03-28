
#include "TP1.h"
#pragma once

void monprojet_add(Inventory* inventory, Item* item) {

	Slot* s;
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
void monprojet_delete(Inventory* inventory, Item* item) {

	Slot* current = inventory->first;
	while (current != NULL) {
		if (current->data == item) {
			current->prev->next = current->next;
			current->next->prev = current->prev;
			current = NULL;
			inventory->count--;
			break;
		}
		current = current->next;
	}
}
void monprojet_sort(Inventory* inventory) {
	Item* temp;
	Slot* current;
	Slot* next;
	int swap = 0;
	for (int i = 1; i < inventory->count; i++){
		current = monprojet_findByPosition(inventory, i);
		next = monprojet_findByPosition(inventory, i+1);
		if(current->data->value > next->data->value){
			swap = 1;
			temp = current->data;
			current->data = next->data;
			next->data = temp;
		}
		if(i == inventory->count - 1 && swap == 1){
			swap = 0;
			i = 0;
		}
	}
}
Slot* monprojet_findByPosition(Inventory* inventory, int position) {
	if(position > inventory->count || position < 1){		
		return;
	}
	Slot* current = inventory->first;
	for (int i = 1; i < position; i++){
		current = current->next;
	}
	return current->data;
}
Item* monprojet_findByName(Inventory* inventory, char* name[512]) {
	Slot* current = inventory->first;
	while (current->data->name != name){
		current = current->next;
		if(current == NULL){
		return;
		}
		
	}
	return current->data;
}
