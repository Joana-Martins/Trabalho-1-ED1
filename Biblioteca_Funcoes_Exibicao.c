#include"Biblioteca_Funcoes_Exibicao.h"

void MostraCarta(TipoCarta* carta){
    _setmode(_fileno(stdout),_O_U16TEXT);
    switch(carta->naipe){
        case 'P':
            wprintf(L"%c\x2663\n",carta->valor);
            break;
        case 'E':
            wprintf(L"%c\x2660\n",carta->valor);
            break;
        case 'C':
            wprintf(L"%c\x2661\n",carta->valor);
            break;
        case 'O':
            wprintf(L"%c\x2662\n",carta->valor);
            break;
    }
    _setmode(_fileno(stdout), _O_TEXT);
}

void MostraCartasBaralho(TipoLista* lista){
    TipoCelula* aux=lista->Primeiro;
    while(aux!=NULL){
        MostraCarta(&aux->Item);
        aux=aux->Prox;
    }
}