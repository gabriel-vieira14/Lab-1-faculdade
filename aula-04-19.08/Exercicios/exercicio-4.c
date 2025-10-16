#include <stdio.h>

int main() {
    int qtd_horas_mes;
    float salario_b, salario_l, vl_hora_trabalhada;
    float inss,ir,c_sindical;
    printf("Digite o valor pago por hora trabalhada:\n");
    scanf("%f", &vl_hora_trabalhada);
    printf("Digite o o total de horas trabalhadas no mes:\n");
    scanf("%d", &qtd_horas_mes);

    salario_b = vl_hora_trabalhada * qtd_horas_mes;
    inss = 0.08 * salario_b;
    ir = 0.11 * salario_b;
     c_sindical = ( 0.05 * salario_b);
    salario_l = salario_b - (inss + ir + c_sindical);

    printf("O seu salario bruto e:%.2f\n", salario_b);
    
    printf("O seu salario liquido e: %.2f\n", salario_l);
    printf(" O descontos que incidem sobre o seu salário são os seguintes: %.2f de IR, %.2f de INSS e %.2f de contribuicao sindical.\n", ir, inss, c_sindical);








}