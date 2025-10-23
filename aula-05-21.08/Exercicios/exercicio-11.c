#include <stdio.h>

int main() {
    int dias_trabalhados, vl_hora= 30;
    float salario_sem_ir, salario_final;
    printf("Digite quantos dias foram trabalhados:\n");
    scanf("%d", &dias_trabalhados);
    salario_sem_ir = dias_trabalhados * vl_hora;
    salario_final = salario_sem_ir - (salario_sem_ir * 0.08);

    printf("O salario do encanador é de %f", salario_final);

}