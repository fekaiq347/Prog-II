#include <stdio.h>
#include <stdlib.h>

int main() {

    int *i, j;
    float *notas;
    char *nome;

    j = 10;
    i = &j;

    //i = 10;

    notas = (float *)malloc(5*sizeof(float));
    if (notas == NULL) {
        printf("Erro na alocação de memória\n");
        return -1;
    }

    for (int i = 0; i < 5; i++)  
        scanf("%f", *(notas + i));

    for (int j = 0; i < 5; i++) 
        printf("%f ", *(notas + j)); 

    free(notas);

    nome = (char *)malloc(50*sizeof(char));
    if (nome == NULL) {
        printf("Erro na alocação de memória\n");
        return -1;
    }

    scanf("%s", nome);
    for (int i = 0; nome[i] != '\0'; i++)
        if (nome[i >= 'A' && nome[i] <= 'Z'])
            nome[i] = nome[i] + 32;

    printf("%s\n", nome);

    for (int i = 0; nome[i] != '\0'; i++)
        if (nome[i >= 'a' && nome[i] <= 'z'])
            nome[i] = nome[i] - 32;

    printf("%s\n", nome);

    free(nome);
    
    return 0;
}