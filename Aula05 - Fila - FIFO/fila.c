/******************************************************************************

FIFO - Fila

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct{
    char dado[20] ;
    struct No *prox ;
} No;

No* gerarEnd( char valor[20] ){
    No *novoNo = ( No* ) malloc( sizeof(No) );
    if( novoNo == NULL ){
        printf("Erro ao alocar memória!");
        exit(1);
    }
    strcpy( novoNo->dado, valor );
    novoNo->prox = NULL;
    return novoNo;
}

int menu(){

	printf("\n\n --:FIFO - Fila:--");
	printf("\n 1 - Adicionar ");
	printf("\n 2 - Remover");
	printf("\n 3 - Imprimir Fila");
	printf("\n 0 - Sair ");
	printf("\nDigite sua escolha: ");
	int op;
	scanf("%d", &op);
	return op;
}

int main()
{
    No *inicio = NULL;
    No *fim = NULL;
    char nome[20];
    int opcao;
    
    do{
        opcao = menu();
        switch( opcao ){
            case 1: 
                printf("Digite o nome (até 20 caracteres): " );
                scanf(" %[^\n]", &nome );

                No *endGerado = gerarEnd( nome );
                
                if( inicio == NULL ){
                    inicio = endGerado;
                    fim = endGerado;
                }else{
                    fim->prox = endGerado;
                    fim = endGerado;
                }
                break;
            case 2:
                if( inicio == NULL ){
                    printf("Fila está Vazia!\n");
                }else{
                    No *aux = inicio;
                    strcpy( nome, aux->dado );
                    inicio = inicio->prox;
                    if( inicio == NULL) fim = NULL;
                    free( aux );
                    printf( "\n%s removido(a) com sucesso!" , nome);
                }
                break;
            case 3:
                if( inicio == NULL ){
                    printf("\nFila Vazia!\n");
                }else{
                    printf("\n -- Fila -- \n");
                    No *aux = inicio;
                    while( aux != NULL ){
                        printf(" - %s" , aux->dado );
                        aux = aux->prox;
                    }
                }
                break;
            case 0:
                break;
            default:
                printf( "\nEsta opção não existe! ");
        }
        
    }while( opcao != 0);
    printf("\n\nBye-bye!");
    return 0;
}