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

//LISTA_LINEAR
typedef struct ListaLinear ListaLinear_t;
ListaLinear_t *criarLista(int capacidade, bool ordenada);
bool listaCheia(ListaLinear_t *p);
int buscar_na_posição(ListaLinear_t *p, int posicao);
void inserir_na_posição(ListaLinear_t *p, int valor, int posicao);
void remover_na_posição(ListaLinear_t *p, int posicao);
int tratamentoPosicao(ListaLinear_t *p, int posicao);
int inserirElemento(ListaLinear_t *p, int valor);
bool listaVazia(ListaLinear_t *p);
int removerElemento(ListaLinear_t *p, int valor);
int buscarElemento(ListaLinear_t *p, int valor, bool buscaLinear);
void destruirLista(ListaLinear_t *p);
void imprimirLista(ListaLinear_t *p);
int primeiroElemento(ListaLinear_t *p);
int tamanhoLista(ListaLinear_t *p);

//LISTA_ENCADEADA
typedef struct no no_t;
no_t *criar_ListaEncadeada(int valor);
void adicionar_ListaEncadeada(no_t **inicio, int valor);
no_t* buscar_ListaEncadeada(no_t** inicio, int valor);
void remover_ListaEncadeada(no_t** inicio, int valor);
void destruir_ListaEncadeada(no_t** inicio);
int tamanho_ListaEncadeada(no_t *inicio);
int primeiro_ListaEncadeada(no_t *inicio);
int imprimir_ListaEncadeada(no_t *inicio);
#endif
