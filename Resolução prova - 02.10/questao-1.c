#include <stdio.h>
int reverso(int n)
{
    int reverso = 0;
    while (n > 0)
    {
        int unidade = n % 10;
        reverso = reverso * 10 + unidade;
        n = n / 10;
    }
    return reverso;
}
int main()
{
}