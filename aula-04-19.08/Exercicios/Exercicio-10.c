#include <stdio.h>

int main() {
    int qtd_carros, total_carros_fim_ano,desgaste_carros, carros_renovados;
    float preco_diaria,  faturamento_mensal, faturamento_anual, total_multas_mes;

    printf("Informe o total de carros que a locadora possui:\n");
    scanf("%d", &qtd_carros);

    printf("Informe quanto custa a diária:\n");
    scanf("%f", &preco_diaria);
    faturamento_mensal = ((qtd_carros / 3.0) * preco_diaria) * 30;
    faturamento_anual = faturamento_mensal * 12;
    total_multas_mes = ((qtd_carros / 3.0) / 10.0) * (0.10 * preco_diaria);

    desgaste_carros = qtd_carros * 0.05;
    carros_renovados = qtd_carros / 8;

    total_carros_fim_ano = (qtd_carros - desgaste_carros) + carros_renovados; 
    printf("O faturamento anual da empresa e de %.2f reais\n", faturamento_anual);
    printf("O valor ganho com multas por mes é de %.2f reais\n", total_multas_mes);
    printf("O total de carros ao final do ano será de %d carros \n", total_carros_fim_ano);
    return 0;
}