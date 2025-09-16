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

ListaLinear_t *criarLista(int capacidade, int tamanho) {
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
    int valor_removido = (*p).elementos[(*p).tamanho - 1];
    for (int i = 0; i < (*p).tamanho; i++) {
        if (*((*p).elementos + i) == valor) {
            (*p).tamanho--;
        }
    }
    return valor_removido;
}

void destruirLista(ListaLinear_t *p) {
    free((*p).elementos);
    free(p);
}