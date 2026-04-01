#include <stdio.h>
void pp(int n) {
    for(int i = 1;i <= n;i++) {
        if(i % 10 == 0) {
            printf("%d\n",i);
            if(i % 3 == 0) {
                printf("pa\n",i);
                if(i % 5 == 0) {
                   if(i % 3 == 0) {
                    printf("papum\n",i);
                    }
                }
            }
        }
    }
}
int main() {
    pp(15);
}