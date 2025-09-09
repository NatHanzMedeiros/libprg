//

// Created by nathan1 on 29/08/2025.

//
#include <stdlib.h>
#include <stdio.h>
#include "libprg/libprg.h"

typedef struct Pilha {
    int *elementos;
    int topo;
    int capacidade;

} Pilha;

Pilha *criarPilha(int capacidade) {
    Pilha *p;
    p = malloc(sizeof(Pilha));
    (*p).elementos = malloc(capacidade * sizeof(int));
    (*p).topo = -1;
    (*p).capacidade = capacidade;
    return p;

}

//Para hardwares com memoria limitada,
//deve se verificar o retorno da função malloc,
//afim de evitar memory leak!


void destruirPilha(Pilha *p) {
    free((*p).elementos);
    free(p);
}

int push(Pilha *p, int valor) {
    if ((*p).topo == (*p).capacidade - 1) {
        //printf("Sua pilha esta cheia!\n");
        return -1;
    }
    (*p).topo++;
    (*p).elementos[(*p).topo] = valor;
    //printf("O valor %d foi adicionado a sua pilha!\n", valor);

}

int pop(Pilha *p) {
    if ((*p).topo == -1) {
        //printf("Sua está pilha vazia!\n");
        return -1;
    }

    int valor_removido = (*p).elementos[(*p).topo];
    (*p).topo--;
    //printf("Elemento foi removido!\n");
    return valor_removido;

}
int topoPilha(Pilha *p) {
    if ((*p).topo == -1) {
        //printf("Sua pilha esta vazia!\n");
        return -1;
    }
    return (*p).elementos[(*p).topo];
}

int tamanhoPilha(Pilha *p) {
    return (*p).topo +1;
}

int imprimirPilha(Pilha *p) {
    if ((*p).topo == -1) {
    //printf("Sua pilha esta vazia!\n");
    return -1;
    }

    for (int i = (*p).topo; i >= 0; i--) {
        printf("%d\n", *((*p).elementos + i));
    }
    return 0;
}
