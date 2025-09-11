/******************************************************************************
Lista Encadeada, em ordem crescente

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

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

	printf("\n\n --:Lista Encadeada em ordem crescente:--");
	printf("\n 1 - Adicionar na lista ");
	printf("\n 2 - Remover da lista ");
	printf("\n 3 - Imprimir lista ");
	printf("\n 0 - Sair ");
	printf("\nDigite sua escolha: ");
	int op;
	scanf("%d", &op);
//	system("cls");
	return op;
}

int main()
{
    No *inicio = NULL;
    char nome[20];
    int opcao;
    
    do{
        opcao = menu();
        switch( opcao ){
            case 1: 
                printf("Digite o nome (até 20 caracteres): " );
                scanf(" %[^\n]", &nome );
                //gets( &nome );
                No *endGerado = gerarEnd( nome );
                if( inicio == NULL ){
                    inicio = endGerado;
                }else{
                    if( strcmp( nome , inicio->dado) < 0 ){
                        endGerado->prox = inicio;
                        inicio = endGerado;
                    }else{
                        No *ant = inicio;
                        No *aux = inicio->prox;
                        while( aux != NULL ){
                            if( strcmp( nome , aux->dado) < 0 ){
                                ant->prox = endGerado;
                                endGerado->prox = aux;
                                break;
                            }
                            ant = aux;
                            aux = aux->prox;
                        }
                        if( aux == NULL ){
                            ant->prox = endGerado;
                        }
                    }
                }
                break;
            case 2:
                if( inicio == NULL ){
                    printf("Lista Vazia!\n");
                }else{
                    printf("Digite o nome para ser excluído: " );
                    scanf(" %[^\n]", &nome );
                    bool removido = false;
                    
                    No *aux = inicio;
                    if( strcmp(nome , inicio->dado) == 0 ){
                        inicio = inicio->prox;
                        free( aux );
                        removido = true;
                    }else{
                        No *ant = inicio;
                        aux = inicio->prox;
                        while( aux != NULL ){
                            if( strcmp(nome , aux->dado) == 0 ){
                                ant->prox = aux->prox;
                                free( aux );
                                removido = true;
                                break;
                            }
                            ant = aux;
                            aux = aux->prox;
                        }
                    }
                    removido ? printf("Elemento removido") : printf("Elemento não encontrado");
                }
                break;
            case 3:
                if( inicio == NULL ){
                    printf("\nLista Vazia!\n");
                }else{
                    No *aux = inicio;
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
    system("cls");
    printf("\n\nBye-bye!");

    return 0;
}