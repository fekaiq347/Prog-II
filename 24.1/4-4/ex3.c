#include <stdio.h>

void max(int *v, int *n) {

    int count = *n, maior = 0;

    while(count--) {

        if (v[count] > maior) 
            maior = v[count];

    }

    *n = maior;
}

int main() {

    int n;

    scanf("%d", &n);

    int v[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &v[i]);
    }

    max(v, &n);

    printf("%d", n);

    return 0;
}