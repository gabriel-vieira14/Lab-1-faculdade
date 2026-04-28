#include <stdio.h>
void n_perfeito() {
    int soma;
    for(int n = 1; n < 1000;n++) {
        soma=0;
       for(int i= 1; i < n;i++) {
            if(n % i == 0) {
                soma += i;
            }
        }
        if(soma == n) {
            printf("%d é um número perfeito.\n", n);
        }
    }
}
int main() {
    n_perfeito();
}