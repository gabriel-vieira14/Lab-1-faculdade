#include <stdio.h>

// Vamos criar uma função com um nome mais claro para o que ela faz.
// Ela vai receber apenas um número: o tamanho inicial do triângulo.
void triangulo_invertido(int tamanho) {
    // tamanho = 4;
    // Este primeiro laço (o "de fora") controla as LINHAS.
    for (int i = tamanho; i >= 1; i--) {
        //1a execução
            //4 maior ou igual a 1? = V
                //entra no laço de dentro
                    //1 menor ou igual a 4?=V
                        //desenha asterisco
                        //j vale 2
                    //2 menor ou igual a 4?=V
                        //desenha asterisco
                        //j vale 3
                    //3 menor ou igual a 4?=V
                        //desenha asterisco
                        //j vale 4
                    //4 menor ou igual a 4?=V
                        //desenha asterisco
                        //j vale 5
                    //desenha 4 asteriscos no final
                //sai do laço de dentro
            //pula linha
        //2a execução
            //4 maior ou igual a 1? = V
                //entra no laço de dentro
                    //1 menor ou igual a 4?=V
                        //desenha asterisco
                        //j vale 2
                    //2 menor ou igual a 4?=V
                        //desenha asterisco
                        //j vale 3
                    //3 menor ou igual a 4?=V
                        //desenha asterisco
                        //j vale 4
                    //4 menor ou igual a 4?=V
                        //desenha asterisco
                        //j vale 5
                    //desenha 4 asteriscos no final
                //sai do laço de dentro
            //pula linha
        //Este segundo laço controla os asteriscos
        for (int j = 1; j <= i; j++) {
            putchar('*');
        }
        putchar('\n');
    }
}

int main() {
    // Agora chamamos a função com o valor 4, como pedido no exercício.
    triangulo_invertido(4);
}