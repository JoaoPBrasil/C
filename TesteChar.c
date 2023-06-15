#include <stdio.h>

int testaTipoChar (char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return 1;
	}
	else if (c >= 'a' && c <= 'z')
	{
		return 2;
	}
	else if ( c >= '0' && c <= '9') 
	{
		return 3;
	}
	else 
	{
		return 0;
	}
}

int main()
{	
	char testechar;
	
	printf("Insira um caractere para testarmos se é Maiusculo, Minusculo, Digito ou outro: ");
	scanf("%c",&testechar);
	
	int resp = testaTipoChar(testechar);
	
	printf("O caractere e do tipo: %d", resp);
	
	return 0;
}
