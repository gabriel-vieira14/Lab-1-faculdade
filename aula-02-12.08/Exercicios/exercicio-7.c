#include <stdio.h>

int main() {
printf("1.Os alunos são %d.\n", 350);
//normal
printf("2.Os alunos são %2d.\n", 350);
//minimo de duas casas antes da vírgula
printf("3.Os alunos são %4d.\n", 350);
//minimo 4 casas antes da virgula
printf("4.Os alunos são %6d.\n", 350);
//minimo 6 casas antes da virgula
printf("5.Os alunos são %02d.\n", 350);
/*minimo 2 casas antes da virgula com os espaços em branco
preenchidos com zeros*/
printf("6.Os alunos são %04d.\n", 350);
/*minimo 4 casas antes da virgula com os espaços em branco
preenchidos com zeros*/
printf("7.Os alunos são %06d.\n", 350);
/*minimo 6 casas antes da virgula com os espaços em branco
preenchidos com zeros*/
printf("8.Os alunos são %10.02d.\n", 350);
printf("9.Os alunos são %10.04d.\n", 350);
printf("10.Os alunos são %10.06d.\n", 350);
/*Esses três ultimos colocam um espaço de 10 caracteres em branco antes do número e os formatos .02,.04 e .06 fazem com que o o número inteiro  tenha no mínimo essa quantidade de dígitos e se ele não tiver, é preenchido com zeros*/
}