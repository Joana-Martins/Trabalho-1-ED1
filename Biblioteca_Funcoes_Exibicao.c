#include"Biblioteca_Funcoes_Exibicao.h"

#if defined(_WIN32) || defined(__MSDOS__)
   #define SPADE   "\x06"
   #define CLUB    "\x05"
   #define HEART   "\x03"
   #define DIAMOND "\x04"
#else
   #define SPADE   "\xE2\x99\xA0"
   #define CLUB    "\xE2\x99\xA3"
   #define HEART   "\xE2\x99\xA5"
   #define DIAMOND "\xE2\x99\xA6"
#endif

void MostraCarta(TipoCarta* carta){
    switch(carta->naipe){
        case 'P':
            printf("%c%s\n",carta->valor,CLUB);
            break;
        case 'E':
            printf("%c%s\n",carta->valor,SPADE);
            break;
        case 'C':
            printf("%c%s\n",carta->valor,HEART);
            break;
        case 'O':
            printf("%c%s\n",carta->valor,DIAMOND);
            break;
    }
}

void MostraCartasBaralho(TipoLista* lista){
    TipoCelula* aux=lista->Primeiro;
    while(aux!=NULL){
        MostraCarta(&aux->Item);
        aux=aux->Prox;
    }
    liberdade_celula(aux);
}
