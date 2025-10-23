#include <stdio.h>

int main()
{

    float invest_1, invest_2, invest_3, vl_premio, vl_aposta, g1, g2, g3;

    printf("Quanto o jogador 1 investiu?\n");
    scanf("%f", &invest_1);
    printf("Quanto o jogador 2 investiu?\n");
    scanf("%f", &invest_2);
    printf("Quanto o jogador 3 investiu?\n");
    scanf("%f", &invest_3);
    printf("Qual o valor do prêmio?\n");
    scanf("%f", &vl_premio);
    vl_aposta = invest_1 + invest_2 + invest_3;
    g1 = vl_premio * (invest_1 / vl_aposta);
    g2 = vl_premio * (invest_2 / vl_aposta);
    g3 = vl_premio * (invest_3 / vl_aposta);

    printf("O ganhador um receberá %.2f, o ganhador 2 receberá %.2f e o ganhador três receberá %.2f", g1, g2, g3);
}