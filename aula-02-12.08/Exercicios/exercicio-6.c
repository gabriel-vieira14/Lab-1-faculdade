#include <stdio.h>

int main() {
    int x;
    float y;
    double z;
    printf("Digite um valor inteiro para x:\n");
    scanf("%d", &x);
    printf("Digite um valor quebrado para y e z, respectivamente:\n");
    scanf("%f", &y);
    scanf("%lf", &z);

    printf("Os valores de x,y e z respectivamente sao:\n %d, %.3f e %.4lf\n",x ,y, z);

    return 0;
}