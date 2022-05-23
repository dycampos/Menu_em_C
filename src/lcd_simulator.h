/*
 ============================================================================
 Name        : lcd_simulator.h
 Author      : DyCampos
 Description : Simulator LCD
 ============================================================================
 */
#ifndef LCD_SIMULATOR_H_
#define LCD_SIMULATOR_H_

#include <stdio.h>

void lcdBegin(int col, int row);
void clearPositionLCD(int col, int row);
void clearLCD();
void writeLCD(int col, int row, char *message);
void printLCD();
char **createDynamicMatrix(int col, int row);

#endif
