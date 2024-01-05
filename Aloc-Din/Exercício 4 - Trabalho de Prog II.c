//ALUNO: KAIQUE FABRICIO EUFRÁSIO
//DRE: 123228961

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Função para inverter uma frase
void invrt_frase(char* frase);

int main(){

    int linhas;

    FILE *arqv_entrada;
    FILE *arqv_saida;

    // Abre o arquivo de entrada para leitura
    arqv_entrada = fopen("origem.txt", "r");
    if (arqv_entrada == NULL){
        printf("Arquivo nao pode ser aberto.");
        return -1; // Retorna um código de erro
    }

    // Abre o arquivo de saída para escrita
    arqv_saida = fopen("megiro.txt", "w");
    if (arqv_saida == NULL){
        printf ("Arquivo nao pode ser aberto.");
        return -1; // Retorna um código de erro
    }

    char frase[81];

    while (fgets(frase, sizeof(frase), arqv_entrada) != NULL) {
        
        frase[strcspn(frase, "\n")] = '\0'; // Remove o caractere de nova linha

        invrt_frase(frase); // Chama a função para inverter a frase

        fprintf(arqv_saida, "%s\n", frase); // Escreve a frase invertida no arquivo de saída
        printf("%s\n", frase); // Imprime a frase invertida no console
    }    

    fclose(arqv_entrada); // Fecha o arquivo de entrada
    fclose(arqv_saida);   // Fecha o arquivo de saída

    return 0;
}

// Função para inverter uma frase
void invrt_frase(char* frase){
    int final = strlen(frase) - 1;

    for(int comeco = 0; comeco < final; comeco++){
        
        char assist = frase[comeco];
        frase[comeco] = frase[final];
        frase[final] = assist;

        final--;
    }
}
