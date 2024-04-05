#include <stdio.h>

void aumento_salario(int *s, int p){

    *s += (p * *s) / 100; 

}


int main() {

    int s, p;

    scanf("%d, %d", &s, &p);

    aumento_salario(&s, p);

    printf("%d", s);

    return 0;
}