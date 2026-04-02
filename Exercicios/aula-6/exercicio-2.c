#include <stdio.h>
void imp_astericos(int n) {
    for(int i = 1;i <= n;i++) {
        putchar('*');
    }
    putchar('\n');
}
int main() {
    imp_astericos(1);
    imp_astericos(2);
    imp_astericos(3);
}