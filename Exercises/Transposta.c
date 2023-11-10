#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
int NL = 5, NC = 7;
    int matriz[NL][NC], transposta[NC][NL], l, c;

    srand(time(NULL));

    for(l = 0; l < NL; l++)
{
        for(c = 0; c < NC; c++)
{
            matriz[l][c] = rand() % 100;
        }
    }

    printf("\nPrincipal:\n");
    for(l = 0; l < NL; l++)
{
        for(c = 0; c < NC; c++)
{
            printf("%3d ", matriz[l][c]);
        }
       
        printf("\n");
    }

    for(l = 0; l < NL; l++)
{
        for(c = 0; c < NC; c++)
{
            transposta[c][l] = matriz[l][c];
        }
    }

    printf("\nTransposta:\n");
    for(l = 0; l < NC; l++)
{
        for(c = 0; c < NL; c++)
{
            printf("%3d ", transposta[l][c]);
        }
       
        printf("\n");
    }

    return 0;
}
# FirstProjects
My first coding projects in the college
