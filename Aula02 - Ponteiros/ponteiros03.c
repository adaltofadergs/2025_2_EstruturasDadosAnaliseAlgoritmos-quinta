/******************************************************************************

*******************************************************************************/
#include <stdio.h>

int somar(int *x, int *y ){
    return *x + *y ;
}

void multiplicar (int *x, int *y , int *result){
     *result = (*x) * (*y) ;
}

int main()
{
    int a = 5, b = 10, multi;
    
    printf("Soma: %d" , somar( &a , &b) );
    multiplicar( &a, &b, &multi) ;
    printf("\nMultiplicação: %d", multi) ;

    return 0;
}
