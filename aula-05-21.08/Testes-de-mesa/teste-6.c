#include <stdio.h>

int main() {
    printf("%d\n", !0);//1
    printf("%d\n", !9);
    //0 pois só daria 1 se fosse 0 a entrada,
    //qualquer número exceto 1 é visto como 0 pelo "!"


    printf("%d\n", 1&&0);//0
    printf("%d\n", 0||1);//1
    printf("%d\n", 2<3 || 3<2);
    //1 || 0 
    // 1
    return 0;
}