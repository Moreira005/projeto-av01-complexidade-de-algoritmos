# Projeto AV01 — Pseudocódigos, Complexidade e Tempo de Execução

**Instituição:** Centro Universitário de João Pessoa (UNIPÊ)
**Disciplina:** Complexidade e Computabilidade de Algoritmo
**Docente:** Prof. Carlos Herriot

**Integrantes:**

| N.º | Nome Completo                      |   RGM    |
| :-: | :--------------------------------- | :------: |
|  1  | Arthur Gomes de Albuquerque Labbê  | 38291339 |
|  2  | Erickson Cezar Colicchio Junior    | 33175233 |
|  3  | Gustavo Moreira de Queiroz         | 39441229 |
|  4  | Joelson dos Santos Mendonça Junior | 40011089 |
|  5  | Pietro Santana Fragoso Vasconcelos | 38187515 |
|  6  | Saulo Contreras de Assis           | 37851039 |

---

## Convenções adotadas

- Cada linha do pseudocódigo tem custo 1 por execução. A coluna **Custo** indica quantas vezes a linha é executada.
- Um laço `para i de a até b` testa sua condição uma vez a mais do que executa o corpo (o último teste é o que encerra o laço). Ex.: `para i de 0 até n-1` executa o teste `n + 1` vezes e o corpo `n` vezes.
- Linhas `senão`, `fim-se` e `fim-para` não têm custo próprio.
- A análise é feita para o **pior caso**.
- Tempo de execução: `tempo = T(entrada) / 10^8` segundos (computador que realiza 10^8 instruções por segundo).
- `log2` é o logaritmo na base 2 e `piso(x)` é o maior inteiro menor ou igual a `x`.

---

## Função 1 — Contagem de Ocorrências Distintas

Código: `contar_ocorrencias` em `src/funcao1.c`.

### Pseudocódigo

```
função contar_ocorrencias(V[0..n-1], n, B[0..k-1], k)
1   total ← 0
2   para i de 0 até k-1 faça
3       para j de 0 até n-1 faça
4           se V[j] = B[i] então
5               total ← total + 1
6   retorne total
```

### Complexidade por linha

| Linha | Comando                     | Custo     |
| :---: | :-------------------------- | :-------- |
|   1   | `total ← 0`                 | 1         |
|   2   | `para i de 0 até k-1`       | k + 1     |
|   3   | `para j de 0 até n-1`       | k(n + 1)  |
|   4   | `se V[j] = B[i]`            | kn        |
|   5   | `total ← total + 1`         | kn        |
|   6   | `retorne total`             | 1         |

Pior caso: todos os elementos de `V` são iguais aos buscados, então a linha 5 executa sempre.

### Expressão de complexidade

```
T(n, k) = 1 + (k + 1) + k(n + 1) + kn + kn + 1
        = 1 + k + 1 + kn + k + 2kn + 1
T(n, k) = 3nk + 2k + 3
```

**Big O:** `O(n · k)`

### Cálculo de tempo (n = 50.000 e k = 4.000)

```
T = 3 · 50.000 · 4.000 + 2 · 4.000 + 3
  = 600.000.000 + 8.000 + 3
  = 600.008.003 instruções

tempo = 600.008.003 / 10^8 ≈ 6,00 segundos
```

---

## Função 2 — Análise de Pares em Matriz Triangular

Código: `analisar_matriz_triangular` em `src/funcao2.c`.

### Pseudocódigo

```
função analisar_matriz_triangular(A[0..n-1][0..n-1], n)
1   contador ← 0
2   para i de 0 até n-1 faça
3       para j de i até n-1 faça
4           soma ← A[i][j] + A[j][i]
5           se soma mod 5 = 0 então
6               contador ← contador + 1
7   retorne contador
```

O laço interno começa em `j = i`, então percorre apenas a diagonal principal (`j = i`) e a metade superior (`j > i`), comparando cada elemento com o seu oposto `A[j][i]`.

### Repetições do laço interno (não regular)

Para cada `i`, o corpo do laço interno executa `n - i` vezes:

| i          | 0 | 1     | 2     | ... | n-1 |
| :--------- |:-:| :---: | :---: | :-: | :-: |
| repetições | n | n - 1 | n - 2 | ... | 1   |

```
Soma das repetições = n + (n-1) + ... + 2 + 1 = n(n + 1) / 2
```

O teste do laço interno executa uma vez a mais para cada `i`:

