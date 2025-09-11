#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[20];
    float altura;
    int idade;
}pessoa;

int main()
{
    pessoa pessoas[3];
    
    for (int i = 0; i < 3; i++) {
        printf("\n----------------------------\n");
        printf("Digite o %dº nome: ", (i+1) );
        fflush(stdin);
        scanf( " %s", pessoas[i].nome );
        fflush(stdin);
        printf("Digite a %dº altura: ", (i+1));
        scanf( "%f" , &pessoas[i].altura );
        printf("Digite a %dº idade: ", (i+1));
        scanf( "%d" , &pessoas[i].idade );
    }
    
    for (int i = 0; i < 3; i++) {
        printf("\n");
        printf( "%dº Pessoa: %s, altura: %.2f, idade: %d", (i+1) ,  
            pessoas[i].nome, pessoas[i].altura, pessoas[i].idade);
    }
    
    return 0;
}
