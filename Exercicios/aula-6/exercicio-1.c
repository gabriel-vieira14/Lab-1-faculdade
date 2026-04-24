#include <stdio.h>
void imp_astericos(int n) {
    for(int i = 1;i <= n;i++) {
        putchar('*');
    }
}
int main() {
    imp_astericos(10);
}