```
Soma dos testes = Σ (n - i + 1), i = 0..n-1 = n(n + 1)/2 + n = (n² + 3n) / 2
```

### Complexidade por linha

| Linha | Comando                         | Custo           |
| :---: | :------------------------------ | :-------------- |
|   1   | `contador ← 0`                  | 1               |
|   2   | `para i de 0 até n-1`           | n + 1           |
|   3   | `para j de i até n-1`           | (n² + 3n) / 2   |
|   4   | `soma ← A[i][j] + A[j][i]`      | n(n + 1) / 2    |
|   5   | `se soma mod 5 = 0`             | n(n + 1) / 2    |
|   6   | `contador ← contador + 1`       | n(n + 1) / 2    |
|   7   | `retorne contador`              | 1               |

Pior caso: todas as somas são múltiplas de 5, então a linha 6 executa sempre.

### Expressão de complexidade

```
T(n) = 1 + (n + 1) + (n² + 3n)/2 + 3 · n(n + 1)/2 + 1
     = n + 3 + (n² + 3n + 3n² + 3n) / 2
     = n + 3 + (4n² + 6n) / 2
     = n + 3 + 2n² + 3n
T(n) = 2n² + 4n + 3
```

**Big O:** `O(n²)`

### Cálculo de tempo (n = 500)

```
T = 2 · 500² + 4 · 500 + 3
  = 500.000 + 2.000 + 3
  = 502.003 instruções

tempo = 502.003 / 10^8 ≈ 0,00502 segundos (≈ 5,02 milissegundos)
```

---

## Função 3 — Comparação de Matrizes Tridimensionais

Código: `comparar_matrizes_3d` em `src/funcao3.c`.

### Pseudocódigo

```
função comparar_matrizes_3d(A[n][n][n], B[n][n][n], n)
1   somaA ← 0
2   somaB ← 0
3   para i de 0 até n-1 faça
4       para j de 0 até n-1 faça
5           para k de 0 até n-1 faça
6               somaA ← somaA + A[i][j][k]
7   para i de 0 até n-1 faça
8       para j de 0 até n-1 faça
9           para k de 0 até n-1 faça
10              somaB ← somaB + B[i][j][k]
11  escreva somaA
12  escreva somaB
13  se somaA ≥ somaB então
14      retorne 1
    senão
15      retorne 0
```

### Complexidade por linha

| Linha | Comando                          | Custo       |
| :---: | :------------------------------- | :---------- |
|   1   | `somaA ← 0`                      | 1           |
|   2   | `somaB ← 0`                      | 1           |
|   3   | `para i de 0 até n-1`            | n + 1       |
|   4   | `para j de 0 até n-1`            | n(n + 1)    |
|   5   | `para k de 0 até n-1`            | n²(n + 1)   |
|   6   | `somaA ← somaA + A[i][j][k]`     | n³          |
|   7   | `para i de 0 até n-1`            | n + 1       |
|   8   | `para j de 0 até n-1`            | n(n + 1)    |
|   9   | `para k de 0 até n-1`            | n²(n + 1)   |
|  10   | `somaB ← somaB + B[i][j][k]`     | n³          |
|  11   | `escreva somaA`                  | 1           |
|  12   | `escreva somaB`                  | 1           |
|  13   | `se somaA ≥ somaB`               | 1           |
| 14/15 | `retorne 1` ou `retorne 0`       | 1           |

Esta função não tem pior ou melhor caso: os dois arranjos são sempre percorridos por completo.

### Expressão de complexidade

Cada bloco de três laços (linhas 3–6 e 7–10) custa:

```
(n + 1) + n(n + 1) + n²(n + 1) + n³
  = n + 1 + n² + n + n³ + n² + n³
  = 2n³ + 2n² + 2n + 1
```

```
T(n) = 2 + 2 · (2n³ + 2n² + 2n + 1) + 1 + 1 + 1 + 1
     = 2 + 4n³ + 4n² + 4n + 2 + 4
T(n) = 4n³ + 4n² + 4n + 8
```

**Big O:** `O(n³)`

### Cálculo de tempo (n = 300)

```
T = 4 · 300³ + 4 · 300² + 4 · 300 + 8
  = 108.000.000 + 360.000 + 1.200 + 8
  = 108.361.208 instruções

tempo = 108.361.208 / 10^8 ≈ 1,08 segundo
```

---

## Função 4 — Análise de Casos Assimétricos no Condicional

