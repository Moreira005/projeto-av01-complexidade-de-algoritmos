#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcao_auxiliar.h"
#include "funcao5.h"

int contar_elementos_encontrados(int n, int A[n], int B[n])
{
    int contador = 0;

    // Para cada elemento do vetor A, faz a busca binaria no vetor B
    for (int i = 0; i < n; i++)
    {
        if (busca_binaria(n, B, A[i]) == 1)
        {
            contador++;
        }
    }

    return contador;
}

void executar_funcao5()
{
    int n, escolha;

    printf("\n--- Funcao 5: Contagem com Busca Binaria ---\n\n");
    printf("Digite o tamanho dos vetores (n): ");
    scanf("%d", &n);

    int A[n]; // Nao ordenado
    int B[n]; // Ordenado

    printf("\nComo deseja preencher os vetores?\n\n");
    printf("1 - Aleatoriamente (Vetor B sera gerado ordenado automaticamente)\n");
    printf("2 - Manualmente\n\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        srand(time(NULL));
        preencher_vetor_aleatorio(n, A);
        preencher_vetor_ordenado_aleatorio(n, B);
    }
    else
    {
        printf("\nPreenchendo o Vetor A (Nao Ordenado):\n");
        preencher_vetor_manual(n, A);

        printf("\nPreenchendo o Vetor B (ATENCAO: Os valores DEVEM ser digitados em ordem crescente!):\n");
        preencher_vetor_manual(n, B);
    }

    printf("\nVetor A (Nao Ordenado):\n\n");
    imprimir_vetor(n, A);

    printf("\nVetor B (Ordenado para a Busca Binaria):\n\n");
    imprimir_vetor(n, B);

    int resultado = contar_elementos_encontrados(n, A, B);

    printf("\nTotal de elementos do Vetor A encontrados no Vetor B: %d\n", resultado);
}