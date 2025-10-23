#include <stdio.h>

int main() {
    int x,y; 
    printf(" Digite um valor inteiro para x:\n"); 
    scanf("%d", &x); 
    printf(" Digite um valor inteiro para y:\n"); 
    scanf("%d", &y);
    x++;
    y--;
    printf("O sucessor de x %d e o antecesssor de y e %d\n",x, y);
}