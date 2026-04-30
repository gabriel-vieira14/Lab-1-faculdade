#include <stdio.h>
void soma_todos() {
    int n, soma=0;
    printf("Digite um número:\n");
    scanf("%d", &n);
    for(int i = 1;i < n;i++) {
        soma += i;
    }
    printf("A soma dos números menores que %d é: %d\n",n,soma);
}
int main() {
    soma_todos();
}