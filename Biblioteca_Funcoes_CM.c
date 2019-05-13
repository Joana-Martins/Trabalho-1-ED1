#include"Biblioteca_Funcoes_CM.h"

/* CRIA UMA LISTA ENCADEADA COMO BARALHO DE UM JOGO DE BISCA */
void CriaBaralhoInicial(TipoLista* baralho){
    char naipes[4]={'P','O','E','C'};
    char valores[10]={'2','3','4','5','6','7','J','Q','K','A'};

    TipoCarta *carta=(TipoCarta*)malloc(40*sizeof(TipoCarta));
    int i=0;
    for(int v=0; v<10; v++){
        for(int n=0; n<4; n++){
            carta[i].naipe=naipes[n];
            carta[i].valor=valores[v];
            InsereCarta(carta[i],baralho);
            i++;
        }
    }
    free(carta);
}

/* FUNCAO AUXILIAR DE EMBARALHAR UM BARALHO */
void EmbaralhaBaralhoAuxiliar(TipoLista* baralho){
    TipoLista *baralhoAux1=InicializaBaralho();
    ChecaBaralhoVazio(baralhoAux1);
    TipoLista *baralhoAux2=InicializaBaralho();
    ChecaBaralhoVazio(baralhoAux2);
    TipoCarta carta;
    int tamanhoBaralho=Quantidade(baralho);
    int metadeBaralho=tamanhoBaralho/2;
    for(int i=0;i<metadeBaralho;i++){
        carta=PegaPrimeiraCarta(baralho);
        InsereCarta(carta,baralhoAux1);
        RetiraPrimeiraCarta(baralho);
    }
    for(int i=metadeBaralho;i<tamanhoBaralho;i++){
        carta=PegaPrimeiraCarta(baralho);
        InsereCarta(carta,baralhoAux2);
        RetiraPrimeiraCarta(baralho);
    }
    while(!ChecaBaralhoVazio(baralhoAux1) && !ChecaBaralhoVazio(baralhoAux2)){
        carta=PegaPrimeiraCarta(baralhoAux1);
        InsereCarta(carta,baralho);
        RetiraPrimeiraCarta(baralhoAux1);
        carta=PegaPrimeiraCarta(baralhoAux2);
        InsereCarta(carta,baralho);
        RetiraPrimeiraCarta(baralhoAux2);
    }
    liberdade_baralho(baralhoAux1);
    liberdade_baralho(baralhoAux2);
}

/* EMBARALHA UM BARALHO, CHAMANDO A FUNCAO DE EMBARALHAR AUXILIAR QUATRO VEZES */
void EmbaralhaBaralho(TipoLista *baralho){
    EmbaralhaBaralhoAuxiliar(baralho);
    EmbaralhaBaralhoAuxiliar(baralho);
    EmbaralhaBaralhoAuxiliar(baralho);
    EmbaralhaBaralhoAuxiliar(baralho);
}

/* RETORNA A MAO DE UM JOGADOR */
TipoLista* FormarMao(TipoLista* baralho){
    TipoLista* mao;
    mao=InicializaBaralho();
    ChecaBaralhoVazio(mao);
    for(int i=0;i<3;i++){
        InsereCarta(PegaPrimeiraCarta(baralho),mao);
        RetiraPrimeiraCarta(baralho);
    }
    return mao;
}
