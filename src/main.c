#include <stdio.h>
#include <stdlib.h>
#include "funcao1.h"
#include "funcao2.h"
#include "funcao3.h"
#include "funcao4.h"
#include "funcao5.h"

int main()
{
    int opcao;

    do
    {
        printf("\n==================================================\n");
        printf(" PROJETO AV1 - COMPLEXIDADE DE ALGORITMOS\n");
        printf("==================================================\n\n");
        printf("==================================================\n");
        printf("1 - Funcao 1: Contagem de Ocorrencias Distintas\n");
        printf("2 - Funcao 2: Analise de Pares em Matriz Triangular\n");
        printf("3 - Funcao 3: Comparacao de Matrizes Tridimensionais\n");
        printf("4 - Funcao 4: Analise de Casos Assimetricos\n");
        printf("5 - Funcao 5: Contagem com Busca Binaria\n");
        printf("0 - Sair\n");
        printf("==================================================\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            executar_funcao1();
            break;
        case 2:
            executar_funcao2();
            break;
        case 3:
            executar_funcao3();
            break;
        case 4:
            executar_funcao4();
            break;
        case 5:
            executar_funcao5();
            break;
        case 0:
            printf("\nEncerrando o programa...\n");
            break;
        default:
            printf("\nOpcao invalida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}