//Por exemplo, se quisermos uma função que recebe um número como parâmetro e imprime o caractere correspondente entre colchetes, ppodemos fazer assim:
#include <stdio.h>

   void colch(int c)
   {
       putchar('[');
       putchar(c);
       putchar(']');
   }

   int main()
   {
       colch('X');
       colch('9');
   }