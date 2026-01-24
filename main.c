/*
Olá, professor!
Esse trabalho foi desenvolvido pela Maria Luíza e pela Ayssa Hadassa :D
Aqui é o nosso main.c, temos:
 . Menu
 . Função para visualizar a lista
 . Chamada das funções de ordenação
*/

// Incluindo bibliotecas
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "gera.h"
# include "metricas.h"
# include "ordena.h"
# include "documento.h"

// Função para ver a lista
void verLista(int vetor[], int tam) {
    printf("\nLista:\n");
    for(int i = 0; i < tam; i++) {
        printf("%d\n", vetor[i]);
    }
}

void main() {
    // Definindo variaveis usadas
    int opcao, qnt, tipo, ordenacao, quick;
    int *vetorOriginal = NULL;
    int *vetorCopia = NULL;

    // Inicializando gerador aleatorio
    srand(time(NULL));

    // Configurando o timer e inicializando as metricas (comparações e trocas)
    Metrica m;
    clock_t ini, fim;
   
    // Menu de visualizacao
    do {
        printf("\n----- Bem-Vindo ao Ordenador! -----\n");
        printf("Selecione uma opcao abaixo:\n");
        printf("1 - Gerar uma lista numerica\n");
        printf("2 - Ver lista gerada\n");
        printf("3 - Ordenar lista\n");
        printf("4 - Ver lista ordenada\n");
        printf("5 - Gerar saida em .txt\n");
        printf("6 - Gerar metricas de TODAS ordenacoes\n");
        printf("0 - Sair\n");
        printf("Opcao: ");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 0: 
                // Antes de finalizar o programa, estamos liberando as listas caso necessário
                if (vetorOriginal != NULL) {
                    free(vetorOriginal);
                }
                if (vetorCopia != NULL) {
                    free(vetorCopia);
                }

                printf("\nObrigada por usar o programa!\n");
                break;
            case 1:
                // Mini-menu para descrever as informações da lista
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

                // Liberando a lista caso seja criada mais de uma
                if (vetorOriginal != NULL) {
                    free(vetorOriginal);
                }

                vetorOriginal = gera(qnt, tipo);

                
                if(vetorOriginal == NULL) {
                    printf("\nErro ao criar a lista!\n");
                }
                else {
                    printf("\nLista gerada com sucesso!\n");
                }

                break;
            case 2:
                // Caso usuário queira visualizar uma lista NULL
                if(vetorOriginal == NULL) {
                    printf("\nA lista esta vazia!\n");
                    break;
                }
                
                verLista(vetorOriginal, qnt);
                
                break;
            case 3:
                // Caso usuário ordenar uma lista NULL
                if(vetorOriginal == NULL) {
                    printf("\nA lista esta vazia!\n");
                    break;
                }

                // Copiando a lista original em uma lista cópia para ordenação
                // Se o vetorCopia não estiver vazio, fazemos ele ser NULL
                if (vetorCopia != NULL) {
                    free(vetorCopia);
                    vetorCopia = NULL;
                }

                // Agora que ele é NULL, copiamos o vetorOriginal para vetorCopia
                vetorCopia = malloc(qnt * sizeof(int));

                if (vetorCopia == NULL) {
                    printf("Erro ao criar a lista!");
                }
                else {
                    for (int i = 0; i < qnt; i++) {
                        vetorCopia[i] = vetorOriginal[i];
                    }
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
                scanf("%d", &ordenacao);

                switch(ordenacao) {
                    case 1:
                        // Inicializando métricas e fazendo ordenação
                        inicializaMetricas(&m);
                        ini = clock();
                        bolha(vetorCopia, qnt, &m);
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
                        inicializaMetricas(&m);
                        ini = clock();
                        bolhaParada(vetorCopia, qnt, &m);
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
                        inicializaMetricas(&m);
                        ini = clock();
                        insercaoDireta(vetorCopia, qnt, &m);
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
                        inicializaMetricas(&m);
                        ini = clock();
                        insercaoBinaria(vetorCopia, qnt, &m);
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
                        inicializaMetricas(&m);
                        ini = clock();
                        insercaoTernaria(vetorCopia, qnt, &m);
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
                        inicializaMetricas(&m);
                        ini = clock();
                        shellsort(vetorCopia, qnt, &m);
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
                        inicializaMetricas(&m);
                        ini = clock();
                        selecaoDireta(vetorCopia, qnt, &m);
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
                        inicializaMetricas(&m);
                        ini = clock();
                        heapsort(vetorCopia, qnt, &m);
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
                        scanf("%d", &quick);
                        
                        switch(quick) {
                            case 1:
                                inicializaMetricas(&m);
                                ini = clock();
                                quicksortcentro(vetorCopia, qnt, &m);
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
                                inicializaMetricas(&m);
                                ini = clock();
                                quicksortfim(vetorCopia, qnt, &m);
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
                                inicializaMetricas(&m);
                                ini = clock();
                                quicksortmediana(vetorCopia, qnt, &m);
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
                                printf("\nInvalido! Tente novamente.\n");
                                break;
                        }
                        break;
                    case 10:
                        inicializaMetricas(&m);
                        ini = clock();
                        mergesort(vetorCopia, qnt, &m);
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
                        inicializaMetricas(&m);
                        ini = clock();
                        radixsort(vetorCopia, qnt, &m);
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
                        inicializaMetricas(&m);
                        ini = clock();
                        bucketsort(vetorCopia, qnt, &m);
                        fim = clock();
                        m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                        // Mostrando desempenho
                        printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                        printf("Metodo: Bucketsort");    
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
                if(vetorOriginal == NULL) {
                    printf("\nA lista esta vazia!\n");
                    break;
                }
                if(vetorOriginal != NULL && vetorCopia == NULL) {
                    printf("\nVoce precisa ordenar primeiro!\n");
                    break;
                }
                
                verLista(vetorCopia, qnt);
                
                break;
            case 5:
                // Caso usuário queira visualizar uma lista ordenada NULL
                if(vetorOriginal == NULL) {
                    printf("\nA lista esta vazia!\n");
                    break;
                }
                if(vetorOriginal != NULL && vetorCopia == NULL) {
                    printf("\nVoce precisa ordenar primeiro!\n");
                    break;
                }

                geraSaida(vetorCopia, qnt, &m);
                printf("\nLista ordenada e salva em saida.txt!\n");
                break;
            case 6:
                
                geraRelatorio(vetorCopia, qnt, &m);


            

            default:
                printf("\nInvalido! Tente novamente.\n");
                break;
        }

    } while (opcao != 0);
}