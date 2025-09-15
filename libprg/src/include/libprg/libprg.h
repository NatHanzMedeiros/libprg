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
int Enfileirar(Fila *p, int valor);
bool filaCheia(const Fila *p);
bool filaVazia(const Fila *p);
int Desenfileirar(Fila *p);
void destruirFila(Fila *p);
int fimFila(const Fila *p);
int tamanhoFila(const Fila *p);
int imprimirFila(const Fila *p);
#endif
