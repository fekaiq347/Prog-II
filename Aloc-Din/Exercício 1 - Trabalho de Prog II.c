//NOME: KAIQUE FABRICIO EUFRÁSIO
//DRE: 123228961

#include <stdio.h>
#include <stdlib.h>

// Função para calcular a maior soma dentro do lote
int maior_soma(int** matriz, int L, int C, int M, int N);

int main() {
    int L, C, M, N;
    int **matriz;
    
    // Variáveis para calcular as somas
    int soma = 0, soma_total = 0;

    // Definindo as variáveis
    printf("Digite os valores respectivos a L, C, M e N:\n");
    scanf("%d %d %d %d", &L, &C, &M, &N);

    // Alocando memória para o número de linhas
    matriz = (int**)malloc(L * sizeof(int*));
    if (matriz == NULL) {
        printf("Falha na alocação de memória.\n");
        return 1; // Saia do programa com um código de erro
    }

    // Alocando memória para o número de colunas
    for (int cont1 = 0; cont1 < L; cont1++) {
        matriz[cont1] = (int*)malloc(C * sizeof(int));
        if (matriz[cont1] == NULL) {
            printf("Falha na alocação de memória.\n");
            return 1; // Saia do programa com um código de erro
        }
    }

    // Preenchendo a matriz
    for (int cont1 = 0; cont1 < L; cont1++) {
        for (int cont2 = 0; cont2 < C; cont2++) {
            printf("Defina o valor da linha[%d] e coluna[%d]:\n", cont1 + 1, cont2 + 1);
            scanf("%d", &matriz[cont1][cont2]);
        }
    }

    // Chamando a função para calcular a maior soma
    int soma_maxima = maior_soma(matriz, L, C, M, N);
    printf("%d", soma_maxima);

    // Liberando a memória alocada para a matriz
    for (int cont1 = 0; cont1 < L; cont1++) {
        free(matriz[cont1]);
    }
    free(matriz);

    return 0;
}

// Função para calcular a maior soma dentro do lote
int maior_soma(int** matriz, int L, int C, int M, int N) {
    int soma_total = 0;

    // Loop para percorrer a matriz em lotes
    for (int cont1 = 0; cont1 < L; cont1 += M) {
        for (int cont2 = 0; cont2 < C; cont2 += N) {
            int soma = 0;
            // Loop para calcular a soma dentro do lote
            for (int cont3 = cont1; cont3 < cont1 + M; cont3++) {
                for (int cont4 = cont2; cont4 < cont2 + N; cont4++) {
                    soma += matriz[cont3][cont4];
                    if (soma_total < soma) {
                        soma_total = soma;
                    }
                }
            }
        }
    }

    return soma_total;
}
