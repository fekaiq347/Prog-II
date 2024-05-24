#include <stdio.h>
#define MAX 81

typedef struct _ALUNO {
    char nome[MAX];
    double n1, n2;
} ALUNO;

int main() {

    FILE *fp;
    char c;

    if ((fp = fopen("arquivo1.txt", "r")) == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return 1;
    }

    int cont;
    fscanf(fp, "%d", &cont);
    fgetc(fp);

    ALUNO *alunos = malloc(cont * sizeof(ALUNO));
    
    FILE *fb;
    if ((fb = fopen("arquivo2.dat", "wb+")) == NULL) {
        printf("Erro na abertura do arquivo binario.\n");
        return 1;
    }

    for (int i = 0; i < cont; i++) {

        fgets(alunos[i].nome, MAX, fp);
        alunos[i].nome[strcspn(alunos[i].nome, "\n")] = 0;

        if (fscanf(fp, "%d\n", &alunos[i].n1) != 1 || fscanf(fp, "%d\n", &alunos[i].n2) != 1) {
            printf("Erro na leitura das informacoes\n");
            return 1;
        }

        if (fwrite(&alunos[i], sizeof(ALUNO), 1, fb) != 1) {
            printf("Erro na escrita do arquivo em binário.\n");
            return 1;
        }

    }

    return 0;
}