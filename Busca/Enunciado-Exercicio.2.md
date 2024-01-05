## Enunciado-Exercicio.2

Altere o método de busca binária para que, a cada divisão do vetor, ele imprima quantos elementos foram descartados na busca.

Faça um programa principal para testar a função implementada.

`int buscaBin(int arr[], int tam, int el){`
`int fim = tam-1;`
`int ini = 0;`
`while (ini <= fim) {`
`int meio = (fim + ini)/2;`
`if (arr[meio] < el)`
`ini = meio + 1;`
`else {`
`if (arr[meio] > el)`
`fim = meio - 1;`
`else return meio;`
`}`
`}`
`return -1; }`