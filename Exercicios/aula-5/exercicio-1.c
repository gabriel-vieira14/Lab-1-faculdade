#include <stdio.h>
void impnum(int num) {
    if (num >= 10) {
        //50 >= 10 = V
        // e por que esse teste? por que não faz sentido pegar o dígito das dezenas se o número for menor que 10
        impnum(num / 10);
        putchar('\n');
        // 50 / 10 = 5 
    }
    putchar('0' + num % 10);
    //pega o dígito das unidades
    
}
int main() {
    impnum((50 +21) + 7 * 5);
    impnum((100 * 32) + 7 * 5);
    impnum((254 * 256) + 7 * 11 - 500 /10);
}