# include <stdio.h>
# include <math.h>

 int calcula_raizes (float x , float y , float z , float * r1 , float * r2);

 int main ()
 {
	float x , y , z , r1 , r2 ;
	
	printf ("Informe os coeficientes para realizarmos a equacao de segundo grau ax ^2 + bx + c: ");
	scanf ("%f %f %f", &x ,&y ,& z);

	printf ("%f %f %f\n", x ,y ,z) ;
	
	if(calcula_raizes (x ,y ,z ,& r1 ,& r2 ) == 1)
	{
		printf ("As raizes correspondentes a equacao %.2 f x^2 + %.2 f x + %.2 f sao %.2f e %.2 f", x ,y ,z , r1 , r2 );
	}
	else
	{
		printf ("Nao existem raizes reais.");
	}
	
	return 0;
 }

 int calcula_raizes ( float x, float y, float z, float * r1, float * r2)
 {
	float delta;
	
	delta = (y* y) - (4* x*z);
	
	printf ("O delta e igual a: %f", delta );
	
	if( delta <0)
	{
		return ( -1);
	}
	else if( delta ==0)
	{
		* r1 = -y /(2* x) ;
	 	* r2 = * r1 ;
	}
	else
	{
	 	* r1 = (-y + sqrt ( delta ) ) /(2* x);
	 	* r2 = (-y - sqrt ( delta ) ) /(2* x);
	}
 	return (1);
 }
