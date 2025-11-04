#include <stdio.h>

float validacao(int n) {
   float soma = 0, entrada;
   int cont_validos = 0, cont_invalidos = 0;   

   while(cont_validos < 10 && cont_invalidos < 10) {
      printf("Digite um número: ");
      scanf("%f", &entrada);
      if(entrada >= 0 && entrada <= n) {
         cont_validos++;
         soma += entrada;
      }
      else {
         cont_invalidos++;
      }
   }

   printf("quantidade de valores inválidos lidos: %d\n", cont_invalidos);
   if(cont_validos == 0) return 0;
   return soma/cont_validos;
}

int main() {
   int n;
   float media;
   printf("Digite o n da validação: ");
   scanf(" %d", &n);
   media = validacao(n);
   printf("media dos valores validos : %.2f\n", media);
}
