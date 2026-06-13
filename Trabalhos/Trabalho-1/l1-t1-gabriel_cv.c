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
    printf("%lf elevado a %d é: %lf\n", base, pot_max, resultado);
}
long double fatorial(long double n) {   
    long double fat=1.0;
    for(int i = 1; i <= n; i++) {
        fat *= i;
    }
    return fat;
}
void testa_fatorial() {
    long int n;
    long double res;
    printf("Digite o número que você quer calcular o fatorial:\n");
    scanf("%ld",&n);
    res = fatorial(n);
    printf("%ld! = %Lf\n",n,res);

}
double vl_abs(double termo){
    double vl_absoluto;
    if(termo < 0.0) {
        vl_absoluto = -termo;
    } else {
        vl_absoluto = termo;
    }
    return vl_absoluto;
}
double calcula_seno(double radianos) {
    double soma = 0.0, termo_soma_inv, termo_soma,termo_abs;
    int impar= 1, sinal  = 1;
    while(1) {
        termo_soma = pot(radianos, impar)/fatorial(impar);
        termo_soma_inv = termo_soma * sinal;
        soma += termo_soma_inv;
        impar += 2;
        sinal *= -1;
        termo_abs = vl_abs(termo_soma);
        if(termo_abs < 1e-10) {
            break;
        }
    }
    return soma;
}
void testa_seno() {
    double angulo,radianos, seno;
    printf("Digite um ângulo em graus para calcular o seno dele:\n");
    scanf("%lf",&angulo);
    radianos = angulo * (PI / 180.0);
    seno = calcula_seno(radianos);
    printf("O seno(%.2f°) é: %lf\n", angulo, seno);
}
double calcula_raiz(double x) {
    double chute = x / 2.0;
    double novo_chute, diferenca, raiz;
    if (x == 0.0) {
        return 0.0;
    }
    while(1)  {
        // aqui calcula a média 
        novo_chute = ((chute) + (x/chute)) / 2.0;
        // diferença entre dois chutes sucessivos
        diferenca = novo_chute - chute;
        //condição de parada
        if(vl_abs(diferenca) < 1e-10) {
            break;
        }
        // pra a variável chute não rodar sempre com os mesmos números
        chute = novo_chute;
    }
    raiz = novo_chute; 
    return raiz;
}
void testa_raiz() {
    double numero, res;
    printf("Digite o número que você quer calcular a raiz quadrada:\n");
    scanf("%lf", &numero);
    res = calcula_raiz(numero);
    printf("A raiz quadrada de %.2lf é: %.10lf\n", numero, res);  
}
double calcula_cosseno(double angulo) {
    double seno,cosseno,seno_ao_quad, raiz_seno;
    seno = calcula_seno(angulo);
    seno_ao_quad = seno * seno;
    raiz_seno = 1.0 - seno_ao_quad;
    cosseno = calcula_raiz(raiz_seno);
    return cosseno;
}
void testa_cosseno() {
    double angulo, cosseno, radianos;
    printf("Digte um ângulo em graus para calcular o cosseno dele:\n");
    scanf("%lf",&angulo);
    radianos = angulo * (PI / 180.0);
    cosseno = calcula_cosseno(radianos);
    printf("O cosseno de %.2lf é: %.5lf\n",angulo, cosseno);
}
void tabela_seno_cosseno() {
    double cosseno,seno, radianos;
    int angulo;
    printf("ang   seno    cos   seno    cos   seno    cos   seno    cos   seno    cos \n"); 
    for(int i = 0;i <= 89;i += 5) {
        printf("%2d  ", i);
        for(int j= 0;j < 5;j++) {
            angulo = i + j;
            radianos = angulo * (PI / 180.0);
            seno = calcula_seno(radianos);
            cosseno = calcula_cosseno(radianos);
            printf(" %6.4lf %6.4lf", seno, cosseno);
        }
        printf("\n");
    }
}
int main() {
    testa_pot();
    testa_fatorial();
    testa_raiz();
    testa_seno();
    testa_cosseno();
    tabela_seno_cosseno();
}