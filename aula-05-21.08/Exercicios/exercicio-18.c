#include <stdio.h>
#include <math.h>
int main()
{
    // Preços fixos para latas e galões
    const float PRECO_LATA = 80.0;
    const float PRECO_GALAO = 25.0;
    const float volume_lata = 18.0;
    const float volume_galao = 3.6;

    float preco_apenas_latas, preco_apenas_galoes, preco_mistura, litros_necessarios, restante_tinta;
    int qtd_galao, qtd_lata, tam_area, qtd_galao_mistura, qtd_lata_mistura;

    // entrada
    printf("Qual o tamanho, em m², do local onde sera aplicada a tinta?");
    scanf("%d", &tam_area);

    // processamento
    litros_necessarios = tam_area / 6.0;
    printf("\nLitros necessários: %.2f\n\n", litros_necessarios);

    // Situação 1 - comprar apenas latas

    qtd_lata = ceil(litros_necessarios / volume_lata);
    preco_apenas_latas = PRECO_LATA * qtd_lata;

    // Situação 2 - comprar apenas galões
    qtd_galao = ceil(litros_necessarios / volume_galao);
    preco_apenas_galoes = qtd_galao * PRECO_GALAO;

    // Situação 3 - Misturar galões e latas para não haver desperdício
    qtd_lata_mistura = (int)(litros_necessarios / volume_lata); // as latas são mais baratas
    restante_tinta = litros_necessarios - qtd_lata_mistura * volume_lata;
    qtd_galao_mistura = ceil(restante_tinta / volume_galao);
    preco_mistura = ((qtd_galao_mistura * PRECO_GALAO) + (qtd_lata_mistura * PRECO_LATA));

    printf("Situação 1 (apenas latas): Você precisará de %d lata(s), custando R$ %.2f\n", qtd_lata, preco_apenas_latas);
    printf("Situação 2 (apenas galões): Você precisará de %d galão(ões), custando R$ %.2f\n", qtd_galao, preco_apenas_galoes);
    printf("Situação 3 (misturado para economizar): Você precisará de %d lata(s) e %d galão(ões), custando R$ %.2f\n", qtd_lata_mistura, qtd_galao_mistura, preco_mistura);

    return 0;
}