// Faça uma função que calcula a raiz da equação
//   ax² + bx + c = 0
// usando o método de Bhaskara
// é utilizado ponteiro por que não tem como retornar as duas raizes ao mesmo tempo
#include <stdio.h>
#include <math.h>
#include <stdbool.h>

bool bhaskara(double a, double b, double c, 
              double *r1, double *r2)
{ 
  double delta = pow(b, 2) - 4 * a * c;
  if (delta < 0) return false;
  *r1 = (-b + sqrt(delta)) / (2 * a);
  *r2 = (-b - sqrt(delta)) / (2 * a);
  return true;
}

int main()
{
  double a, b, c;
  double raiz1, raiz2;
  printf("Digite os valores dos coeficientes ");
  printf("a, b e c da equação 'a x² + b x + c'\n");
  scanf("%ld%ld%ld", &a, &b, &c);
  if (bhaskara(a, b, c, &raiz1, &raiz2)) {
    printf("As raizes são %f e %f\n", raiz1, raiz2);
  } else {
    printf("Equação sem raízes reais\n");
  }
}







