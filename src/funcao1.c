/*
 * PROJETO AV01 - COMPLEXIDADE E COMPUTABILIDADE DE ALGORITMO (UNIPE)
 * Integrantes:
 *   Arthur Gomes de Albuquerque Labbe   - RGM 38291339
 *   Erickson Cezar Colicchio Junior     - RGM 33175233
 *   Gustavo Moreira de Queiroz          - RGM 39441229
 *   Joelson dos Santos Mendonca Junior  - RGM 40011089
 *   Pietro Santana Fragoso Vasconcelos  - RGM 38187515
 *   Saulo Contreras de Assis            - RGM 37851039
 *
 * Funcao 1: Contagem de Ocorrencias Distintas
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcao_auxiliar.h"
#include "funcao1.h"

// Complexidade: T(n, k) = 3nk + 2k + 3  ->  O(n*k)
long long contar_ocorrencias(int n, int V[n], int k, int B[k])
{
    long long ocorrencias_totais = 0;

    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (V[j] == B[i])
            {
                ocorrencias_totais++;
            }
        }
    }

    return ocorrencias_totais;
}

void executar_funcao1(void)
{
    printf("\n--- Funcao 1: Contagem de Ocorrencias Distintas ---\n\n");
    int n = ler_dimensao("Digite o tamanho do vetor principal (n): ");
    int k = ler_dimensao("Digite o tamanho do vetor de buscas (k): ");

    int *V = alocar_memoria(sizeof(int[n]));
    int *B = alocar_memoria(sizeof(int[k]));
    if (V == NULL || B == NULL)
    {
        free(V);
        free(B);
        return;
    }

    if (escolher_preenchimento("os vetores") == 1)
    {
        preencher_vetor_aleatorio(n, V);
        preencher_vetor_aleatorio(k, B);
    }
    else
    {
        printf("\nPreenchendo o Vetor Principal:\n");
        preencher_vetor_manual(n, V);
        printf("\nPreenchendo o Vetor de Buscas:\n");
        preencher_vetor_manual(k, B);
    }

    // Exigência do projeto: Imprimir o arranjo gerado antes de exibir o resultado
    if (confirmar_impressao((long long)n + k))
    {
        printf("\nVetor Principal:\n\n");
        imprimir_vetor(n, V);
        printf("\nVetor de Buscas:\n\n");
        imprimir_vetor(k, B);
    }

    long long total = contar_ocorrencias(n, V, k, B);
    printf("\nTotal de ocorrencias encontradas: %lld\n", total);

    free(V);
    free(B);
}
