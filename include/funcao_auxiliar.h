#ifndef FUNCAO_AUXILIAR_H
#define FUNCAO_AUXILIAR_H

// Funcoes para Vetores (Funcao 1)
void preencher_vetor_aleatorio(int n, int V[n]);
void preencher_vetor_manual(int n, int V[n]);
void imprimir_vetor(int n, int V[n]);

// Funcoes para Matrizes Quadradas (Funcao 2)
void preencher_matriz_aleatoria(int n, int M[n][n]);
void preencher_matriz_manual(int n, int M[n][n]);
void imprimir_matriz(int n, int M[n][n]);

// Funcoes para Matrizes Tridimensionais (Funcao 3)
void preencher_matriz_3d_aleatoria(int n, int M[n][n][n]);
void preencher_matriz_3d_manual(int n, int M[n][n][n]);
void imprimir_matriz_3d(int n, int M[n][n][n], const char *nome_matriz);

#endif