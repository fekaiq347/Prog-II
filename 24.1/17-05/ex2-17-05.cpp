#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
} REGISTRO;

typedef struct {
    REGISTRO A[MAX];
    int topo;
} PILHA;

void inicializarPilha(PILHA* p) {
    p -> topo = -1;
}

int tamanhoPilha(PILHA* p) {
    return p -> topo + 1;
}

bool inserirElementoPilha(PILHA* p, REGISTRO reg) {
    if (p -> topo >= MAX - 1) return false;
    p -> topo = p -> topo + 1;
    p -> A[p -> topo] = reg;
    return true; 
}

bool excluirElementoPilha(PILHA* p, REGISTRO* reg) {
    if (p -> topo == -1) return false;
    *reg = p -> A[p -> topo];
    p -> topo = p -> topo - 1;
    return true;
}

int calcular(REGISTRO* a, REGISTRO* b, REGISTRO* resultado, char op) {
    switch (op) {
        case '+': return a -> chave + b -> chave;
        case '-': return a -> chave - b -> chave;
        case '*': return a -> chave * b -> chave;
        case '/': return a -> chave / b -> chave;
        default: return 0; 
    }
}

int main() {

    FILE *file = fopen("arq.txt", "r");

    if (!file) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    PILHA pilha;
    char linha[MAX];
    REGISTRO a, b, l, resultado;

    fgets(linha, MAX, file);

    for (int i = 0; i < strlen(linha); i++) {
        if (linha[i] >= '0'&& linha[i] <= '9') {
            l.chave = linha[i] - '0';
            inserirElementoPilha(&pilha, l);
        }
        else if (linha[i] == '+' || linha[i] == '-' || linha[i] == '*' || linha[i] == '/') {
            excluirElementoPilha(&pilha, &a);
            excluirElementoPilha(&pilha, &b);
            calcular(&a, &b, &resultado, linha[i]);
            inserirElementoPilha(&pilha, resultado);
        }
    }

    printf("Resultado: %d\n", resultado.chave);
    fclose(file);

    return 0;
}