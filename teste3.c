#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int getch(void){
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

int seta(){
  getch();
  switch(getch()){
    case 'A':
    return 0;
    break;

    case 'B':
    return 1;
    break;
  }
}
void dificuldade (int i){
  switch (i){
    case 0:
      system("clear");
      printf("================================== BISCA ==================================\n\n\n");
      printf("SELECIONE A DIFICULDADE:\n\n");
      printf("  EASY\n");
      printf("  HARD\n");
      printf("SELECIONE A QUANTIDADE DE JOGADORES: \n\n");
      printf("  2 jogadores\n");
      printf("  4 jogadores\n");
      printf("1 - JOGAR\n");
      printf("0 - SAIR");
      break;
    case 1:
      system("clear");
      printf("================================== BISCA ==================================\n\n\n");
      printf("SELECIONE A DIFICULDADE:\n\n");
      printf("  -> EASY\n");
      printf("  HARD\n");
      printf("SELECIONE A QUANTIDADE DE JOGADORES: \n\n");
      printf("  2 jogadores\n");
      printf("  4 jogadores\n");
      printf("1 - JOGAR\n");
      printf("0 - SAIR");
      break;
    case 2:
      system("clear");
      printf("================================== BISCA ==================================\n\n\n");
      printf("SELECIONE A DIFICULDADE:\n\n");
      printf("  EASY\n");
      printf("-> HARD\n");
      printf("SELECIONE A QUANTIDADE DE JOGADORES: \n\n");
      printf("  2 jogadores\n");
      printf("  4 jogadores\n");
      printf("1 - JOGAR\n");
      printf("0 - SAIR");
      break;
    case 3:
      system("clear");
      printf("================================== BISCA ==================================\n\n\n");
      printf("SELECIONE A DIFICULDADE:\n\n");
      printf("  EASY\n");
      printf("  HARD\n");
      printf("SELECIONE A QUANTIDADE DE JOGADORES: \n\n");
      printf("  -> 2 jogadores\n");
      printf("  4 jogadores\n");
      printf("1 - JOGAR\n");
      printf("0 - SAIR");
      break;
    case 4:
      system("clear");
      printf("================================== BISCA ==================================\n\n\n");
      printf("SELECIONE A DIFICULDADE:\n\n");
      printf("  EASY\n");
      printf("  HARD\n");
      printf("SELECIONE A QUANTIDADE DE JOGADORES: \n\n");
      printf("  2 jogadores\n");
      printf("  -> 4 jogadores\n");
      printf("1 - JOGAR\n");
      printf("0 - SAIR");
      break;
    default:
    break;
  }
}

void selecionado(int i){
  switch (i) {
    case 0:
      printf(" \nSelecionado-> DIFICULDADE: - JOGADORES: - \n");
      printf(" - Se nao escolhido sera o default -");
      break;
    case 1:
      printf(" \nSelecionado-> DIFICULDADE: Facil JOGADORES: - \n");
      break;
    case 2:
      printf(" \nSelecionado-> DIFICULDADE: Facil JOGADORES: 2 \n");
      printf(" - Se nao escolhido sera o default -");
      break;
    case 3
      printf(" \nSelecionado-> DIFICULDADE: Facil JOGADORES: 4 \n");
      printf(" - Se nao escolhido sera o default -");
    case 4:
      printf(" \nSelecionado-> DIFICULDADE: Dificil JOGADORES: - \n");
      printf(" - Se nao escolhido sera o default -");
    case 5:
      printf(" \nSelecionado-> DIFICULDADE: Dificil JOGADORES: 2 \n");
      printf(" - Se nao escolhido sera o default -");
    case 6:
      printf(" \nSelecionado-> DIFICULDADE: Dificil JOGADORES: - \n");
      printf(" - Se nao escolhido sera o default -");
    case 7:
      printf(" \nSelecionado-> DIFICULDADE: - JOGADORES: 2 \n");
      printf(" - Se nao escolhido sera o default -");
    case 8:
      printf(" \nSelecionado-> DIFICULDADE: - JOGADORES: 4 \n");
      printf(" - Se nao escolhido sera o default -");
    default:
    break;
  }
}

int main(){
  int d, j;
  dificuldade(0);
  slecionado(0);
  while(1){
    switch(getch()){
      case '\033':
        if(seta() == 0){

        }
      case '\n':
      case '1':
      case '0':
      default:
      break;
    }
  }
}
