#include <stdio.h>
#include <stdlib.h>

int main () {

    FILE *arq;
    char c, arq_nome[100];

    scanf("%s", arq_nome[100]);

    arq = fopen (arq_nome, "r");

    if (arq == NULL) {
        printf("Arquivo nao pode ser aberto.\n");
        return -1;
    }

    int a = 0, e = 0, i = 0, o = 0, u = 0;

    while ((c = fgetc(arq)) != EOF) {
        if (c == 'a' || c == 'A') {
            a++;
        } else if (c == 'e' || c == 'E') {
            e++;
        } else if (c == 'i' || c == 'I') {
            i++;
        } else if (c == 'o' || c == 'O') {
            o++;
        } else if (c == 'u' || c == 'U') {
            u++;
        }
    }

    fclose(arq);

    printf("a %d", a);
    printf("e %d", e);
    printf("i %d", i);
    printf("o %d", o);
    printf("u %d", u);

}