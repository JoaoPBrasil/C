 #include <stdio.h>
 #include <math.h>

void funcDecInc (int *x , int *y);

 int main ()
 {
	int n1 , n2 ;
	
	printf ("Insira dois valores inteiros:") ;
	scanf ("%d %d", &n1 ,&n2 );
	funcDecInc (&n1 , &n2 );
	printf ("Os novos valores são : %d %d", n1, n2) ;
	
	return 0;
 }

 void funcDecInc (int *x , int *y)
 {
	 *x = *x - 1; 
	 *y = *y + 1; 
 }
