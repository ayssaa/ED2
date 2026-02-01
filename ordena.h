#ifndef ORDENA_H
#define ORDENA_H
#include "metricas.h"

void bolha(int vetor[], int tam, Metrica *m);

void bolhaParada(int vetor[], int tam, Metrica *m);

void insercaoDireta(int vetor[], int tam, Metrica *m);

void insercaoBinaria(int vetor[], int tam, Metrica *m);

void insercaoTernaria(int vetor[], int tam, Metrica *m);

void shellsort(int vetor[], int tam, Metrica *m);

void selecaoDireta(int vetor[], int tam, Metrica *m);

void heapsort(int vetor[], int tam, Metrica *m);

void quicksort(int vetor[], int esq, int dir, int tipo, Metrica *m);

void mergesort(int vetor[], int tam, Metrica *m);

void radixsort(int vetor[], int tam, Metrica *m);

void bucketsort(int vetor[], int tam, Metrica *m);

#endif
