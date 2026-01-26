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

// Implementando Inserção Direta
void insercaoDireta(int vetor[], int tam, Metrica *m) {
    int i, j, atual;

    for (i = 1; i < tam; i++) {
        atual = vetor[i];

        for (j = i; j > 0; j--) {
            m->comparacoes++;

            if (atual < vetor[j - 1]) {
                vetor[j] = vetor[j - 1];
                m->trocas++;
            } else {
                break;
            }
        }

        vetor[j] = atual;
        m->trocas++;
    }
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
void selecaoDireta(int v[], int tam, Metrica *m) {
    int i, j, menor, aux;

    for (i = 0; i < tam - 1; i++) {
        menor = i;

        for (j = i + 1; j < tam; j++) {
            m->comparacoes++;

            if (v[j] < v[menor]) {
                menor = j;
            }
        }

        if (menor != i) {
            aux = v[menor];
            v[menor] = v[i];
            v[i] = aux;

            m->trocas++;
        }
    }
}


// Função auxiliar da heapsort
void criaHeap(int vetor[], int pai, int fim, Metrica *m) {
    int aux = vetor[pai];
    int filho = 2 * pai + 1;

    while (filho <= fim) {

        if (filho < fim) {
            m->comparacoes++;
            if (vetor[filho] < vetor[filho + 1]) {
                filho++;
            }
        }

        m->comparacoes++;
        if (aux < vetor[filho]) {
            vetor[pai] = vetor[filho];
            m->trocas++;

            pai = filho;
            filho = 2 * pai + 1;
        } else {
            filho = fim + 1;
        }
    }

    vetor[pai] = aux;
    m->trocas++;
}

// Implementando Heapsort
void heapsort(int vetor[], int tam, Metrica *m) {
    int i, aux;

    // Constroi o heap
    for (i = (tam - 1) / 2; i >= 0; i--) {
        criaHeap(vetor, i, tam - 1, m);
    }

    // Ordena o vetor
    for (i = tam - 1; i >= 1; i--) {
        aux = vetor[0];
        vetor[0] = vetor[i];
        vetor[i] = aux;
        m->trocas++;

        criaHeap(vetor, 0, i - 1, m);
    }
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

// Função Merge auxiliar para a Mergesort
void merge(int vetor[], int inicio, int meio, int fim, Metrica *m) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (int *) malloc(tamanho * sizeof(int));
    if (temp != NULL) {

        for (i = 0; i < tamanho; i++) {

            if (!fim1 && !fim2) {
                m->comparacoes++;

                if (vetor[p1] < vetor[p2]) {
                    temp[i] = vetor[p1++];
                } else {
                    temp[i] = vetor[p2++];
                }
                m->trocas++;

                if (p1 > meio) fim1 = 1;
                if (p2 > fim)  fim2 = 1;

            } else {
                if (!fim1) {
                    temp[i] = vetor[p1++];
                } else {
                    temp[i] = vetor[p2++];
                }
                m->trocas++;
            }
        }

        for (j = 0, k = inicio; j < tamanho; j++, k++) {
            vetor[k] = temp[j];
            m->trocas++;
        }
    }

    free(temp);
}

// Função recursiva auxiliar da Mergesort
void mergeSortRec(int vetor[], int inicio, int fim, Metrica *m) {
    int meio;

    if (inicio < fim) {
        meio = (inicio + fim) / 2;

        mergeSortRec(vetor, inicio, meio, m);
        mergeSortRec(vetor, meio + 1, fim, m);
        merge(vetor, inicio, meio, fim, m);
    }
}

// Implementando Mergesort
void mergesort(int vetor[], int tam, Metrica *m) {
    mergeSortRec(vetor, 0, tam - 1, m);
}

// Implementando Radixsort
void radixsort(int vetor[], int tam, Metrica *m) {

}

// Implementando Bucketsort
void bucketsort(int vetor[], int tam, Metrica *m) {
    
}