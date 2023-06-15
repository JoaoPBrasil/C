#include <stdio.h>

int main()
{
    int n,y;

    printf("Insira um numero inteiro: ");
    scanf("%d", &n);

    y = 1;
   
    while (y <= 100)
    {
    if(y % n == 2)
{
    printf("%d\n", y);
}

    y = y + 1;
    }
}
