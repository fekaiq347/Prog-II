#include <stdio.h>
#include <stdlib.h>

int numero_vogais(char string[]) {

    int qtd_v = 0;

    for (int i = 0; string[i] != '\n'; i++) {
        if (string[i] == 'a' || string[i] == 'e' ||
            string[i] == 'i' || string[i] == 'o' ||
            string[i] == 'u') {
                qtd_v++;
            }
    }

    return qtd_v;

}

int main() {

    char s[100];
    int qtd;

    fgets(s, sizeof(s), stdin);

    qtd = numero_vogais(s);

    printf("%d \n", qtd);

    return 0;
}