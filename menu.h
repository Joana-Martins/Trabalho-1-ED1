//BIBLIOTECA DO MENU INTERATIVO DO JOGO

#ifndef MENU_H_
#define MENU_H_

#include<stdio.h>
#include<stdlib.h>
#include<termios.h>
#include<unistd.h>

int getch(void);
int seta();
void titulo();
void dificuldade(int i);
void jogadores(int i);
void selecionado(int i);
int menu_J(int y);
int menu_D();
int menu();

#endif