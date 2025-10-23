#include <stdio.h>

int main() {
    int a,b;

    printf("Digite um valor inteiro para a: \n");
    scanf("%d", &a);
    printf("Digite um valor inteiro para b: \n");
    scanf("%d", &b);
    a = a + b;
    b = a - b; 
    a = a - b; 
    printf("a: %d\n", a);
    printf("b: %d\n", b);

    
    
}