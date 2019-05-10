#include"Biblioteca_Funcoes_IR.h"

int ExisteCarta(TipoCarta carta, TipoLista* baralho){
    TipoCelula* aux=baralho->Primeiro;
    int cont=0;
    while(aux!=NULL){
        if(aux->Item.naipe==carta.naipe && aux->Item.valor==carta.valor) cont++;
        aux=aux->Prox;
    }
    return cont;
}

void InsereCarta(TipoCarta carta, TipoLista *baralho){
    TipoCelula* novaCelula=InicializaCelula();
    if(ChecaBaralhoVazio(baralho)){
        baralho->Primeiro=novaCelula;
        baralho->Primeiro->Item=carta;
        baralho->Primeiro->Prox=NULL;
        baralho->Ultimo=baralho->Primeiro;
    }
    else if(ExisteCarta(carta,baralho)==0){
        baralho->Ultimo->Prox=novaCelula;
        baralho->Ultimo=baralho->Ultimo->Prox;
        baralho->Ultimo->Item=carta;
        baralho->Ultimo->Prox=NULL;
    }
    else printf("\nTENTAVIVA DE INSERIR CARTA JA EXISTENTE. NENHUMA CARTA SERA INSERIDA.\n");
}

void RetiraPrimeiraCarta(TipoLista *baralho){
    TipoCelula* p=baralho->Primeiro;
    if(ChecaBaralhoVazio(baralho)){
        printf("\nLista vazia\n");
        return;
    }
    else{
        baralho->Primeiro=p->Prox;
        free(p);
        return;
    }
}

void RetiraCarta(TipoCarta carta, TipoLista *baralho){
    TipoCelula* ant=NULL;
    TipoCelula* p=baralho->Primeiro;
    if(ChecaBaralhoVazio(baralho)){
        printf("\nBaralho vazia\n");
        return;
    }
    while(p!=NULL && (p->Item.naipe!=carta.naipe || p->Item.valor!=carta.valor)){
        ant=p;
        p=p->Prox;
    }
    if(p==NULL){
        printf("\nCarta nao existe. Nenhum elemento sera retirado.\n");
        free(p);
        return;
    }
    if(p==baralho->Primeiro){
        baralho->Primeiro=p->Prox;
        free(p);
        free(ant);
        printf("\n");
        return;
    }
    else if(p==baralho->Ultimo){
        baralho->Ultimo=ant;
        ant->Prox=NULL;
        free(p);
        printf("\n");
        return;
    }
    else{
        ant->Prox=p->Prox;
        free(p);
        printf("\n");
        return;
    }
}

TipoCarta PegaPrimeiraCarta(TipoLista *baralho){
    TipoCelula* p=baralho->Primeiro;
    if(ChecaBaralhoVazio(baralho)) printf("\nLista vazia\n");
    else return p->Item;
}