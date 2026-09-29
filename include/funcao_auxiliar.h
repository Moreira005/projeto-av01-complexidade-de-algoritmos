#ifndef FUNCAO_AUXILIAR_H
#define FUNCAO_AUXILIAR_H

#include <stddef.h>

// Funcoes de Entrada e Memoria (usadas por todas as funcoes)
int ler_inteiro(void);
int ler_dimensao(const char *mensagem);
int escolher_preenchimento(const char *nome_arranjo);
int confirmar_impressao(long long total_elementos);
void *alocar_memoria(size_t bytes);
void imprimir_integrantes(void);

// Funcoes para Vetores (Funcoes 1, 4 e 5)
void preencher_vetor_aleatorio(int n, int V[n]);
void preencher_vetor_manual(int n, int V[n]);
void imprimir_vetor(int n, int V[n]);

// Funcoes para Matrizes (Funcao 2 e Matriz Dinamica)
void preencher_matriz_aleatoria(int linhas, int colunas, int M[linhas][colunas]);
void preencher_matriz_manual(int linhas, int colunas, int M[linhas][colunas]);
void imprimir_matriz(int linhas, int colunas, int M[linhas][colunas]);
void *criar_matriz_dinamica(int *linhas, int *colunas);
void executar_matriz_dinamica(void);

// Funcoes para Matrizes Tridimensionais (Funcao 3)
void preencher_matriz_3d_aleatoria(int n, int M[n][n][n]);
void preencher_matriz_3d_manual(int n, int M[n][n][n]);
void imprimir_matriz_3d(int n, int M[n][n][n], const char *nome_matriz);

// Funcoes para a Funcao 5
int busca_binaria(int n, int V[n], int valor);
void preencher_vetor_ordenado_aleatorio(int n, int V[n]);
int vetor_esta_ordenado(int n, int V[n]);
void ordenar_vetor(int n, int V[n]);

#endif
