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
 * Funcao 3: Comparacao de Matrizes Tridimensionais
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcao_auxiliar.h"
#include "funcao3.h"

// Complexidade: T(n) = 4n^3 + 4n^2 + 4n + 8  ->  O(n^3)
int comparar_matrizes_3d(int n, int A[n][n][n], int B[n][n][n])
{
    long long somaA = 0;
    long long somaB = 0;

    // Percorrer a matriz A completamente
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                somaA += A[i][j][k];
            }
        }
    }

    // Percorrer a matriz B completamente
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                somaB += B[i][j][k];
            }
        }
    }

    printf("\nSoma total da Matriz A: %lld", somaA);
    printf("\nSoma total da Matriz B: %lld\n", somaB);

    // Retorna 1 se A for maior ou igual a B, caso contrario 0
    if (somaA >= somaB)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void executar_funcao3(void)
{
    printf("\n--- Funcao 3: Comparacao de Matrizes Tridimensionais ---\n\n");
    int n = ler_dimensao("Digite a dimensao das matrizes 3D (n): ");

    int (*A)[n][n] = alocar_memoria(sizeof(int[n][n][n]));
    int (*B)[n][n] = alocar_memoria(sizeof(int[n][n][n]));
    if (A == NULL || B == NULL)
    {
        free(A);
        free(B);
        return;
    }

    if (escolher_preenchimento("as matrizes 3D") == 1)
    {
        preencher_matriz_3d_aleatoria(n, A);
        preencher_matriz_3d_aleatoria(n, B);
    }
    else
    {
        printf("\nPreenchendo a Matriz A:\n");
        preencher_matriz_3d_manual(n, A);
        printf("\nPreenchendo a Matriz B:\n");
        preencher_matriz_3d_manual(n, B);
    }

    // Imprime o arranjo gerado antes de exibir o resultado
    if (confirmar_impressao(2LL * n * n * n))
    {
        imprimir_matriz_3d(n, A, "Matriz A");
        imprimir_matriz_3d(n, B, "Matriz B");
    }

    int resultado = comparar_matrizes_3d(n, A, B);

    printf("\nResultado da comparacao (1 se A >= B, 0 caso contrario): %d\n", resultado);

    free(A);
    free(B);
}
