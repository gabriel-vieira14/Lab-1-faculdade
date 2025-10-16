#include <stdio.h>

#define LINHA 10
#define COLUNA 10
int main()
{

    int mat[LINHA][COLUNA];
    int linhas_colunas;
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            printf("Digite um número\n");
            scanf("%d", &mat[i][j]);
        }
    }
    for (int i = 0; i < LINHA; i++)
    {
        for (int j = 0; j < COLUNA; j++)
        {
            int valor = i * 10 + j;
            if (valor % 9 == 0)
            {
                printf("XX");
            }
            else
            {
                printf("%d", mat[i][j]);
            }
        }
    }
}
