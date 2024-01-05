//Aluno: Kaique Fabricio Eufrásio; DRE: 123228961
//Eu mudei o espaçamento nesse código, então você deve estranhar quando comparar com o código anterior.
#include <stdio.h>
#include <stdlib.h>

// Função que busca a quantidade de números menores e maiores que um elemento em um vetor ordenado utilizando busca binária
void buscaMenorMaiorBin(int arr[], int tam, int el, int *menor, int *maior);

int main() {

    int qtd, elem, maior, menor;

    // Solicita ao usuário a quantidade de elementos do vetor
    printf("Digite a quantidade de elementos do vetor: ");
    scanf("%d", &qtd);

    // Cria um vetor com a quantidade de elementos informada pelo usuário
    int arr[qtd];

    // Solicita ao usuário os elementos do vetor
    printf("\nDigite os elementos do vetor: ");
    for (int i = 0; i < qtd; i++) {
        scanf("%d", &arr[i]);
        printf(" ");
    }

    // Solicita ao usuário o elemento a ser procurado
    printf("\nDigite o elemento procurado: ");
    scanf("%d", &elem);

    // Chama a função que busca a quantidade de números menores e maiores que o elemento informado pelo usuário
    buscaMenorMaiorBin(arr, qtd, elem, &menor, &maior);

    // Exibe a quantidade de números menores e maiores que o elemento informado pelo usuário
    printf("A quantidade de numeros menores e maiores, respectivamente, e: %d e %d", menor, maior);

}

// Função que busca a quantidade de números menores e maiores que um elemento em um vetor ordenado utilizando busca binária
void buscaMenorMaiorBin(int arr[], int tam, int el, int *menor, int *maior) {

    int fim = tam-1;
    int ini = 0;

    // Realiza a busca binária pelo elemento informado pelo usuário
    while (ini <= fim) {
        int meio = (fim + ini)/2;
        if (arr[meio] < el)
            ini = meio + 1;
        else {
            if (arr[meio] > el)
                fim = meio - 1;
            else {
                // Se o elemento for encontrado, conta a quantidade de números menores e maiores que ele
                for (int i = meio; i > 0; i--) {
                    (*menor)++;
                }
                for (int j = meio; j < tam - 1; j++) {
                    (*maior)++;
                }
                break;
            }
        }
    }
}