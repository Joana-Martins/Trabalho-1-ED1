#include "liberdade.h"

void liberdade_baralho(TipoLista *Lista){
  TipoCelula *p = Lista -> Primeiro;
  TipoCelula *aux = p;
  while( p != NULL){
    aux = p;
    p = p -> Prox;
    free(aux);
  }  
  free(Lista);
}

void liberdade_Lista_de_Lista(TipoLista **Lista, int tam){
  int i;
  for(i = 0; i < tam; i++){
    liberdade_baralho(Lista[i]);
  }
  free(Lista);
}

void liberdade_celula(TipoCelula *x){
  free(x);
}
