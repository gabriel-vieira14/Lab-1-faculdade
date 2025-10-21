#include <stdio.h>

int main() {
    float result, a = 1, b = 2, c = 3, d = 7, e = 8;
    result = (b-(c*7))/(4-(a*c*a));
    //(2-(3*7))/(4-(1*3*1))
    //(2-21)/(4-3)
    //-19/1
    //-19
    printf("%.2f", result);
    return 0;
}