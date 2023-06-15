#include <stdio.h>

void converteHora (int total , int * hora, int * minutos, int * segundos);

 int main () 
 {

	int input, h, m, s;
	
	printf ("Infrome a quantidade de segundos para convertermos em Horas/Minutos/Segundos: ") ;
	scanf ("%d", & input);
	
	converteHora (input , &h , &m , &s);
	
	printf ("%d segundos correspondem a %d horas , %d minutos e %d segundos", input , h , m , s) ;
	
	return 0;
 }

 void converteHora (int total , int * hora , int * minutos , int * segundos)
 {
	* hora = total / (60*60);
	* minutos = total % (60*60) / 60;
	* segundos = total % (60*60) % 60;
 }
