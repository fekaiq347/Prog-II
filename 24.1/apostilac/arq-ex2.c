#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 20

typedef struct {
    char nome[max];
    double p1;
    double p2; 
} aluno;

int main() {

    FILE *fp;
    int cont;

    if ((fp = fopen("arquivo.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo para leitura.\n");
        return 1;
    }

    fscanf(fp, "%d", &cont);
    fgetc(fp);
    aluno *alunos = malloc(cont * sizeof(aluno));

 for (int i = 0; i < cont; i++) {
        // Lê o nome do aluno
        fgets(alunos[i].nome, max, fp);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0; // Remove o caractere de nova linha do nome

        // Lê as notas do aluno
        if (fscanf(fp, "%lf\n", &alunos[i].p1) != 1 || fscanf(fp, "%lf\n", &alunos[i].p2) != 1) {
            printf("Erro na leitura das informacoes.\n");
            return 1;
        }

        if ((alunos[i].p1 + alunos[i].p2) / 2 < 7) {
            printf("\n%s\n", alunos[i].nome);
        }
    }

    free(alunos);
    fclose(fp);
    return 0;
}