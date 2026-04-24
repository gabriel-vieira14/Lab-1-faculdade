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
    int n = 1;
    while (n <= 4) {
        espacos(4-n);
        linha(n);
        putchar('\n');
        n++;
    }
}
