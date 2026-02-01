// Incluindo bibliotecas
# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include "gera.h"       // funcao que gera lista 
# include "metricas.h"   // funcao que cuida da metrica (tempo, comp, troca)
# include "ordena.h"     // implementacao dos metodos
# include "util.h"       // utilidades (saída e copiar lista)

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

                copiaLista(lista, listaAux, qnt);
                inicializaMetricas(&m);
                ini = clock();

                switch(opcao) {
                    case 1:
                        bolha(listaAux, qnt, &m);
                        break;
                    case 2:
                        bolhaParada(listaAux, qnt, &m);
                        break;
                    case 3:
                        insercaoDireta(listaAux, qnt, &m);
                        break;
                    case 4:
                        insercaoBinaria(listaAux, qnt, &m);
                        break;
                    case 5:
                        insercaoTernaria(listaAux, qnt, &m);
                        break;
                    case 6:
                        shellsort(listaAux, qnt, &m);
                        break;
                    case 7:
                        selecaoDireta(listaAux, qnt, &m);
                        break;
                    case 8:
                        heapsort(listaAux, qnt, &m);
                        break;
                    case 9:
                        // Mini-menu para escolher método de Quicksort
                        printf("\n----- Escolha um tipo de Quicksort -----\n");
                        printf("1 - Pivo Central\n");
                        printf("2 - Pivo no Fim\n");
                        printf("3 - Pivo por Mediana\n");
                        printf("Opcao: ");
                        scanf("%d", &opcao);

                        // reinicia o tempo para desconsiderar o menu do quicksort
                        ini = clock();
                        
                        switch(opcao) {
                            case 1:
                                quicksort(listaAux, 0, qnt, 1, &m);
                                break;
                            case 2:
                                quicksort(listaAux, 0, qnt, 2, &m);
                                break;
                            case 3:
                                quicksort(listaAux, 0, qnt, 3, &m);
                                break;
                            default:
                                break;
                        }
                        break;
                    case 10:
                        mergesort(listaAux, qnt, &m);
                        break;
                    case 11:
                        radixsort(listaAux, qnt, &m);
                        break;
                    case 12:
                        bucketsort(listaAux, qnt, &m);
                        break;
                    default:
                        printf("\nInvalido! Tente novamente.\n");
                        break;
                }

                fim = clock();
                m.tempo = (double)(fim - ini) / CLOCKS_PER_SEC;

                // Mostrando desempenho
                printf("\n----- Metricas de desempenho da Ordenacao -----\n");
                printf("Tempo: %f segundos\n", m.tempo);
                printf("Trocas: %lld\n", m.trocas);
                printf("Comparacoes: %lld\n", m.comparacoes);
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

                relatorio(lista, listaAux, qnt, tipo);

                printf("\nRelatorio gerado em relatorio_metricas.txt!\n");
                break;
        }
    } while (opcao != 0);
}