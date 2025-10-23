#include <stdio.h>

int main() {
    
    char palavra[16];
  
    printf("Digite uma palavra de até 15 letras:\n");
    scanf("%s", palavra);

    printf("\"%s\"\n", palavra);
    return 0;
}