#include <stdlib.h>
#include <stdio.h>

//#include "menu.c"
#include "menu.c"

//typedef struct _menu{
//	char item[20];
//	int level;
//	struct _menu *next;
//}menu;
//
//
//void menu_add(menu **list, char *item, int level){
//
//	menu *newEl;
//	menu *lst_iter = *list;
//
//	newEl = (menu*) malloc(sizeof(*newEl)); // erzeuge ein neues Element
//	strcpy(newEl->item, item);
//	newEl->level = level;
//	newEl->next = NULL; // Wichtig für das Erkennen des Listenendes
//
//	if (lst_iter != NULL) { // sind Elemente vorhanden
//		while (lst_iter->next != NULL) // suche das letzte Element
//			lst_iter = lst_iter->next;
//		lst_iter->next = newEl; // Hänge das Element hinten an
//	}
//	else // wenn die liste leer ist, bin ich das erste Element
//		*list = newEl;
//}
//
//void menu_show(menu *list, int level) {
//	int counter = 1;
//	while (list != NULL) {
//		if (list->level == level)
//			printf("%d. %s\n", counter++, list->item);
//		list = list->next;
//	}
//}


int main() {
	//menu *m = NULL; // init. die Liste mit NULL = leere liste
	menu *m = NULL;
	
	/*char *menu1[] = { 
		"Kunde anlegen", 
		"Anmelden", 
		"Beenden"};
	int len = 3;
	for (int i = 0; i < len; i++)
		menu_add(&m, menu1[i], 1);*/

	menu_add(&m, "Kunde anlegen",1);
	menu_add(&m, "Anmelden", 1);
	menu_add(&m, "Schliessen", 1);
	menu_add(&m, "Einzahlen", 2);
	menu_add(&m, "Auszahlen", 2);

	menu_show(m, 1);
	printf("-----------------\n");
	menu_show(m, 2);

		
	getch();
	return 0;
}