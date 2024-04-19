#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _func {
    char nome[40];
    int ano_nasc;
    float renda;
} Tfunc;

void * inicializa (Tfunc *, int);
void * inclui_novos(Tfunc *, int, int);
void imprime (Tfunc *, int, int);

int main(void) {

    Tfunc *cadastro;
    int funcionarios, adicionais;
    
    printf("Quantos funcionarios? ");
    scanf("%d",&funcionarios);
    
    cadastro=inicializa(cadastro, funcionarios);
    
    if (!cadastro)
    return -1;
    
    printf("Quantos funcionarios a mais deseja adicionar? ");
    scanf("%d",&adicionais);
    
    cadastro = inclui_novos(cadastro, funcionarios, adicionais);
    
    if (!cadastro)
    return -1;
    
    printf("Lista de funcionarios cadastrados\n");
    imprime(cadastro, 0, funcionarios+adicionais);
    free(cadastro);
    
    return 0;
}

void * inicializa (Tfunc *cadastro, int funcionarios) {
    cadastro = (int *)malloc(funcionarios * sizeof(Tfunc));

    for (int i = 0; i < funcionarios; i++) {
        printf("Digite as informacoes do %do funcionario:\n", i + 1);
        
        printf("Nome: ");
        scanf("%s", cadastro[i].nome);
    
        printf("Ano de nascimento: ");
        scanf("%d", &cadastro[i].ano_nasc);

        printf("Renda: ");
        scanf("%f", &cadastro[i].renda);

    }

}

void * inclui_novos(Tfunc *cadastro, int funcionarios, int adicionais) {
    cadastro = (int *)malloc((funcionarios + adicionais) * sizeof(Tfunc));
}