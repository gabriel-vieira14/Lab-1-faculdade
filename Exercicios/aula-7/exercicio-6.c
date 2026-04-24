#include <stdio.h>
void divisores_positivos() {
    int n;
    printf("Digite um número: ");
    scanf("%d",&n);
    for(int i = 1; i < n;i++) {
        if(n % i == 0) {
            printf("%d, ", i);
        }
    }
    printf("%d",n);
}
int main() {
    divisores_positivos();
}