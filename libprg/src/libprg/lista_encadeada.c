//
// Created by nathan1 on 06/10/2025.
//

#include <libprg/libprg.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct no {
    int valor;
    struct no *proximo;
} no_t;

no_t *criar_ListaEncadeada(int valor) {
    no_t *no = malloc(sizeof(no_t));
    (*no).valor = valor;
    (*no).proximo = NULL;
    return no;
}

void adicionar_ListaEncadeada(no_t **inicio, int valor) { // Ou seja, **inicio vai apontar para outro ponteiro que eu chamar na main.
    no_t *novo_no = criar_ListaEncadeada(valor);          // Exemplificação, "minha_lista"  é um ponteiro do tipo "no_t"  a variavel "minha_lista" tem endereço = 0x100 e armazena(aponta) para o endereço 0x200.
    (*novo_no).proximo = *inicio;                         // Então quando criamos "(*novo_no).proximo = *inicio" estamos dizendo que o campo "proximo" desse "novo_no" vai receber o que tem guardado na variavel
    *inicio = novo_no;                                    //"inicio" que é o endereço de "minha_lista" mas como é "*inicio", ele faz desreferenciar esse endereço logo vamos receber o que esse endereço de "minha_lista" guarda!
}

no_t* buscar_ListaEncadeada(no_t **inicio, int valor) {
    no_t *atual = *inicio;
    while (atual != NULL) {
        if ((*atual).valor == valor) {
            return atual;
        }
            atual = (*atual).proximo;
    }
    return NULL;
}

void remover_ListaEncadeada(no_t **inicio, int valor) {
    no_t *atual = *inicio;
    no_t *anterior = NULL;
    while (atual != NULL) {
        if ((*atual).valor == valor) {
            if (anterior == NULL) {
                *inicio = (*atual).proximo;
            } else {
                (*anterior).proximo = (*atual).proximo;
            }
            free(atual);
            return;
        }
        anterior = atual;
        atual = (*atual).proximo;
    }
}

void destruir_ListaEncadeada(no_t** inicio) {
    no_t *atual = *inicio;
    while (atual) {
        no_t *proximo = (*atual).proximo;
        free(atual);
        atual = proximo;
    }
}
