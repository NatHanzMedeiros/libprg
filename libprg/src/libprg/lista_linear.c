//
// Created by nathan1 on 16/09/2025.
//
#include <stdlib.h>
#include <stdio.h>
#include "libprg/libprg.h"
#include <stdbool.h>

typedef struct ListaLinear {
    int *elementos;
    int capacidade;
    int tamanho;
}ListaLinear_t;

ListaLinear_t *criarLista(int capacidade){
    ListaLinear_t *p;
    p = malloc(sizeof(ListaLinear_t));
    (*p).elementos = malloc(sizeof(int) * capacidade);
    (*p).tamanho = 0;
    (*p).capacidade = capacidade;
    return p;
}

bool listaCheia(ListaLinear_t *p) {
    return (*p).tamanho == (*p).capacidade;
}

bool listaVazia(ListaLinear_t *p) {
    return (*p).tamanho == 0;
}

int inserirElemento(ListaLinear_t *p, int valor) {
    if (listaCheia(p)) {
        exit(EXIT_FAILURE);
    }
    (*p).elementos[(*p).tamanho] = valor;
    (*p).tamanho++;
}

int removerElemento(ListaLinear_t *p, int valor) {
    if (listaVazia(p)) {
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < (*p).tamanho; i++) {
        if (*((*p).elementos + i) == valor) {
            int removido = *((*p).elementos + i);
           *((*p).elementos + i) = (*p).elementos[(*p).tamanho - 1];
            (*p).tamanho--;
            return removido;
        }
    }
    return -1;
}

void imprimirLista(ListaLinear_t *p) {
    if (listaVazia(p)) {
        printf("Lista vazia!\n");
        return;
    }
    printf("Lista: ");
    for (int i = 0; i < (*p).tamanho; i++) {
        printf("%d ", (*p).elementos[i]);
    }
    printf("\n");
}

int primeiroElemento(ListaLinear_t *p) {
    if (listaVazia(p)) {
        exit(EXIT_FAILURE);
    }
   int primeiro = *((*p).elementos + 0);
   return primeiro;
}

int tamanhoLista(ListaLinear_t *p) {
    if (listaVazia(p)) {
        exit(EXIT_FAILURE);
    }
    return (*p).tamanho;
}

void destruirLista(ListaLinear_t *p) {
    free((*p).elementos);
    free(p);
}