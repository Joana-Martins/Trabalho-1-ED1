#include"Biblioteca_Funcoes_Exibicao.h"
#include"Biblioteca_Funcoes_Trunfo.h"
#include"Biblioteca_Funcoes_CM.h"

int main(){
    TipoLista* baralho=InicializaBaralho();
    FazBaralhoVazio(baralho);
    ChecaBaralhoVazio(baralho);
    CriaBaralhoInicial(baralho);
    EmbaralhaBaralho(baralho);
    TipoCarta trunfo=CortaTrunfo(baralho);
    ReposicionaTrunfo(trunfo,baralho);
    TipoLista* mao1=FormarMao(baralho);
    TipoLista* mao2=FormarMao(baralho);
    return 0;
}