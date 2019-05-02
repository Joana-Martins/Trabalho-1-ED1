#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>

int getch(void){
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr ); //Guarda as flags antigas
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO ); //Seta as flags de comportamento para leitura imediata pra caractere
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr ); //Aplica as flags setadas
    ch = getchar(); //Lê o caractere
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr ); // Seta as flags antigas
    return ch;
}

int main(){
int c, jogadores;
system("/bin/stty raw");
  printf("================================== BISCA ==================================\n\n\n");
  printf("SELECIONE A QUANTIDADE DE JOGADORES:\n\n");
  printf("  2 jogadores\n");
  printf("  4 jogadores\n");
  printf("0 - SAIR");
while((c = getch()) != '0'){

  if((c = getch()) == 91){
    system("clear");
    printf("================================== BISCA ==================================\n\n\n");
    printf("SELECIONE A QUANTIDADE DE JOGADORES:\n\n");
    printf("  -> 2 jogadores\n");
    printf("  4 jogadores\n\n");
    printf("0 - SAIR");
  }else if ((c = getch()) == 27){
    system("clear");
    printf("================================== BISCA ==================================\n\n\n");
    printf("SELECIONE A QUANTIDADE DE JOGADORES:\n\n");
    printf("  -> 2 jogadores\n");
    printf("  4 jogadores\n\n");
    printf("0 - SAIR");
  }
}
system("/bin/stty cooked");
return 0;
}
