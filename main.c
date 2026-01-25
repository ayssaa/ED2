// Incluindo bibliotecas
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "gera.h"       // funcao que gera lista 
# include "metricas.h"   // funcao que cuida da metrica (tempo, comp, troca)
# include "ordena.h"     // implementacao dos metodos
# include "documento.h"  // funcao que gera .txt

// Funcao que copia/reseta uma lista
void copiaLista(int listaOriginal[], int listaCopia[], int quantidade) {
    for(int i = 0; i < quantidade; i++) {
        listaCopia[i] = listaOriginal[i];
    }
}

void main() {

    int opcao, qnt, tipo;
    int *lista = NULL;
    int *listaAux = NULL;
    Metrica m;
    clock_t ini, fim;

    srand(time(NULL));
    
    // Menu principal
    do {
        printf("\n----- Bem-Vindo ao Ordenador! -----\n");
        printf("Selecione uma opcao abaixo:\n");
        printf("1 - Gerar uma lista numerica\n");
        printf("2 - Ver lista\n");
        printf("3 - Ordenar lista\n");
        printf("4 - Gerar saida em .txt\n");
        printf("5 - Gerar saida de todas implementacoes\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 0:
                // Liberando listas
                if (lista != NULL) {
                    free(lista);
                }
                if (listaAux != NULL) {
                    free(listaAux);
                }
                printf("\nObrigada por usar o programa!\n");
                break;
            case 1:
                // Mini menu para as informações da lista
                // Quantidade de números
                printf("\n----- Informacoes sobre a lista -----\n");
                printf("Quantidade de numeros: "); 
                scanf("%d", &qnt);

                // Tipo de lista
                printf("Tipo de lista:\n");
                printf("1 - Ordem Aleatoria\n");
                printf("2 - Ordem Crescente\n");
                printf("3 - Ordem Decrescente\n");
                printf("Opcao: ");
                scanf("%d", &tipo);

                // se ja tiver valores anteriores, vamos libera-los
                if (lista != NULL) {
                    free(lista);
                    lista = NULL;
                }

                lista = gera(qnt, tipo);

                if (lista == NULL) {
                    printf("\nErro ao criar lista!\n");
                } else {
                    printf("\nLista criada com Sucesso!\n");
                }
                break;
            case 2:
                if(lista == NULL) {
                    printf("\nA lista esta vazia!\n");
                } else {
                    printf("\nLista:\n");
                    for(int i = 0; i < qnt; i++) {
                        printf("%d\n", lista[i]);
                    }
                }
                break;
            case 3:
                if(lista == NULL) {
                    printf("\nA lista esta vazia!\n");
                    break;
                }

                if (listaAux != NULL) {
                    free(listaAux);
                    listaAux = NULL;
                }

                // Criando um vetor copiado para manipulacao
                listaAux = malloc(qnt * sizeof(int));

                if (listaAux == NULL) {
                    printf("Erro ao criar a lista!");
                    break;
                }
                
                // Mini-menu para escolher método de ordenação
                printf("\n----- Formas de Ordenacao -----\n");
                printf("1 - Bolha\n");
                printf("2 - Bolha com Criterio de Parada\n");
                printf("3 - Insercao Direta\n");
                printf("4 - Insercao Binaria\n");
                printf("5 - Insercao Ternaria\n");
                printf("6 - Shellsort\n");
                printf("7 - Selecao Direta\n");
                printf("8 - Heapsort\n");
                printf("9 - Quicksort\n");
                printf("10 - Mergesort\n");
                printf("11 - Radixsort\n");
                printf("12 - Bucketsort\n");
                printf("Opcao: ");
                scanf("%d", &opcao);

                switch(opcao) {
                    case 1:
                        copiaLista(lista, listaAux, qnt);
                        inicializaMetricas(&m);
                        
                        ini = clock();
                        bolha(listaAux, qnt, &m);
                        fim = clock();

                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Bolha\n");
                        printf("Tempo: %f segundos\n", m.tempo);
                        printf("Trocas: %lld\n", m.trocas);
                        printf("Comparacoes: %lld\n", m.comparacoes);
                        break;
                    case 2:
                        copiaLista(lista, listaAux, qnt);
                        inicializaMetricas(&m);

                        ini = clock();
                        bolhaParada(listaAux, qnt, &m);
                        fim = clock();

                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Bolha com criterio de Parada\n");    
                        printf("Tempo: %.8f segundos\n", m.tempo);
                        printf("Trocas: %lld\n", m.trocas);
                        printf("Comparacoes: %lld\n", m.comparacoes);
                        break;
                    case 3:
                        copiaLista(lista, listaAux, qnt);
                        inicializaMetricas(&m);

                        ini = clock();
                        insercaoDireta(listaAux, qnt, &m);
                        fim = clock();

                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Insercao Direta\n");    
                        printf("Tempo: %.8f segundos\n", m.tempo);
                        printf("Trocas: %lld\n", m.trocas);
                        printf("Comparacoes: %lld\n", m.comparacoes);
                        break;
                    case 4:
                        copiaLista(lista, listaAux, qnt);
                        inicializaMetricas(&m);

                        ini = clock();
                        insercaoBinaria(listaAux, qnt, &m);
                        fim = clock();

                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Insercao Binaria\n");    
                        printf("Tempo: %.8f segundos\n", m.tempo);
                        printf("Trocas: %lld\n", m.trocas);
                        printf("Comparacoes: %lld\n", m.comparacoes);
                        break;
                    case 5:
                        copiaLista(lista, listaAux, qnt);
                        inicializaMetricas(&m);

                        ini = clock();
                        insercaoTernaria(listaAux, qnt, &m);
                        fim = clock();

                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Insercao Ternaria\n");    
                        printf("Tempo: %.8f segundos\n", m.tempo);
                        printf("Trocas: %lld\n", m.trocas);
                        printf("Comparacoes: %lld\n", m.comparacoes);
                        break;
                    case 6:
                        copiaLista(lista, listaAux, qnt);
                        inicializaMetricas(&m);

                        ini = clock();
                        shellsort(listaAux, qnt, &m);
                        fim = clock();

                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Shellsort\n");    
                        printf("Tempo: %.8f segundos\n", m.tempo);
                        printf("Trocas: %lld\n", m.trocas);
                        printf("Comparacoes: %lld\n", m.comparacoes);
                        break;
                    case 7:
                        copiaLista(lista, listaAux, qnt);
                        inicializaMetricas(&m);

                        ini = clock();
                        selecaoDireta(listaAux, qnt, &m);
                        fim = clock();

                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Selecao Direta\n");    
                        printf("Tempo: %.8f segundos\n", m.tempo);
                        printf("Trocas: %lld\n", m.trocas);
                        printf("Comparacoes: %lld\n", m.comparacoes);
                        break;
                    case 8:
                        copiaLista(lista, listaAux, qnt);
                        inicializaMetricas(&m);

                        ini = clock();
                        heapsort(listaAux, qnt, &m);
                        fim = clock();

                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Heapsort\n");    
                        printf("Tempo: %.8f segundos\n", m.tempo);
                        printf("Trocas: %lld\n", m.trocas);
                        printf("Comparacoes: %lld\n", m.comparacoes);
                        break;
                    case 9:
                        // Mini-menu para escolher método de Quicksort
                        printf("\n----- Escolha um tipo de Quicksort -----\n");
                        printf("1 - Pivo Central\n");
                        printf("2 - Pivo no Fim\n");
                        printf("3 - Pivo por Mediana\n");
                        printf("Opcao: ");
                        scanf("%d", &opcao);
                        
                        switch(opcao) {
                            case 1:
                                copiaLista(lista, listaAux, qnt);
                                inicializaMetricas(&m);

                                ini = clock();
                                quicksortcentro(listaAux, qnt, &m);
                                fim = clock();

                                m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                                // Mostrando desempenho
                                printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                                printf("Metodo: Quicksort com pivo central\n");    
                                printf("Tempo: %.8f segundos\n", m.tempo);
                                printf("Trocas: %lld\n", m.trocas);
                                printf("Comparacoes: %lld\n", m.comparacoes);
                                break;
                            case 2:
                                copiaLista(lista, listaAux, qnt);
                                inicializaMetricas(&m);

                                ini = clock();
                                quicksortfim(listaAux, qnt, &m);
                                fim = clock();

                                m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                                // Mostrando desempenho
                                printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                                printf("Metodo: Quicksort com pivo no fim\n");    
                                printf("Tempo: %.8f segundos\n", m.tempo);
                                printf("Trocas: %lld\n", m.trocas);
                                printf("Comparacoes: %lld\n", m.comparacoes);
                                break;
                            case 3:
                                copiaLista(lista, listaAux, qnt);
                                inicializaMetricas(&m);

                                ini = clock();
                                quicksortmediana(listaAux, qnt, &m);
                                fim = clock();

                                m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                                // Mostrando desempenho
                                printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                                printf("Metodo: Quicksort com pivo por mediana\n");    
                                printf("Tempo: %.8f segundos\n", m.tempo);
                                printf("Trocas: %lld\n", m.trocas);
                                printf("Comparacoes: %lld\n", m.comparacoes);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 10:
                        copiaLista(lista, listaAux, qnt);
                        inicializaMetricas(&m);

                        ini = clock();
                        mergesort(listaAux, qnt, &m);
                        fim = clock();

                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Mergesort\n");    
                        printf("Tempo: %.8f segundos\n", m.tempo);
                        printf("Trocas: %lld\n", m.trocas);
                        printf("Comparacoes: %lld\n", m.comparacoes);
                        break;
                    case 11:
                        copiaLista(lista, listaAux, qnt);
                        inicializaMetricas(&m);

                        ini = clock();
                        radixsort(listaAux, qnt, &m);
                        fim = clock();

                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Radixsort\n");    
                        printf("Tempo: %.8f segundos\n", m.tempo);
                        printf("Trocas: %lld\n", m.trocas);
                        printf("Comparacoes: %lld\n", m.comparacoes);
                        break;
                    case 12:
                        copiaLista(lista, listaAux, qnt);
                        inicializaMetricas(&m);

                        ini = clock();
                        bucketsort(listaAux, qnt, &m);
                        fim = clock();

                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Bucketsort\n");    
                        printf("Tempo: %.8f segundos\n", m.tempo);
                        printf("Trocas: %lld\n", m.trocas);
                        printf("Comparacoes: %lld\n", m.comparacoes);
                        break;
                    default:
                        printf("\nInvalido! Tente novamente.\n");
                        break;
                }
                printf("\nLista ordenada com sucesso!\n");
                break;
            case 4:
                // Caso usuário queira visualizar uma lista ordenada NULL
                if(listaAux == NULL) {
                    printf("\nVoce deve ordenar uma lista primeiro!\n");
                }
                else {
                    saida(listaAux, qnt, &m);
                    printf("\nLista ordenada e salva em saida.txt!\n");
                }
                break;
            case 5:
                if(lista == NULL) {
                    printf("\nA lista esta vazia!\n");
                    break;
                }

                if (listaAux != NULL) {
                    free(listaAux);
                    listaAux = NULL;
                }

                // Criando um vetor copiado para manipulacao
                listaAux = malloc(qnt * sizeof(int));

                if (listaAux == NULL) {
                    printf("Erro ao criar a lista!");
                    break;
                }

                FILE *relatorio = fopen("relatorio_metricas.txt", "w");

                if (relatorio == NULL) {
                    printf("Erro ao criar arquivo de relatorio!\n");
                    break;
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
                printf("\nRelatorio gerado em relatorio_metricas.txt!\n");
                break;
        }
    } while (opcao != 0);
}