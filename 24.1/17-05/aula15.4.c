// Aluno: Kaique Fabricio Eufrásio - DRE: 123228961
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 1000

typedef struct {
    char caractere;
    int indice;
} ItemPilha;

typedef struct {
    ItemPilha *itens;
    int tamanho;
    int topo;
} Pilha;

Pilha *criarPilha(int tamanho) {
    Pilha *p = malloc(sizeof(Pilha));
    p -> tamanho = tamanho;
    p -> itens = (ItemPilha *)malloc(sizeof(ItemPilha) * tamanho);
    p -> topo = -1;
    return p;
}

void destruirPilha(Pilha *p) {
    free(p -> itens);
    free(p);
}

void empilhar (Pilha *p, char caractere, int indice) {
    if (p -> topo < p -> tamanho - 1) {
        p -> topo++;
        p -> itens[p -> topo].caractere = caractere;
        p -> itens[p -> topo].indice = indice;
    }
}

ItemPilha desempilhar(Pilha *p) {
    ItemPilha item = { '\0', -1 };
    if (p -> topo >= 0) {
        item = p -> itens[p -> topo];
        p -> topo--;
    }
    return item;
}

bool expressaoBalanceada(const char *expressao){
    Pilha *p = criarPilha(strlen(expressao));

    for (int i = 0; expressao[i] != '\0'; i++) {
        char caractere = expressao[i];
        switch (caractere) {
            case '(':
            case '[':
            case '{':
                empilhar(p, caractere, i);
                break;
            case ')':
            case ']':
            case '}':
                if (p -> topo == -1) {
                    printf("Erro: excesso de %c na posição %d\n", caractere, i);
                    destruirPilha(p);
                    return false;
                }
                ItemPilha item = desempilhar(p);
                if ((caractere == ')' && item.caractere != '(') ||
                    (caractere == ']' && item.caractere != '[') ||
                    (caractere == '}' && item.caractere != '{')) {
                    printf("Erro: esperado %c na posição %d\n", caractere, i);
                    printf("Erro: encontrado %c na posição %d\n", item.caractere, item.indice);
                    destruirPilha(p);
                    return false;
                }
                break;
            default:
                break;
        }
    }

    bool balanceada = p -> topo == -1;
    destruirPilha(p);
    return balanceada;
}

int main() {

    char expressao[MAX];

    printf("Escreva suas expressão matemática abaixo:\n");
    fgets(expressao, sizeof(expressao), stdin);

    if (expressaoBalanceada(expressao)) {
        printf("Expressão balanceada!\n");
    } else {
        printf("Expressão não balanceada!\n");
    }

    return 0;
}