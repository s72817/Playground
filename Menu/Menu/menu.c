#include <stdio.h>
#include <stdlib.h>

/// <summary>
/// Menu-Struktur mit Ebenen
/// </summary>
/// <param name="item">Menu-Name</param>
/// <param name="level">Menuebene</param>
typedef struct _menu{
	char item[20];
	int level;
	struct _menu *next;
} menu;


/// <summary>
/// Menuelement hinzufugen
/// </summary>
/// <param name="list">Zeiger auf Liste</param>
/// <param name="item">Menu-Name</param>
/// <param name="level">Menuebene</param>
void menu_add(menu **list, char *item, int level){

	menu *newEl;
	menu *lst_iter = *list;

	newEl = (menu*)malloc(sizeof(*newEl)); // erzeuge ein neues Element
	strcpy(newEl->item, item);
	newEl->level = level;
	newEl->next = NULL; // Wichtig für das Erkennen des Listenendes

	if (lst_iter != NULL) { // sind Elemente vorhanden
		while (lst_iter->next != NULL) // suche das letzte Element
			lst_iter = lst_iter->next;
		lst_iter->next = newEl; // Hänge das Element hinten an
	}
	else // wenn die liste leer ist, bin ich das erste Element
		*list = newEl;
}

/// <summary>
/// Menu wird erstellt
/// </summary>
/// <param name="list">Liste</param>
/// <param name="level">Menuebene</param>
void menu_show(menu *list, int level) {
	int counter = 1;
	while (list != NULL) {
		if (list->level == level)
			printf("%d. %s\n", counter++, list->item);
		list = list->next;
	}
}