/******************************************************************************

Pilha - LIFO

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

	printf("\n\n --: PILHA - LIFO :--");
	printf("\n 1 - Adicionar na pilha ");
	printf("\n 2 - Remover da pilha ");
	printf("\n 3 - Imprimir Pilha ");
	printf("\n 0 - Sair ");
	printf("\nDigite sua escolha: ");
	int op;
	scanf("%d", &op);
	return op;
}

int main()
{
    No *topo = NULL;
    char nome[20];
    int opcao;
    
    do{
        opcao = menu();
        switch( opcao ){
            case 1: 
                printf("Digite o nome (até 20 caracteres): " );
                scanf(" %[^\n]", &nome );
                No *endGerado = gerarEnd( nome );
                
                if( topo != NULL ){
                    endGerado->prox = topo;
                }
                topo = endGerado;
                printf("\n%s empilhado!", endGerado->dado );
                break;
            case 2:
                if( topo == NULL ){
                    printf("\nPilha Vazia!\n");
                }else{
                    No *aux = topo;
                    topo = topo->prox;
                    printf("\n%s removido da pilha", aux->dado);
                    free(aux);
                }
                break;
            case 3:
                if( topo == NULL ){
                    printf("\nPilha Vazia!\n");
                }else{
                    No *aux = topo;
                    while( aux != NULL ){
                        printf("\n -- %s" , aux->dado );
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