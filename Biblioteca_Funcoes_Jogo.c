#include"Biblioteca_Funcoes_Jogo.h"
/* Prepara o baralho, embaralhando-o, cortando-o e reposicionando o trunfo */
TipoLista* PreparaBaralho(TipoCarta* trunfo){
    TipoLista* baralho=InicializaBaralho();
    ChecaBaralhoVazio(baralho);
    CriaBaralhoInicial(baralho);
    EmbaralhaBaralho(baralho);
    *trunfo=CortaTrunfo(baralho);
    ReposicionaTrunfo(*trunfo,baralho);
    return baralho;
}

/* Prepara as maos do jogador e do(s) computador(es) */
TipoLista** PreparaMaos(TipoLista* baralho, int numero_jogadores){
    TipoLista** mao=(TipoLista**)malloc(numero_jogadores*sizeof(TipoLista*));
    for(int i=0;i<numero_jogadores;i++){
        mao[i]=FormarMao(baralho);
    }
    return mao;
}

/* Prepara o monte de pontos do jogador e do(s) computador(es) */
TipoLista** PreparaMontePontos(TipoLista* baralho, int numero_jogadores){
    TipoLista** pontos=(TipoLista**)malloc(numero_jogadores*sizeof(TipoLista*));
    for(int i=0;i<numero_jogadores;i++){
        pontos[i]=InicializaBaralho();
        ChecaBaralhoVazio(pontos[i]);
    }
    return pontos;
}

/* Checa se a carta que o jogador pretende jogar existe em sua mao */
TipoCarta ChecaExisteCarta(TipoCarta carta[], TipoLista** mao, int numero_jogadores){
    do{
        printf("\nDIGITE O VALOR E O NAIPE DA CARTA QUE DESEJA JOGAR: ");
        scanf(" %c %c",&carta[JOGADOR].valor,&carta[JOGADOR].naipe);
        if(ExisteCarta(carta[JOGADOR],mao[JOGADOR])==0) printf("CARTA INVALIDA. TENTE NOVAMENTE.");
    }while(ExisteCarta(carta[JOGADOR],mao[JOGADOR])==0);
    return carta[JOGADOR];
}

/* Estrategia do computador no  modo facil - jogar sempre a primeira carta da mao */
void JogaComputadorFacil(TipoCarta carta[], TipoLista** mao, int adversario){
        carta[adversario]=PegaPrimeiraCarta(mao[adversario]);
        RetiraPrimeiraCarta(mao[adversario]);
}

/* Retorna a melhor carta da mao */
TipoCarta* MelhordaMao(TipoLista* mao){
    TipoCelula* aux=mao->Primeiro;
    TipoCarta* melhorCarta=&aux->Item;
    while(aux!=NULL){
        if(PontosCarta(&aux->Item)>PontosCarta(melhorCarta)) melhorCarta=&aux->Item;
        aux=aux->Prox;
    }
    return melhorCarta;
}

/* Retorna a pior carta da mao */
TipoCarta* PiordaMao(TipoLista* mao){
    TipoCelula* aux=mao->Primeiro;
    TipoCarta* piorCarta=&aux->Item;
    while(aux!=NULL){
        if(PontosCarta(&aux->Item)<PontosCarta(piorCarta)) piorCarta=&aux->Item;
        aux=aux->Prox;
    }
    return piorCarta;
}

/* Estrategia do computador no  modo facil - jogar sempre a primeira carta da mao */
void JogaComputadorDificil(TipoCarta carta[], TipoCarta* trunfo, TipoLista** mao, int adversario){
        TipoCarta* cartasMao=(TipoCarta*)malloc(3*sizeof(TipoCarta));
        TipoCelula* aux=mao[adversario]->Primeiro;
        int j=0;
        while(aux!=0){
            cartasMao[j]=aux->Item;
            aux=aux->Prox;
            j++;
        }
        if(MesmoNaipe(&carta[JOGADOR],trunfo)) carta[adversario]=*PiordaMao(mao[adversario]);
        else carta[adversario]=*MelhordaMao(mao[adversario]);
        RetiraCarta(carta[adversario],mao[adversario]);
        free(cartasMao);

}

/* Retorna a quantidade de pontos de uma certa carta */
int PontosCarta(TipoCarta* carta){
    switch(carta->valor){
        case '7': return 10;
        case 'J': return 2;
        case 'Q': return 3;
        case 'K': return 4;
        case 'A': return 11;
        default: return 0;
    }
}


