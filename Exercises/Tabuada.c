#include <stdio.h>

int main()
{
    int x,y,v = 0;

    printf("Insira um numero para mostrarmos sua tabuada: ");
    scanf("%d", &x);

    y = 1;
    while (y <= 10)
    {
    v = x * y;
   
        printf("%d\n",v);
       
        y = y + 1;
    }
}
