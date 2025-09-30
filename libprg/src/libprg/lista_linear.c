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
    bool ordenada;
} ListaLinear_t;

ListaLinear_t *criarLista(int capacidade, bool ordenada) {
    ListaLinear_t *p;
    p = malloc(sizeof(ListaLinear_t));
    (*p).elementos = malloc(sizeof(int) * capacidade);
    (*p).tamanho = 0;
    (*p).capacidade = capacidade;
    (*p).ordenada = ordenada;
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
    if ((*p).ordenada == false) {
        *((*p).elementos + (*p).tamanho) = valor;
    } else {
        int i;
        for (i = (*p).tamanho - 1; i >= 0 && *((*p).elementos + i) > valor; i--) {
            *((*p).elementos + i + 1) = *((*p).elementos + i);
        }
        *((*p).elementos + i + 1) = valor;
    }
    (*p).tamanho++;
    return 1;
}

int removerElemento(ListaLinear_t *p, int valor) {
    if (listaVazia(p)) {
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < (*p).tamanho; i++) {
        if (*((*p).elementos + i) == valor) {
            int removido = *((*p).elementos + i);

            if ((*p).ordenada == true) {
                *((*p).elementos + i) = *((*p).elementos + (*p).tamanho - 1); // Uso não ordenado, aqui ele apenas esta substituindo o ultimo valor da lista no indice de qual foi retirado!
            } else {
                for (int j = i; j < (*p).tamanho - 1; j++) {
                    *((*p).elementos + j) = *((*p).elementos + j + 1); // Uso ordenado, agora a ordem importa, então aqui ele desloca os valores mais a direta para esquerda, mas no final o o ultimo elemento fica duplicado, então pra não ficar duplicado diminuimos -1 no tamanho!
                }
            }
            (*p).tamanho--;
            return removido;
        }
    }

}

void imprimirLista(ListaLinear_t *p) {
    if (listaVazia(p)) {
        exit(EXIT_FAILURE);
    }
    printf("Lista: ");
    for (int i = 0; i < (*p).tamanho; i++) {
        printf("%d ", *((*p).elementos + i));
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
    return (*p).tamanho;
}

void destruirLista(ListaLinear_t *p) {
    free((*p).elementos);
    free(p);
}

int buscarElemento(ListaLinear_t *p, int valor, bool buscaLinear) {
    if (listaVazia(p)) {
        exit(EXIT_FAILURE);
    }
    if (buscaLinear == true) {

        for (int i = 0; i < (*p).tamanho; i++) {
            if (*((*p).elementos + i) == valor) {
                return i;
            }
        }
    } else {
        int esquerda = 0;
        int direita = (*p).tamanho - 1;
        for (; esquerda <= direita;) {
            int meio = (esquerda + direita) / 2;

            if (*((*p).elementos + meio) == valor) {
                return meio;
            }
            if (*((*p).elementos + meio) < valor) {
                esquerda = meio + 1;
            } else {
                direita = meio - 1;
            }
        }
    }
    return 0;
}
