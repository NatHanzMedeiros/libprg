//
// Created by nathan1 on 09/09/2025.
//
#include <stdlib.h>
#include <stdio.h>
#include "libprg/libprg.h"
#include <stdbool.h>

typedef struct Fila {
    int *elementos;
    int capacidade;
    int tamanho;
    int inicio;
    int fim;
}Fila;

Fila *criarFila(int capacidade) {
    Fila *p;
    p = malloc(sizeof(Fila));
    (*p).elementos = malloc(sizeof(int) * capacidade);
    (*p).capacidade = capacidade;
    (*p).inicio = 0;
    (*p).fim = 0;
    (*p).elementos = 0;
    (*p).tamanho = 0;
    return p;
}

void Enfileirar(Fila *p, int valor) {
    if (filaCheia(p)) {
        exit(EXIT_FAILURE);
    }

    (*p).elementos[(*p).fim] = valor;
    (*p).fim ++;
    (*p).tamanho++;
}

bool filaCheia(Fila *p) {
    return (*p).tamanho >= (*p).capacidade;
}

bool filaVazia(Fila *p) {
    return (*p).tamanho == 0;
}

int Desenfileirar(Fila *p) {
    int valor_removido = (*p).elementos[(*p).inicio];
    (*p).inicio = ((*p).inicio + 1) % (*p).capacidade;
    (*p).tamanho--;
    return valor_removido;
}

int fimFila(Fila *p) {
    int indice_fim = ((*p).fim - 1 + (*p).capacidade) % (*p).capacidade;
    return (*p).elementos[indice_fim];
}

void destruirFila(Fila *p) {
    free((*p).elementos);
    free(p);
}


