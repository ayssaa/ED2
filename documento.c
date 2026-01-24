#include <stdio.h>
# include <time.h>
#include "documento.h"
#include "metricas.h"

void geraSaida(int vetor[], int tam, Metrica *m) {
    FILE *arquivo = fopen("saida.txt", "w");

    if (arquivo == NULL) {
        printf("Erro ao criar o arquivo de saida!\n");
        return;
    }

    fprintf(arquivo, "METRICAS DE DESEMPENHO\n");
    fprintf(arquivo, "Tempo de execucao: %.8f segundos\n", m->tempo);
    fprintf(arquivo, "Numero de comparacoes: %lld\n", m->comparacoes);
    fprintf(arquivo, "Numero de trocas: %lld\n", m->trocas);
    fprintf(arquivo, "\nVETOR ORDENADO:\n");

    for (int i = 0; i < tam; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);

}

void geraRelatorio(int vetor[], int tam, Metrica *m) {
    int vetorAux[] = malloc(tam * sizeof(int));

    FILE *relatorio = fopen("saida.txt", "w");

    if (relatorio == NULL) {
        printf("Erro ao criar o arquivo de saida!\n");
        return;
    }

    // Bolha 
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    }

    inicializaMetricas(&m);
    clock_t ini = clock();
    bolha(vetorAux, tam, &m);
    clock_t fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Bolha\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);
    
    // Bolha com criterio de Parada
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    }

    inicializaMetricas(&m);
    ini = clock();
    bolhaParada(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Bolha com criterio de Parada\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

    // Insersao Direta
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    }

    inicializaMetricas(&m);
    ini = clock();
    insercaoDireta(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Insercao Direta\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

    // Insercao Binaria
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    } 
    
    inicializaMetricas(&m);
    ini = clock();
    insercaoBinaria(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Insercao Binaria\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

    // Insercao Ternaria 
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    }

    inicializaMetricas(&m);
    ini = clock();
    insercaoTernaria(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Insercao Ternaria\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

    // Shellsort 
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    }

    inicializaMetricas(&m);
    ini = clock();
    shellsort(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Shellsort\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

    // Selecao Direta 
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    }

    inicializaMetricas(&m);
    ini = clock();
    selecaoDireta(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Selecao Direta\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

    // Heapsort 
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    }

    inicializaMetricas(&m);
    ini = clock();
    heapsort(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Heapsort\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

    // Quicksort Centro
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    } 

    inicializaMetricas(&m);
    ini = clock();
    quicksortcentro(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Quicksort Centro\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

    // Quicksort com pivo no fim 
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    }

    inicializaMetricas(&m);
    ini = clock();
    quicksortfim(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Quicksort com pivo no fim\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

    // Quicksort com pivo por mediana
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    } 

    inicializaMetricas(&m);
    ini = clock();
    quicksortmediana(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Quicksort com pivo por mediana\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

    // Mergesort 
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    }

    inicializaMetricas(&m);
    ini = clock();
    mergesort(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Mergesort\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

    // Radixsort 
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    }

    inicializaMetricas(&m);
    ini = clock();
    radixsort(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Radixsort\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);


    // Bucketsort 
    // Copia o vetor
    for (int i = 0; i < tam; i++) {
        vetorAux[i] = vetor[i];
    }

    inicializaMetricas(&m);
    ini = clock();
    bucketsort(vetorAux, tam, &m);
    fim = clock();
    m->tempo = (double)(fim - ini) / CLOCKS_PER_SEC;


    fprintf(relatorio, "\n----- Metricas de desempenho da Ordenacao -----\n");
    fprintf(relatorio, "Metodo: Bucketsort\n");    
    fprintf(relatorio, "Tempo: %f segundos\n", m->tempo);
    fprintf(relatorio, "Trocas: %lld\n", m->trocas);
    fprintf(relatorio, "Comparacoes: %lld\n", m->comparacoes);

}

