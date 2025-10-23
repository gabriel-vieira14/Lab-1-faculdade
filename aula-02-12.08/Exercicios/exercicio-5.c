#include <stdio.h>

int main()
{
    char nome[10];
    int idade;
    printf("Qual meu nome?\n");
    // Use fgets for safer input to prevent buffer overflows
    if (fgets(nome, sizeof(nome), stdin) != NULL)
    {
        // Remove the newline character that fgets might leave
        nome[strcspn(nome, "\n")] = 0;
    }
    printf("Qual minha idade?\n");
    scanf("%d", &idade);

    printf("Meu nome é %s.\nEu tenho %d anos\n", nome, idade);
}