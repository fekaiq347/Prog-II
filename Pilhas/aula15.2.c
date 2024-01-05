// Aluno: Kaique Fabricio Eufrásio - DRE: 123228961
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct numero{
    int n;
    struct numero *proximo;
} Numero;

typedef struct {
    Numero *topo;
} Pilha;


void inicializa_pilha(Pilha *p) {
    p -> topo = NULL;
}

int pilha_vazia(Pilha *p) {
    return p -> topo == NULL;
}

void empilha(Pilha *p, int valor) {
    Numero *novo = malloc(sizeof(Numero));

    if(novo) {
        novo -> proximo = p -> topo;
        novo -> n = valor;
        p -> topo = novo;
    }
    else
        printf("Erro ao alocar memoria\n");
}

int desempilha(Pilha *p) {
    if (!pilha_vazia(p)){
        Numero *aux1 = p ->topo;
        int aux2 = aux1 -> n;
        p -> topo = aux1 -> proximo;
        free(aux1);
        return aux2;
    }
    else{
        printf("Pilha vazia\n");
        return 1;
    }
}

int main() {

    int n1, n2;
    Pilha p;

    inicializa_pilha(&p);

    FILE *f = fopen("arquivo_entrada", "r");
    if (!f) {
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    char entrada[100];

    while (fgets(entrada, 100, f)){
        printf("%s", entrada);
    }

    for (int i = 0; i < 100; i++) {
        int aux;
        
        if (entrada[i] == '\0')
            break;

        if (entrada[i] == ' ')
            continue;

        if (isdigit(entrada[i])){ 
            aux = atoi(&entrada[i]);
            empilha(&p, aux);
        }
        else if(entrada[i] == '+' || entrada[i] == '-' || entrada[i] == '*' || entrada[i] == '/'){ // Added missing conditions
            n1 = desempilha(&p);
            n2 = desempilha(&p);
            switch (entrada[i]) {
                case '+':
                    empilha(&p, n2 + n1);
                    break;
                case '-':
                    empilha(&p, n2 - n1);
                    break;
                case '*':
                    empilha(&p, n2 * n1);
                    break;
                case '/':
                    empilha(&p, n2 / n1);
                    break;
            }
        }
        
    }

    printf("Resultado: %d\n", desempilha(&p));

    return 0;
}
