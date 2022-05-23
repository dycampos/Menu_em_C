/*
 ============================================================================
 Name        : lcd_simulator.c
 Author      : DyCampos
 Description : Simulator LCD
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "lcd_simulator.h"

int lcd_height;
int lcd_width;
int lcd_init_g = 0;
char **lcd_g = NULL;

//Dynamically allocate a matrix
//https://www.youtube.com/watch?v=YNVKlEL2hpo
char **createDynamicMatrix(int col, int row) {
	char **mtx = malloc(row * sizeof(char*));

	for(int i = 0; i < row; i++){
		mtx[i] = malloc(col * sizeof(char));
	}

	return mtx;
}

void lcdBegin(int col, int row) {
	lcd_g = createDynamicMatrix(col, row);
	lcd_height = row;
	lcd_width = col;
	lcd_init_g = 1;

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			lcd_g[i][j] = ' ';
		}
	}
}

void clearPositionLCD(int col, int row) {
  if(lcd_init_g) {
	  lcd_g[row][col] = ' ';
  }  
}

void clearLCD() {
  if(lcd_init_g) {
    for(int c = 0; c < lcd_width; c++){
      for(int r = 0; r < lcd_height; r++){
    	  clearPositionLCD(c, r);
      }
    }
  }
}

void writeLCD(int col, int row, char *message) {
  if(lcd_init_g) {
    int i = 0;  
    while(message[i] != '\0'){
    	lcd_g[row][col + i] = message[i];
      i++;
    }   
  } 
}

void printLCD(){
  if(lcd_init_g) {
    //Print superior limit line
    for(int c = 0; c < lcd_width; c++){
      printf("%c", '-');
    }
    printf("%c", '\n');

    //Print LCD message
    for(int r = 0; r < lcd_height; r++){
      for(int c = 0; c < lcd_width; c++){
        printf("%c", lcd_g[r][c]);
      }
      printf("%c", '\n'); 
    }
    
    //Print inferior limit line
    for(int c = 0; c < lcd_width; c++){
    printf("%c", '-');     
    }
    printf("%c", '\n');
  }
}
