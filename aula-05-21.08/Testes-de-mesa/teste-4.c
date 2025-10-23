#include <stdio.h>
 
int main() {
   int x = 5, y, z;
    y = x++ + 2; //x vale 5 e y vale 7
    z = --x + 2; //x valia 6 na linha de cima e agora vale 5 e z vale  7
    printf("x = %d, y = %d, z = %d\n", x, y, z);
    return 0; 
}