#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int posicao (char *substr, char *str) {
    char *pos = strstr(str, substr);
    if (pos) {
        return pos - str;
    }

    return -1;
}

int main () {

    char str[100], substr[100];

    scanf("%s", str);
    scanf("%s", substr);

    int pos = posicao(str, substr);

    printf("%d", pos);

    return 0;
}