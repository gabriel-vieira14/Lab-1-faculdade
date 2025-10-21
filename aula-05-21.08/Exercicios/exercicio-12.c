#include <stdio.h>

int main()
{
    float total, desc, total_c_desc, vl_parcela, com_vend_avista, com_vend_parcelada;
    printf("Digite o valor total da compra do cliente:\n");
    scanf("%f", &total);

    desc = 0.10 * total;
    total_c_desc = total - desc;
    vl_parcela = total / 3;
    com_vend_avista = 0.05 * total_c_desc;
    com_vend_parcelada = 0.05 * total;

    printf("O total a pagar com desconto de 10%% é de %.2f \n", total_c_desc);
    printf("Parcelando em 3x sem juros, a parcela fica no valor de %.2f\n", vl_parcela);
    printf("\n\n INFORMAÇÕES PARA O VENDEDOR!\n \n");
    printf("Caso o cliente compre a vista, sua comissão sera de %.2f\n", com_vend_avista);
    printf("Caso o cliente compre a prazo, sua comissão sera de %.2f\n", com_vend_parcelada);

    return 0;
}