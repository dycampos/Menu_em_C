/*
 * menu.h
 *
 *  Created on: 22 de mai. de 2022
 *      Author: DyCampos
 *      Descri��o: biblioteca que implementa um Menu em linguagem C.
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * Enumera��o teclas representa os bot�es de sele��o do menu.
 */
enum teclas {UP, /*!< Sobe um item no menu. */
			DOWN,  /*!< Desce um item no menu. */
			RIGHT, /*!< Quando no modo de edi��o, incrementa o valor do item selecionado. */
			LEFT, /*!< Quando no modo de edi��o, decrementa o valor do item selecionado. */
			SELECT /*!< Entra no item selecionado para alterar seu valor. */
};

/**
 * Estrutura do Menu. Cont�m as informa��es dos itens do menu.
 */
struct menu{
	int id; /*!< representa a identifica��o do item do Menu. Deve ser atribu�do um valor �nico para cada Menu. */
	int valor; /*!< Valor a ser atribuido ao item do menu. */
	char *titulo; /*!< Mensagem que aparecer� no dispositivo de sa�da identificando o item do Menu */
};

/**
 * Fun��o que inicializa o menu. Esta fun��o deve ser utilizada antes de qualquer outra.
 *
 * @param nLinhasTela - a vari�vel recebe um inteiro com o n�mero de linhas do dispositivo de sa�da.
 * 		Por exemplo, para um LCD 16x2, a vari�vel deve ser definida com o valor 2. A vari�vel � utilizada
 * 		para controle do limite da seta de sele��o do Menu.
 * @param nItens - a vari�vel recebe um inteiro com a quantidade de itens que ser� utilizada no Menu.
 */
void menuInit(int nLinhasTela, int nItens);

/**
 * Fun��o que retorna o n�mero de linhas, definido pelo usu�rio, do dispositivo de sa�da.
 * @return retorna um inteiro com o n�mero de linhas do dispositivo de sa�da.
 */
int getNumeroLinhasTelaMenu();

/**
 * Fun��o que altera o n�mero de linhas do dispositivo de sa�da. A vari�vel � inicializada na chamada
 * 		da fun��o menuInit().
 * @param nLinhasTela recebe um inteiro com o n�mero de linhas do dispositivo de sa�da.
 */
void setNumeroLinhasTelaMenu(int nLinhasTela);

/**
 * Fun��o que retorna a posi��o atual da seta de sele��o do Menu.
 * @return retorna um inteiro com o n�mero da linha que a seta de sele��o est� posicionada.
 */
int getPosicaoSetaMenu();

/**
 * Fun��o de adiciona um novo item na lista de Menu.
 * @param item recebe uma estrutura do tipo Menu com as informa��es do menu a ser adicionado na lista
 */
void addItemMenu(struct menu item);

/**
 * Fun��o utilizada para incrementar o ID do item selecionado no Menu. O ID do item selecionado,
 * 		indica a sele��o do usu�rio.
 */
void decrementaItemMenu();

/**
 * Fun��o utilizada para decrementar o ID do item selecionado no Menu. O ID do item selecionado,
 * 		indica a sele��o do usu�rio.
 */
void incrementaItemMenu();

/**
 * Fun��o utilizada para decrementar a posi��o da seta no dispositivo de sa�da. A posi��o da seta, indica
 * 		qual a linha, do dispositivo de sa�da, est� selecionada pelo usu�rio.
 */
void decrementaPosicaoSetaMenu();

/**
 * Fun��o utilizada para incrementar a posi��o da seta no dispositivo de sa�da. A posi��o da seta, indica
 * 		qual a linha, do dispositivo de sa�da, est� selecionada pelo usu�rio.
 */
void incrementaPosicaoSetaMenu();

/**
 * Fun��o que retorna o ID  do item selecionado pelo usu�rio no dispositivo de sa�da.
 * @return um inteiro com o valor do ID do item selecionado.
 */
int getIDSelecionadoMenu();

/**
 * Fun��o que retorna a estrutura do item selecionado.
 * @param i recebe um inteiro com o ID do item selecionado
 * @return uma estrutura do tipo menu com as informa��es do item selecionado.
 */
struct menu getItemMenu(int i);

/**
 * Fun��o que retorna a quantidade de itens do Menu
 * @return retorna um inteiro com o n�mero de itens do menu.
 */
int getNumeroItensMenu();

/**
 * Fun��o que controla as informa��es de posi��o da seta e do ID com base no bot�o pressionado.
 * @param botao recebe um inteiro com o valor do bot�o pressionado. � utilizado a informa��o do enum Teclas.
 */
void botaoPressionado(int botao);

#endif /* MENU_H_ */
