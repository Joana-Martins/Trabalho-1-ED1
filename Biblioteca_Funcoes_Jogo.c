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
void JogaComputadorFacil(TipoCarta carta[], TipoLista** mao, int numero_jogadores){
    for(int i=ADVERSARIO1;i<numero_jogadores;i++){
        carta[i]=PegaPrimeiraCarta(mao[i]);
        RetiraPrimeiraCarta(mao[i]);
    }
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
void JogaComputadorDificil(TipoCarta carta[], TipoCarta* trunfo, TipoLista** mao, int numero_jogadores){
    for(int i=1;i<numero_jogadores;i++){
        TipoCarta* cartasMao=(TipoCarta*)malloc(3*sizeof(TipoCarta));
        TipoCelula* aux=mao[i]->Primeiro;
        int j=0;
        while(aux!=0){
            cartasMao[j]=aux->Item;
            aux=aux->Prox;
            j++;
        }
        if(MesmoNaipe(&carta[JOGADOR],trunfo)) carta[i]=*PiordaMao(mao[i]);
        else carta[i]=*MelhordaMao(mao[i]);
        RetiraCarta(carta[i],mao[i]);
        free(cartasMao);
    }
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

/* Retorna a melhor entre as cartas do jogador e do(s) computador(es) */
TipoCarta* CartaGanhadora(TipoCarta carta[],TipoCarta* trunfo, int numero_jogadores){
    TipoCarta* cartaGanhadora;
    switch(numero_jogadores){
        case 2: cartaGanhadora=CartaGanhadoraAux(&carta[JOGADOR],&carta[ADVERSARIO1],trunfo);
        break;
        case 4:{
	    TipoCarta *cartaGanhadoraAux1=CartaGanhadoraAux(&carta[JOGADOR],&carta[ADVERSARIO1],trunfo);
            TipoCarta *cartaGanhadoraAux2=CartaGanhadoraAux(&carta[ADVERSARIO2],&carta[ADVERSARIO3],trunfo);
            cartaGanhadora=CartaGanhadoraAux(cartaGanhadoraAux1,cartaGanhadoraAux2,trunfo);
	}
	break;
    }
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
void InsereMontePontos(TipoCarta carta[],TipoLista** pontos, TipoCarta *trunfo, int numero_jogadores){
    for(int j=0;j<numero_jogadores;j++){
        if(MesmaCarta(CartaGanhadora(carta,trunfo,numero_jogadores),&carta[j])){
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
