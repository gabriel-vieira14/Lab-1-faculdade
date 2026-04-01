  #include <stdio.h>
  void impnum(int num)
   {
      if (num >= 10) {
         impnum(num / 10);
      }
      putchar('0' + num % 10);
   }
   int main() {
    impnum(487);
   }