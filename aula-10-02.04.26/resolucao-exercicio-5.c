/*
Faça uma função que lê caracteres do teclado até ser digitado enter. Os caracteres que não são dígitos decimais devem ser ignorados. Os caracteres que são dígitos devem ser usados para formar um número, que será retornado pela função quando ela ler o enter. Dica: se em certo momento a função já tem o valor 34 (porque já foram lidos os dígitos '3' e '4') e for lido o dígito '7', o novo valor pode ser calculado por 34 * 10 + 7.
*/
#include <stdio.h>
int lechar() {
    int numero = 0, novo_numero;
    char caractere;
    while(1) {
        caractere = getchar();
        if((caractere <= '0') && (caractere <= '9')) {
            numero = numero * 10 + (caractere - '0');
            //subtrai o codigo do 0 pra transformar em numero
            //num * 10 para deslocar o numero anterior para a esquerda
        } else if(caractere == '\n') {
            return numero;
        } else {
            ;
        }
    }

}
int main() {
    lechar();
    
}