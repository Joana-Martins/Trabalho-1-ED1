CC=gcc
CFLAGS=-I. -Wall  -lm
DEPS = Biblioteca_Modos_Jogo.h Biblioteca_Funcoes_Jogo.h Biblioteca_Funcoes_CM.h Biblioteca_Funcoes_Trunfo.h Biblioteca_Funcoes_IR.h Biblioteca_Funcoes_Exibicao.h Biblioteca_Funcoes_Basicas.h menu.h
OBJ = Biblioteca_Modos_Jogo.o Biblioteca_Funcoes_Jogo.c Biblioteca_Funcoes_CM.o Biblioteca_Funcoes_Trunfo.o Biblioteca_Funcoes_IR.o Biblioteca_Funcoes_Exibicao.o Biblioteca_Funcoes_Basicas.o menu.o ideias.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

ideias: $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

clean:
	rm -f *.o
