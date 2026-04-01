#include <stdio.h>
void divisor(int num) {
    for(int i = 1; i < num; num++) //gera possíveis divisores menores que o número
    {
        if(num % i == 0) { //testa se é divisor
            printf("%d",num);
            //imprime se for divisor
        }   
    }
}
int main() {
}