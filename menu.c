
#include "menu.h"

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
  int option;
  getch();
  switch(getch()){
    case 'A':
    option=0;
    break;

    case 'B':
    option=1;
    break;
  }
  return option;
}

void titulo(){
  puts("                .------..------..------..------..------.");
  puts("                |B.--. ||I.--. ||S.--. ||C.--. ||A.--. |");
  puts("                | :(): || (||) || :||: || :(): || ()() |");
  puts("                | ()() || :||: || :||: || :(): || :||: |");
  puts("                | '--'B|| '--'I|| '--'S|| '--'C|| '--'A|");
  puts("                `------'`------'`------'`------'`------'");
}

void dificuldade(int i){
  switch (i) {
    case 0:
    system("clear");
    titulo();
    printf("\n                         SELECIONE A DIFICULDADE:\n\n");
    printf("                                  FACIL\n");
    printf("                                  DIFICIL\n");
    printf("\n                               1 - PROX\n");
    printf("\n                               0 - SAIR\n");
    break;
    case 1:
    system("clear");
    titulo();
    printf("\n                         SELECIONE A DIFICULDADE:\n\n");
    printf("                                  -> FACIL\n");
    printf("                                  DIFICIL\n");
    printf("\n                               1 - PROX\n");
    printf("\n                               0 - SAIR\n");
    break;
    case 2:
    system("clear");
    titulo();
    printf("\n                         SELECIONE A DIFICULDADE:\n\n");
    printf("                                  FACIL\n");
    printf("                                  -> DIFICIL\n");
    printf("\n                               1 - PROX\n");
    printf("\n                               0 - SAIR\n");
    break;
    default:
    break;
  }
}

void jogadores(int i){
  switch (i) {
    case 0:
    system("clear");
    titulo();
    printf("\n                         SELECIONE A QUANTIDADE DE JOGADORES:\n\n");
    printf("                                  2 JOGADORES\n");
    printf("                                  4 JOGADORES\n");
    printf("\n                                 1 - JOGAR\n");
    printf("\n                                 0 - SAIR\n");
    break;
    case 1:
    system("clear");
    titulo();
    printf("\n                         SELECIONE A QUANTIDADE DE JOGADORES:\n\n");
    printf("                                  -> 2 JOGADORES\n");
    printf("                                  4 JOGADORES\n");
    printf("\n                                 1 - JOGAR\n");
    printf("\n                                 0 - SAIR\n");
    break;
    case 2:
    system("clear");
    titulo();
    printf("\n                         SELECIONE A QUANTIDADE DE JOGADORES:\n\n");
    printf("                                  2 JOGADORES\n");
    printf("                                  -> 4 JOGADORES\n");
    printf("\n                                 1 - JOGAR\n");
    printf("\n                                 0 - SAIR\n");
    default:
    break;
  }
}

void selecionado(int i){
  switch (i) {
    case 0:
      printf("\n \nSelecionado-> DIFICULDADE: Facil JOGADORES: 2 \n");
      break;
    case 2:
      printf("\n\nSelecionado-> DIFICULDADE: Facil JOGADORES: 4 \n");
      break;
    case 1:
      printf("\n\nSelecionado-> DIFICULDADE: Dificil JOGADORES: 2 \n");
      break;
    case 3:
      printf(" \n\nSelecionado-> DIFICULDADE: Dificil JOGADORES: 4 \n");
      break;
    default:
    break;
  }
}


int menu_J(int y){
  int i = 0, x, w = 0;
  int d = y;
  jogadores(i);
  selecionado(d);
  while (w == 0){
    switch(getch()){
      case '\033':
        if((seta()) == 1){
          if( i == 0){
            i = 1;
            x = 2;
            jogadores(i);
            selecionado(d);
          }else if (i == 1){
            i = 2;
            x = 3;
            jogadores(i);
            selecionado(d);
          }else if (i == 2){
            i = 0;
            jogadores(i);
            selecionado(d);
          }
        }else{
          if(i == 2){
            i = 1;
            x = 2;
            jogadores(i);
            selecionado(d);
          }else if(i == 1){
            i = 0;
            jogadores(i);
            selecionado(d);
          }else if( i == 0){
            i = 2;
            x = 3;
            jogadores(i);
            selecionado(d);
          }
        }
      break;
      case '\n':
        if (x == 2 && y == 0){
          d = 0;
          jogadores(i);
          selecionado(d);
        }else if( x == 2 && y == 1){
          d = 1;
          jogadores(i);
          selecionado(d);
        }else if ( x   selecionado(d);
== 3 && y == 0){
          d = 2;
          jogadores(i);
          selecionado(d);
        }else if ( x == 3 && y == 1){
          d = 3;
          jogadores(i);
          selecionado(d);
        }
      break;
      case '1':
      system("clear");
      w = 1;


      break;
      case '0':
      exit(0);
      break;
      default:
      break;
    }
  }

  return d;
}



int menu_D(){
  int i = 0, d = 0, x, w = 0;
  dificuldade(i);
  selecionado(d);
  while (w == 0){
    switch(getch()){
      case '\033':
        if(seta() == 1){
          if( i == 0){
            i = 1;
            x = 0;
            dificuldade(i);
            selecionado(d);
          }else if (i == 1){
            i = 2;
            x = 1;
            dificuldade(i);
            selecionado(d);
          }else if (i == 2){
            i = 0;
            dificuldade(i);
            selecionado(d);
          }
        }else{
          if(i == 2){
            i = 1;
            x = 0;
            dificuldade(i);
            selecionado(d);
          }else if(i == 1){
            i = 0;
            dificuldade(i);
            selecionado(d);
          }else if( i == 0){
            i = 2;
            x = 1;
            dificuldade(i);
            selecionado(d);
          }
        }
      break;
      case '\n':
        if (x == 0){
          d = 0;
          dificuldade(i);
          selecionado(x);
        }else if( x == 1){
          d = 1;
          dificuldade(i);
          selecionado(x);
        }
      break;
      case '1':
      system("clear");
      w = 1;
      break;
      case '0':
      exit(0);
      break;
      default:
      break;
    }
  }

  return d;
}


int menu(){
  int i, f;
  i = menu_D();
  f = menu_J(i);
  return f;
}
