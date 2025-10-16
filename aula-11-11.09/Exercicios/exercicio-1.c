#include <stdio.h>

int somar(int n) {
    int cont, soma = 0, n1 = 1;
    for(cont = 1; cont <= n; cont++) {
        soma = soma + n1;
        n1++;
    }
    return soma;
}
int main() {
    int res, limite_soma= 6;

    res = somar(limite_soma);
    printf("O resultado da soma é %d", res);
}

