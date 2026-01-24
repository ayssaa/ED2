#ifndef METRICAS_H
#define METRICAS_H

typedef struct metrica {
    long long comparacoes;
    long long trocas;
    double tempo;
} Metrica;

void inicializaMetricas(Metrica *m);

#endif
