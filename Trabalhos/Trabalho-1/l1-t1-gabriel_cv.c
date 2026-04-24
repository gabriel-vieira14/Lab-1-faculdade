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
long double fatorial(long double n) {
    long double mult=0;
    long double fat;
    while(mult != 0) {
        fat = fat *  mult;
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
double abs(double termo){
    double vl_absoluto;
    if(termo < 0.0) {
        vl_absoluto = -termo;
    } else {
        vl_absoluto = termo;
    }
    return vl_absoluto;
}
double calcula_seno(double angulo) {
    double soma = 0.0, termo_soma_inv, termo_soma,termo_abs;
    int impar= 1, sinal  = 1;
    while(1) {
        termo_soma = pot(angulo, impar)/fatorial(impar);
        termo_soma_inv = termo_soma * sinal;
        soma += angulo + termo_soma_inv;
        impar =+ 2;
        sinal *= -1;
        termo_abs = abs(termo_soma_inv);
        if(termo_abs < 1e-10) {
            break;
        }
    }
}
void testa_seno() {
    float angulo;
    double seno;
    printf("Digte um ângulo para calcular o seno dele:\n");
    scanf("%f",&angulo);
    calcula_seno(angulo);
    printf("O seno(%f) é: %lf\n", angulo, seno);
}
double calcula_raiz(double x) {
    double chute,novo_chute, diferenca, raiz;
    printf("Chute um valor:\n");
    scanf("%lf", &chute);
    if(chute <= 0) {
        printf("Você chutou um número inválido! Chute apenas valores positivos diferentes de 0!\n");
        scanf("%lf", &chute);    
    }
    while(1)  {
        // aqui calcula a média 
        novo_chute = ((chute) + (x/chute)) / 2.0;
        // diferença entre dois chutes sucessivos
        diferenca = novo_chute - chute;
        //condição de parada
        if(abs(diferenca) < 1e-10) {
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

int main() {
    testa_pot();
    testa_fatorial();
    testa_raiz();
    testa_seno();

}