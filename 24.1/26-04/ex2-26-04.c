#include <stdio.h>
#define tam 80

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Erro na linha de comando.\n");
        return -1;
    }

    FILE *in, *out;

    in = fopen (argv[1], "r");
    if (in == NULL) {
        printf("Erro ao abrir o arquivo de leitura.\n");
        return -1;
    }

    out = fopen (argv[2], "w");
    if (out == NULL) {
        printf("Erro ao abrir o arquivo de saida.\n");
        return -1;
    }

    int c;

    while ((c = fgetc(in)) != EOF) {
        if (c >= 97 && c <= 122) {
            c -= 32;
        }

        fputc(c, out);

    }

    fclose(in);
    fclose(out);


    return 0;
}