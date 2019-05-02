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
  int c;

  if(getch() == '\033'){
    if(getch() == '['){
      return 0;
    }
  }else{
    return 1;
  }
}

int main(){
int c, jogadores;
//system("/bin/stty raw");
  printf("================================== BISCA ==================================\n\n\n");
  printf("SELECIONE A QUANTIDADE DE JOGADORES:\n\n");
  printf("  2 jogadores\n");
  printf("  4 jogadores\n");
  printf("0 - SAIR");
while(1){
  if (seta()){
    c = getch();
    switch (c) {
      case 'A':
      system("clear");
      printf("================================== BISCA ==================================\n\n\n");
      printf("SELECIONE A QUANTIDADE DE JOGADORES:\n\n");
      printf("->2 jogadores\n");
      printf("  4 jogadores\n\n");
      printf("0 - SAIR");
      break;
      case 'B':
      system("clear");
      printf("================================== BISCA ==================================\n\n\n");
      printf("SELECIONE A QUANTIDADE DE JOGADORES:\n\n");
      printf("  2 jogadores\n");
      printf("->4 jogadores\n\n");
      printf("0 - SAIR");
      break;
      case '0':
      exit(0);
      break;
      default:
      break;
    }
  }
}
return 0;
}
/*
if(getch() == 'A'){
  system("clear");
  printf("================================== BISCA ==================================\n\n\n");
  printf("SELECIONE A QUANTIDADE DE JOGADORES:\n\n");
  printf("->2 jogadores\n");
  printf("  4 jogadores\n\n");
  printf("0 - SAIR");
}
  if (getch() == 'B'){
  system("clear");
  printf("================================== BISCA ==================================\n\n\n");
  printf("SELECIONE A QUANTIDADE DE JOGADORES:\n\n");
  printf("  2 jogadores\n");
  printf("->4 jogadores\n\n");
  printf("0 - SAIR");
}
*/