Código: `processar_vetor` e a auxiliar `calcular_fatorial` em `src/funcao4.c`.

### Pseudocódigo

```
função calcular_fatorial(m)
1   se m < 0 então
2       retorne 0
3   fat ← 1
4   para i de 2 até m faça
5       fat ← fat · i
6   retorne fat

função processar_vetor(V[0..n-1], n)
7   somatorio ← 0
8   para i de 0 até n-1 faça
9       se V[i] mod 2 = 0 então
10          somatorio ← somatorio + V[i]
        senão
11          somatorio ← somatorio + calcular_fatorial(V[i])
12  retorne somatorio
```

### Complexidade de `calcular_fatorial(m)` (m ≥ 1)

| Linha | Comando                  | Custo   |
| :---: | :----------------------- | :------ |
|   1   | `se m < 0`               | 1       |
|   2   | `retorne 0`              | 0       |
|   3   | `fat ← 1`                | 1       |
|   4   | `para i de 2 até m`      | m       |
|   5   | `fat ← fat · i`          | m - 1   |
|   6   | `retorne fat`            | 1       |

O laço vai de 2 até m, então o corpo executa `m - 1` vezes e o teste executa `m` vezes.

```
F(m) = 1 + 1 + m + (m - 1) + 1 = 2m + 2      →  O(m)
```

### Casos assimétricos

O custo de cada iteração depende do ramo do `se`:

- **Elemento par:** apenas uma soma. Custo constante (1).
- **Elemento ímpar:** chama o fatorial, que custa `F(m) = 2m + 2`, mais a soma. Custo `2m + 3`, que cresce com o **valor** `m` do elemento.

### Complexidade por linha de `processar_vetor`

Seja `p` a quantidade de pares e `q = n - p` a de ímpares.

| Linha | Comando                                           | Custo (geral)         | Pior caso (todos ímpares, valor m) |
| :---: | :------------------------------------------------ | :-------------------- | :--------------------------------- |
|   7   | `somatorio ← 0`                                   | 1                     | 1                                  |
|   8   | `para i de 0 até n-1`                             | n + 1                 | n + 1                              |
|   9   | `se V[i] mod 2 = 0`                               | n                     | n                                  |
|  10   | `somatorio ← somatorio + V[i]`                    | p                     | 0                                  |
|  11   | `somatorio ← somatorio + calcular_fatorial(V[i])` | Σ (1 + F(V[i])) nos q ímpares | n(1 + 2m + 2) = n(2m + 3)  |
|  12   | `retorne somatorio`                               | 1                     | 1                                  |

### Expressão de complexidade

**Melhor caso** (todos pares):

```
T(n) = 1 + (n + 1) + n + n + 1 = 3n + 3      →  O(n)
```

**Pior caso** (todos ímpares, de valor m):

```
T(n, m) = 1 + (n + 1) + n + 0 + n(2m + 3) + 1
        = 2nm + 5n + 3
```

**Big O (pior caso):** `O(n · m)`, onde `m` é o maior valor ímpar do vetor.

Como o fatorial é guardado em `unsigned long long` (64 bits), o maior fatorial representável é 20!. Assim, o maior ímpar válido é **m = 19** (21! já estoura). Com `m` limitado por essa constante, o pior caso fica **linear em n**:

```
T(n) = 2n · 19 + 5n + 3 = 43n + 3      →  O(n)
```

### Cálculo de tempo (n = 50.000, pior caso)

Com todos os elementos ímpares e iguais a 19, o maior ímpar cujo fatorial cabe em 64 bits:

```
T = 43 · 50.000 + 3
  = 2.150.003 instruções

tempo = 2.150.003 / 10^8 ≈ 0,0215 segundo (≈ 21,5 milissegundos)
```

> Observação: no preenchimento aleatório o programa gera valores de 0 a 11, então o maior ímpar é m = 11. Nesse cenário, `T = 2 · 50.000 · 11 + 5 · 50.000 + 3 = 1.350.003` instruções, cerca de 13,5 milissegundos.

---

## Função 5 — Contagem de Elementos Presentes em Vetor Ordenado

Código: `contar_elementos_encontrados` em `src/funcao5.c` e a auxiliar `busca_binaria` em `src/funcao_auxiliar.c`.

### Pseudocódigo

