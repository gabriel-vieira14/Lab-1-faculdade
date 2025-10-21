#include <stdio.h>


int main() {
   int x = 5, y, z;
   y = ++x + 2;// x vale 6
   printf("x= %d, y = %d\n",x,y); //x vale 6
   z = x-- + 2; // x vale 6
   printf("x = %d, z = %d\n", x, z); // x vale 5
   printf("x = %d, y = %d, z = %d\n", x, y, z); //x vale 5
   return 0;
}