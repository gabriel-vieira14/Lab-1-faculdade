#include <stdio.h>

int main() {
    const int NUM = 5;
    int NUM_sucessor, NUM_antecessor;
    NUM_sucessor = NUM + 1;
    NUM_antecessor = NUM - 1;
    printf("O sucessor da constante NUM é %d\n", NUM_sucessor);
    printf("O antecessor da constante NUM é %d\n", NUM_antecessor);

}