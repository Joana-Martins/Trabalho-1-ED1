// BIBLIOTECA DE FUNCOES DE MANIPULACAO DO TRUNFO

#ifndef BIBLIOTECAFUNCOESTRUNFO_H_
#define BIBLIOTECAFUNCOESTRUNFO_H_

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include"Biblioteca_Funcoes_Basicas.h"
#include"Biblioteca_Funcoes_IR.h"

TipoCarta CortaTrunfo(TipoLista* baralho);
void ReposicionaTrunfo(TipoCarta trunfo, TipoLista* baralho);

#endif