```
função busca_binaria(V[0..n-1], n, x)
1   inicio ← 0
2   fim ← n - 1
3   enquanto inicio ≤ fim faça
4       meio ← inicio + (fim - inicio) / 2
5       se V[meio] = x então
6           retorne 1
7       se V[meio] < x então
8           inicio ← meio + 1
        senão
9           fim ← meio - 1
10  retorne 0

função contar_elementos_encontrados(A[0..n-1], B[0..n-1], n)
11  contador ← 0
12  para i de 0 até n-1 faça
13      se busca_binaria(B, n, A[i]) = 1 então
14          contador ← contador + 1
15  retorne contador
```

### Complexidade de `busca_binaria` (pior caso: elemento não encontrado)

A cada iteração o intervalo de busca cai pela metade. No pior caso o laço executa

```
L = piso(log2 n) + 1   iterações
```

| Linha | Comando                                   | Custo  |
| :---: | :---------------------------------------- | :----- |
|   1   | `inicio ← 0`                              | 1      |
|   2   | `fim ← n - 1`                             | 1      |
|   3   | `enquanto inicio ≤ fim`                   | L + 1  |
|   4   | `meio ← inicio + (fim - inicio) / 2`      | L      |
|   5   | `se V[meio] = x`                          | L      |
|   6   | `retorne 1`                               | 0      |
|   7   | `se V[meio] < x`                          | L      |
|  8/9  | `inicio ← meio + 1` ou `fim ← meio - 1`   | L      |
|  10   | `retorne 0`                               | 1      |

```
Bb(n) = 1 + 1 + (L + 1) + L + L + L + L + 1
      = 5L + 4
      = 5 · (piso(log2 n) + 1) + 4
Bb(n) = 5 · piso(log2 n) + 9      →  O(log n)
```

O pior caso da busca é **não encontrar** o elemento. Quando ele é encontrado, a busca termina antes: no máximo `5L + 1` instruções, e somando o incremento da linha 14 são `5L + 2`, ainda menos que `5L + 4`.

### Complexidade por linha de `contar_elementos_encontrados`

Pior caso: nenhum elemento de `A` está em `B`, então todas as buscas custam `Bb(n)` e a linha 14 nunca executa.

| Linha | Comando                                  | Custo              |
| :---: | :--------------------------------------- | :----------------- |
|  11   | `contador ← 0`                           | 1                  |
|  12   | `para i de 0 até n-1`                    | n + 1              |
|  13   | `se busca_binaria(B, n, A[i]) = 1`       | n · (1 + Bb(n))    |
|  14   | `contador ← contador + 1`                | 0                  |
|  15   | `retorne contador`                       | 1                  |

### Expressão de complexidade

```
T(n) = 1 + (n + 1) + n · (1 + 5 · piso(log2 n) + 9) + 0 + 1
     = n + 3 + n · (5 · piso(log2 n) + 10)
T(n) = n · (5 · piso(log2 n) + 11) + 3
```

**Big O:** `O(n log n)`

### Cálculo de tempo (n = 10.000.000)

```
log2(10.000.000) ≈ 23,25   →   piso(log2 n) = 23   (2^23 = 8.388.608 ≤ 10^7 < 2^24)

T = 10.000.000 · (5 · 23 + 11) + 3
  = 10.000.000 · 126 + 3
  = 1.260.000.003 instruções

tempo = 1.260.000.003 / 10^8 ≈ 12,6 segundos
```

---

## Resumo

| Função | Expressão de complexidade (pior caso)  | Big O        | Entrada               | Instruções    | Tempo (10^8 instr/s) |
| :----: | :------------------------------------- | :----------- | :-------------------- | ------------: | -------------------: |
|   1    | T(n, k) = 3nk + 2k + 3                 | O(n · k)     | n = 50.000; k = 4.000 | 600.008.003   | ≈ 6,00 s             |
|   2    | T(n) = 2n² + 4n + 3                    | O(n²)        | n = 500               | 502.003       | ≈ 5,02 ms            |
|   3    | T(n) = 4n³ + 4n² + 4n + 8              | O(n³)        | n = 300               | 108.361.208   | ≈ 1,08 s             |
|   4    | T(n, m) = 2nm + 5n + 3 (m = 19 → 43n + 3) | O(n · m) → O(n) | n = 50.000      | 2.150.003     | ≈ 21,5 ms            |
|   5    | T(n) = n(5 · piso(log2 n) + 11) + 3    | O(n log n)   | n = 10.000.000        | 1.260.000.003 | ≈ 12,6 s             |
