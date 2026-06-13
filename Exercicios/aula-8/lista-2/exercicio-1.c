#include <stdio.h>
/*
    Altere a função anterior para no final imprimir o número de "papum" que foram impressos.
*/
void pa_pum(int n) { 
    for(int i = 1; i <= n; i++) {
        if(i % 3 == 0) {
            if(i % 10 == 5) {
                printf("papum ");
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
} 
int main() {
    int papum;
    pa_pum(16);
}
