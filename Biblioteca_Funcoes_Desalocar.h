#ifndef BIBLIOTECAFUNCOESDESALOCAR_H_
#define BIBLIOTECAFUNCOESDESALOCAR_H_

#include<stdio.h>
#include<stdlib.h>
#include"Biblioteca_Funcoes_Basicas.h"

void DesalocaCelula(TipoCelula *celula);
void DesalocaLista(TipoLista *Lista);
void DesalocaListaDeLista(TipoLista **Lista, int numero_jogadores);

#endif