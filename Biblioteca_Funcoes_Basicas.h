// BIBLIOTECA DE STRUCTUS E FUNCOES DE INICIALIZACAO DE VARIAVEIS

#ifndef BIBLIOTECAFUNCOESBASICAS_H_
#define BIBLIOTECAFUNCOESBASICAS_H_

#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char valor;
    char naipe;
} TipoCarta;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoCarta Item;
  TipoApontador Prox;
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

TipoCarta* InicializaCarta();
TipoCelula* InicializaCelula();
TipoLista* InicializaBaralho();
TipoLista* FazBaralhoVazio();
int ChecaBaralhoVazio(TipoLista* baralho);
int Quantidade(TipoLista* baralho);

#endif