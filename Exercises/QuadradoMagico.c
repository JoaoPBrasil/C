#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 3 

void preencheMatriz (int m[][TAM], int nl, int nc, int lim);
int somaDiag (int m[][TAM], int tam, int dir);
int somaLinha (int m[][TAM], int nc, int lin);
int somaColuna (int m[][TAM], int nl, int col);
int ehQuadradoMagico (int m[][TAM], int tam);

int main()
{
	int matriz[TAM][TAM];
	
	srand(time(NULL));
	
	preencheMatriz(matriz, TAM, TAM, 2);
	
	matriz[TAM][TAM] = {{8, 0, 7},{4, 5, 6},{3, 10, 2}};
	
	imprimeMatriz(matriz, TAM, TAM);
	
	if (ehQuadradoMagico(matriz, TAM))
	{
		printf("A matriz eh quadrado magico!");
	}
	else
	{
		printf("A matriz NAO eh quadrado magico!");
	}
	
	return 0;	
	
}

int ehQuadradoMagico (int m[][TAM], int tam)
{
	int i, j, valorReferencia;
	
	valorReferencia = somaDiag(m, TAM, 1);
	
	if (somaDiag (m, TAM, -1) != valorReferencia)
	{
		return 0;
	}
	
	for (i = 0; i < tam; i++)
	{
		if (somaLinha(m, tam, i) != valorReferencia)
		{
			return 0;
		}
	}
	
	for (j = 0; j < tam; j++)
	{
		if (somaColuna(m, tam, j) != valorReferencia)
		{
			return 0;
		}
	}
	
	return 1;
}

int somaDiag (int m[][TAM], int tam, int dir)
{
	int i, j, soma = 0, inic;
	
	if (dir == 1)
	{
		inic = 0;
	}
	else
	{
		if (dir == -1)
		{ 
			inic = tam = -1;
		}
	}
	
	for (i = 0, j = inic; i < tam; i++, j = j + dir)
	{
		soma = soma + m[i][j];
	}
	
	return soma;
}

int somaLinha (int m[][TAM], int nc, int lin)
{
	int j, soma = 0;
	
	for (j = 0; j < nc; j++)
	{
		soma = soma + m[lin][j];
	}
	
	return soma;
}

int somaColuna (int m[][TAM], int nl, int col)
{
	int i, soma = 0;
	
	for (i = 0; i < nl; i++)
	{
		soma = soma + m[i][col];
	}
	
	return soma;
}
