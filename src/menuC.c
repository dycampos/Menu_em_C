/*
 ============================================================================
 Name        : menuC.c
 Author      : DyCampos
 Version     :
 Copyright   : 
 Description : Menu in C. Exemplo de aplicação.
 Repository of lcd_simulator: https://github.com/dycampos/simulador_de_LCD_em_linguagem_C
 ============================================================================
 */

#include <stdio.h>
#include "lcd_simulator.h"
#include "menu.h"

int main() {
	//Tamanho da tela do dispositivo de saída. No exemplo um LCD 16x4
	int tamanhoTela = 4;

	//Tecla pressionada. Utiliza o enum teclas.
	int teclaPressionada = -1;

	//Desenho utilizado na seta do menu
	char desenho_seta[2] = {'>', '\0'};

	//Inicia o LCD 16x4
	lcdBegin(16, tamanhoTela);

	//Inicia o menu com espaço alocado para 12 itens
	menuInit(tamanhoTela, 12);

	//Adiciona os itens do menu
	addItemMenu((struct menu){0, 10, "Frequencia"});
	addItemMenu((struct menu){1, 25, "Potencia"});
	addItemMenu((struct menu){2, 10, "Tensão"});
	addItemMenu((struct menu){3, 10, "Corrente"});
	addItemMenu((struct menu){4, 17, "A"});
	addItemMenu((struct menu){5, 48, "B"});
	addItemMenu((struct menu){6, 7, "C"});
	addItemMenu((struct menu){7, 72, "D"});
	addItemMenu((struct menu){8, 89, "E"});
	addItemMenu((struct menu){9, 13, "F"});
	addItemMenu((struct menu){10, 240, "G"});
	addItemMenu((struct menu){11, 130, "H"});

	while(1) {
		clearLCD();

		//Imprimi os itens do menu com base na posição da seta e no ID do item selecionado
		int id_inicial = getIDSelecionadoMenu() - getPosicaoSetaMenu();
		for(int i = 0; i < getNumeroLinhasTelaMenu(); i++) {
			writeLCD(2, i, getItemMenu(id_inicial + i).titulo);
		}
		writeLCD(0, getPosicaoSetaMenu(), desenho_seta);
		printLCD();

		//Recebe opção do botão pressionado: UP = 0, DOWN = 1, RIGHT = 2, LEFT = 3, SELECT = 4
		printf("Digite a opção:");
		fflush(stdout);
		scanf("%d", &teclaPressionada);
		botaoPressionado(teclaPressionada);
	}

  return 0;
}


