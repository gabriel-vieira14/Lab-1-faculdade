#include <stdio.h>

int main() {
    int a,b, auxiliar;

    printf("Digite um valor inteiro para a: \n");
    scanf("%d", &a); // 10
    printf("Digite um valor inteiro para b: \n");
    scanf("%d", &b);// 25

    auxiliar = b;
    b = a;
    a = auxiliar;
    printf("a: %d e b:%d", a,b);
    
    return 0;
}