//
// Created by nathan1 on 18/11/2025.
//
#include "libprg/libprg.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct arvoreBinaria {
    int valor;
    struct arvore_binaria *esquerda;
    struct arvore_binaria *direita;
}no_arvoreB;

no_arvoreB *criar_no_arvore(int valor) {
    no_arvoreB *no = (no_arvoreB *)malloc(sizeof(no_arvoreB));
    no->valor = valor;
    no->esquerda = no->direita = NULL;
    return no;
}

void destruir_no_arvore(no_arvoreB *no) {
    if (no) {
        destruir_no_arvore(no->esquerda);
        destruir_no_arvore(no->direita);
        free(no);
    }
}

no_arvoreB *inserir_na_arvore(no_arvoreB *raiz, int valor) {
    if (!raiz) return criar_no_arvore(valor);
    if (valor < raiz->valor) {
        raiz->esquerda = inserir_na_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir_na_arvore(raiz->direita, valor);
    }
    return raiz;
}

bool busca_na_arvore(no_arvoreB *raiz, int valor) {
    if (!raiz) return false;
    if (valor == raiz->valor) return true;
    if (valor < raiz->valor) return busca_na_arvore(raiz->esquerda, valor);
    return busca_na_arvore(raiz->direita, valor);
}

no_arvoreB *remover_valor_da_arvore(no_arvoreB *raiz, int valor) {
    if (!raiz) return NULL;
    if (valor < raiz->valor) {
        raiz->esquerda = remover_valor_da_arvore(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover_valor_da_arvore(raiz->direita, valor);
    } else {
        if (!raiz->esquerda || !raiz->direita) {
            // em processo
        } else {
            // em processo
        }
    }
    return raiz;
}