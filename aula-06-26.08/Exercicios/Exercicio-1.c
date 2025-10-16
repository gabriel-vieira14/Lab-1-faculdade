#include <stdio.h>

int main()
{
    int n1, n2;
    printf("\n--------Verificador de múltiplos -------\n");
    printf("Digite um número");
    scanf("%d", &n1);
    printf("Digite outro número");
    scanf("%d", &n2);
    if (n1 % n2 == 0)
    {
        printf("São múltiplos");
    }
    else
    {
        printf("Não são múltiplos");
    }
}
