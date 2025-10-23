#include <stdio.h>
#include <math.h>
int main()
{
    int n;
    float inv, abs;

    printf("Digite um número:\n");
    scanf("%d", &n);
    if (n > 0)
    {
        inv = 1 / n;
        printf("O inverso do número digitado é %d", inv);
    }
    else
    {
        abs = fabs(n);
        printf("O valor absoluto do %d é %d", n, abs);
    }
}