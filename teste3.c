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
    printf("SELECIONE A DIFICULDADE\n\n");
    printf("  EASY\n");
    printf("  HARD\n");
    printf("0 - SAIR");
    break;
    case 1:
    system("clear");
    printf("================================== BISCA ==================================\n\n\n");
    printf("SELECIONE A DIFICULDADE\n\n");
    printf("  -> EASY\n");
    printf("  HARD\n");
    printf("0 - SAIR");
    break;
    case 2:
    system("clear");
    printf("================================== BISCA ==================================\n\n\n");
    printf("SELECIONE A DIFICULDADE\n\n");
    printf("  EASY\n");
    printf("  -> HARD\n");
    printf("0 - SAIR");
    break;
    default:
    break;
  }
}

void jogadores (int i){
  switch (i){
    case 0:
    system("clear");
    printf("================================== BISCA ==================================\n\n\n");
    printf("SELECIONE A QUANTIDADE DE JOGADORES \n\n");
    printf("  2 jogadores\n");
    printf("  4 jogadores\n");
    printf("0 - SAIR\n");
    break;
    case 1:
    system("clear");
    printf("================================== BISCA ==================================\n\n\n");
    printf("SELECIONE A QUANTIDADE DE JOGADORES \n\n");
    printf("  -> 2 jogadores\n");
    printf("  4 jogadores\n");
    printf("0 - SAIR\n");
    break;
    case 2:
    system("clear");
    printf("================================== BISCA ==================================\n\n\n");
    printf("SELECIONE A QUANTIDADE DE JOGADORES \n\n");
    printf("  2 jogadores\n");
    printf("  -> 4 jogadores\n");
    printf("0 - SAIR\n");
    break;
    default:
    break;
  }
}



int main(){

int d = 0, j = 0;

  while(1){
    dificuldade(d);
      switch(getch()){
        case '\033':
          if(seta == 0){
            d = 1;
            dificuldade(d);
          }else{
              d = 2;
              dificuldade(d);
              }
          break;

        case '\n':
          jogadores(j);
            switch(getch()){
              case '\033':
                if(seta() == 0){
                  j = 1;
                  jogadores(j);
                }else{
                    j = 2;
                    jogadores(j);
                    }
                    break;
            case '\n':
                system("clear");
                printf("O JOGO VAI COMECAR\n");
                break;
            default:
            break;
          }
          break;

      case '0':
        exit(0);
        break;

      default:
      break;

    }
  }
}
