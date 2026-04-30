// Faça uma função que calcula a raiz da equação
//   ax² + bx + c = 0
// usando o método de Bhaskara
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
bool bhaskara(double a, double b, double c, double* r1, double* r2) {
    double delta = pow(b,2) - 4 * a * c;
    if(delta > 0) {
        *r1 = (-b + sqrt(delta)) / (2 * a);
        *r2 = (-b - sqrt(delta))/ (2 * a);
        return true;
    } else if(delta < 0) {
        return false;
    }
}
int main() {
    double a, b, c;
    double r1, r2;
    printf("Digite os valores dos coeficientes ");
    printf("a, b e c da equação 'a x² + b x + c'\n");
    scanf("%ld %ld %ld", &a, &b, &c);
    if(bhaskara(a,b,c,&r1,&r2)) {
        printf("As raízes são: %f,%f", r1,r2);
    } else {
        printf("A equação não possuí raízes no conjunto dos reais");
    }
}