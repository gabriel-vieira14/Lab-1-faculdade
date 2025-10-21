#include <stdio.h>
#include <math.h>
int main()
{
    int potencia_lampada, potencia_nec, lampadas_nec;
    float largura, comprimento, area;

    printf("Qual a potência da(s) lâmpada(s) a ser(em) utilizada(s)?");
    scanf("%d", &potencia_lampada);
    printf("Qual  a largura da área a ser iluminada?");
    scanf("%f", &largura);

    printf("Qual  o comprimento da área a ser iluminada?");
    scanf("%f", &comprimento);
    area = largura * comprimento;
    potencia_nec = area * 18;
    lampadas_nec = ceil(potencia_nec / potencia_lampada);
    printf("A quantidade de lampadas necessárias para iluminar esse ambiente e de %d", lampadas_nec);
}