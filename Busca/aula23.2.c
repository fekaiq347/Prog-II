//Aluno: Kaique Fabricio Eufrásio; DRE: 123228961
#include <stdio.h>
#include <stdlib.h>

// Função que realiza a busca binária em um vetor
int buscaBin(int arr[], int tam, int el);

int main() {

      int qtd, elem;

      // Solicita ao usuário a quantidade de elementos do vetor
      printf("Digite a quantidade de elementos do vetor: ");
      scanf("%d", &qtd);

      // Cria um vetor com a quantidade de elementos informada pelo usuário
      int arr[qtd];

      // Solicita ao usuário que digite os elementos do vetor
      printf("\nDigite os elementos do vetor: ");
      for (int i = 0; i < qtd; i++) {
            scanf("%d", &arr[i]);
            printf(" ");
      }

      // Solicita ao usuário o elemento a ser procurado
      printf("\nDigite o elemento procurado: ");
      scanf("%d", &elem);

      // Chama a função de busca binária e passa o vetor, a quantidade de elementos e o elemento a ser procurado como parâmetros
      buscaBin( arr, qtd, elem);
}

// Função que realiza a busca binária em um vetor
int buscaBin(int arr[], int tam, int el){
      
      int fim = tam-1;
      int ini = 0;
      int count = 0;

      // Enquanto o índice inicial for menor ou igual ao índice final
      while (ini <= fim) {

            // Calcula o índice do meio do vetor
            int meio = (fim + ini)/2;

            // Se o elemento do meio for menor que o elemento procurado, atualiza o índice inicial para o próximo elemento
            if (arr[meio] < el)
                  ini = meio + 1;
            else {
                  // Se o elemento do meio for maior que o elemento procurado, atualiza o índice final para o elemento anterior
                  if (arr[meio] > el)
                        fim = meio - 1;
                  else {
                        // Se o elemento do meio for igual ao elemento procurado, retorna o índice do meio
                        count++;
                        printf("\n%da iteração: %d", count, tam - (tam - meio) + 1);
                        return meio;
                  }
            }

            // Incrementa o contador de iterações e exibe o número da iteração e o índice do elemento atual
            count++;
            printf("\n%da iteração: %d", count, tam - (tam - meio) + 1);
      }

      // Se o elemento não for encontrado, retorna -1
      return -1;
}
