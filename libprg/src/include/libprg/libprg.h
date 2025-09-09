#ifndef LIBPRG_LIBPRG_H
#define LIBPRG_LIBPRG_H
#include <stdbool.h>
//PILHA
typedef struct Pilha Pilha;
Pilha *criarPilha(int capacidade);
void destruirPilha(Pilha *p);
int push(Pilha *p, int valor);
int pop(Pilha *p);
int topoPilha(Pilha *p);
int tamanhoPilha(Pilha *p);
int imprimirPilha(Pilha *p);

//FILA
typedef struct Fila Fila;
Fila *criarFila(int capacidade);
void Enfileirar(Fila *p, int valor);
bool filaCheia(Fila *p);
bool filaVazia(Fila *p);
#endif
