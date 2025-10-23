#include <stdio.h>
void colidiu_ou_nao()
{

    int x, y, x_sup, y_sup, x_rec2, y_rec2, x_sup_rec2, y_sup_rec2;
    printf("Retangulo 1\n");
    printf("Digite as coordernadas x0 e y0 do prmeiro retangulo:\n");
    scanf("%d %d", &x, &y);
    printf("Digite as coordernadas x1 e y1 do prmeiro retangulo:\n");
    scanf("%d %d", &x_sup, &y_sup);

    printf("Retangulo 2\n");

    printf("Digite as coordernadas x0 e y0 do prmeiro retangulo:\n");
    scanf("%d %d", &x_rec2, &y_rec2);
    printf("Digite as coordernadas x1 e y1 do prmeiro retangulo:\n");
    scanf("%d %d", &x_sup_rec2, &y_sup_rec2);

    if ((((x_sup - x_sup_rec2) > 0) && ((y_sup - y_sup_rec2) > 0)) || (y_sup_rec2))
    {
        printf("1");
    }
}
int main()
{
    colidiu_ou_nao();
}