#include <stdio.h>
#include <stdlib.h>
#include "funcao_auxiliar.h"

// FUNÇÃO 1:

void preencher_vetor_aleatorio(int n, int V[n])
{
    for (int i = 0; i < n; i++)
    {
        V[i] = rand() % 100;
    }
}

void preencher_vetor_manual(int n, int V[n])
{
    for (int i = 0; i < n; i++)
    {
        printf("Digite o valor para a posicao [%d]: ", i);
        scanf("%d", &V[i]);
    }
}

void imprimir_vetor(int n, int V[n])
{
    printf("[ ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", V[i]);
    }
    printf("]\n");
}

//-----------------------------------------------------------------------

// FUNÇÃO 2:

// Implementações para Matrizes Quadradas
void preencher_matriz_aleatoria(int n, int M[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            M[i][j] = rand() % 50; // Valores aleatórios entre 0 e 49
        }
    }
}

void preencher_matriz_manual(int n, int M[n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Digite o valor para a posicao [%d][%d]: ", i, j);
            scanf("%d", &M[i][j]);
        }
    }
}

void imprimir_matriz(int n, int M[n][n])
{
    printf("\nMatriz Gerada (%dx%d):\n\n", n, n);
    for (int i = 0; i < n; i++)
    {
        printf("| ");
        for (int j = 0; j < n; j++)
        {
            printf("%3d ", M[i][j]);
        }
        printf(" |\n");
    }
}

//-----------------------------------------------------------------------

// FUNÇÃO 3:

void preencher_matriz_3d_aleatoria(int n, int M[n][n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                M[i][j][k] = rand() % 20; // Valores entre 0 e 19
            }
        }
    }
}

void preencher_matriz_3d_manual(int n, int M[n][n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                printf("Digite o valor para a posicao [%d][%d][%d]: ", i, j, k);
                scanf("%d", &M[i][j][k]);
            }
        }
    }
}

void imprimir_matriz_3d(int n, int M[n][n][n], const char *nome_matriz)
{
    printf("\n--- %s Gerada (%dx%dx%d) ---\n", nome_matriz, n, n, n);
    for (int i = 0; i < n; i++)
    {
        printf("Camada [%d]:\n", i);
        for (int j = 0; j < n; j++)
        {
            printf("| ");
            for (int k = 0; k < n; k++)
            {
                printf("%3d ", M[i][j][k]);
            }
            printf(" |\n");
        }
        printf("\n");
    }
}

//-----------------------------------------------------------------------
