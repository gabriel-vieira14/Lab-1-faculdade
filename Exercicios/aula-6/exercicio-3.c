#include <stdio.h>
void linha(int n) {
    for(int i = 1;i <= n;i++) {
        putchar('*');
    }
    putchar('\n');
}
int main() {
   int n = 1;
    while (n <= 5) {
        linha(n);
        n++;
    }
}