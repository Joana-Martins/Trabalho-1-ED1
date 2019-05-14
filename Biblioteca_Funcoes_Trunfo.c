#include"Biblioteca_Funcoes_Trunfo.h"

/* RETORNA UMA CARTA ALEATORIA PARA SER O TRUNFO */
TipoCarta CortaTrunfo(TipoLista* baralho){
    TipoCarta trunfo;
    if(ChecaBaralhoVazio(baralho)) printf("\nBaralho vazio!\n");
    else{
        srand(time(NULL));
        trunfo=baralho->Primeiro->Item;
        TipoCelula* aux=baralho->Primeiro;
        for(int i=2;aux!=NULL;i++){
            if(rand()%i==0)
		        trunfo=aux->Item;
            aux=aux->Prox;
        }
        DesalocaCelula(aux);
    }
    return trunfo;
}

/* REPOSICIONA O TRUNFO NO BARALHO, RETIRANDO-O DO MESMO E INSERINDO-O NO FINAL */
void ReposicionaTrunfo(TipoCarta trunfo, TipoLista* baralho){
    RetiraCarta(trunfo,baralho);
    InsereCarta(trunfo,baralho);
}
