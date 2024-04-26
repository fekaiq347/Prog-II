#include <stdio.h>
#define tam 80

int compare (char *str, char substr) {
    int cont = 0;
    char p = strstr(str, substr);

    for (int i = 0; i < strlen(str); i++) {
        if (p == str[i])
            break;

        cont++;
    }

    return cont;
}

int main(int argc, char *argv[]) {

    if (argc != 3) {
        printf("Erro na linha de comando.\n");
        return -1;
    }

    FILE *in;

    in = fopen (argv[1], "r");
    if (in == NULL) {
        printf("Erro ao abrir o arquivo de leitura.\n");
        return -1;
    }

    char substr[tam] = argv[2];
    char line [tam];
    int pos;

    while (fgets(line, tam, in) != NULL) {
        pos = compare(line, substr);    


    return 0;


}