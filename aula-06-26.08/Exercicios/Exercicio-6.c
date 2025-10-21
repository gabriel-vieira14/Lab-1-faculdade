#include <stdio.h>

int main()
{
    float altura, peso;
    char sexo;

    printf("\n---- Calculadora de peso ideal-----\n");
    printf("Digite o sexo do paciente: H para homem e M para mulher\n");
    scanf("%c", &sexo);
    printf("Digite a altura do paciente:\n");
    scanf("%f", &altura);
    if (sexo == 'M')
    {
        peso = (72.7 * altura) - 58;
    }
    else if (sexo == 'M')
    {
        peso = (62.1 * altura) - 44.7;
    }
    printf("O peso ideal do paciente é:%f\n", peso);
}