#include"Biblioteca_Funcoes_Jogo.h"
/* PREPARA O BARALHO, EMBARALHANDO-O, CORTANDO-O E REPOSICIONANDO O TRUNFO */
TipoLista* PreparaBaralho(TipoCarta* trunfo){
    TipoLista* baralho=InicializaBaralho();
    ChecaBaralhoVazio(baralho);
    CriaBaralhoInicial(baralho);
    EmbaralhaBaralho(baralho);
    *trunfo=CortaTrunfo(baralho);
    ReposicionaTrunfo(*trunfo,baralho);
    return baralho;
}
/* PREPARA AS MAOS DO JOGADOR E DO(S) COMPUTADOR(ES) */
TipoLista** PreparaMaos(TipoLista* baralho, int numero_jogadores){
    TipoLista** mao=(TipoLista**)malloc(numero_jogadores*sizeof(TipoLista*));
    for(int i=0;i<numero_jogadores;i++){
        mao[i]=FormarMao(baralho);
    }
    return mao;
}

/* PREPARA O MONTE DE PONTOS DO JOGADOR E DO(S) COMPUTADOR(ES) */
TipoLista** PreparaMontePontos(TipoLista* baralho, int numero_jogadores){
    TipoLista** pontos=(TipoLista**)malloc(numero_jogadores*sizeof(TipoLista*));
    for(int i=0;i<numero_jogadores;i++){
        pontos[i]=InicializaBaralho();
        ChecaBaralhoVazio(pontos[i]);
    }
    return pontos;
}

/* CHECA SE A CARTA QUE O JOGADOR PRETENDE JOGAR EXISTE EM SUA MAO */
TipoCarta ChecaExisteCarta(TipoCarta carta[], TipoLista** mao, int numero_jogadores){
    do{
        printf("\nDIGITE O VALOR E O NAIPE DA CARTA QUE DESEJA JOGAR: ");
        scanf(" %c %c",&carta[JOGADOR].valor,&carta[JOGADOR].naipe);
        if(ExisteCarta(carta[JOGADOR],mao[JOGADOR])==0) printf("CARTA INVALIDA. TENTE NOVAMENTE.");
    }while(ExisteCarta(carta[JOGADOR],mao[JOGADOR])==0);
    return carta[JOGADOR];
}

/* RETORNA A MELHOR CARTA DA MAO - A QUE POSSUI MAIOR PONTOS */
TipoCarta* MelhordaMao(TipoLista* mao){
    TipoCelula* aux=mao->Primeiro;
    TipoCarta* melhorCarta=&aux->Item;
    while(aux!=NULL){
        if(PontosCarta(&aux->Item)>PontosCarta(melhorCarta)) melhorCarta=&aux->Item;
        aux=aux->Prox;
    }
    return melhorCarta;
}

/* RETORNA A PIOR CARTA DA MAO - A QUE POSSUI MENOR PONTOS */
TipoCarta* PiordaMao(TipoLista* mao){
    TipoCelula* aux=mao->Primeiro;
    TipoCarta* piorCarta=&aux->Item;
    while(aux!=NULL){
        if(PontosCarta(&aux->Item)<PontosCarta(piorCarta)) piorCarta=&aux->Item;
        aux=aux->Prox;
    }
    return piorCarta;
}

