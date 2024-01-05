//ALUNO: KAIQUE FABRICIO EUFRÁSIO
//DRE: 123228961

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main() {
    char nomeArquivo[100];   // Variável para armazenar o nome do arquivo.
    char *palavraAlvo = NULL; // Ponteiro para armazenar a palavra a ser buscada.

    printf("Digite o nome do arquivo: ");
    scanf("%s", nomeArquivo); // Solicita ao usuário o nome do arquivo.

    printf("Digite a palavra a ser buscada: ");
    scanf(" %m[^\n]", &palavraAlvo); // Solicita a palavra a ser buscada e aloca dinamicamente a memória.

    FILE *arquivo = fopen(nomeArquivo, "r"); // Abre o arquivo no modo de leitura.
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        free(palavraAlvo); // Libera a memória alocada para a palavraAlvo em caso de erro.
        return 1;
    }

    char buffer[100]; // Buffer para armazenar as palavras lidas do arquivo.
    int contador = 0; // Variável para contar as ocorrências da palavra.

    while (fscanf(arquivo, "%s", buffer) != EOF) { // Lê palavras do arquivo até o final.
        if (strcmp(buffer, palavraAlvo) == 0) { // Compara a palavra lida com a palavra alvo.
            contador++; // Incrementa o contador se forem iguais.
        }
    }

    printf("A palavra '%s' aparece %d vezes no arquivo.\n", palavraAlvo, contador);

    fclose(arquivo); // Fecha o arquivo.
    free(palavraAlvo); // Libera a memória alocada para palavraAlvo.

    return 0;
}
