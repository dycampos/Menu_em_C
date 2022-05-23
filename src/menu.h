/*
 * menu.h
 *
 *  Created on: 22 de mai. de 2022
 *      Author: DyCampos
 */

#ifndef MENU_H_
#define MENU_H_

#ifndef NUMERO_ITENS_MENU
#define NUMERO_ITENS_MENU 4
#endif

#ifndef NUMERO_LINHAS_PRINT_MENU
#define NUMERO_LINHAS_PRINT_MENU 2
#endif

#define TAMANHO_TITULO 11

struct menu{
	int id;
	int valor;
	char titulo[TAMANHO_TITULO];
};

void addItemMenu(struct menu);
void decrementaItemMenu();
void incrementaItemMenu();
int getIDSelecionadoMenu();
struct menu getItemMenu(int);
int getNumeroItensMenu();

#endif /* MENU_H_ */
