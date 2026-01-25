# include <stdio.h>
# include "documento.h"
# include "metricas.h"

void saida(int vetor[], int tam, Metrica *m) {
    FILE *arquivo = fopen("saida.txt", "w");

    if (arquivo == NULL) {
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

    for (int i = 0; i < tam; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);

}