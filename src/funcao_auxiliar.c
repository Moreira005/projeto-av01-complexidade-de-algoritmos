#include <stdio.h>
#include <stdlib.h>
#include "funcao_auxiliar.h"

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