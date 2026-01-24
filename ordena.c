#include <stdio.h>
#include <stdlib.h>
#include "ordena.h"
#include "metricas.h"

// Implementando Bolha
void bolha(int vetor[], int tam, Metrica *m) {
    for (int i = 0; i < tam; i++) { // percorre lista
        for (int j = 0; j < (tam-1); j++) { // compara elementos entre si

            m->comparacoes++;

            if(vetor[j] > vetor[j+1]) { // comparando
                // se o valor atual é maior do que o mais à direita, efetuando troca!
                int aux = vetor[j];
                vetor[j] = vetor[j+1];
                vetor[j+1] = aux;

                m->trocas++;
            }
        }
    }
}

// Implementando Bolha com Criterio de Parada
void bolhaParada(int vetor[], int tam, Metrica *m) {
    int mudou = 1;
    int indice = tam - 1;

    while (mudou) {
        int j = 1;
        mudou = 0;

        while (j < tam) {
            m->comparacoes++; // comparacao entre chaves

            if (vetor[j - 1] > vetor[j]) {

                // troca
                int aux = vetor[j - 1];
                vetor[j - 1] = vetor[j];
                vetor[j] = aux;

                m->trocas++;   // contando a troca
                mudou = 1;
                indice = j;
            }
            j++;
        }
        tam = indice;
    }
}


// Implementando Insercao Direta
void insercaoDireta(int vetor[], int tam, Metrica *m) {
    for (int i = 1; i < tam; i++) {
        int aux = vetor[i];
        int j = i - 1;

        // desloca enquanto for maior
        while (j >= 0) {
            m->comparacoes++; // comparacao entre chaves

            if (vetor[j] > aux) {
                vetor[j + 1] = vetor[j];
                m->trocas++; // deslocamento
                j -= 1;
            } 
            else {
                break;
            }
        }

        vetor[j + 1] = aux;
        m->trocas++; // insercao final
    }
}

// Implementando Insercao Binaria
void insercaoBinaria(int vetor[], int tam, Metrica *m) {
    for (int i = 1; i < tam; i++) { 
        int aux = vetor[i];
        int esq = 0;
        int dir = i;

        while (esq < dir) {
            int meio = (esq + dir) / 2;

            m->comparacoes++; // comparacaoo entre chaves
            if (vetor[meio] <= aux) {
                esq = meio + 1;
            } 
            else {
                dir = meio;
            }
        }

        // deslocamento dos elementos
        for (int j = i; j > dir; j--) {
            vetor[j] = vetor[j - 1];
            m->trocas++; // movimentação no vetor
        }

        vetor[dir] = aux;
        m->trocas++; // insercao final
    }
}

// Implementando Insercao Ternaria
void insercaoTernaria(int vetor[], int tam, Metrica *m) {
    for (int i = 1; i < tam; i++) {
        int aux = vetor[i];
        int esq = 0;
        int dir = i;

        while (esq < dir) {
            int m1 = esq + (dir - esq) / 3;
            int m2 = esq + 2 * (dir - esq) / 3;

            m->comparacoes++;
            if (aux < vetor[m1]) {
                dir = m1;
            } 
            else {
                m->comparacoes++;

                if (aux > vetor[m2]) {
                    esq = m2 + 1;
                } 
                else {
                    esq = m1 + 1;
                    dir = m2;
                }
            }
        }

        for (int j = i; j > esq; j--) {
            vetor[j] = vetor[j - 1];
            m->trocas++;
        }

        vetor[esq] = aux;
        m->trocas++;
    }
}

// Implementando Shellsort
void shellsort(int vetor[], int tam, Metrica *m) {
    int h = 1;

    while (h < tam / 3) {
        h = (3 * h) + 1;
    }

    while (h > 1) {
        for (int i = h; i < tam; i++) {
            int aux = vetor[i];
            int j = i - h;

            while(j >= 0) {
                m->comparacoes++;

                if(aux < vetor[j]) {
                    vetor[j + h] = vetor[j];
                    j -= h;
                }
                else {
                    break;
                }
            }
            vetor[j + h] = aux;
            m->trocas++;
        }
        h = h / 3;
    }
}

// Implementando Selecao Direta
void selecaoDireta(int vetor[], int tam, Metrica *m) {
    for (int i = 0; i < (tam-1); i++) {
        int menor = i;
        
        for(int j = i + 1; j < tam; j++) {
            m->comparacoes++;
            if(vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if(i != menor) {
            int aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
            m->trocas++;
        }
    }
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