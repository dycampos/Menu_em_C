/*
 * menu.h
 *
 *  Created on: 22 de mai. de 2022
 *      Author: DyCampos
 *      Descrição: biblioteca que implementa um Menu em linguagem C.
 */

#ifndef MENU_H_
#define MENU_H_

/**
 * Enumeração teclas representa os botões de seleção do menu.
 */
enum teclas {UP, /*!< Sobe um item no menu. */
			DOWN,  /*!< Desce um item no menu. */
			RIGHT, /*!< Quando no modo de edição, incrementa o valor do item selecionado. */
			LEFT, /*!< Quando no modo de edição, decrementa o valor do item selecionado. */
			SELECT /*!< Entra no item selecionado para alterar seu valor. */
};

/**
 * Estrutura do Menu. Contêm as informações dos itens do menu.
 */
struct menu{
	int id; /*!< representa a identificação do item do Menu. Deve ser atribuído um valor único para cada Menu. */
	int valor; /*!< Valor a ser atribuido ao item do menu. */
	char *titulo; /*!< Mensagem que aparecerá no dispositivo de saída identificando o item do Menu */
};

/**
 * Função que inicializa o menu. Esta função deve ser utilizada antes de qualquer outra.
 *
 * @param nLinhasTela - a variável recebe um inteiro com o número de linhas do dispositivo de saída.
 * 		Por exemplo, para um LCD 16x2, a variável deve ser definida com o valor 2. A variável é utilizada
 * 		para controle do limite da seta de seleção do Menu.
 * @param nItens - a variável recebe um inteiro com a quantidade de itens que será utilizada no Menu.
 */
void menuInit(int nLinhasTela, int nItens);

/**
 * Função que retorna o número de linhas, definido pelo usuário, do dispositivo de saída.
 * @return retorna um inteiro com o número de linhas do dispositivo de saída.
 */
int getNumeroLinhasTelaMenu();

/**
 * Função que altera o número de linhas do dispositivo de saída. A variável é inicializada na chamada
 * 		da função menuInit().
 * @param nLinhasTela recebe um inteiro com o número de linhas do dispositivo de saída.
 */
void setNumeroLinhasTelaMenu(int nLinhasTela);

/**
 * Função que retorna a posição atual da seta de seleção do Menu.
 * @return retorna um inteiro com o número da linha que a seta de seleção está posicionada.
 */
int getPosicaoSetaMenu();

/**
 * Função de adiciona um novo item na lista de Menu.
 * @param item recebe uma estrutura do tipo Menu com as informações do menu a ser adicionado na lista
 */
void addItemMenu(struct menu item);

/**
 * Função utilizada para incrementar o ID do item selecionado no Menu. O ID do item selecionado,
 * 		indica a seleção do usuário.
 */
void decrementaItemMenu();

/**
 * Função utilizada para decrementar o ID do item selecionado no Menu. O ID do item selecionado,
 * 		indica a seleção do usuário.
 */
void incrementaItemMenu();

/**
 * Função utilizada para decrementar a posição da seta no dispositivo de saída. A posição da seta, indica
 * 		qual a linha, do dispositivo de saída, está selecionada pelo usuário.
 */
void decrementaPosicaoSetaMenu();

/**
 * Função utilizada para incrementar a posição da seta no dispositivo de saída. A posição da seta, indica
 * 		qual a linha, do dispositivo de saída, está selecionada pelo usuário.
 */
void incrementaPosicaoSetaMenu();

/**
 * Função que retorna o ID  do item selecionado pelo usuário no dispositivo de saída.
 * @return um inteiro com o valor do ID do item selecionado.
 */
int getIDSelecionadoMenu();

/**
 * Função que retorna a estrutura do item selecionado.
 * @param i recebe um inteiro com o ID do item selecionado
 * @return uma estrutura do tipo menu com as informações do item selecionado.
 */
struct menu getItemMenu(int i);

/**
 * Função que retorna a quantidade de itens do Menu
 * @return retorna um inteiro com o número de itens do menu.
 */
int getNumeroItensMenu();

/**
 * Função que controla as informações de posição da seta e do ID com base no botão pressionado.
 * @param botao recebe um inteiro com o valor do botão pressionado. É utilizado a informação do enum Teclas.
 */
void botaoPressionado(int botao);

#endif /* MENU_H_ */
