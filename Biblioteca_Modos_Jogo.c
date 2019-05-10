#include"Biblioteca_Modos_Jogo.h"


char modo_d(int d){
  char c;
  if (d == 0 || d == 2){
    c = 'F';
  }else if ( d == 1 || d == 3){
    c = 'D';
  }
  return c;
}

int modo_j(int d){
  int i ;
  if (d == 0 || d == 1){
    i = 2;
  }else if ( d == 2 || d == 3){
    i = 4;
  }
  return i;
}

void JogoBisca(int d){
    int numero_jogadores = modo_j(d);
    char modo_jogo = modo_d(d);
    TipoCarta trunfo;
    TipoLista* baralho=PreparaBaralho(&trunfo);
    TipoLista** mao=PreparaMaos(baralho,numero_jogadores);
    TipoLista** pontos=PreparaMontePontos(baralho,numero_jogadores);
    TipoCarta carta[numero_jogadores];
    printf("SUA MAO INICIAL:\n");
    MostraCartasBaralho(mao[JOGADOR]);

    while(!ChecaBaralhoVazio(mao[JOGADOR])){
        printf("\nTRUNFO: ");
        MostraCarta(&trunfo);
        carta[JOGADOR]=ChecaExisteCarta(carta,mao,numero_jogadores);
        RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
        if(modo_jogo=='F') JogaComputadorFacil(carta,mao,numero_jogadores);
        else JogaComputadorDificil(carta,&trunfo,mao,numero_jogadores);
        ImprimeCartasJogadas(carta,numero_jogadores);
        printf("\nCARTA GANHADORA: ");
        MostraCarta(CartaGanhadora(carta,&trunfo,numero_jogadores));
        InsereMontePontos(carta,pontos,&trunfo,numero_jogadores);
        RefazMaoBaralho(mao,baralho,numero_jogadores);
        if(!ChecaBaralhoVazio(mao[JOGADOR])){
            printf("\nSUA NOVA MAO:\n");
            MostraCartasBaralho(mao[JOGADOR]);
        }
    }
    ImprimePontos(pontos,numero_jogadores);
    Ganhador(pontos,numero_jogadores);
}
