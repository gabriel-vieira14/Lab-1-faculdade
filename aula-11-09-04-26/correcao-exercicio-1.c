#include <stdio.h>
int main() {
  float peq = 0.0000000001;
  float gra = 1;
  for (;;) {
    float meio = (peq + gra) / 2 ;
    if (meio == peq) {
      printf("maior que nao afeta: %.15f\n", peq);
      return 0;
    }
    float um = 1;
    float soma = um + meio;
    printf("%.15f %.15f %.15f %.15f\n", peq, gra, meio, soma);
    if (soma == um) {
      peq = meio;
    } else {
      gra = meio;
    }
  }
}

  
