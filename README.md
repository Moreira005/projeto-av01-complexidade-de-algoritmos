# Projeto AV01 — Complexidade e Computabilidade de Algoritmos

> Software em C contendo 5 funções analíticas com avaliação de complexidade algorítmica ($O$), expressões matemáticas e cálculo de tempo estimado de execução em hardware teórico ($10^8$ instruções/s).

---

## 📌 Informações Gerais

- **Instituição:** Centro Universitário de João Pessoa (UNIPÊ)
- **Disciplina:** Complexidade e Computabilidade de Algoritmo
- **Docente:** Prof. Carlos Herriot
- **Avaliação:** Projeto - AV01

---

## 👥 Membros da Equipe

> ⚠️ **Atenção:** Todos os 6 membros devem ser listados abaixo e no cabeçalho dos ficheiros fonte antes do envio final.

| N.º | Nome Completo                          |    RGM     | Função / Responsabilidade               |
| :-: | :------------------------------------- | :--------: | :-------------------------------------- |
|  1  | **Arthur Gomes de Albuquerque Labbê**  | `38291339` | Desenvolvedor / Análise de Complexidade |
|  2  | **Erickson Cezar Colicchio Junior**    | `33175233` | Desenvolvedor / Análise de Complexidade |
|  3  | **Gustavo Moreira de Queiroz**         | `39441229` | Desenvolvedor / Análise de Complexidade |
|  4  | **Joelson dos Santos Mendonça Junior** | `40011089` | Desenvolvedor / Análise de Complexidade |
|  5  | **Pietro Santana Fragoso Vasconcelos** | `38187515` | Desenvolvedor / Análise de Complexidade |
|  6  | **Saulo Contreras de Assis**           | `37851039` | Desenvolvedor / Análise de Complexidade |

---

## 🎯 Objetivo do Projeto

Desenvolver uma aplicação interativa via linha de comando (CLI) na linguagem **C (padrão C99)** que disponibilize um menu com 5 funções analíticas de dados/arranjos. Além da implementação do código funcional, o projeto exige:

1. Implementação das funções em **pseudocódigo**.
2. Análise da complexidade de linha a linha.
3. Dedução da **expressão de complexidade** $T(n)$ e classificação na notação **Big-O** ($O$).
4. **Cálculo teórico de tempo de execução** considerando um processador com capacidade de $10^8$ instruções por segundo ($100 \text{ MIPS}$).

---

## 📋 Especificação das Funções

### 1️⃣ Função 1: Contagem de Ocorrências Distintas

- **Descrição:** Recebe um vetor principal de inteiros de tamanho $n$ e um vetor de busca de tamanho $k$. Percorre a lista de $k$ elementos e conta a quantidade total de aparições acumuladas no vetor de tamanho $n$.
- **Cálculo de Tempo:** $n = 50.000$ e $k = 4.000$.

### 2️⃣ Função 2: Análise de Pares em Matriz Triangular

- **Descrição:** Recebe uma matriz quadrada de inteiros $n \times n$. Avalia todos os elementos da diagonal principal e da metade superior em relação aos seus opostos na metade inferior ($A[i][j] + A[j][i]$). Incrementa um contador sempre que a soma for um número múltiplo de 5.
- **Cálculo de Tempo:** $n = 500$.

### 3️⃣ Função 3: Comparação de Matrizes Tridimensionais

- **Descrição:** Recebe dois arranjos tridimensionais de inteiros $A$ e $B$ de dimensões $n \times n \times n$. Performa o somatório completo de $A$ e de $B$, retornando `1` se $\text{soma}(A) \ge \text{soma}(B)$ e `0` caso contrário.
- **Cálculo de Tempo:** $n = 300$.

### 4️⃣ Função 4: Análise de Casos Assimétricos no Condicional

- **Descrição:** Percorre um vetor de inteiros de tamanho $n$. Para elementos **pares**, adiciona o valor diretamente a um somatório. Para elementos **ímpares**, calcula o fatorial do número e adiciona o resultado ao somatório.
- **Cálculo de Tempo:** $n = 50.000$ _(no pior caso)_.

### 5️⃣ Função 5: Contagem de Elementos Presentes em Vetor Ordenado

- **Descrição:** Utiliza uma função auxiliar de **Busca Binária**. Dado um vetor $A$ não ordenado ($n$) e um vetor $B$ ordenado ($n$), realiza a busca de cada elemento de $A$ dentro de $B$ e retorna a quantidade de sucessos encontrados.
- **Cálculo de Tempo:** $n = 10.000.000$.

---

## ⚙️ Diretrizes de Implementação e Alocação de Memória

- **Alocação Dinâmica / VLAs:** Uso do padrão **C99 (Variable Length Arrays)** para alocação flexível de matrizes e vetores através de parâmetros:

  ```c
  void exemplo(int n, int M[n][n]);
  ```

  ## 📄 Para mais detalhes

  acesse o [documento original do professor](./docs/Projeto_AV01.docx).

# ↓ 💻 COMO COMPILAR O PROJETO ↓

## 1. Ferramentas Necessárias

Para compilar e executar o projeto, você precisará ter o seguinte ambiente configurado:

- **Compilador C:** GCC (GNU Compiler Collection) ou MinGW (para Windows).
- **Ambiente de Desenvolvimento:** DEV C++, Code Blocks, Visual Studio Code (VS Code) ou qualquer outra IDE de sua preferência.
- **Terminal:** Prompt de Comando (Windows), PowerShell ou terminal Linux/macOS.

## 2. Como Compilar e Executar o Projeto

Como o projeto está modularizado e separado em diretórios (`src` e `include`), a compilação requer a indicação dos caminhos dos arquivos.

**Passo 1: Abra o terminal na pasta raiz do projeto (`projeto-av01-complexidade-de-algoritmos`).**

**Passo 2: Execute o comando de compilação:**

```bash
gcc src/*.c -I include -o programa
```

**Passo 3: Execute o comando para iniciar o programa:**

```bash
No Windows: .\programa.exe

No Linux/Mac: ./programa
```
