#include "metricas.h"

void inicializaMetricas(Metrica *m) {
    m->comparacoes = 0;
    m->trocas = 0;
    m->tempo = 0.0;
}
