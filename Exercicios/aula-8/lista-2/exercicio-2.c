#include <stdio.h>
/*
    Faça uma função que recebe um número e imprime os valores entre 1 e o número recebido de uma forma especial:

    como um número decimal ou
    como "pa" se for múltiplo de 3 ou
    como "pum" se terminar com o dígito 5 ou
    como "papum" se terminar com o dígito 5 e também for múltiplo de 3.
    Não pode usar os operadores || nem &&.
*/
int pa_pum(int n) { 
    int papum;   
    for(int i = 1; i <= n; i++) {
        if(i % 3 == 0) {
            if(i % 10 == 5) {
                printf("papum ");
                papum++;
            } else {
                printf("pa "); 
            }
            
        } else  {
            if(i % 10 == 5) {
                printf("pum ");
            } else {
                printf("%d ", i);
            }
            
        }
    }
    return papum;
} 
int main() {
    int papum;
    papum = pa_pum(16);
    printf("\n Foram impressos %d papums\n", papum);
}
