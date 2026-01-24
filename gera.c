#include <stdlib.h>
#include "gera.h"

int* gera(int quantidade, int tipo) {
    int *vetor = malloc(quantidade * sizeof(int)); // vamos guardar o vetor gerado aqui

    if (vetor == NULL) {
        return NULL; // erro ao alocar memoria!
    }

    if(tipo == 1) { // lista aleatoria
        for (int i = 0; i < quantidade; i++) {
            vetor[i] = rand() % 10; // *alterar pra 1000* gerando numeros aleatorios que variam de 0 até 999
        }
    } 
    
    else if(tipo == 2) { // lista crescente
        for (int i = 0; i < quantidade; i++) {
            vetor[i] = i; // numeros que variam de 0 até a quantidade - 1
        }
    }

    else if(tipo == 3) { // lista decrescente
        for (int i = 0; i < quantidade; i++) {
            vetor[i] = quantidade - i; // numeros que variam da quantidade até 1
        }
    }

    else { // caso que usuario escolheu um tipo de lista invalido
        free(vetor);
        return NULL;
    }

    return vetor;
}