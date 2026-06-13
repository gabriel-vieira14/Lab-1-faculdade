#include <stdio.h>
void tabuada(int n) {
    for(int i = 0; i <= 9; i++) {
        printf("%d x %d = %d\n",i, n, (n * i));
    }
}
int main() {
    int n;
    printf("Digite o número que você quer a tabuada:\n");
    scanf("%d",&n);
    tabuada(n);
}