/* Retorna a melhor entre duas cartas, sem considerar o trunfo, analisando naipe e valor */
TipoCarta* MaiorValor(TipoCarta* carta1, TipoCarta* carta2){
    if(MesmoNaipe(carta1,carta2)){
        if(PontosCarta(carta1)>PontosCarta(carta2)) return carta1;
        else return carta2;
    }
    else return carta1;
}

/* Funcao auxiliar que retorna a melhor entre duas cartas, considerando o trunfo, analisando naipe e valro */
TipoCarta* CartaGanhadoraAux(TipoCarta* carta1, TipoCarta* carta2, TipoCarta* trunfo){
    if(MesmoNaipe(carta1,trunfo) && !MesmoNaipe(carta2,trunfo)) return carta1;
    else if(!MesmoNaipe(carta1,trunfo) && MesmoNaipe(carta2,trunfo)) return carta2;
    else return MaiorValor(carta1,carta2);
}

int * posicoes(int ganhou, int numero_jogadores){
  int * posicoes = malloc(sizeof(int) * numero_jogadores);
  for(int j = 0; j < numero_jogadores; j++){
     posicoes[j] = (ganhou + j) % numero_jogadores;
    }
  return posicoes;
}

/* Retorna a melhor entre as cartas do jogador e do(s) computador(es) */
TipoCarta* CartaGanhadora(TipoCarta carta[],TipoCarta* trunfo, int numero_jogadores, int ganhou){
    TipoCarta* cartaGanhadora;
    int i = 0, *p;
    p = posicoes(ganhou, numero_jogadores);
    switch(numero_jogadores){
        case 2:
          if(ganhou == 0){
              cartaGanhadora=CartaGanhadoraAux(&carta[JOGADOR],&carta[ADVERSARIO1],trunfo);
            }else{
              cartaGanhadora=CartaGanhadoraAux(&carta[ADVERSARIO1],&carta[JOGADOR],trunfo);
            }
        break;
        case 4:{
	          TipoCarta *cartaGanhadoraAux1=CartaGanhadoraAux(&carta[p[i]],&carta[p[i+1]],trunfo);
            TipoCarta *cartaGanhadoraAux2=CartaGanhadoraAux(&carta[i+2],&carta[i+3],trunfo);
            cartaGanhadora=CartaGanhadoraAux(cartaGanhadoraAux1,cartaGanhadoraAux2,trunfo);
    	}
	break;
    }
    free(p);
    return cartaGanhadora;
}

/* Imprime as cartas jogadas de certa rodada */
void ImprimeCartasJogadas(TipoCarta carta[], int numero_jogadores){
    printf("\nRODADA:\n");
    for(int i=0;i<numero_jogadores;i++){
        if(i==0) printf("Jogador: ");
        else printf("Computador %d: ",i);
        MostraCarta(&carta[i]);
    }
}

/* Insere as cartas da rodada no monte de pontos do ganhador da mesma */
void InsereMontePontos(TipoCarta carta[],TipoLista** pontos, TipoCarta *trunfo, int numero_jogadores, int ganhou){
    for(int j=0;j<numero_jogadores;j++){
        if(MesmaCarta(CartaGanhadora(carta,trunfo,numero_jogadores, ganhou),&carta[j])){
            for(int i=0;i<numero_jogadores;i++) InsereCarta(carta[i],pontos[j]);
        }
    }
}

/* Refaz as maos do jogador e do(s) computador(es), retirando a primeira carta do baralho e inserindo-a nas devidas maos */
void RefazMaoBaralho(TipoLista** mao, TipoLista* baralho, int numero_jogadores){
    if(!ChecaBaralhoVazio(baralho)){
        for(int i=0;i<numero_jogadores;i++){
            InsereCarta(PegaPrimeiraCarta(baralho),mao[i]);
            RetiraPrimeiraCarta(baralho);
        }
    }
}

/* Retorna o total de pontos de um certo monte de pontos */
int TotalPontos(TipoLista* monte){
    TipoCelula* aux=monte->Primeiro;
    int total=0;
    while(aux!=NULL){
        total=total+PontosCarta(&aux->Item);
        aux=aux->Prox;
    }
    return total;
}

/* Imprime o total de pontos do jogador e do(s) computador(es) */
void ImprimePontos(TipoLista** pontos,int numero_jogadores){
    printf("\nPONTUACAO FINAL:");
    printf("\nJogador: %d",TotalPontos(pontos[JOGADOR]));
    for(int i=1;i<numero_jogadores;i++) printf("\nComputador %d: %d",i,TotalPontos(pontos[i]));
}

