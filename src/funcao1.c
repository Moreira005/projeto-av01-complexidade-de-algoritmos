#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcao_auxiliar.h"
#include "funcao1.h"

// Complexidade calculada na etapa teórica: O(n*k)
int contar_ocorrencias(int n, int V[n], int k, int B[k])
{
    int ocorrencias_totais = 0;

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

void executar_funcao1()
{
    int n, k, escolha;

    printf("\n--- Funcao 1: Contagem de Ocorrencias Distintas ---\n\n");
    printf("Digite o tamanho do vetor principal (n): ");
    scanf("%d", &n);
    printf("Digite o tamanho do vetor de buscas (k): ");
    scanf("%d", &k);

    int V[n];
    int B[k];

    printf("\nComo deseja preencher os vetores?\n\n");
    printf("1 - Aleatoriamente\n");
    printf("2 - Manualmente\n\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        srand(time(NULL));
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

    printf("\nVetor Principal:\n\n");
    imprimir_vetor(n, V);
    printf("\nVetor de Buscas:\n\n");
    imprimir_vetor(k, B);

    int total = contar_ocorrencias(n, V, k, B);
    printf("\nTotal de ocorrencias encontradas: %d\n", total);
}