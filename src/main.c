#include <stdio.h>
#include <stdlib.h>
#include "funcao1.h"
// No futuro, colocaremos: #include "funcao_2.h", #include "funcao_3.h"...

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
        // printf("2 - Funcao 2: ...\n");
        // printf("3 - Funcao 3: ...\n");
        // printf("4 - Funcao 4: ...\n");
        // printf("5 - Funcao 5: ...\n");
        printf("0 - Sair\n");
        printf("==================================================\n\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao)
        {
        case 1:
            executar_funcao_1();
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