/* Retorna o monte com maior numero de pontos */
TipoLista* MaiorPonto(TipoLista** pontos,int numero_jogadores){
    TipoLista* maior=pontos[JOGADOR];
    for(int i=0;i<numero_jogadores;i++){
        if(TotalPontos(pontos[i])>TotalPontos(maior)) maior=pontos[i];
    }
    return maior;
}

/* Exibe o ganhador, baseado no monte com maior numero de pontos */
void Ganhador(TipoLista** pontos,int numero_jogadores){
    printf("\n\nGANHADOR: ");
    if(MaiorPonto(pontos,numero_jogadores)==pontos[JOGADOR]) printf("Jogador\n");
    else if(MaiorPonto(pontos,numero_jogadores)==pontos[ADVERSARIO1]) printf("Computador 1\n");
    else if(MaiorPonto(pontos,numero_jogadores)==pontos[ADVERSARIO2]) printf("Computador 2\n");
    else if(MaiorPonto(pontos,numero_jogadores)==pontos[ADVERSARIO3]) printf("Computador 3\n");
}


/* Escolhe a ordem de jogadores com base em ganhou a rodada anterior - MODO FACIL */
void primeiro_jogar_facil(int ganhou, int numero_jogadores, TipoCarta carta[], TipoLista **mao){
if(numero_jogadores == 2){
switch(ganhou){
case 0:
    RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
    JogaComputadorFacil(carta,mao,ADVERSARIO1);
    break;

case 1:
    JogaComputadorFacil(carta,mao,ADVERSARIO1);
    RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
    break;
  }

}else{
switch (ganhou) {
case 0:
      RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
      JogaComputadorFacil(carta,mao,ADVERSARIO1);
      JogaComputadorFacil(carta,mao,ADVERSARIO2);
      JogaComputadorFacil(carta,mao,ADVERSARIO3);
      break;
case 1:
    JogaComputadorFacil(carta,mao,ADVERSARIO1);
    JogaComputadorFacil(carta,mao,ADVERSARIO2);
    JogaComputadorFacil(carta,mao,ADVERSARIO3);;
    RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
    break;
case 2:
    JogaComputadorFacil(carta,mao,ADVERSARIO2);
    JogaComputadorFacil(carta,mao,ADVERSARIO3);
    RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
    JogaComputadorFacil(carta,mao,ADVERSARIO1);
    break;
case 3:
      JogaComputadorFacil(carta,mao,ADVERSARIO3);
      RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
      JogaComputadorFacil(carta,mao,ADVERSARIO1);
      JogaComputadorFacil(carta,mao,ADVERSARIO2);
    break;
  }
}
}

/* Escolhe a ordem de jogadores com base em ganhou a rodada anterior - MODO DIFICIL */
void primeiro_jogar_dificil(int ganhou, int numero_jogadores, TipoCarta carta[], TipoLista **mao, TipoCarta *trunfo){
  if(numero_jogadores == 2){
  switch(ganhou){
  case 0:
      RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
      JogaComputadorDificil(carta,trunfo, mao,ADVERSARIO1);
      break;

  case 1:
      JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO1);
      RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
      break;
    }
  }else{
  switch (ganhou) {
  case 0:
        RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
        JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO1);
        JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO2);
        JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO3);
        break;
  case 1:
      JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO1);
      JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO2);
      JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO3);
      RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
      break;
  case 2:
      JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO2);
      JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO3);
      RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
      JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO1);
      break;
  case 3:
        JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO3);
        RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
        JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO1);
        JogaComputadorDificil(carta,trunfo,mao,ADVERSARIO2);
      break;
    }
  }
}

int ganhador_rodada(int numero_jogadores, TipoCarta carta[], TipoCarta *cartaganhadora){
  int ganhou;
  if (numero_jogadores == 2){
    if(MesmaCarta(cartaganhadora,&carta[JOGADOR])){
      ganhou = 0;
    }else{
      ganhou = 1;
    }
  }else{
    if(MesmaCarta(cartaganhadora,&carta[JOGADOR])){
      ganhou = 0;
    }else if(MesmaCarta(cartaganhadora,&carta[ADVERSARIO1])){
      ganhou = 1;
    }else if(MesmaCarta(cartaganhadora,&carta[ADVERSARIO2])){
      ganhou = 2;
    }else{
      ganhou = 3;
    }
  }
  return ganhou;
}
