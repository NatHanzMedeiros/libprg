#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
typedef struct Pilha Pilha;
Pilha *criarPilha(int capacidade);
void destruirPilha(Pilha *p);
int push(Pilha *p, int valor);
int pop(Pilha *p);
int topoPilha(Pilha *p);
int tamanhoPilha(Pilha *p);
int imprimirPilha(Pilha *p);
#endif
