#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funcao_auxiliar.h"
#include "funcao4.h"

// Função auxiliar para calcular o fatorial
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

void executar_funcao4()
{
    int n, escolha;

    printf("\n--- Funcao 4: Analise de Casos Assimetricos no Condicional ---\n\n");
    printf("Digite o tamanho do vetor (n): ");
    scanf("%d", &n);

    int V[n];

    printf("\nComo deseja preencher o vetor?\n\n");
    printf("1 - Aleatoriamente (Valores limitados a 12 para evitar overflow)\n");
    printf("2 - Manualmente\n\n");
    printf("Escolha: ");
    scanf("%d", &escolha);

    if (escolha == 1)
    {
        srand(time(NULL));
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

    printf("\nVetor Gerado:\n\n");
    imprimir_vetor(n, V);

    unsigned long long resultado = processar_vetor(n, V);

    // Usamos %llu para imprimir um "unsigned long long"
    printf("\nSomatorio final (Pares somados, Impares convertidos em fatorial): %llu\n", resultado);
}