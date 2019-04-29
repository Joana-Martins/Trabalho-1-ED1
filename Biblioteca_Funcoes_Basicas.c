#include"Biblioteca_Funcoes_Basicas.h"

TipoCarta* InicializaCarta(){
    TipoCarta* carta=(TipoCarta*)malloc(sizeof(TipoCarta));
    return carta;
}

TipoCelula* InicializaCelula(){
    TipoCelula* celula=(TipoCelula*)malloc(sizeof(TipoCelula));
    celula->Prox=(TipoApontador)malloc(sizeof(TipoApontador));
    return celula;
}

TipoLista* InicializaBaralho(){
    TipoLista* baralho=(TipoLista*)malloc(sizeof(TipoLista));
    baralho->Primeiro=InicializaCelula();
    baralho->Ultimo=InicializaCelula();
    return baralho;
}

TipoLista* FazBaralhoVazio(){
    TipoLista* baralho;
    baralho->Primeiro=NULL;
    baralho->Ultimo=NULL;
}

int ChecaBaralhoVazio(TipoLista* baralho){
    return (baralho->Primeiro==NULL);
}

int Quantidade(TipoLista* baralho){
    TipoCelula* aux=baralho->Primeiro;
    int cont=0;
    while(aux!=NULL){
        cont++;
        aux=aux->Prox;
    }
    return cont;
}