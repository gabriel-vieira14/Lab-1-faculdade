#include <stdio.h>

int main() {
    int qtd_macas, total_cx;
    float preco_maca, vl_tot_carg;

    printf("Digite a quantidade de macas que serao transportadas:\n");
    scanf("%d",&qtd_macas);
    printf("Digite o preco/un da maca:\n");
    scanf("%f", &preco_maca);
    vl_tot_carg = qtd_macas * preco_maca;
    total_cx = qtd_macas / 45;
    printf("O valor total da carga é de R$ %.2f e o total de caixas que devem ser transportadas é de %d caixas", vl_tot_carg, total_cx);
}