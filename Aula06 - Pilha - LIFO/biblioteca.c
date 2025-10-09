/******************************************************************************
Exercício: Implementar uma pilha de livros

Cada livro deve conter id, título e autor

implementar as opções de: 
1) Adicionar livro na pilha
2) Remover livro da pilha
3) Imprimir pilha
4) Informar um autor e retornar todos os livros deste autor
0) Sair

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int id;
    char titulo[50];
    char autor[20] ;
    struct Livro *prox ;
} Livro;

Livro* gerarEnd( int _id, char _titulo[50] , char _autor[20] ){
    Livro *novoLivro = ( Livro* ) malloc( sizeof(Livro) );
    if( novoLivro == NULL ){
        printf("Erro ao alocar memória!");
        exit(1);
    }
    novoLivro->id = _id;
    strcpy( novoLivro->titulo, _titulo );
    strcpy( novoLivro->autor, _autor );
    novoLivro->prox = NULL;
    return novoLivro;
}

int menu(){

	printf("\n\n --: PILHA - LIFO :--");
	printf("\n 1 - Adicionar na pilha ");
	printf("\n 2 - Remover da pilha ");
	printf("\n 3 - Imprimir Pilha ");
	printf("\n 4 - Buscar livros de um autor ");
	printf("\n 0 - Sair ");
	printf("\nDigite sua escolha: ");
	int op;
	scanf("%d", &op);
	return op;
}

int main()
{
    Livro *topo = NULL;
    char titulo[50];
    char autor[20];
    int id = 0;
    int opcao;
    
    do{
        opcao = menu();
        switch( opcao ){
            case 1: 
                printf("Digite o título (até 50 caracteres): " );
                scanf(" %[^\n]", &titulo );
                printf("Digite o nome do(a) autor(a) (até 20 caracteres): " );
                scanf(" %[^\n]", &autor );
                id++;
                Livro *endGerado = gerarEnd( id, titulo, autor );
                
                if( topo != NULL ){
                    endGerado->prox = topo;
                }
                topo = endGerado;
                printf("\n%s empilhado!", endGerado->titulo );
                break;
            case 2:
                if( topo == NULL ){
                    printf("\nPilha Vazia!\n");
                }else{
                    Livro *aux = topo;
                    topo = topo->prox;
                    printf("\n%s removido da pilha", aux->titulo);
                    free(aux);
                }
                break;
            case 3:
                if( topo == NULL ){
                    printf("\nPilha Vazia!\n");
                }else{
                    Livro *aux = topo;
                    printf("\n ---------------------" );
                    while( aux != NULL ){
                        printf("\n -- %d) %s - %s" , aux->id, aux->titulo, aux->autor );
                        aux = aux->prox;
                    }
                }
                break;
            case 4:
                printf("Digite o nome do(a) autor(a) (até 20 caracteres): " );
                scanf(" %[^\n]", &autor );
                Livro *aux = topo;
                int cont = 0;
                while( aux != NULL ){
                    cont ++;
                    if( strcmp( aux->autor , autor ) == 0 ){
                        printf("\nPosição %d -- %d) %s" , cont, aux->id, aux->titulo );
                    }
                    aux = aux->prox;
                }
                
            case 0:
                break;
            default:
                printf( "\nEsta opção não existe! ");
            
        }
        
    }while( opcao != 0);
    printf("\n\nBye-bye!");
    return 0;
}