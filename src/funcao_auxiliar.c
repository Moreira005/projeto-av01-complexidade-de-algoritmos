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
 * Funcoes auxiliares (nao avaliadas na analise de complexidade).
 */

#include <stdio.h>
#include <stdlib.h>
#include "funcao_auxiliar.h"

// Acima deste total de elementos o programa pergunta antes de imprimir o arranjo
#define LIMITE_IMPRESSAO 2000

// ENTRADA E MEMORIA:

static void limpar_buffer(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
    {
    }
}

// Le um inteiro do teclado, repetindo a leitura enquanto a entrada for invalida
int ler_inteiro(void)
{
    int valor;
    int lidos;

    while ((lidos = scanf("%d", &valor)) != 1)
    {
        if (lidos == EOF)
        {
            printf("\nFim da entrada. Encerrando o programa...\n");
            exit(0);
        }
        limpar_buffer();
        printf("Entrada invalida! Digite um numero inteiro: ");
    }

    return valor;
}

// Le uma dimensao de arranjo, que precisa ser maior que zero
int ler_dimensao(const char *mensagem)
{
    int valor;

    printf("%s", mensagem);
    valor = ler_inteiro();
    while (valor <= 0)
    {
        printf("A dimensao deve ser maior que zero. %s", mensagem);
        valor = ler_inteiro();
    }

    return valor;
}

// Pergunta se o arranjo sera preenchido aleatoriamente (1) ou manualmente (2)
int escolher_preenchimento(const char *nome_arranjo)
{
    int escolha;

    printf("\nComo deseja preencher %s?\n\n", nome_arranjo);
    printf("1 - Aleatoriamente\n");
    printf("2 - Manualmente\n\n");
    printf("Escolha: ");
    escolha = ler_inteiro();
    while (escolha != 1 && escolha != 2)
    {
        printf("Opcao invalida! Digite 1 ou 2: ");
        escolha = ler_inteiro();
    }

    return escolha;
}

// Arranjos pequenos sao sempre impressos; nos grandes o usuario confirma antes
int confirmar_impressao(long long total_elementos)
{
    int resposta;

    if (total_elementos <= LIMITE_IMPRESSAO)
    {
        return 1;
    }

    printf("\nO arranjo possui %lld elementos. Deseja imprimi-lo mesmo assim? (1 - Sim / 0 - Nao): ", total_elementos);
    resposta = ler_inteiro();

    return resposta == 1;
}

// Aloca no heap (arranjos grandes nao cabem na pilha como VLA local)
void *alocar_memoria(size_t bytes)
{
    void *ponteiro = malloc(bytes);

    if (ponteiro == NULL)
    {
        printf("\nErro: memoria insuficiente para alocar o arranjo. Tente uma dimensao menor.\n");
    }

    return ponteiro;
}

void imprimir_integrantes(void)
{
    printf("==================================================\n");
    printf(" UNIPE - Complexidade e Computabilidade de Algoritmo\n");
    printf(" Prof. Carlos Herriot - Projeto AV01\n");
    printf("--------------------------------------------------\n");
    printf(" Integrantes:\n");
    printf("  Arthur Gomes de Albuquerque Labbe   (38291339)\n");
    printf("  Erickson Cezar Colicchio Junior     (33175233)\n");
    printf("  Gustavo Moreira de Queiroz          (39441229)\n");
    printf("  Joelson dos Santos Mendonca Junior  (40011089)\n");
    printf("  Pietro Santana Fragoso Vasconcelos  (38187515)\n");
    printf("  Saulo Contreras de Assis            (37851039)\n");
    printf("==================================================\n");
}

//-----------------------------------------------------------------------

// VETORES (FUNCOES 1, 4 E 5):

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
        V[i] = ler_inteiro();
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

//-----------------------------------------------------------------------

// MATRIZES (FUNCAO 2 E MATRIZ DINAMICA):

void preencher_matriz_aleatoria(int linhas, int colunas, int M[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            M[i][j] = rand() % 50; // Valores aleatórios entre 0 e 49
        }
    }
}

void preencher_matriz_manual(int linhas, int colunas, int M[linhas][colunas])
{
    for (int i = 0; i < linhas; i++)
    {
        for (int j = 0; j < colunas; j++)
        {
            printf("Digite o valor para a posicao [%d][%d]: ", i, j);
            M[i][j] = ler_inteiro();
        }
    }
}

