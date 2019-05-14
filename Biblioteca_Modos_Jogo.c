#include"Biblioteca_Modos_Jogo.h"

/* RETORNA O MODO DE JOGO ESCOLHIDO (FACIL/DIFICIL) */
char modo_d(int d){
  char c;
  if(d==0||d==2) c = 'F';
  else if(d==1||d==3) c = 'D';
  return c;
}

/* RETORNA O TOTAL DE JOGADORES ESCOLHIDOS (2/4) */
int modo_j(int d){
  int i;
  if(d==0||d==1) i = 2;
  else if( d ==2||d == 3) i = 4;
  return i;
}

/* FUNCAO DE JOGABILIDADE DO BISCA */
void JogoBisca(int d){
  clock_t t0, tf;
  double tempo_gasto;
  t0 = clock();
  int numero_jogadores = modo_j(d);
  char modo_jogo = modo_d(d);
  int ganhou = 0;
  char opcao;
  TipoCarta trunfo;
  TipoCarta *cartaganhadora;
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
    FazOrdemJogadores(ganhou,numero_jogadores,&trunfo,carta,mao,modo_jogo);
    cartaganhadora=CartaGanhadora(carta,&trunfo,numero_jogadores, ganhou);
    ImprimeCartasJogadas(carta,numero_jogadores,ganhou);
    ganhou=GanhadorRodada(numero_jogadores, carta, cartaganhadora);
    printf("\nCARTA GANHADORA: ");
    MostraCarta(CartaGanhadora(carta,&trunfo,numero_jogadores, ganhou));
    InsereMontePontos(carta,pontos,&trunfo,numero_jogadores, ganhou);
    RefazMaoBaralho(mao,baralho,numero_jogadores);
    do{
      printf("\n**********************MENU**********************\n");
      printf("\n1 - MOSTRAR CARTAS DO BARALHO");
      printf("\n2 - MOSTRAR QUANTIDADE DE CARTAS NA MAO");
      printf("\n3 - MOSTRAR PONTOS DOS JOGADORES");
      printf("\n\nDigite a opcao ou 'zero' para sair: ");
      scanf(" %c",&opcao);
      system("clear");

      switch(opcao){
        case '0':
        break;
        case '1':
          printf("\nIMPRIMINDO BARALHO\n");
          MostraCartasBaralho(baralho);
        break;
        case '2': printf("\nTOTAL DE CARTAS NA MAO: %d\n",Quantidade(mao[JOGADOR]));
        break;
        case '3':
          printf("\nPONTUACAO:");
          ImprimePontos(pontos,numero_jogadores);
          printf("\n");
        break;
        default: printf("OPCAO INVALIDA. TENTE NOVAMENTE.\n");
        break;
      }
    }while(opcao!='0');
    
    if(!ChecaBaralhoVazio(mao[JOGADOR])){
      printf("\nSUA NOVA MAO:\n");
      MostraCartasBaralho(mao[JOGADOR]);
      }
  }
  printf("\nPONTUACAO FINAL:");
  ImprimePontos(pontos,numero_jogadores);
  Ganhador(pontos,numero_jogadores);
  DesalocaLista(baralho);
  DesalocaListaDeLista(mao, numero_jogadores);
  DesalocaListaDeLista(pontos, numero_jogadores);
  tf = clock();
  tempo_gasto = ( (double) (tf - t0) ) / CLOCKS_PER_SEC;
  printf("\nTempo gasto: %lf s\n", tempo_gasto);
}