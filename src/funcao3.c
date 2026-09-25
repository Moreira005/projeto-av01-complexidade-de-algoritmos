#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcao_auxiliar.h"
#include "funcao3.h"

int comparar_matrizes_3d(int n, int A[n][n][n], int B[n][n][n])
{
    int somaA = 0;
    int somaB = 0;

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

    printf("\nSoma total da Matriz A: %d", somaA);
    printf("\nSoma total da Matriz B: %d\n", somaB);

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

void executar_funcao3()
{
    int n, escolha;

    printf("\n--- Funcao 3: Comparacao de Matrizes Tridimensionais ---\n\n");
    printf("Digite a dimensao das matrizes 3D (n): ");
    scanf("%d", &n);

    int A[n][n][n];
    int B[n][n][n];

    printf("\nComo deseja preencher as matrizes 3D?\n\n");
    printf("1 - Aleatoriamente\n");
    printf("2 - Manualmente\n\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        srand(time(NULL));
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

    imprimir_matriz_3d(n, A, "Matriz A");
    imprimir_matriz_3d(n, B, "Matriz B");

    int resultado = comparar_matrizes_3d(n, A, B);

    printf("\nResultado da comparacao (1 se A >= B, 0 caso contrario): %d\n", resultado);
}