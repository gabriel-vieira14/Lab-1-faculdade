#include <stdio.h>
void menor_ou_impar(int n) {
    for(int i = 1; i < n;i++) {
        if((i % 2 != 0) && (i > (n/2))) {
            printf("%d ", i);
        }
    }
}
int main() {
    int n;
    printf("Digite um número:\n");
    scanf("%d",&n);
    menor_ou_impar(n);
}