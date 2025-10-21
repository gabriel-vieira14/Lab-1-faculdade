#include <stdio.h>

void substitui_caractere()
{
    char frase[10], nova_frase[10];
    char c1, c2;

    printf("Digite uma frase:\n");
    fgets(frase, 10, stdin);
    printf("Digite o caractere que você quer substituir na frase: \n");
    scanf(" %c", &c1);
    printf("Digite o caractere o novo caractere que vai substituir o digitado anteriormente:\n");
    scanf(" %c", &c2);
    for (int i = 0; frase[i] != '\0'; i++)
    {
        if (frase[i] == c1)
        {
            nova_frase[i] = c2;
        }
        else
        {
            nova_frase[i] = frase[i];
        }
    }
    puts(frase);
    puts(nova_frase);
}
int main()
{
    substitui_caractere();
}