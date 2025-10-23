#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, delta, x1, x2, x_delta_0;
    printf("\n----- Calculdadora de equação de 2o Grau -----\n");
    printf("Digite o valor de a:\n");
    scanf("%f", &a);
    printf("Digite o valor de b:\n");
    scanf("%f", &b);
    printf("Digite o valor de c:\n");
    scanf("%f", &c);
    delta = pow(b, 2) - 4 * a * c;
    if (delta > 0)
    {
        x1 = (-b + sqrt(delta)) / (2 * a);
        x2 = (-b - sqrt(delta)) / (2 * a);
        printf("A raiz 1 é %f e a raiz 2 é %f", x1, x2);
    }
    else if (delta == 0)
    {
        x_delta_0 = (-b - 0) / 2 * a;
        printf("A única raiz é %f", x_delta_0);
    }
    else
    {
        printf("Não há raízes no conjunto dos reais!");
    }
}