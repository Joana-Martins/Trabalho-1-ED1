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

int seta(void){
  if(getch() == '\033'){
      getch();
      return 0;
  }else{
    return 1;
  }
}

int main(){
int c, jogadores;
//system("/bin/stty raw");
  system("clear");
  printf("================================== BISCA ==================================\n\n\n");
  printf("SELECIONE A DIFICULDADE\n\n");
  printf("  EASY\n");
  printf("  HARD\n");
  printf("0 - SAIR");

while(c = getch() != '0'){
  if (seta()){
    switch (getch()) {
      case 'A':
      system("clear");
      printf("================================== BISCA ==================================\n\n\n");
      printf("SELECIONE A DIFICULDADE\n\n");
      printf("  -> EASY\n");
      printf("  HARD\n");
      printf("0 - SAIR");
      break;
      case 'B':
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
}
return 0;
}
