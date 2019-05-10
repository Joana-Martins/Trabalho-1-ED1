// BIBLIOTECA DE STRUCTUS E FUNCOES DE INICIALIZACAO DE VARIAVEIS

#ifndef BIBLIOTECAFUNCOESBASICAS_H_
#define BIBLIOTECAFUNCOESBASICAS_H_

#include<stdio.h>
#include<stdlib.h>

/* STRUCTS */
typedef struct{
    char valor; //DETERMINA A PONTUACAO DA CARTA
    char naipe; //DETERMINA O NAIPE DA CARTA
} TipoCarta;

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula {
  TipoCarta Item; //CARTA DE UMA CELULA
  TipoApontador Prox; //APONTADOR PARA A PROXIMA CELULA
} TipoCelula;

typedef struct {
  TipoApontador Primeiro, Ultimo;
} TipoLista;

/* FUNCOES */

TipoCarta* InicializaCarta();
TipoCelula* InicializaCelula();
TipoLista* InicializaBaralho();
TipoLista* FazBaralhoVazio();
int ChecaBaralhoVazio(TipoLista* baralho);
int Quantidade(TipoLista* baralho);
int MesmoNaipe(TipoCarta *carta1, TipoCarta* carta2);
int MesmoValor(TipoCarta *carta1, TipoCarta* carta2);
int MesmaCarta(TipoCarta *carta1, TipoCarta* carta2);

#endif