/*
 * menu.c
 *
 *  Created on: 22 de mai. de 2022
 *      Author: DyCampos
 */

#include <stdlib.h>
#include "menu.h"

int id_selecionado_menu = 0;
int posicao_seta_menu = 0;
int numero_linhas_menu = 0;
int menu_iniciado = 0;
int numero_itens_menu = 0;
struct menu *p_menu;

void menuInit(int nLinhasTela, int nItens){
	numero_linhas_menu = nLinhasTela;
	menu_iniciado = 1;
	numero_itens_menu = nItens;
	p_menu = malloc(nItens * sizeof(struct menu));
}

int getNumeroLinhasTelaMenu(){
	return numero_linhas_menu;
}

void setNumeroLinhasTelaMenu(int nLinhasTela){
	numero_linhas_menu = nLinhasTela;
}

int getPosicaoSetaMenu() {
	return posicao_seta_menu;
}

void addItemMenu(struct menu item) {
	if(item.id < numero_itens_menu && item.id >= 0) {
		p_menu[item.id] = item;
	}
}

void decrementaItemMenu() {
	if(id_selecionado_menu > 0) {
		id_selecionado_menu = id_selecionado_menu - 1;
	}
}

void incrementaItemMenu() {
	if(id_selecionado_menu < numero_itens_menu - 1) {
		id_selecionado_menu = id_selecionado_menu + 1;
	}
}

void decrementaPosicaoSetaMenu() {
	if(posicao_seta_menu > 0) {
		posicao_seta_menu--;
	}
}

void incrementaPosicaoSetaMenu() {
	if(posicao_seta_menu < numero_linhas_menu - 1) {
		posicao_seta_menu++;
	}
}

int getIDSelecionadoMenu(){
	return id_selecionado_menu;
}

struct menu getItemMenu(int i){
	return p_menu[i];
}

int getNumeroItensMenu(){
	return (int) numero_itens_menu;
}

void botaoPressionado(int botao) {
	if(menu_iniciado) {
		switch(botao) {
			case UP:
				decrementaItemMenu();
				decrementaPosicaoSetaMenu();
				break;

			case DOWN:
				incrementaItemMenu();
				incrementaPosicaoSetaMenu();
				break;

			case LEFT:
				break;

			case RIGHT:
				break;

			case SELECT:
				break;
		}
	}
}

