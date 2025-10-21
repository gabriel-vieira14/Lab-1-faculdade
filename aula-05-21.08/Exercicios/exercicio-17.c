#include <stdio.h>

int main()
{
    float vl_combustivel, distribuicao_rev, custo_etanol, icms, cide_pis_cofins, vl_refinaria;

    printf("Qual foi o valor pago pelo litro de combustível?\n");
    scanf("%f", &vl_combustivel);
    distribuicao_rev = 0.17 * vl_combustivel;
    custo_etanol = 0.12 * vl_combustivel;
    icms = 0.28 * vl_combustivel;
    cide_pis_cofins = 0.07 * vl_combustivel;
    vl_refinaria = vl_combustivel - (distribuicao_rev + custo_etanol + cide_pis_cofins + icms);
    printf("+Valor na bomba: R$ %.2f\n -Distribuição e revenda: R$ %.2f\n -Custo Etanol Anitro: R$ %.2f\n-ICMS:R$ %.2f\nCIDE,-PIS/PASEP E COFINS: R$ %.2f\n=Valor refinaria: R$ %.2f", vl_combustivel, distribuicao_rev, custo_etanol, icms, cide_pis_cofins, vl_refinaria);
}
