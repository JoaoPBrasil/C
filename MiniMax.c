#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NLIN 10
#define NCOL 10

void preencheMatriz (int m[][NCOL], int nl, int nc, int lim);
void imprimeMatriz (int m[][NCOL], int nl, int nc);
int encontraMinimax (int matriz[][NCOL], int nl, int nc, int *l, int *c);
int maiorElemMatriz (int m[][NCOL], int nl, int nc, int *lmaior);
int menorElemVetor (int v[], int n, int *pos);

int main()
{
	int matriz[NLIN][NCOL], minMax, lin, col;
	
	srand(time(NULL));
	
	preencheMatriz(matriz, NLIN, NCOL, 20);
	
	imprimeMatriz(matriz, NLIN, NCOL);
	
	minMax = encontraMinimax(matriz, NLIN, NCOL, &lin, &col);
	
	printf("\nminimax: %d \nCoordenada: %d-%d \n", minMax, lin, col);
	
	
	return 0;
}

void preencheMatriz (int m[][NCOL], int nl, int nc, int lim)
{
	int i, j;
	
	for (i = 0; i < nl; i++)
	{
		for(j = 0; j < nc; j++)
		{
			m[i][j] = rand() % lim + 1;
		}
	}	
}

void imprimeMatriz (int m[][NCOL], int nl, int nc)
{
	int i, j;
	
	for (i = 0; i < nl; i++)
	{
		for (j = 0; j < nc; j++)
		{
			printf("%4d", m[i][j]);
			printf("\n");
		}
	}	
}

int encontraMinimax (int matriz[][NCOL], int nl, int nc, int *l, int *c)
{
	int maior, limM;
	int minimax, colm;
	
	maior = maiorElemMatriz(matriz, nl, nc, &limM);
	printf("\nmaior: %d", maior);
	
	minimax = menorElemVetor(matriz[limM], NCOL, &colm);
	
	*l = limM;
	*c = colm;
	
	return minimax;
}

int maiorElemMatriz (int m[][NCOL], int nl, int nc,int *lmaior)
{
	int i, j;
	int maior = m[0][0];
	
	*lmaior = 0; 	
	
	for (i = 0; i < nl; i++)
	{
		for (j = 0; j < nc; j++)
		{
			if (m[i][j] > maior)
			{
				maior = m[i][j];
				*lmaior = i;
			}
		}
	}
	
	return maior;
}

int menorElemVetor(int v[], int n, int *pos)
{
	int i;
	int menor = v[0];
	
	*pos = 0;
	
	for (i = 1; i < n; i++)
	{
		if (v[i] < menor)
		{
			menor = v[i];
			*pos = i;	
		} 
	}	
		
	return menor;
}
