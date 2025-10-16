/******************************************************************************
• Construa um algoritmo de busca contendo um vetor de números
inteiros de 20 posições.
• O algoritmo deve ter duas funções, uma para busca sequencial e
outra para busca binária.
• Coloque um contador em cada função para contar as iterações de
cada função.
• Peça ao usuário que informe o valor que deseja procurar.
• Então informe ao usuário se este valor existe no vetor e quantas
iterações foram necessárias em cada função.

*******************************************************************************/
#include <stdio.h>

int buscaSequencial( int vet[20], int n, int k, int *cont){
    int i;
    *cont = 0;
    for( i = 0 ; i < n ; i++){
        *cont = *cont + 1;
        if( vet[i] == k ){
            return i;
        }
    }
    return -1;
}

int buscaBinaria( int vet[20], int n, int k, int * cont){
    *cont = 0;
    
    int inicio = 0;
    int fim = n-1;
    int centro;
    while( inicio <= fim){
        *cont = *cont + 1;
        centro = (inicio + fim) / 2;
        if( vet[centro] == k ){
            return centro;
        }else{
            if( k < vet[centro]){
                fim = centro -1;
            }else{
                inicio = centro + 1;
            }
        }
    }
    return -1;
}

int main()
{
    int vetor[20] = { 2,4,6,5, 7,10, 18, 21, 27, 28, 30,  35, 38, 43, 45, 50, 57, 70, 74, 94};
    int chave, contSequencial=0, contBinario=0;
    int posicao;
    
    printf("Digite o valor a ser procurado: ");
    scanf("%d", &chave);
    
    posicao = buscaSequencial(vetor, 20, chave, &contSequencial);
    if( posicao == -1 ){
        printf( "\nNa busca sequencial, o valor %d não foi encontrado", chave);
        printf( "\nForam executadas %d iterações", contSequencial);
    }else{
        printf( "\nNa busca sequencial, o valor %d foi encontrado na posição: %d", chave, posicao);
        printf( "\nForam executadas %d iterações", contSequencial);
    }
    
    posicao = buscaBinaria(vetor, 20, chave, &contBinario);
    if( posicao == -1 ){
        printf( "\nNa busca binária, o valor %d não foi encontrado", chave);
        printf( "\nForam executadas %d iterações", contBinario);
    }else{
        printf( "\nNa busca binária, o valor %d foi encontrado na posição: %d", chave, posicao);
        printf( "\nForam executadas %d iterações", contBinario);
    }

    return 0;
}



