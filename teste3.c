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
    case 7:
    break;
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
      printf("\n \nSelecionado-> DIFICULDADE: Facil JOGADORES: 2 \n");
      break;
    case 1:
      printf("\n\nSelecionado-> DIFICULDADE: Facil JOGADORES: 4 \n");
      break;
    case 2:
      printf("\n\nSelecionado-> DIFICULDADE: Dificil JOGADORES: 2 \n");
      break;
    case 3:
      printf(" \n\nSelecionado-> DIFICULDADE: Dificil JOGADORES: 4 \n");
      break;
    default:
    break;
  }
}

int main(){
  int d = 0, j = 0, i = 0;

  int x = 1, y = 1;
  dificuldade(i);
  selecionado(i);
  while(1){
    switch(getch()){
      case '\033':
        if(seta() == 1){
          if( i == 0){
            i = 1;
            x = 1;
          dificuldade(i);
          selecionado(d);

        }else if(i == 1){
          i = 2;
          x = 2;
          dificuldade(i);
          selecionado(d);
        }else if(i == 2){
            i = 3;
            y = 1;
            dificuldade(i);
            selecionado(d);
          }else if(i == 3){
            i = 4;
            y = 2;
            dificuldade(i);
            selecionado(d);
          }
        }else{
          if( i == 1){
            i = 0;
            dificuldade(i);
            selecionado(d);

          }else if(i == 2){
            i = 1;
            x = 1;
            dificuldade(i);
            selecionado(d);

          }else if(i == 3){
            i = 2;
            x = 2;
            dificuldade(i);
            selecionado(d);

          }else if(i == 4){
            i = 3;
            y = 1;
            dificuldade(i);
            selecionado(d);
            }
        }
        break;
      case '\n':
        if(x == 1 && y == 1){
          d = 0;
          system("clear");
          dificuldade(0);
          selecionado(d);
        }else if ( x == 1 && y == 2){
          d = 1;
          system("clear");
          dificuldade(0);
          selecionado(d);
        }else if( x == 2 && y == 1){
          d = 2;
          system("clear");
          dificuldade(0);
          selecionado(d);
        }else if(x == 2 && y == 2){
          d = 3;
          system("clear");
          dificuldade(0);
          selecionado(d);
        }
        break;
      case '1':
      system("clear");
      printf("\nIniciando jogo\n");
      break;
      case '0':
      printf("\n");
      exit(0);
      break;
      default:
      break;
    }
  }
}
