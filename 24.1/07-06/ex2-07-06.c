#include <stdio.h>
#include <stdlib.h>

#define ll long long
#define true 1
#define false 0

typedef int bool;
typedef int TIPOCHAVE;

typedef struct {
    TIPOCHAVE chave;
    char nome[100];
    int segundo_chegada;
    int numero_produtos;
    int tempo_saida;
} REGISTRO;

typedef struct aux {
    REGISTRO reg;
    struct aux* prox;
} ELEMENTO;

typedef ELEMENTO* PONT;

typedef struct {
    PONT inicio;
} LISTA;

void inicializarLista(LISTA* l) {
    l->inicio = NULL;
}

int tamanho(LISTA* l) {
    PONT end = l->inicio;
    int tam = 0;
    while (end != NULL) {
        tam++;
        end = end->prox;
    }
    return tam;
}

void exibirLista(LISTA* l) {
    PONT end = l->inicio;
    printf("Lista: \" ");
    while (end != NULL) {
        printf("%i ", end->reg.chave);
        end = end->prox;
    }
    printf("\"\n");
}

bool insere(LISTA* l, REGISTRO reg, int pos) {
    if (pos < 0 || pos > tamanho(l)) return false;
    ELEMENTO* novo = (ELEMENTO*) malloc(sizeof(ELEMENTO));
    novo->reg = reg;
    int i;
    ELEMENTO* p;
    if (pos == 0) {
        novo->prox = l->inicio;
        l->inicio = novo;
    } else {
        p = l->inicio;
        for (i = 0; i < pos - 1; i++) p = p->prox;
        novo->prox = p->prox;
        p->prox = novo;
    }
    return true;
}

bool exclui(LISTA* l, int pos) {
    if (pos < 0 || pos > tamanho(l) - 1) return false;
    int i;
    ELEMENTO* p;
    ELEMENTO* apagar;
    if (pos == 0) {
        apagar = l->inicio;
        l->inicio = apagar->prox;
    } else {
        p = l->inicio;
        for (i = 0; i < pos - 1; i++) p = p->prox;
        apagar = p->prox;
        p->prox = apagar->prox;
    }

    printf("%s %d %d\n", apagar->reg.nome, apagar->reg.segundo_chegada, apagar->reg.tempo_saida);

    free(apagar);
    return true;
}

void reinicializarFila(LISTA* l) {
    PONT end = l->inicio;
    while (end != NULL) {
        PONT apagar = end;
        end = end->prox;
        free(apagar);
    }
    l->inicio = NULL;
}

int main() {

    ll k, c;
    scanf("%lld", &k);
    scanf("%lld", &c);

    LISTA *l= malloc(sizeof(LISTA));
    inicializarLista(l);

    for (ll i = 0; i < c; i++) {
        REGISTRO reg;
        
        scanf("%s", reg.nome);
        scanf("%d", &reg.segundo_chegada);
        scanf("%d", &reg.numero_produtos);

        reg.tempo_saida = reg.segundo_chegada + 10 + reg.numero_produtos * k;
        reg.chave = i;

        insere(l, reg, i);
    }

    printf("\n");

    for (ll i = 0; i < c; i++) {
        exclui(l, 0);
    }

    free(l);

    return 0;
}