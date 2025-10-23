#include <stdio.h>

int main() {
    float area_livre_t, percentual_area_livre,area_c,area_t, largura_t,comprimento_t, largura_c, comprimento_c;
    //Medidas Terreno
    printf("Digite largura do terreno em m:\n");
    scanf("%f", &largura_t);
    printf("Digite o comprimento do terreno em m:\n");
    scanf("%f", &comprimento_t);
    //Medidas casa
    printf("Digite a largura da casa em m:\n");
    scanf("%f", &largura_c);
    printf("Digite o comprimento da casa em m:\n");
    scanf("%f", &comprimento_c);
    area_c = comprimento_c * largura_c;
    area_t = comprimento_t * largura_t;
    area_livre_t = area_t - area_c;
    percentual_area_livre = (area_livre_t / 100) ; 
    printf("O terreno tem %.2f%% de área livre, o que, em valores absolutos dá %f", percentual_area_livre, area_livre_t);


}