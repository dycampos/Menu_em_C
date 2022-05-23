/*
 ============================================================================
 Name        : menuC.c
 Author      : DyCampos
 Version     :
 Copyright   : 
 Description : Menu in C
 Repository of lcd_simulator: https://github.com/dycampos/simulador_de_LCD_em_linguagem_C
 ============================================================================
 */
#include <stdio.h>
#include "lcd_simulator.h"
#include "menu.h"

#define NUMERO_ITENS_MENU 4
#define NUMERO_LINHAS_PRINT_MENU 2

enum teclas {UP, DOWM,  RIGHT, LEFT};

int main() {
	addItemMenu((struct menu){0, 10, "Frequencia"});
	addItemMenu((struct menu){1, 25, "Potencia"});
	addItemMenu((struct menu){2, 10, "Tensão"});
	addItemMenu((struct menu){3, 10, "Corrente"});

	for(int i = 0; i < getNumeroItensMenu(); i++) {
		printf("ID: %d \n", getItemMenu(i).id);
		printf("Valor: %d\n", getItemMenu(i).valor);
		printf("Título: %s\n", getItemMenu(i).titulo);
		printf("\n");
	}

  int opcao;
  int sair = 0;

  lcdBegin(16, NUMERO_LINHAS_PRINT_MENU);

  while(!sair) {
	clearLCD();
	int itemSelecionado = getIDSelecionadoMenu();
	if(getIDSelecionadoMenu() == getNumeroItensMenu() -1){
		writeLCD(1, 0, getItemMenu(itemSelecionado - 1).titulo);
		writeLCD(1, 1, getItemMenu(itemSelecionado).titulo);
		printLCD();
     }
     else{
    	 writeLCD(1, 0, getItemMenu(itemSelecionado).titulo);
    	 writeLCD(1, 1, getItemMenu(itemSelecionado + 1).titulo);
    	 printLCD();
     }

     printf("Digite a opção:");
     fflush(stdout);
     scanf("%d", &opcao);

     if(opcao == -1){
       sair = 1;
     }
     //tecla 1 sobe Menu
     else if(opcao == UP){
    	 decrementaItemMenu();
     }
     //tecla 1 desce Menu
     else if (opcao == DOWM){
    	 incrementaItemMenu();
     }
   }

  return 0;
}


