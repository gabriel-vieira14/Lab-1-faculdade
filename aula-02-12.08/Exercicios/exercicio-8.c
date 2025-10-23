#include <stdio.h>

int main() {
    int i=1;
    printf("*%d%d%d%d%2d%d%d%d*\n", i,i,i,i,i,i,i,i);
    printf("*%d%d%d%4d%d%d*\n", i,i,i,i,i,i);
    printf("*%d%d%6d%d*\n", i,i,i,i);
    printf("*%d%8d*\n", i,i);
    printf("*%d%d%6d%d*\n", i,i,i,i);
    printf("*%d%d%d%4d%d%d*\n", i,i,i,i,i,i);
    printf("*%d%d%d%d%2d%d%d%d*\n", i,i,i,i,i,i,i,i);
}