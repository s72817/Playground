#include <stdlib.h>
#include <stdio.h>

//#include "menu.c"
#include "menu.c"


int main() {
	menu *m = NULL; // init. die Liste mit NULL = leere liste

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