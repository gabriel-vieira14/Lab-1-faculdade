#include <stdio.h>

int main()
{
    int jogador1, jogador2, jogador3;
    printf("Digite a pontuação do jogador 1:\n");
    scanf("%d", &jogador1);
    printf("Digite a pontuação do jogador 2:\n");
    scanf("%d", &jogador2);
    printf("Digite a pontuação do jogador 3:\n");
    scanf("%d", &jogador3);
    if (jogador1 > jogador2 && jogador2 > jogador3)
    {
        printf("1º:jogador1 \n 2º: jogador2 \n3º:jogador3\n");
    }
    else if (jogador1 > jogador3 && jogador3 > jogador2)
    {
        printf("1º:jogador1 \n 2º: jogador3 \n3º:jogador2\n");
    }
    else if (jogador2 > jogador1 && jogador1 > jogador3)
    {
        printf("1º:jogador2 \n 2º: jogador1 \n3º:jogador3\n");
    }
    else if (jogador2 > jogador3 && jogador3 > jogador1)
    {
        printf("1º:jogador2 \n 2º: jogador3 \n3º:jogador1\n");
    }
    else if (jogador3 > jogador1 && jogador1 > jogador2)
    {
        printf("1º:jogador3 \n 2º: jogador1 \n3º:jogador2\n");
    }
    else
    {
        printf("1º:jogador3 \n 2º: jogador2 \n3º:jogador1\n");
    }
    return 0;
}