// BIBLIOTECA DE FUNCOES DE CRIACAO E MANIPULACAO DE BARALHO

#ifndef BIBLIOTECAFUNCOESCM_H_
#define BIBLIOTECAFUNCOESCM_H_

#include<stdio.h>
#include<stdlib.h>
#include"Biblioteca_Funcoes_Basicas.h"
#include"Biblioteca_Funcoes_IR.h"

void CriaBaralhoInicial(TipoLista* baralho);
void EmbaralhaBaralhoAuxiliar(TipoLista* baralho);
void EmbaralhaBaralho(TipoLista *baralho);
TipoLista* FormarMao(TipoLista* baralho);

#endif