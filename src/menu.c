/*
 * menu.c
 *
 *  Created on: 22 de mai. de 2022
 *      Author: DyCampos
 */

#include "menu.h"

int id_selecionado_menu = 0;
struct menu p_menu[NUMERO_ITENS_MENU];

void addItemMenu(struct menu item) {
	if(item.id < NUMERO_ITENS_MENU && item.id >= 0) {
		p_menu[item.id] = item;
	}
}

void decrementaItemMenu() {
	if(id_selecionado_menu > 0) {
		id_selecionado_menu = id_selecionado_menu - 1;
	}
}

void incrementaItemMenu() {
	if(id_selecionado_menu < NUMERO_ITENS_MENU - NUMERO_LINHAS_PRINT_MENU) {
		id_selecionado_menu = id_selecionado_menu + 1;
	}
}

int getIDSelecionadoMenu(){
	return id_selecionado_menu;
}

struct menu getItemMenu(int i){
	return p_menu[i];
}

int getNumeroItensMenu(){
	return (int) NUMERO_ITENS_MENU;
}

