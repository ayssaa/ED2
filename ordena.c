#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"
#include "metricas.h"

// Implementando Bolha
void bolha(int vetor[], int tam, Metrica *m) {
    int i, j, aux;

    for (i = 0; i < (tam - 1); i++) { // percorre lista
        for (j = 0; j < (tam-1); j++) { // compara elementos entre si

            m->comparacoes++;

            if(vetor[j] > vetor[j+1]) { // comparando
                // se o valor atual é maior do que o mais à direita, efetuando troca!
                aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;

                m->trocas++;
            }
        }
    }
}

// Implementando Bolha com Criterio de Parada
void bolhaParada(int vetor[], int tam, Metrica *m) {
    int i, aux, continua;
    int fim = tam;

    do {
        continua = 0;

        for (i = 0; i < fim - 1; i++) {
            m->comparacoes++;

            if (vetor[i] > vetor[i + 1]) {
                aux = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = aux;

                m->trocas++;
                continua = i;
            }
        }

        fim--;
    } while (continua != 0);
}

// Implementando Insercao Direta
void insercaoDireta(int vetor[], int tam, Metrica *m) {
    
}

// Implementando Insercao Binaria
void insercaoBinaria(int vetor[], int tam, Metrica *m) {
    
}

// Implementando Insercao Ternaria
void insercaoTernaria(int vetor[], int tam, Metrica *m) {
    
}

// Implementando Shellsort
void shellsort(int vetor[], int tam, Metrica *m) {
    
}

// Implementando Selecao Direta
void selecaoDireta(int vetor[], int tam, Metrica *m) {
    
}

// Implementando Heapsort
void heapsort(int vetor[], int tam, Metrica *m) {

}

// Implementando Quicksort Centro
void quicksortcentro(int vetor[], int tam, Metrica *m) {

}

// Implementando Quicksort Fim
void quicksortfim(int vetor[], int tam, Metrica *m) {

}

// Implementando Quicksort Mediana
void quicksortmediana(int vetor[], int tam, Metrica *m) {
    
}

// Implementando Mergesort
void mergesort(int vetor[], int tam, Metrica *m) {

}

// Implementando Radixsort
void radixsort(int vetor[], int tam, Metrica *m) {

}

// Implementando Bucketsort
void bucketsort(int vetor[], int tam, Metrica *m) {
    
}