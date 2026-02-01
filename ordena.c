#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "ordena.h"
#include "metricas.h"

// Implementando Bolha
void bolha(int vetor[], int tam, Metrica *m) {
    int i, j, aux;

    for (i = 0; i < (tam - 1); i++) {
        for (j = 0; j < (tam-1); j++) {

            m->comparacoes++;

            if(vetor[j] > vetor[j+1]) {
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
    int i, j, atual;
    int esq, dir, meio;

    for (i = 1; i < tam; i++) {
        atual = vetor[i];
        esq = 0;
        dir = i - 1;

        while (esq <= dir) {
            meio = (esq + dir) / 2;
            m->comparacoes++;

            if (atual < vetor[meio]) {
                dir = meio - 1;
            } else {
                esq = meio + 1;
            }
        }

        for (j = i; j > esq; j--) {
            vetor[j] = vetor[j - 1];
            m->trocas++;
        }

        vetor[esq] = atual;
        m->trocas++;
    }
}

// Implementando Insercao Ternaria
void insercaoTernaria(int vetor[], int tam, Metrica *m) {
    int i, j, atual;
    int esq, dir;
    int m1, m2;

    for (i = 1; i < tam; i++) {
        atual = vetor[i];
        esq = 0;
        dir = i - 1;

        while (esq <= dir) {
            m1 = esq + (dir - esq) / 3;
            m2 = dir - (dir - esq) / 3;

            m->comparacoes++;
            if (atual < vetor[m1]) {
                dir = m1 - 1;
            } else {
                m->comparacoes++;
                if (atual > vetor[m2]) {
                    esq = m2 + 1;
                } else {
                    esq = m1 + 1;
                    dir = m2 - 1;
                }
            }
        }

        for (j = i; j > esq; j--) {
            vetor[j] = vetor[j - 1];
            m->trocas++;
        }

        vetor[esq] = atual;
        m->trocas++;
    }
}

// Implementando Shellsort
void shellsort(int vetor[], int tam, Metrica *m) {
    int h = 1;
    int i, j;
    int atual;

    while (h < tam) {
        h = 3 * h + 1;
    }

    while (h > 1) {
        h = h / 3;

        for (i = h; i < tam; i++) {
            atual = vetor[i];
            j = i - h;

            while (j >= 0) {
                m->comparacoes++;

                if (atual < vetor[j]) {
                    vetor[j + h] = vetor[j];
                    m->trocas++;
                    j = j - h;
                } else {
                    break;
                }
            }

            vetor[j + h] = atual;
            m->trocas++;
        }
    }
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

// Implementando Particao Centro para Quicksort
int particaoCentro(int vetor[], int esq, int dir, Metrica *m) {
    int centro = (esq + dir) / 2;
    int aux;

    // move o pivo para o final
    aux = vetor[centro];
    vetor[centro] = vetor[dir];
    vetor[dir] = aux;
    m->trocas++;

    int pivo = vetor[dir];
    int i = esq - 1;

    for (int j = esq; j < dir; j++) {
        m->comparacoes++;
        if (vetor[j] <= pivo) {
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            m->trocas++;
        }
    }

    aux = vetor[i + 1];
    vetor[i + 1] = vetor[dir];
    vetor[dir] = aux;
    m->trocas++;

    return i + 1;
}

// Implementando Particao Fim para Quicksort
int particaoFim(int vetor[], int esq, int dir, Metrica *m) {
    int pivo = vetor[dir];
    int i = esq - 1;
    int aux;

    for (int j = esq; j < dir; j++) {
        m->comparacoes++;
        if (vetor[j] <= pivo) {
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            m->trocas++;
        }
    }

    aux = vetor[i + 1];
    vetor[i + 1] = vetor[dir];
    vetor[dir] = aux;
    m->trocas++;

    return i + 1;
}

// Implementando Particao Mediana para Quicksort
int particaoMediana(int vetor[], int esq, int dir, Metrica *m) {
    int centro = (esq + dir) / 2;
    int aux;

    m->comparacoes++;
    if (vetor[esq] > vetor[centro]) {
        aux = vetor[esq];
        vetor[esq] = vetor[centro];
        vetor[centro] = aux;
        m->trocas++;
    }

    m->comparacoes++;
    if (vetor[esq] > vetor[dir]) {
        aux = vetor[esq];
        vetor[esq] = vetor[dir];
        vetor[dir] = aux;
        m->trocas++;
    }

    m->comparacoes++;
    if (vetor[centro] > vetor[dir]) {
        aux = vetor[centro];
        vetor[centro] = vetor[dir];
        vetor[dir] = aux;
        m->trocas++;
    }

    // pivo vai para o fim
    aux = vetor[centro];
    vetor[centro] = vetor[dir];
    vetor[dir] = aux;
    m->trocas++;

    int pivo = vetor[dir];
    int i = esq - 1;

    for (int j = esq; j < dir; j++) {
        m->comparacoes++;
        if (vetor[j] <= pivo) {
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
            m->trocas++;
        }
    }

    aux = vetor[i + 1];
    vetor[i + 1] = vetor[dir];
    vetor[dir] = aux;
    m->trocas++;

    return i + 1;
}

// Implementando Quicksort
void quicksort(int vetor[], int esq, int dir, int tipo, Metrica *m) {
    if (esq < dir) {
        int p;

        if (tipo == 1) {
            p = particaoCentro(vetor, esq, dir, m);
        }
        else if (tipo == 2) {
            p = particaoFim(vetor, esq, dir, m);
        }
        else {
            p = particaoMediana(vetor, esq, dir, m);
        }

        quicksort(vetor, esq, p - 1, tipo, m);
        quicksort(vetor, p + 1, dir, tipo, m);
    }
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

// Funcao auxiliar para Radixsort
void countingDigito(int vetor[], int tam, int exp, int aux[], Metrica *m) {
    int cont[10] = {0};

    for (int i = 0; i < tam; i++) {
        int dig = (vetor[i] / exp) % 10;
        m->comparacoes++;          // comparacao/inspecao de digito
        cont[dig]++;
    }

    for (int d = 1; d < 10; d++) {
        cont[d] += cont[d - 1];
    }

    for (int i = tam - 1; i >= 0; i--) {
        int dig = (vetor[i] / exp) % 10;
        m->comparacoes++;          // comparacao/inspecao de digito

        aux[cont[dig] - 1] = vetor[i];
        cont[dig]--;
        m->trocas++;               // movimentacao para o aux
    }

    for (int i = 0; i < tam; i++) {
        vetor[i] = aux[i];
        m->trocas++;               // movimentacao de volta pro vetor
    }
}

// Implementando Radixsort
void radixsort(int vetor[], int tam, Metrica *m) {
    int maior = vetor[0];

    for (int i = 1; i < tam; i++) {
        if (vetor[i] > maior) {
            maior = vetor[i];
        }
    }

    int *aux = malloc(tam * sizeof(int));
    if (aux == NULL) return;

    for (int exp = 1; maior / exp > 0; exp *= 10) {
        countingDigito(vetor, tam, exp, aux, m);
    }

    free(aux);
}

// Implementando Bucketsort
void bucketsort(int vetor[], int tam, Metrica *m) {
    int i;

    int numBaldes = 3000;
    int minRange = 0;
    int maxRange = 29999;
    int largura = 10;

    int *qtd = (int *) calloc(numBaldes, sizeof(int)); // usando calloc pra vir zerado logo!
    int *inicio = (int *) malloc(numBaldes * sizeof(int));
    int *pos = (int *) malloc(numBaldes * sizeof(int));
    int *buffer = (int *) malloc(tam * sizeof(int));

    if (qtd == NULL || inicio == NULL || pos == NULL || buffer == NULL) {
        free(qtd);
        free(inicio);
        free(pos);
        free(buffer);
        return;
    }

    for (i = 0; i < tam; i++) {
        int idx = (vetor[i] - minRange) / largura;

        if (idx < 0) {
            idx = 0;
        }
        if (idx >= numBaldes) {
            idx = numBaldes - 1;
        }

        qtd[idx]++;
    }

    inicio[0] = 0;
    for (i = 1; i < numBaldes; i++) {
        inicio[i] = inicio[i - 1] + qtd[i - 1];
    }

    for (i = 0; i < numBaldes; i++) {
        pos[i] = inicio[i];
    }

    for (i = 0; i < tam; i++) {
        int idx = (vetor[i] - minRange) / largura;

        if (idx < 0) {
            idx = 0;
        }
        if (idx >= numBaldes) {
            idx = numBaldes - 1;
        }

        buffer[pos[idx]] = vetor[i];
        pos[idx]++;
        m->trocas++;
    }

    for (i = 0; i < numBaldes; i++) {
        int tamanhoBalde = qtd[i];

        if (tamanhoBalde > 1) {
            bolha(&buffer[inicio[i]], tamanhoBalde, m);
        }
    }

    for (i = 0; i < tam; i++) {
        vetor[i] = buffer[i];
        m->trocas++;
    }

    free(qtd);
    free(inicio);
    free(pos);
    free(buffer);
}
