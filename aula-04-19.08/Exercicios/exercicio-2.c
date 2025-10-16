#include <stdio.h>

int main() {

    int a=5,b=2,c;
    float d;

    c = a/b; //imprime só a parte inteira do valor
    printf("%d\n",c);
    d = (float)a/b;
    printf("%.2f\n",d);
    return 0;
}
