# include <stdio.h>

 void determinaValores (int n);

 int main ()
 {
 	int n;
 	
	printf ("Insira um valor para n: ");
 	scanf ("%d", &n) ;

 	determinaValores (n);

 	return (0) ;
 }

 void determinaValores (int n)
 {
 	int x, y;

 	for (x = 1; x < n; x ++)
 	{
 		for (y = 1; y < n - x; y ++)
 		{
 			printf ("%d\t%d\t%d\n", x, y, n - x - y);
 		}
 	}
 }
