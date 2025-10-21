#include <stdio.h>

int main()
{

    int ano_atual, idade, ano_nasc;
    printf("Digite em que ano estamos:\n");
    scanf("%d", &ano_atual);
    printf("Digite sua idade:\n");
    scanf("%d", &idade);

    ano_nasc = ano_atual - idade;
    printf("Você nasceu em %d", ano_nasc);
}