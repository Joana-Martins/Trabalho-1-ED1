// BIBLIOTECA DE FUNCOES DE INSERIR E RETIRAR CARTAR DE BARALHO

#ifndef BIBLIOTECAFUNCOESIR_H_
#define BIBLIOTECAFUNCOESIR_H_

#include<stdio.h>
#include<stdlib.h>
#include"Biblioteca_Funcoes_Basicas.h"
#include "liberdade.h"

int ExisteCarta(TipoCarta carta, TipoLista* baralho);
void InsereCarta(TipoCarta carta, TipoLista *baralho);
void RetiraPrimeiraCarta(TipoLista *baralho);
void RetiraCarta(TipoCarta carta, TipoLista *baralho);
TipoCarta PegaPrimeiraCarta(TipoLista *baralho);

#endif
