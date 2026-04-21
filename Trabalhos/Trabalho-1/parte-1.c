#include <stdio.h>
const double PI = 3.1415;
double pot(double x,int numero) {
    double res= 1.0;
    int numero_absoluto = numero;
    //caso o expoente seja negativo, fica positivo pra entrar no laço
    if (numero < 0) {
        numero_absoluto = -numero;
    }
    for(int i= 0;i < numero_absoluto; i++) {
        res *= x;
    }
    // Como transformamos o exponte negativo em positivo, agora temos que transformar de volta em negativo.
    if (numero < 0) {

        return 1.0 / res;
    }
    return res;
}
void testa_pot() {
    double base;
    int pot_max;
    double resultado;
    printf("Digite o número que você quer elevar:\n");
    scanf("%lf",&base);
    printf("Digite o número de potências que você quer calcular:\n");
    scanf("%d",&pot_max);
    resultado = pot(base, pot_max);
    printf("%.2lf elevado a %d é: %.5lf\n", base, pot_max, resultado);
}
long double fatorial(long int n) {
    long int mult=0;
    long double fat = 1;
    mult = n;
    while(mult != 0) {
        fat = fat * mult;
        mult--;
    }
    return fat;
}
void testa_fatorial() {
    long int n;
    long double res;
    printf("Digite o número que você quer calcular o fatorial:\n");
    scanf("%ld",&n);
    res = fatorial(n);
    printf("%ld! = %Lf",n,res);

}
double conversao_graus_rad(double graus) {
    double radianos;
    radianos = (graus * PI)/180;
    return radianos;
}

int main() {
    testa_pot();
    testa_fatorial();
}