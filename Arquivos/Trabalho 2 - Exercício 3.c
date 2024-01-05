//ALUNO: KAIQUE FABRICIO EUFRÁSIO
//DRE: 123228961

#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *arquivoEntrada = fopen("entrada.txt", "r");
    if (arquivoEntrada == NULL) {
        printf("Erro ao abrir o arquivo de entrada.\n");
        return -1;
    }

    FILE *arquivoSaida = fopen("saida.txt", "w");
    if (arquivoSaida == NULL) {
        printf("Erro ao abrir o arquivo de saída.\n");
        return -1;
    }

    int totalAtletas, numCorridas;
    fscanf(arquivoEntrada, "%d %d", &totalAtletas, &numCorridas);

    int menorTempo = -1; // Inicializa menorTempo com -1 para garantir que seja atualizado na primeira iteração.
    int atletaVencedor = -1; // Armazena o número do atleta vencedor.

    // Loop para calcular o tempo total de cada atleta.
    for (int i = 1; i <= totalAtletas; i++) {
        int tempoTotal = 0;

        // Loop para ler o tempo de cada corrida do atleta.
        for (int j = 0; j < numCorridas; j++) {
            int horas, minutos, segundos;
            fscanf(arquivoEntrada, "%d %d %d", &horas, &minutos, &segundos);
            tempoTotal += (horas * 3600) + (minutos * 60) + segundos;
        }

        // Verifica se é a primeira iteração ou se o tempo total é menor que o menor tempo até agora.
        if (atletaVencedor == -1 || tempoTotal < menorTempo) {
            menorTempo = tempoTotal;
            atletaVencedor = i;
        }
    }

    // Verifica se um atleta vencedor foi encontrado e escreve no arquivo de saída.
    if (atletaVencedor != -1) {
        fprintf(arquivoSaida, "%d\n", atletaVencedor);
    }

    // Fecha os arquivos.
    fclose(arquivoEntrada);
    fclose(arquivoSaida);

    return 0;
}
