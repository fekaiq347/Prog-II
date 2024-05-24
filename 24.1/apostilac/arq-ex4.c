#include <stdio.h>
#define TAM_MAX 80

int main(int argc, char *argv[]) {

    if (argc != 2) {
        printf("Numero de argumentos invalido.\n");
        return 1;
    }

    FILE *bf;
    if ((bf = fopen(argv[1], "r")) == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int v[TAM_MAX];
    double soma = 0, qtd = 0, resultado;

    for (int i = 0; i < TAM_MAX && (fscanf(bf, "%d", &v[i])) == 1; i++) {
        soma += v[i];
        qtd++;
    }

    if (qtd != 0) {
        resultado = soma / qtd;
        printf("%lf", resultado);
    } else {
        printf("Nenhum número foi lido do arquivo.\n");
    }
    
    return 0;
}