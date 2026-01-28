# include <stdio.h>
# include <time.h>
# include "util.h"
# include "metricas.h"
# include "ordena.h"

void copiaLista(int listaOriginal[], int listaCopia[], int qnt) {
    for(int i = 0; i < qnt; i++) {
        listaCopia[i] = listaOriginal[i];
    }
}

void saida(int vetor[], int tam, Metrica *m) {
    FILE *arquivo = fopen("saida.txt", "w");

    if (arquivo == NULL)
    {
        printf("Erro ao criar o arquivo de saida!\n");
        return;
    }

    // Cabecalho para o .txt
    fprintf(arquivo, "Relatorio das metricas de ordenacao\n");
    fprintf(arquivo, "Quantidade de numeros: %d\n\n", tam);

    fprintf(arquivo, "METRICAS DE DESEMPENHO\n");
    fprintf(arquivo, "Tempo de execucao: %.8f segundos\n", m->tempo);
    fprintf(arquivo, "Numero de comparacoes: %lld\n", m->comparacoes);
    fprintf(arquivo, "Numero de trocas: %lld\n", m->trocas);
    fprintf(arquivo, "\nVETOR ORDENADO:\n");

    for (int i = 0; i < tam; i++)
    {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);
}

void relatorio(int lista[], int listaAux[], int qnt, int tipo) {
    FILE *relatorio = fopen("relatorio_metricas.txt", "w");
    Metrica m;
    clock_t ini, fim;

    if (relatorio == NULL) {
        printf("Erro ao criar arquivo de relatorio!\n");
        return;
    }

    // Cabecalho para o .txt
    fprintf(relatorio, "Relatorio das metricas de ordenacao\n");
    fprintf(relatorio, "Quantidade de numeros: %d\n", qnt);
    if (tipo == 1) {
        fprintf(relatorio, "Ordenacao: Aleatorio\n");
    }
    else if (tipo == 2) {
        fprintf(relatorio, "Ordenacao: Crescente\n");
    }
    else if (tipo == 3) {
        fprintf(relatorio, "Ordenacao: Decrescente\n");
    }

    // Bolha
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    bolha(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Bolha -----\n");
    fprintf(relatorio, "Tempo: %f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Bolha com criterio de parada
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    bolhaParada(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Bolha com criterio de Parada -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Insercao direta
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    insercaoDireta(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Insercao Direta -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Insercao Binaria
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    insercaoBinaria(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Insercao Binaria -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Insercao ternaria
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    insercaoTernaria(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Insercao Ternaria -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Shellsort
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    shellsort(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Shellsort -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Selecao direta
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    selecaoDireta(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Selecao Direta -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Heapsort
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    heapsort(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Heapsort -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Quicksort centro
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    quicksortcentro(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Quicksort com pivo central -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Quicksort fim
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    quicksortfim(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Quicksort com pivo no fim -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Quicksort mediana
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    quicksortmediana(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Quicksort com pivo por mediana -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Mergesort
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    mergesort(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Mergesort -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Radixsort
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    radixsort(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Radixsort -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    // Bucketsort
    copiaLista(lista, listaAux, qnt);
    inicializaMetricas(&m);

    ini = clock();
    bucketsort(listaAux, qnt, &m);
    fim = clock();

    m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

    // Mostrando desempenho
    fprintf(relatorio, "\n----- Bucketsort -----\n");
    fprintf(relatorio, "Tempo: %.8f segundos\n", m.tempo);
    fprintf(relatorio, "Trocas: %lld\n", m.trocas);
    fprintf(relatorio, "Comparacoes: %lld\n\n", m.comparacoes);

    fclose(relatorio);
}
