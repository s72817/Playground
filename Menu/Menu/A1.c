#include <stdlib.h>
#include <stdio.h>


struct _menu{
	char item[20];
	struct _menu *next;
};

typedef struct _menu menu;


void menu_add(menu **list, char *item){

	menu *newEl;
	menu *lst_iter = *list;

	newEl = (menu*) malloc(sizeof(*newEl)); // erzeuge ein neues Element
	strcpy(newEl->item, item);
	newEl->next = NULL; // Wichtig für das Erkennen des Listenendes

	if (lst_iter != NULL) { // sind Elemente vorhanden
		while (lst_iter->next != NULL) // suche das letzte Element
			lst_iter = lst_iter->next;
		lst_iter->next = newEl; // Hänge das Element hinten an
	}
	else // wenn die liste leer ist, bin ich das erste Element
		*list = newEl;
}

void menu_show(menu *list) {
	while (list != NULL) {
		printf("%s\n", list->item);
		list = list->next;
	}
}

int main() {
	menu *m = NULL; // init. die Liste mit NULL = leere liste

	menu_add(&m, "Kunde anlegen");
	menu_add(&m, "Anmelden");
	menu_add(&m, "Schliessen");

	menu_show(m);
		
	getch();
	return 0;
}