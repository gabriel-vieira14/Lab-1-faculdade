#include <stdio.h>

int main()
{

    int seg_digitado, seg_resultado, min, h;

    printf("Digite o tempo em segundos:\n");
    scanf("%d", &seg_digitado);
    h = seg_digitado / 3600;
    min = (seg_digitado % 3600) / 60;
    seg_resultado = (seg_digitado % 3600) % 60;
    printf("O resultado é: %d:%d:%d", h, min, seg_resultado);
}