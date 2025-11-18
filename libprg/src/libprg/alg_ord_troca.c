//
// Created by nathan1 on 15/11/2025.
//
#include "libprg/libprg.h"
#include <stdio.h>

void bubble_sort(int *vetor, int n) {
int aux;
    for (int i = 0; i < n-1; i++) {
        for (int j = 0 ; j < n-i-1; i++) {
            if (*(vetor + j) < *(vetor + j +1)) {
                aux = *(vetor + j);
                *(vetor + j)= *(vetor + j +1);
                *(vetor + j +1) = aux;
            }
        }
    }
}

void insertion_sort(int *vetor, int n) {
    int chave, j ;
    for (int i = 1; i < n; i++) {
        chave = *(vetor + i);
        j=i-1;
        while (j >= 0 && *(vetor + j) > chave) {
            *(vetor + j +1) = *(vetor + j);
            j--;
        }
        *(vetor + j) = chave;
    }
}

void selection_sort(int *vetor, int n) {
int min, j, aux;
    for (int i = 0; i < n; i++) {
        min = i;
        for (j = i +1 ; j < n ; j++) {
            if (*(vetor + j) < *(vetor + min)) {
                min = j;
            }
        }
        if (min != i) {
            aux = *(vetor + i);
            *(vetor + i) = *(vetor + min);
            *(vetor + min) = aux;
        }
    }
}
