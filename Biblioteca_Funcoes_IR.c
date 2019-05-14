#include"Biblioteca_Funcoes_IR.h"

/* RETORNA A QUANTIDADE DE VEZES QUE UMA DADA CARTA APARECE EM UM DADO BARALHO */
int ExisteCarta(TipoCarta carta, TipoLista* baralho){
    TipoCelula* aux=baralho->Primeiro;
    int cont=0;
    while(aux!=NULL){
        if(aux->Item.naipe==carta.naipe && aux->Item.valor==carta.valor) cont++;
        aux=aux->Prox;
    }
    DesalocaCelula(aux);
    return cont;
}

/* INSERE NO FIM DE UM DADO BARALHO UMA DADA CARTA */
void InsereCarta(TipoCarta carta, TipoLista *baralho){
    if(ChecaBaralhoVazio(baralho)){
        baralho->Primeiro=(TipoApontador) malloc(sizeof(TipoCelula));
        baralho->Primeiro->Item=carta;
        baralho->Primeiro->Prox=NULL;
        baralho->Ultimo=baralho->Primeiro;
    }
    else if(ExisteCarta(carta,baralho)==0){
        baralho->Ultimo->Prox=(TipoApontador) malloc(sizeof(TipoCelula));
        baralho->Ultimo = baralho->Ultimo->Prox;
        baralho->Ultimo->Item=carta;
        baralho->Ultimo->Prox=NULL;
    }
    else printf("\nTENTAVIVA DE INSERIR CARTA JA EXISTENTE. NENHUMA CARTA SERA INSERIDA.\n");
}

/* RETIRA A PRIMEIRA CARTA DE UM DADO BARALHO */
void RetiraPrimeiraCarta(TipoLista *baralho){
    if(ChecaBaralhoVazio(baralho)){
        printf("\nLista vazia\n");
        return;
    }else{
	    TipoCelula* p=baralho->Primeiro;
        baralho->Primeiro=p->Prox;
        DesalocaCelula(p);
        return;
    }
}

/* RETIRA UMA DADA CARTA DE UM DADO BARALHO */
void RetiraCarta(TipoCarta carta, TipoLista *baralho){
    TipoCelula* ant=NULL;
    TipoCelula* p=baralho->Primeiro;
    if(ChecaBaralhoVazio(baralho)){
        printf("\nBaralho vazio\n");
        return;
    }
    while(p!=NULL && (p->Item.naipe!=carta.naipe || p->Item.valor!=carta.valor)){
        ant=p;
        p=p->Prox;
    }
    if(p==NULL){
        printf("\nCarta nao existe. Nenhum elemento sera retirado.\n");
	    DesalocaCelula(ant);
        DesalocaCelula(p);
        return;
    }
    if(p==baralho->Primeiro){
        baralho->Primeiro=p->Prox;
        DesalocaCelula(ant);
        DesalocaCelula(p);
        return;
    }
    else if(p==baralho->Ultimo){
        baralho->Ultimo=ant;
        ant->Prox=NULL;
        DesalocaCelula(p);
        return;
    }
    else{
        ant->Prox=p->Prox;
        DesalocaCelula(p);
        return;
    }
}

/* RETORNA A PRIMEIRA CARTA DE UM DADO BARALHO */
TipoCarta PegaPrimeiraCarta(TipoLista *baralho){
    TipoCelula* p;
    if(ChecaBaralhoVazio(baralho)) printf("\nLista vazia\n");
    else p=baralho->Primeiro;
    return p->Item;
}