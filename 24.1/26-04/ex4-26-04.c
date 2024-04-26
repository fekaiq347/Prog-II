#include <stdio.h>
#define tam 81

void reverse (char *str) {
    int len = strlen(str);

    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Uso da linha de comando invalido.\n");
        return -1;
    }

    FILE *in, *out;

    in = fopen (argv[1], "r");

    if (in == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return -1;
    }

    out = fopen (argv[2], "w");

    if (out == NULL) {
        printf("Erro ao abrir o arquivo de saida.\n");
        return -1;
    }

    char line[tam];

    while (fgets(line, tam, in) != NULL) {
        reverse(line);
        fputs(line, out);
    }

    fclose(in);
    fclose(out);

    return 0;
}