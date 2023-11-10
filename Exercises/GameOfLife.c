#include <stdio.h>
#include <stdlib.h>

#define ORG 'X'
#define VAZ '.'
#define TAM 101
#define MAXL 100
#define MAXC 100

// o trecho abaixo define algumas macros
#ifdef __unix__
    #include <unistd.h>
    #define LIMPATELA "clear"
    #define DORME(a) sleep(a)
    #define TEMPO 5
#else
    #include <Windows.h>
    #define LIMPATELA "cls"
    #define DORME(a) Sleep(a)
    #define TEMPO 100
#endif


int main()
{

   char mat[MAXL][MAXC];

   int nL = 20, nC = 20, nCiclos = 50;

int n = 1;

printf("Seja Bem-vindo ao jogo da vida!");

while (n == 1)
{
		menuInicJogo(mat,nL,nC);
        jogaJogoVida(mat,nL,nC,nCiclos);
       
       
        printf("Deseja jogar novamente?\n 1- Sim\n qualquer outro numero para Nao");
        scanf("%d",&n);
       
        
       
}

   return 0;
}

void limpaMatriz(char m[ ][MAXC], int nL, int nC)
{
    int i,j;
    for(i = 0; i < nL; i++)
     for(j = 0; j < nC; j++)
        m[i][j]=VAZ;
}

void inicBlinker(char m[ ][MAXC], int nL, int nC)
{
  char padrao[1][3]={{ORG,ORG,ORG}};
  int i,j, xInic=nL/2, yInic=nC/2;

  limpaMatriz(m,nL,nC);

 for(i = 0; i < 1; i++)
    for(j = 0; j < 3; j++)
      m[xInic+i][yInic+j]=padrao[i][j];
}


void inicBloco(char m[ ][MAXC], int nL, int nC)
{
 char padrao[2][2]={{ORG,ORG},{ORG,ORG}};
  int i,j,xInic=nL/2, yInic=nC/2;


 limpaMatriz(m,nL,nC);


 for(i = 0 ;i < 2 ;i++)
    for(j = 0; j < 2; j++)
      m[xInic+i][yInic+j]=padrao[i][j];
}

void inicSapo(char m[ ][MAXC], int nL, int nC)
{

 char padrao[2][4]={{VAZ,ORG,ORG,ORG},{ORG,ORG,ORG,VAZ}};
  int i,j,xInic=nL/2, yInic=nC/2;

  limpaMatriz(m,nL,nC);


   for(i = 0; i < 2; i++)
      for(j = 0; j < 4; j++)
      m[xInic+i][yInic+j]=padrao[i][j];

}

void inicGlider(char m[ ][MAXC], int nL, int nC)
{
char padrao[3][3]={{ORG,ORG,ORG},{ORG,VAZ,VAZ},{VAZ,ORG,VAZ}};
 int i,j,xInic,yInic;

 limpaMatriz(m,nL,nC);

 xInic = nL - 4;
 yInic = nC - 4;

 for(i = 0; i < 3; i++)
    for(j = 0; j < 3; j++)
      m[xInic+i][yInic+j]=padrao[i][j];
}

void inicLWSS(char m[ ][MAXC], int nL, int nC)
{
char padrao[4][5]={{VAZ,ORG,VAZ,VAZ,ORG},{ORG,VAZ,VAZ,VAZ,VAZ},{ORG,VAZ,VAZ,VAZ,ORG},{ORG,ORG,ORG,ORG,VAZ}};
 int i,j,xInic,yInic;

 limpaMatriz(m,nL,nC);

 xInic = nL - 5;
 yInic = nC - 6;

 for(i = 0; i < 4; i++)
    for(j = 0; j < 5; j++)
      m[xInic+i][yInic+j]=padrao[i][j];

}

void menuInicJogo(char mat[ ][MAXC], int nL, int nC)
{
    int opcao;

   printf("\n(1)Bloco\n(2)Blinker\n(3)Sapo\n(4)Glider\n(5)LWSS\nEntre com a opcao: ");
   scanf("%d",&opcao);
   switch(opcao)
   {
    case 0:   break;
     case 1:   inicBloco(mat,nL,nC); break;
     case 2:   inicBlinker(mat,nL,nC); break;
     case 3:   inicSapo(mat,nL,nC); break;
     case 4:   inicGlider(mat,nL,nC); break;
     case 5:   inicLWSS(mat,nL,nC); break;
   }

    imprimeMatriz(mat,nL,nC);
    printf("Se inicializacao correta digite qualquer tecla para iniciar o jogo..."); while(getchar()!='\n'); getchar();

}

void imprimeMatriz(char m[][MAXC],int nL, int nC)
{
	int i, j;

	for (i = 0; i < nL; i++)
	{
		for (j = 0; j < nC; j++)
		{
			printf("%4d", m[i][j]);
			printf("\n");
		}
	}
}

void copiaMatriz(char mDestino[][MAXC],char mOrigem[][MAXC], int nL, int nC)
{
	int i, j;

	for (i = 0; i < nL; i++)
	{
		for (j = 0; j < nC; j++)
		{

		}
	}

}

void atualizaMat(char mAtual[][MAXC], char mAnt[][MAXC], int nL, int nC)
{
   int i, j, c;
   
   for (i = 0; i < nL; i++)
   {
    for (j = 0; j < nC; j++)
    {

   		c = contViz(mAnt, i, j);
    
		if(c < 2 || c > 3)
	   {
	   		mAtual[i][j] = VAZ;
		}
	  	else
		{ 
			mAtual[i][j] = ORG;
		} 			
	}
   }
   
}

void jogaJogoVida(char mAtual[ ][MAXC], int nL, int nC, int nCiclos)
{
  char mAnt[MAXL][MAXC];
  int c;
  imprimeMatriz(mAnt,nL,nC); 
  system(LIMPATELA);
  imprimeMatriz(mAtual,nL,nC); 
  DORME(TEMPO);  
  getchar();
  for(c = 1; c <= nCiclos; c++)
  {
        copiaMatriz(mAnt,mAtual,nL,nC); 

        atualizaMat(mAtual,mAnt,nL,nC); 
        system(LIMPATELA);
        imprimeMatriz(mAtual,nL,nC);
    	getchar();
        DORME(TEMPO);
  }

}
int contViz(char mAnt[][MAXC], int i, int j)
{
    int x, y; 
	int cont=0;
	
    for (x = i - 1; x < i + 2; x++)
   {
   		for (y = j - 1; y < j + 2; y++)
    	{
   			if (mAnt[i][j]=ORG)
			{ 
				cont++;
			}
       
    	}
    return cont;
   }
}
