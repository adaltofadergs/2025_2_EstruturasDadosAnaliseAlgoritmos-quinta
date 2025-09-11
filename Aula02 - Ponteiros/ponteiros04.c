/******************************************************************************

*******************************************************************************/
#include <stdio.h>

void somar(int *vetor , int tamanho, int *soma){
    for( int i = 0 ; i < tamanho ; i++){
        *soma += vetor[i];
    }
}

int main()
{
    int tam, sum = 0; 
    
    printf("Quantos valores você que somar? ");
    scanf("%d" , &tam);
    int numeros[tam];
    for( int i = 0 ; i < tam ; i++){
        printf("Digite o %dº valor: " , (i+1) );
        scanf( "%d" , &numeros[i]);
    }
    somar( &numeros , tam , &sum);
    printf( "Soma total: %d" , sum );

    return 0;
}
