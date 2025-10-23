#include <stdio.h>

int main() {
    int i = 10, j = 18;
    printf("%.2f", ((++i + j++)/2.0));
    //11+18=29/2.0==14.50
    
    return 0;
}