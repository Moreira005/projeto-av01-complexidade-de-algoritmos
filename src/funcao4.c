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
 * Funcao 4: Analise de Casos Assimetricos no Condicional
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcao_auxiliar.h"
#include "funcao4.h"

// Função auxiliar para calcular o fatorial
// Complexidade: F(m) = 2m + 2  ->  O(m)
unsigned long long calcular_fatorial(int numero)
{
    if (numero < 0)
    {
        return 0; // Fatoriais de negativos não se aplicam aqui
    }

    unsigned long long fat = 1;
    for (int i = 2; i <= numero; i++)
    {
        fat *= i;
    }
    return fat;
}

// Função principal solicitada no projeto
// Complexidade (pior caso, todos ímpares de valor m): T(n) = 2nm + 5n + 3  ->  O(n*m)
unsigned long long processar_vetor(int n, int V[n])
{
    unsigned long long somatorio = 0;

    for (int i = 0; i < n; i++)
    {
        if (V[i] % 2 == 0)
        {
            // Se o elemento for PAR
            somatorio += V[i];
        }
        else
        {
            // Se o elemento for ÍMPAR
            somatorio += calcular_fatorial(V[i]);
        }
    }

    return somatorio;
}

void executar_funcao4(void)
{
    printf("\n--- Funcao 4: Analise de Casos Assimetricos no Condicional ---\n\n");
    int n = ler_dimensao("Digite o tamanho do vetor (n): ");

    int *V = alocar_memoria(sizeof(int[n]));
    if (V == NULL)
    {
        return;
    }

    printf("\n(No preenchimento aleatorio os valores ficam entre 0 e 11 para evitar overflow do fatorial)\n");
    if (escolher_preenchimento("o vetor") == 1)
    {
        // Preenchimento local para limitar os números gerados (0 a 11)
        for (int i = 0; i < n; i++)
        {
            V[i] = rand() % 12;
        }
    }
    else
    {
        printf("\nPreenchendo o Vetor (Dica: Use numeros de 0 a 15 para nao estourar a memoria):\n");
        preencher_vetor_manual(n, V);
    }

    // Imprime o arranjo gerado antes de exibir o resultado
    if (confirmar_impressao(n))
    {
        printf("\nVetor Gerado:\n\n");
        imprimir_vetor(n, V);
    }

    unsigned long long resultado = processar_vetor(n, V);

    // Usamos %llu para imprimir um "unsigned long long"
    printf("\nSomatorio final (Pares somados, Impares convertidos em fatorial): %llu\n", resultado);

    free(V);
}
