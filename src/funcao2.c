#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcao_auxiliar.h"
#include "funcao2.h"

// Função principal de Análise Triangular
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

void executar_funcao2()
{
    int n, escolha;

    printf("\n--- Funcao 2: Analise de Pares em Matriz Triangular ---\n\n");
    printf("Digite a ordem da matriz quadrada (n): ");
    scanf("%d", &n);

    int M[n][n]; // Declaração da matriz usando VLA do C99

    printf("\nComo deseja preencher a matriz?\n\n");
    printf("1 - Aleatoriamente\n");
    printf("2 - Manualmente\n\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        srand(time(NULL));
        preencher_matriz_aleatoria(n, M);
    }
    else
    {
        printf("\nPreenchendo a Matriz:\n");
        preencher_matriz_manual(n, M);
    }

    // Exigência do projeto: Imprimir o arranjo gerado antes de exibir o resultado
    imprimir_matriz(n, M);

    int resultado = analisar_matriz_triangular(n, M);
    printf("\nTotal de pares cuja soma e multipla de 5: %d\n", resultado);
}