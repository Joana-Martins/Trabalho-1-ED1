
primeiro_jogar_facil(int ganhou, int numero_jogadores, TipoCarta *carta, TipoLista **mao){
if(n_jogadores == 2){
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
default:
break;

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
default:
break;
  }
}
}

primeiro_jogar_dificil(int ganhou, int numero_jogadores, TipoCarta *carta, TipoLista **mao){
  if(n_jogadores == 2){
  switch(ganhou){
  case 0:
      RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
      JogaComputadorDificil(carta,mao,ADVERSARIO1);
      break;

  case 1:
      JogaComputadorDificil(carta,mao,ADVERSARIO1);
      RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
      break;
    }
  default:
  break;

  }else{
  switch (ganhou) {
  case 0:
        RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
        JogaComputadorDificil(carta,mao,ADVERSARIO1);
        JogaComputadorDificil(carta,mao,ADVERSARIO2);
        JogaComputadorDificil(carta,mao,ADVERSARIO3);
        break;
  case 1:
      JogaComputadorDificil(carta,mao,ADVERSARIO1);
      JogaComputadorDificil(carta,mao,ADVERSARIO2);
      JogaComputadorDificil(carta,mao,ADVERSARIO3);
      RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
      break;
  case 2:
      JogaComputadorDificil(carta,mao,ADVERSARIO2);
      JogaComputadorDificil(carta,mao,ADVERSARIO3);
      RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
      JogaComputadorDificil(carta,mao,ADVERSARIO1);
      break;
  case 3:
        JogaComputadorDificil(carta,mao,ADVERSARIO3);
        RetiraCarta(carta[JOGADOR],mao[JOGADOR]);
        JogaComputadorDificil(carta,mao,ADVERSARIO1);
        JogaComputadorDificil(carta,mao,ADVERSARIO2);
      break;
  default:
  break;
    }
  }
}






int ganhador_rodada(int numero_jogadores, TipoCarta *carta, TipoCarta *cartaganhadora){
  int ganhou;
  if (numero_jogadores == 2){
    if(cartaganhadora ==  carta[JOGADOR]){
      ganhou = 0;
    }else{
      ganhou = 1;
    }
  }else{
    if(cartaganhadora ==  carta[JOGADOR]){
      ganhou = 0;
    }else if(cartaganhadora == carta[ADVERSARIO1]){
      ganhou = 1;
    }else if(cartaganhadora == carta[ADVERSARIO2]){
      ganhou = 2;
    }else{
      ganhou = 3;
    }
  }
}
