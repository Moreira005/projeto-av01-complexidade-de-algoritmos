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
 * Funcao 5: Contagem de Elementos Presentes em Vetor Ordenado
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcao_auxiliar.h"
#include "funcao5.h"

// Complexidade (pior caso, nenhum elemento encontrado):
// T(n) = n(5*floor(log2 n) + 11) + 3  ->  O(n log n)
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

void executar_funcao5(void)
{
    printf("\n--- Funcao 5: Contagem com Busca Binaria ---\n\n");
    int n = ler_dimensao("Digite o tamanho dos vetores (n): ");

    // Alocados no heap: com n = 10.000.000 os vetores nao caberiam na pilha
    int *A = alocar_memoria(sizeof(int[n])); // Nao ordenado
    int *B = alocar_memoria(sizeof(int[n])); // Ordenado
    if (A == NULL || B == NULL)
    {
        free(A);
        free(B);
        return;
    }

    printf("\n(No preenchimento aleatorio o Vetor B e gerado ja ordenado)\n");
    if (escolher_preenchimento("os vetores") == 1)
    {
        preencher_vetor_aleatorio(n, A);
        preencher_vetor_ordenado_aleatorio(n, B);
    }
    else
    {
        printf("\nPreenchendo o Vetor A (Nao Ordenado):\n");
        preencher_vetor_manual(n, A);

        printf("\nPreenchendo o Vetor B (ATENCAO: Os valores DEVEM ser digitados em ordem crescente!):\n");
        preencher_vetor_manual(n, B);

        // A busca binaria so funciona em vetor ordenado
        if (!vetor_esta_ordenado(n, B))
        {
            printf("\nO Vetor B nao estava em ordem crescente e foi ordenado automaticamente.\n");
            ordenar_vetor(n, B);
        }
    }

    // Exigência do projeto: Imprimir o arranjo gerado antes de exibir o resultado
    if (confirmar_impressao(2LL * n))
    {
        printf("\nVetor A (Nao Ordenado):\n\n");
        imprimir_vetor(n, A);

        printf("\nVetor B (Ordenado para a Busca Binaria):\n\n");
        imprimir_vetor(n, B);
    }

    int resultado = contar_elementos_encontrados(n, A, B);

    printf("\nTotal de elementos do Vetor A encontrados no Vetor B: %d\n", resultado);

    free(A);
    free(B);
}
