// erro - o programa não vai compilar
// warning - advertência - compila igual mas não de forma correta na mmaioria dos casos
// #include <biblioteca que vai usar>
#include <stdio.h> 
void titulo(int a) {
    putchar('L');
    putchar('a');
    putchar('b');
    putchar(a);
    putchar('\n');
}
//void - titulo não dá retorno algum
int main() {
    //putchar(80); //80 é o código para a letra P da tabela ASCII
    titulo(80);
    putchar('\n');
    titulo('2');
    titulo('\n');   
}
// entre aspas simples só pode utilizar um caractere e são aceitos somente da tabela ASCII
// \a  
// \b 
// \r 
// \\ 
// \' 
// \"
