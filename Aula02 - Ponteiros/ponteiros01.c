/******************************************************************************
Ponteiros
*******************************************************************************/
#include <stdio.h>

int main()
{
    int x = 5;
    int *p ;
    p = &x ;
    
    printf("Valor da variável X: %d", x );
    printf("\nEndereço da variável X: %p", &x );
    printf("\nValor da variável P: %p", p );
    printf("\nValor apontado por P: %d", *p );
    printf("\nEndereço da variável P: %p", &p );
    
    *p = 10;
    
    printf("\nNovo valor da variável X: %d", x );

    return 0;
}
