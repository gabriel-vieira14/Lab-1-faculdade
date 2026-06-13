#include <stdio.h>
void linha(int n) {
    for(int i = 1;i <= n;i++) {
        putchar('*');
    }
}
void espacos(int n) {
    //4
    for(int i = 1;i <= n;i++) {
        putchar(' ');
    }
}
int main() {
    int n = 4;
    while (n > 0) {
        linha(n);
        n--;
        espacos(n);
        putchar('\n');
    }
}
