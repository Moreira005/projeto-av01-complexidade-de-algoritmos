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
 * Funcao 2: Analise de Pares em Matriz Triangular
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcao_auxiliar.h"
#include "funcao2.h"

// Complexidade: T(n) = 2n^2 + 4n + 3  ->  O(n^2)
int analisar_matriz_triangular(int n, int M[n][n])
{
    int contador = 0;

    // Laço externo percorre as linhas
    for (int i = 0; i < n; i++)
    {
        // Laço interno restrito: inicia em 'i' para pegar a diagonal e o triângulo superior
        for (int j = i; j < n; j++)
        {
            int soma = M[i][j] + M[j][i];
            if (soma % 5 == 0)
            {
                contador++;
            }
        }
    }

    return contador;
}

void executar_funcao2(void)
{
    printf("\n--- Funcao 2: Analise de Pares em Matriz Triangular ---\n\n");
    int n = ler_dimensao("Digite a ordem da matriz quadrada (n): ");

    // Matriz dinâmica (ponteiro para VLA do C99) alocada no heap
    int (*M)[n] = alocar_memoria(sizeof(int[n][n]));
    if (M == NULL)
    {
        return;
    }

    if (escolher_preenchimento("a matriz") == 1)
    {
        preencher_matriz_aleatoria(n, n, M);
    }
    else
    {
        printf("\nPreenchendo a Matriz:\n");
        preencher_matriz_manual(n, n, M);
    }

    // Exigência do projeto: Imprimir o arranjo gerado antes de exibir o resultado
    if (confirmar_impressao((long long)n * n))
    {
        imprimir_matriz(n, n, M);
    }

    int resultado = analisar_matriz_triangular(n, M);
    printf("\nTotal de pares cuja soma e multipla de 5: %d\n", resultado);

    free(M);
}
