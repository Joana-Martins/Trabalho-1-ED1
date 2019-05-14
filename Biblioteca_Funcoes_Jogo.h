// BIBLIOTECA DE FUNCOES DE JOGO

#ifndef BIBLIOTECAFUNCOESJOGO_H_
#define BIBLIOTECAFUNCOESJOGO_H_

#define JOGADOR 0
#define ADVERSARIO1 1
#define ADVERSARIO2 2
#define ADVERSARIO3 3

#include<stdio.h>
#include<stdlib.h>
#include"Biblioteca_Funcoes_Basicas.h"
#include"Biblioteca_Funcoes_IR.h"
#include"Biblioteca_Funcoes_Trunfo.h"
#include"Biblioteca_Funcoes_CM.h"
#include"Biblioteca_Funcoes_Exibicao.h"

TipoLista* PreparaBaralho(TipoCarta* trunfo);
TipoLista** PreparaMaos(TipoLista* baralho, int numero_jogadores);
TipoLista** PreparaMontePontos(TipoLista* baralho, int numero_jogadores);
TipoCarta ChecaExisteCarta(TipoCarta carta[], TipoLista** mao, int numero_jogadores);
TipoCarta* MelhordaMao(TipoLista* mao);
TipoCarta* PiordaMao(TipoLista* mao);
void JogaComputador(TipoCarta carta[], TipoCarta* trunfo, TipoLista** mao, int adversarios, char modo_jogo);
int PontosCarta(TipoCarta* carta);
TipoCarta* MelhorCarta(TipoCarta* carta1, TipoCarta* carta2);
TipoCarta* CartaGanhadoraAux(TipoCarta* carta1, TipoCarta* carta2, TipoCarta* trunfo);
int* RefazOrdemJogadores(int ganhou, int numero_jogadores);
TipoCarta* CartaGanhadora(TipoCarta carta[],TipoCarta* trunfo, int numero_jogadores, int ganhou);
void ImprimeCartasJogadas(TipoCarta carta[], int numero_jogadores, int ganhou);
void InsereMontePontos(TipoCarta carta[],TipoLista** pontos, TipoCarta *trunfo, int numero_jogadores, int ganhou);
void RefazMaoBaralho(TipoLista** mao, TipoLista* baralho, int numero_jogadores);
int TotalPontos(TipoLista* bolo);
void ImprimePontos(TipoLista** pontos,int numero_jogadores);
TipoLista* MaiorPonto(TipoLista** pontos,int numero_jogadores);
void Ganhador(TipoLista** pontos,int numero_jogadores);
void FazOrdemJogadores(int ganhou, int numero_jogadores, TipoCarta* trunfo, TipoCarta carta[], TipoLista **mao, char modo_jogo);
int GanhadorRodada(int numero_jogadores, TipoCarta carta[], TipoCarta *cartaganhadora);

#endif