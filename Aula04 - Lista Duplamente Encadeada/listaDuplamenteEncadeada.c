/******************************************************************************
Lista Duplamente Encadeada, em ordem crescente

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    struct No *anterior ;
    char dado[20] ;
    struct No *proximo ;
} No;

No* gerarEnd( char valor[20] ){
    No *novoNo = ( No* ) malloc( sizeof(No) );
    if( novoNo == NULL ){
        printf("Erro ao alocar memória!");
        exit(1);
    }
    strcpy( novoNo->dado, valor );
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}

int menu(){

	printf("\n\n --:Lista Duplamente Encadeada em ordem crescente:--");
	printf("\n 1 - Adicionar na lista ");
	printf("\n 2 - Remover da lista ");
	printf("\n 3 - Imprimir lista ");
	printf("\n 4 - Imprimir lista reversa");
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
                    if( strcmp( nome , inicio->dado) < 0 ){
                        endGerado->proximo = inicio;
                        inicio->anterior = endGerado;
                        inicio = endGerado;
                    }else{
                        No *ant = inicio;
                        No *aux = inicio->proximo;
                        while( aux != NULL ){
                            if( strcmp( nome , aux->dado) < 0 ){
                                ant->proximo = endGerado;
                                endGerado->proximo = aux;
                                endGerado->anterior = ant;
                                aux->anterior = endGerado;
                                break;
                            }
                            ant = aux;
                            aux = aux->proximo;
                        }
                        if( aux == NULL ){
                            ant->proximo = endGerado;
                            endGerado->anterior = ant;
                            fim = endGerado;
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
                        inicio = inicio->proximo;
                        if( inicio != NULL)
                            inicio->anterior = NULL;
                        free( aux );
                        removido = true;
                    }else{
                        No *ant = inicio;
                        aux = inicio->proximo;
                        while( aux != NULL ){
                            if( strcmp(nome , aux->dado) == 0 ){
                                ant->proximo = aux->proximo;
                                if( ant->proximo == NULL){
                                    fim = ant;
                                }else{
                                    //aux->proximo->anterior = ant;
                                    No *proximo = aux->proximo;
                                    proximo->anterior = ant;
                                }
                                free( aux );
                                removido = true;
                                break;
                            }
                            ant = aux;
                            aux = aux->proximo;
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
                        aux = aux->proximo;
                    }
                }
                break;
            case 4:
                if( inicio == NULL ){
                    printf("\nLista Vazia!\n");
                }else{
                    printf("\nLista Reversa\n");
                    No *aux = fim;
                    while( aux != NULL ){
                        printf("\n -- %s" , aux->dado );
                        aux = aux->anterior;
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