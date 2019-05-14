/*TRABALHO 1 ESTRUTURA DE DADOS 1
  JOANA MARTINS E JULIANE FERREIRA
          15/05/2019
          Prof. Vinicius
          */
#include"Biblioteca_Modos_Jogo.h"
#include"menu.h"

/* FUNCAO PRINCIPAL - MENU INTERATIVO E CHAMADA DO JOGO EM QUESTAO */
int main(){
    int i;
    i = menu();
    JogoBisca(i);
    return 0;
}
