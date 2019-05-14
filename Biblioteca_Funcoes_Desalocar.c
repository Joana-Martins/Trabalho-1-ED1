#include "Biblioteca_Funcoes_Desalocar.h"

/* DESALOCA UMA DADA CELULA */
void DesalocaCelula(TipoCelula *celula){
  free(celula);
}

/* DESALOCA UMA DADA LISTA */
void DesalocaLista(TipoLista *Lista){
  TipoCelula *p=Lista->Primeiro;
  TipoCelula *aux=p;
  while(p!=NULL){
    aux=p;
    p=p->Prox;
    free(aux);
  }  
  free(Lista);
}

/* DESALOCA UMA DADA LISTA DE LISTAS */
void DesalocaListaDeLista(TipoLista **Lista, int numero_jogadores){
  for(int i=0;i<numero_jogadores;i++){
    DesalocaLista(Lista[i]);
  }
  free(Lista);
}