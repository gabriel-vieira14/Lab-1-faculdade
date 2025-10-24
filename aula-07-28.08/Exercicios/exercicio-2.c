#include <stdio.h>

int main()
{
    int a, b, c, d;

    printf("///////////////////\n");
    printf("Verificador de equilibrio do mobile\n");
    printf("///////////////////\n");
    printf("Digite o valor para a bola A:\n");
    scanf("%d", &a);
    printf("Digite o valor para a bola B:\n");
    scanf("%d", &b);
    printf("Digite o valor para a bola C:\n");
    scanf("%d", &c);
    printf("Digite o valor para a bola D:\n");
    scanf("%d", &d);
    if ((b == c) && (d == (b + c)) && (a == (b + c + d)))
    {
        printf("O mobile esta completamente equilibrado");
    }
    else
    {
        printf("O mobile nao esta equilibrado!");
    }
}