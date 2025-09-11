/******************************************************************************

*******************************************************************************/
#include <stdio.h>

void incrementar(int *n){
    *n = *n + 1;
    //(*n) ++;
    printf("\nValor atualizado para %d", *n);
}

int main()
{
    int x, v;
    printf("Digite um número inteiro positivo: ");
    scanf("%d" , &x);
    printf("Digite a quantidade do incremento: ");
    scanf("%d" , &v);
    
    for( int i = 1; i <= v; i++){
        incrementar( &x );
    }
    printf("\nValor final do X: %d", x);

    return 0;
}