/* JOGADA DO COMPUTADOR - DIVIDIDA PARA MODO FACIL E DIFICIL */
void JogaComputador(TipoCarta carta[], TipoCarta* trunfo, TipoLista** mao, int adversario, char modo_jogo){
    if(modo_jogo=='F'){
        carta[adversario]=PegaPrimeiraCarta(mao[adversario]);
        RetiraPrimeiraCarta(mao[adversario]);
    }else{
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
}

/* RETORNA A QUANTIDADE DE PONTOS DE UMA DADA CARTA */
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

/* RETORNA A MELHOR ENTRE DUAS CARTAS, SEM CONSIDERAR O TRUNDO, ANALISANDO NAIPE E VALOR */
TipoCarta* MelhorCarta(TipoCarta* carta1, TipoCarta* carta2){
    if(MesmoNaipe(carta1,carta2)){
        if(PontosCarta(carta1)>PontosCarta(carta2)) return carta1;
        else return carta2;
    }
    else return carta1;
}

/* RETORNA A MELHOR ENTRE DUAS CARTAS, CONSIDERANDO O TRUNDO, ANALISANDO NAIPE E VALOR */
TipoCarta* CartaGanhadoraAux(TipoCarta* carta1, TipoCarta* carta2, TipoCarta* trunfo){
    if(MesmoNaipe(carta1,trunfo) && !MesmoNaipe(carta2,trunfo)) return carta1;
    else if(!MesmoNaipe(carta1,trunfo) && MesmoNaipe(carta2,trunfo)) return carta2;
    else return MelhorCarta(carta1,carta2);
}

/* REFAZ A ORDEM DOS JOGADORES COM BASE NO GANHADOR DA RODADA ANTERIOR */
int* RefazOrdemJogadores(int ganhou, int numero_jogadores){
  int* posicoes = malloc(numero_jogadores*sizeof(int));
  for(int i=0;i<numero_jogadores;i++){
     posicoes[i] = (ganhou+i)%numero_jogadores;
    }
  return posicoes;
}

/* RETORNA A MELHOR ENTE AS CARTAS DO JOGADOR E DO(S) COMPUTADOR(ES) */
TipoCarta* CartaGanhadora(TipoCarta carta[], TipoCarta* trunfo, int numero_jogadores, int ganhou){
    TipoCarta* cartaGanhadora;
    int i = 0, *p;
    p=RefazOrdemJogadores(ganhou,numero_jogadores);
    switch(numero_jogadores){
        case 2:
            if(ganhou == 0) cartaGanhadora=CartaGanhadoraAux(&carta[JOGADOR],&carta[ADVERSARIO1],trunfo);
            else cartaGanhadora=CartaGanhadoraAux(&carta[ADVERSARIO1],&carta[JOGADOR],trunfo);
        break;
        case 4:{
	        TipoCarta *cartaGanhadoraAux1=CartaGanhadoraAux(&carta[p[i]],&carta[p[i+1]],trunfo);
            TipoCarta *cartaGanhadoraAux2=CartaGanhadoraAux(&carta[p[i+2]],&carta[p[i+3]],trunfo);
            cartaGanhadora=CartaGanhadoraAux(cartaGanhadoraAux1,cartaGanhadoraAux2,trunfo);
    	}
	    break;
    }
    free(p);
    return cartaGanhadora;
}

/* IMPRIME AS CARTAS JOGADAS EM UMA CERTA RODADA */
void ImprimeCartasJogadas(TipoCarta carta[], int numero_jogadores, int ganhou){
    int* p=RefazOrdemJogadores(ganhou,numero_jogadores);
    system("clear");
    printf("\nRODADA:\n");
    for(int i=0;i<numero_jogadores;i++){
        switch(p[i]){
            case 0: printf("Jogador: ");
            break;
            case 1: printf("Computador 1: ");
            break;
            case 2: printf("Computador 2: ");
            break;
            case 3: printf("Computador 3: ");
            break;
        }
        MostraCarta(&carta[p[i]]);
    }
    free(p);
}

/* INSERE AS CARTAS DA RODADA NO MONTE DE PONTOS DO GANHADOR DA MESMA */
void InsereMontePontos(TipoCarta carta[],TipoLista** pontos, TipoCarta *trunfo, int numero_jogadores, int ganhou){
    for(int j=0;j<numero_jogadores;j++){
        if(MesmaCarta(CartaGanhadora(carta,trunfo,numero_jogadores, ganhou),&carta[j])){
            for(int i=0;i<numero_jogadores;i++) InsereCarta(carta[i],pontos[j]);
        }
    }
}

/* REFAZ AS MAOS DO JOGADOR E DO(S) COMPUTADOR(ES), RETIRANDO A PRIMEIRA CARTA DO BARALHO E INSERINDO-A NAS DEVIDAS MAOS */
void RefazMaoBaralho(TipoLista** mao, TipoLista* baralho, int numero_jogadores){
    if(!ChecaBaralhoVazio(baralho)){
        for(int i=0;i<numero_jogadores;i++){
            InsereCarta(PegaPrimeiraCarta(baralho),mao[i]);
            RetiraPrimeiraCarta(baralho);
        }
    }
}

/* RETORNA O TOTAL DE PONTOS DE UM DADO MONTE DE PONTOS */
int TotalPontos(TipoLista* monte){
    TipoCelula* aux=monte->Primeiro;
    int total=0;
    while(aux!=NULL){
        total=total+PontosCarta(&aux->Item);
        aux=aux->Prox;
    }
    return total;
}

/* IMPRIME O TOTAL DE PONTOS DO JOGADOR E DO(S) COMPUTADOR(ES) */
void ImprimePontos(TipoLista** pontos,int numero_jogadores){
    printf("\nJogador: %d",TotalPontos(pontos[JOGADOR]));
    for(int i=1;i<numero_jogadores;i++) printf("\nComputador %d: %d",i,TotalPontos(pontos[i]));
}

/* RETORNA O MONTE COM MAIOR NUMERO DE PONTOS */
TipoLista* MaiorPonto(TipoLista** pontos,int numero_jogadores){
    TipoLista* maior=pontos[JOGADOR];
    for(int i=0;i<numero_jogadores;i++){
        if(TotalPontos(pontos[i])>TotalPontos(maior)) maior=pontos[i];
    }
    return maior;
}

/* EXIBE O GANHADOR, BASEANDO-SE NO MONTE COM MAIOR NUMERO DE PONTOS */
void Ganhador(TipoLista** pontos,int numero_jogadores){
    printf("\n\nGANHADOR: ");
    if(MaiorPonto(pontos,numero_jogadores)==pontos[JOGADOR]) printf("Jogador\n");
    else if(MaiorPonto(pontos,numero_jogadores)==pontos[ADVERSARIO1]) printf("Computador 1\n");
    else if(MaiorPonto(pontos,numero_jogadores)==pontos[ADVERSARIO2]) printf("Computador 2\n");
    else if(MaiorPonto(pontos,numero_jogadores)==pontos[ADVERSARIO3]) printf("Computador 3\n");
}

/* FAZ A ORDEM DE JOGADA, COM BASE NO GANHADOR DA RODADA ANTERIOR  */
void FazOrdemJogadores(int ganhou, int numero_jogadores, TipoCarta* trunfo, TipoCarta carta[], TipoLista **mao, char modo_jogo){
    if(numero_jogadores == 2){
        switch(ganhou){
            case 0:
                RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
                JogaComputador(carta,trunfo,mao,ADVERSARIO1,modo_jogo);
            break;
            case 1:
                JogaComputador(carta,trunfo,mao,ADVERSARIO1,modo_jogo);
                RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
            break;
        }
    }
    else{
        switch(ganhou){
            case 0:
                RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
                JogaComputador(carta,trunfo,mao,ADVERSARIO1,modo_jogo);
                JogaComputador(carta,trunfo,mao,ADVERSARIO2,modo_jogo);
                JogaComputador(carta,trunfo,mao,ADVERSARIO3,modo_jogo);
            break;
            case 1:
                JogaComputador(carta,trunfo,mao,ADVERSARIO1,modo_jogo);
                JogaComputador(carta,trunfo,mao,ADVERSARIO2,modo_jogo);
                JogaComputador(carta,trunfo,mao,ADVERSARIO3,modo_jogo);
                RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
            break;
            case 2:
                JogaComputador(carta,trunfo,mao,ADVERSARIO2,modo_jogo);
                JogaComputador(carta,trunfo,mao,ADVERSARIO3,modo_jogo);
                RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
                JogaComputador(carta,trunfo,mao,ADVERSARIO1,modo_jogo);
            break;
            case 3:
                JogaComputador(carta,trunfo,mao,ADVERSARIO3,modo_jogo);
                RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
                JogaComputador(carta,trunfo,mao,ADVERSARIO1,modo_jogo);
                JogaComputador(carta,trunfo,mao,ADVERSARIO2,modo_jogo);
            break;
        }
    }
}

/* RETORNA O NUMERO DO GANHADOR DE UMA RODADA */
int GanhadorRodada(int numero_jogadores, TipoCarta carta[], TipoCarta *cartaganhadora){
    int ganhou;
    if(numero_jogadores == 2){
        if(MesmaCarta(cartaganhadora,&carta[JOGADOR])) ganhou = 0;
        else ganhou = 1;
    }
    else{
        if(MesmaCarta(cartaganhadora,&carta[JOGADOR])) ganhou = 0;
        else if(MesmaCarta(cartaganhadora,&carta[ADVERSARIO1])) ganhou = 1;
        else if(MesmaCarta(cartaganhadora,&carta[ADVERSARIO2])) ganhou = 2;
        else ganhou = 3;
    }
    return ganhou;
}
