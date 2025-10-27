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
    (*p).tamanho = 0;
    return p;
}

int Enfileirar(Fila *p, int valor) {
    if (filaCheia(p)) {
        exit(EXIT_FAILURE);
    }

    (*p).elementos[(*p).fim] = valor;
    (*p).fim ++;
    (*p).tamanho++;
    return 0;
}

bool filaCheia(const Fila *p) {
    return (*p).tamanho >= (*p).capacidade;
}

bool filaVazia(const Fila *p) {
    return (*p).tamanho == 0;
}

int Desenfileirar(Fila *p) {
    if (filaVazia(p)) {
        exit(EXIT_FAILURE);
    }

    int valor_removido = (*p).elementos[(*p).inicio];
    (*p).inicio = ((*p).inicio + 1) % (*p).capacidade; // Aqui é como se fosse (*p).inicio++; mas não pode ser porque não é circular
    (*p).tamanho--;
    return valor_removido;
    //Em Desenfileirar, soma se um no inicio e subtrai se um no tamanho.
}

int fimFila(const Fila *p) {
    if (filaVazia(p)) {
    exit(EXIT_FAILURE);
    }

    int indice_fim = ((*p).fim - 1 + (*p).capacidade) % (*p).capacidade;
    return (*p).elementos[indice_fim];
}

int tamanhoFila(const Fila *p) {
    return (*p).tamanho;
}

int imprimirFila(const Fila *p) {
    if (filaVazia(p)) {
    exit(EXIT_FAILURE);
    }
    for (int i = (*p).inicio; i < (*p).fim; i++) {
        printf("%d\n", *((*p).elementos + i));
    }
}

int imprimirElemento1( Fila *p, int posicao) {
    if (filaVazia(p)) {
        exit(EXIT_FAILURE);
    }
    int a =  *((*p).elementos + posicao);
    return a;
}

void destruirFila(Fila *p) {
    free((*p).elementos);
    free(p);
}


