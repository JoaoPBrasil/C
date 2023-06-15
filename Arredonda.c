#include <stdio.h>

int arredonda (float x)
{
	
	float dec = x - (int)x;
	int xInteiro = (int)x;
	
	if(dec <= 0.5)
	{
		return xInteiro;
	}
	else
	{
		return (xInteiro + 1);
	}
}

int main()
{
	
	float x;
	
	printf("Insira um numero para arredondarmos: ");
	scanf("%f", &x);
	
	printf("O numero arredondado e igual a: %d\n", arredonda(x));

	return 0;				
}
