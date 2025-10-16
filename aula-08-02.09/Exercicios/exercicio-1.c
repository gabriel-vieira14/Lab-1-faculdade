#include <stdio.h>

int main() {
    int i;
    float a,b,c;
    printf("Digite um valor para a:\n");
    scanf("%f", &a);
    printf("Digite um valor para b:\n");
    scanf("%f", &b);
    printf("Digite um valor para c:\n");
    scanf("%f", &c);
    printf("Em qual ordem ordem você quer que sejam mostrados os valores?\n");
    printf("Digite 1 para crescente, 2 para decrescente e 3 para que o maior valor fiquei no meio dos outros dois:\n");
    scanf("%d", &i);

    switch(i) {
        case 1: 
            if(a > b && b > c ) {
                printf("%.2f > %.2f > %.2f",a,b,c);
            }  else if (a > b && c > b) {
                    printf("%.2f > %.2f > %.2f\n",a,c,b);
            } else if (b > a && a > c) {
                    printf("%.2f > %.2f > %.2f\n",b,a,c); 
            } else if (b > c && c > a) {
                    printf("%.2f > %.2f > %.2f\n",b,c,a); 
            } else if (c > a && a > b) {
                    printf("%.2f > %.2f > %.2f\n",c,a,b); 
            } else {
                    printf("%.2f > %.2f > %.2f\n",c,b,a); 
            }
            break;
        case 2: if(a < b && b < c) {
            printf("%.2f < %.2f < %.2f",a,b,c);
            }  else if (a < c && c < b) {
                printf("%.2f < %.2f < %.2f",a,c,b);
            } else if (b < a && a < c) {
                printf("%.2f < %.2f < %.2f",b,a,c); 
            } else if (b < c && c < a) {
                printf("%.2f < %.2f < %.2f",b,c,a); 
            } else {
                printf("%.2f < %.2f < %.2f",c,a,b); 
            }
            break;
    }   
    
}