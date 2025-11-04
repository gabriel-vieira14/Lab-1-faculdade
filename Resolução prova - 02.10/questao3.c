#include <stdio.h>

int inverte_numero(int n) {
    int inverso = 0;
    while(n > 0) {
        int digito = n % 10;
        inverso = inverso * 10 + digito;
        n = n / 10;
    }
    return inverso;
}

int soh_impares(int n) {
    while(n > 0) {
        int digito = n % 10;
        if(digito % 2 == 0) return 0;
        n = n / 10;
    }
    return 1;
}

int main() {
    int N;
    scanf("%d", &N);

    int reverso = inverte_numero(N);
    printf("Numero reverso: %d\n", reverso);
    int soma = N + reverso;

    if(soh_impares(soma)) printf("Reversível\n");
    else printf("Não reversível\n");

    return 0;
}
