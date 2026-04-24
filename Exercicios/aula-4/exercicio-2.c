#include <stdio.h>
void caractere(int num) {
    putchar('\n');
    putchar('|');
    putchar(' ');    
    putchar(num);
    putchar(' ');
    putchar('|');

}
void sinais() {
    putchar('\n');
    putchar('+');
    putchar('-');
    putchar('-');
    putchar('-');
    putchar('+');
}
void nome() {
    caractere(74);//| J |
    caractere(117);//| u |
    caractere(99);//| c |
    caractere(97);//| a |
}
int main() {
    sinais();
    nome();
    sinais();
}