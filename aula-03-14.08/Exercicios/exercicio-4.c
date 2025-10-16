#include <stdio.h>

int main() {
    float preco, desconto, acrescimo;
    
    printf("Digite o preco do produto:\n");
    scanf("%f", &preco);
    desconto = preco - (0.10 * preco);

    acrescimo = preco +(0.10 * preco);

    printf("O preco inicial do produto e %.2f, o produto com desconto e %.2f e o preco com acrescimo e %.2f", preco, desconto, acrescimo);
    return 0;
}