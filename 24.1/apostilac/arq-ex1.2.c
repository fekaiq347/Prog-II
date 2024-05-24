#include <stdio.h>

int main() {

    FILE *pa;
    int c, qtd = 0;

    if ((pa = fopen("arquivo.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo para escrita.\n");
        return 0;
    }
    
    while ((c = fgetc(pa)) != EOF) {
        qtd++;
    }

    printf("%d", qtd);

    return 0;
}