void imprimir_matriz(int linhas, int colunas, int M[linhas][colunas])
{
    printf("\nMatriz Gerada (%dx%d):\n\n", linhas, colunas);
    for (int i = 0; i < linhas; i++)
    {
        printf("| ");
        for (int j = 0; j < colunas; j++)
        {
            printf("%3d ", M[i][j]);
        }
        printf(" |\n");
    }
}

// Pergunta linhas e colunas, cria a matriz dinamicamente e a preenche com valores aleatorios.
// O retorno deve ser usado como int (*M)[colunas] e liberado com free().
void *criar_matriz_dinamica(int *linhas, int *colunas)
{
    *linhas = ler_dimensao("Digite a quantidade de linhas: ");
    *colunas = ler_dimensao("Digite a quantidade de colunas: ");

    int (*M)[*colunas] = alocar_memoria(sizeof(int[*linhas][*colunas]));
    if (M != NULL)
    {
        preencher_matriz_aleatoria(*linhas, *colunas, M);
    }

    return M;
}

void executar_matriz_dinamica(void)
{
    int linhas, colunas;

    printf("\n--- Criacao de Matriz Dinamica Aleatoria ---\n\n");

    void *bloco = criar_matriz_dinamica(&linhas, &colunas);
    if (bloco == NULL)
    {
        return;
    }

    int (*M)[colunas] = bloco;
    if (confirmar_impressao((long long)linhas * colunas))
    {
        imprimir_matriz(linhas, colunas, M);
    }

    free(M);
}

//-----------------------------------------------------------------------

// MATRIZES TRIDIMENSIONAIS (FUNCAO 3):

void preencher_matriz_3d_aleatoria(int n, int M[n][n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                M[i][j][k] = rand() % 20; // Valores entre 0 e 19
            }
        }
    }
}

void preencher_matriz_3d_manual(int n, int M[n][n][n])
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                printf("Digite o valor para a posicao [%d][%d][%d]: ", i, j, k);
                M[i][j][k] = ler_inteiro();
            }
        }
    }
}

void imprimir_matriz_3d(int n, int M[n][n][n], const char *nome_matriz)
{
    printf("\n--- %s Gerada (%dx%dx%d) ---\n", nome_matriz, n, n, n);
    for (int i = 0; i < n; i++)
    {
        printf("Camada [%d]:\n", i);
        for (int j = 0; j < n; j++)
        {
            printf("| ");
            for (int k = 0; k < n; k++)
            {
                printf("%3d ", M[i][j][k]);
            }
            printf(" |\n");
        }
        printf("\n");
    }
}

//-----------------------------------------------------------------------

// FUNCAO 5:

// Algoritmo clássico de Busca Binária
int busca_binaria(int n, int V[n], int valor)
{
    int inicio = 0;
    int fim = n - 1;

    while (inicio <= fim)
    {
        int meio = inicio + (fim - inicio) / 2;

        if (V[meio] == valor)
        {
            return 1; // Encontrado
        }
        if (V[meio] < valor)
        {
            inicio = meio + 1; // Busca na metade direita
        }
        else
        {
            fim = meio - 1; // Busca na metade esquerda
        }
    }

    return 0; // Nao encontrado
}

// Garante que o vetor seja gerado em ordem estritamente crescente
void preencher_vetor_ordenado_aleatorio(int n, int V[n])
{
    V[0] = rand() % 10; // Primeiro valor
    for (int i = 1; i < n; i++)
    {
        // O próximo valor é sempre o anterior somado a um incremento aleatório (de 1 a 10)
        V[i] = V[i - 1] + (rand() % 10) + 1;
    }
}

int vetor_esta_ordenado(int n, int V[n])
{
    for (int i = 1; i < n; i++)
    {
        if (V[i - 1] > V[i])
        {
            return 0;
        }
    }

    return 1;
}

static int comparar_inteiros(const void *a, const void *b)
{
    int x = *(const int *)a;
    int y = *(const int *)b;

    return (x > y) - (x < y);
}

void ordenar_vetor(int n, int V[n])
{
    qsort(V, n, sizeof(int), comparar_inteiros);
}
