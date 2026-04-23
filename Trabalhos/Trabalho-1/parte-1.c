#include <stdio.h>
#define PI 3.1415
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
double fatorial(int n) {
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
double conversao_graus_rad(double grau) {
    double radianos;
    radianos = (grau * PI)/180;
    return radianos;
}
double calcula_seno(double angulo) {
    
}
double calcula_raiz(double x) {
    double chute,novo_chute, chute_abs, diferenca, diferenca_abs, raiz;
    int loop=1;
    printf("Chute um valor:\n");
    scanf("%lf", &chute);
    if(chute <= 0) {
        printf("Você chutou um número inválido! Chute apenas valores positivos diferentes de 0!\n");
        scanf("%lf", &chute);    
    }
    while(loop == 1)  {
        // aqui calcula a média 
        novo_chute = ((chute) + (x/chute)) / 2.0;
        // diferença entre dois chutes sucessivos
        diferenca = novo_chute - chute;
        //valor absoluto da diferenca
        if(diferenca < 0) {
            diferenca_abs = -diferenca;
        } else if(diferenca >= 0) {
            diferenca_abs = diferenca;
        }
        //condição de parada
        if(diferenca_abs < 0.0000000001) {
            loop = 0;
        }
        // pra a variável chute não rodar sempre com os mesmos números
        chute = novo_chute;
    }
    raiz = novo_chute; 
    return raiz;
}
void testa_raiz() {

}
int main() {
    testa_pot();
    testa_fatorial();
}