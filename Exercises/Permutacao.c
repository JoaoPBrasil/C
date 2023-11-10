# include <stdio.h>

 int contadigitos (int i , int a);
 int ehPermutacao (int n1 , int n2);

 main ()
 {
	int x , y;
	
	printf (" Digite dois inteiros : ") ;
	scanf ("%d %d" ,&x ,& y);
	
	if (ehPermutacao (x , y) == 1)
	printf ("%05d e permutacao, %05 d\n",x , y);
	else
	printf ("%05d Nao e permutacao, %05 d\n",x ,y);

 }

 int contadigitos ( int i , int a)
 {
	int conta = 0, resto;
	
	while (i != 0)
	{
		resto = i % 10; 
		i = i /10; 
		if ( resto == a)
		{
			conta ++;
		}
	}
	
	return conta;
 }

 int ehPermutacao ( int n1 , int n2 )
 {
	 int a, ehPermut = 1;
	
	for (a = 1; a <= 9; a ++) 
	{
	 
		if ( contadigitos (n1 ,a) != contadigitos (n2 ,a) )
		{ 
		 ehPermut = 0;
		}
	}	
		
		if (ehPermut == 1) 
		{
			return 1;
		}
		 else
		{
		 	return 0;
		}		
 }
