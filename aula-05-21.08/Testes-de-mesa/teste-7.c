#include <stdio.h>

int main() {
int x;
int y;
int z;
x = 10;
y = -20;
z = x-y;//10-(-20)
//10 +20 = 30
printf("Resultado 1 = %d\n", z); 
z = y+x; //-10
printf("Resultado 2 = %d\n", z);
z = z/(x/5);
//-10 / (10/5)
//-10/2
//-5
printf("Resultado 3 = %d\n", z);
return(0);
}