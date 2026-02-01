#include <stdlib.h>
#include "gera.h"

int* gera(int quantidade, int tipo) {
    int *vetor = malloc(quantidade * sizeof(int));

    if (vetor == NULL) {
        return NULL;
    }

    // lista aleatoria
    if(tipo == 1) {
        for (int i = 0; i < quantidade; i++) {
            vetor[i] = rand() % 30000; // gerando numeros aleatorios
        }
    } 

    // lista crescente
    else if(tipo == 2) {
        for (int i = 0; i < quantidade; i++) {
            vetor[i] = i; // numeros que variam de 0 até a quantidade - 1
        }
    }

    // lista decrescente
    else if(tipo == 3) {
        for (int i = 0; i < quantidade; i++) {
            vetor[i] = quantidade - i; // numeros que variam da quantidade até 1
        }
    }

    // caso usuario escolha um tipo de lista invalido
    else {
        free(vetor);
        return NULL;
    }

    return vetor;
}