#include <stdio.h>

int main() {
    int m_001, m_005, m_010, m_025, m_050, m_1;
    float total;

    printf("Digite a quantidade de moedas de R$ 0,01:\n");
    scanf("%d", &m_001);
    printf("Digite a quantidade de moedas de R$ 0,05:\n");
    scanf("%d", &m_005);
    printf("Digite a quantidade de moedas de R$ 0,10:\n");
    scanf("%d", &m_010);
    printf("Digite a quantidade de moedas de R$ 0,25:\n");
    scanf("%d", &m_025);
    printf("Digite a quantidade de moedas de R$ 0,50:\n");
    scanf("%d", &m_050);
    printf("Digite a quantidade de moedas de R$ 1,00:\n");
    scanf("%d", &m_1);
    total = (0.01 * m_001) + (0.05 * m_005) + (0.10 * m_010) + (0.25 * m_025) + (0.50 * m_050) + m_1;
    printf("O total economizado é de: %.2f", total);

}