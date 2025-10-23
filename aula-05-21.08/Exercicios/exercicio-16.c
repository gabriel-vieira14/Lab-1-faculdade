#include <stdio.h>

int main()
{
    float vl_hora, s_bruto, s_liquido, inss, sindicato, ir;
    int h_trabalhadas;

    printf("Digite qual o valor pago pela hora trabalhada:\n");
    scanf("%f", &vl_hora);
    printf("Digite quantas horas foram trabalhadas no mês:\n");
    scanf("%d", &h_trabalhadas);

    s_bruto = h_trabalhadas * vl_hora;
    inss = 0.11 * s_bruto;
    ir = 0.14 * s_bruto;
    sindicato = 0.01 * s_bruto;
    s_liquido = s_bruto - (inss + sindicato + ir);

    printf("O salário bruto é de %.2f, o valor descontado de Imposto de Renda é de %.2f, o valor descontado do sindicato é de %.2f e o salario liquido é de %.2f", s_bruto, ir, sindicato, s_liquido);
}