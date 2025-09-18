/******************************************************************************
Implementar um algoritmo de uma playlist de música onde cada Nó da lista possuirá
id, título, artista.
Construa as seguintes funções:
1. Inserir no início da lista
2. Inserir no fim da lista
3. Remover um item, pelo seu id
4. Imprimir a playlist
5. Imprimir a playlist em ordem reversa
6. Buscar uma música pelo título
0. Sair

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct{
    struct No *anterior ;
    int id;
    char titulo[50];
    char artista[50];
    struct No *proximo ;
} No;

No* gerarEnd( int _id, char _titulo[50], char _artista[50] ){
    No *novoNo = ( No* ) malloc( sizeof(No) );
    if( novoNo == NULL ){
        printf("Erro ao alocar memória!");
        exit(1);
    }
    novoNo->id = _id;
    strcpy( novoNo->titulo, _titulo );
    strcpy( novoNo->artista, _artista );
    novoNo->anterior = NULL;
    novoNo->proximo = NULL;
    return novoNo;
}

int menu(){

  printf("\n\n    _____________--: AppMusic :-- ____________   ");
	printf("\n  /                                            \\");
	printf("\n | 1. Inserir no início da lista                | ");
	printf("\n | 2. Inserir no fim da lista                   | ");
	printf("\n | 3. Remover um item, pelo seu id              | ");
	printf("\n | 4. Imprimir a playlist                       | ");
	printf("\n | 5. Imprimir a playlist em ordem reversa      | ");
	printf("\n | 6. Buscar uma música pelo título             | ");
	printf("\n | 0 - Sair                                     |");
	printf("\n  \\____________________________________________/");
	printf("\n\nDigite sua escolha: ");
	int op;
	scanf("%d", &op);
	return op;
}

int main()
{
    No *inicio = NULL;
    No *fim = NULL;
    char titulo[50];
    char artista[50];
    int opcao;
    int idMusica = 0;
    int idExcluir;
    
    No *endGerado = NULL;
    
    do{
        opcao = menu();
        switch( opcao ){
            case 1: // Adicionar no início da Lista
                printf("Digite o título (até 50 caracteres): " );
                scanf(" %[^\n]", &titulo );
                printf("Digite o(a) artista (até 50 caracteres): " );
                scanf(" %[^\n]", &artista );
                idMusica++;
                endGerado = gerarEnd( idMusica, titulo, artista  );
                if( inicio == NULL ){
                    inicio = endGerado;
                    fim = endGerado;
                }else{
                    endGerado->proximo = inicio;
                    inicio->anterior = endGerado;
                    inicio = endGerado;
                }
                break;
            case 2: // Adicionar no fim da Lista
                printf("Digite o título (até 50 caracteres): " );
                scanf(" %[^\n]", &titulo );
                printf("Digite o(a) artista (até 50 caracteres): " );
                scanf(" %[^\n]", &artista );
                idMusica++;
                endGerado = gerarEnd( idMusica, titulo, artista  );
                if( fim == NULL ){
                    inicio = endGerado;
                    fim = endGerado;
                }else{
                    endGerado->anterior = fim;
                    fim->proximo = endGerado;
                    fim = endGerado;
                }
                break;
            case 3:
                if( inicio == NULL ){
                    printf("Lista Vazia!\n");
                }else{
                    printf("Digite o ID da música que deseja excluir: " );
                    scanf("%d", &idExcluir );
                    bool removido = false;
                    
                    No *aux = inicio;
                    if( inicio->id  == idExcluir ){
                        inicio = inicio->proximo;
                        if( inicio != NULL)
                            inicio->anterior = NULL;
                        free( aux );
                        removido = true;
                    }else{
                        No *ant = inicio;
                        aux = inicio->proximo;
                        while( aux != NULL ){
                            if( inicio->id  == idExcluir ){
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
                    removido ? printf("Música removida") : printf("Id não encontrado");
                }
                break;
            case 4:
                if( inicio == NULL ){
                    printf("\nPlaylist Vazia!\n");
                }else{
                    No *aux = inicio;
                    while( aux != NULL ){
                        printf("\n -- ID: %d" , aux->id );
                        printf("\n    Título: %s" , aux->titulo );
                        printf("\n    Artista: %s" , aux->artista );
                        printf("\n ------------------------------" );
                        aux = aux->proximo;
                    }
                }
                break;
            case 5:
                if( inicio == NULL ){
                    printf("\nPlaylist Vazia!\n");
                }else{
                    printf("\nPlaylist Reversa\n");
                    No *aux = fim;
                    while( aux != NULL ){
                        printf("\n -- ID: %d" , aux->id );
                        printf("\n    Título: %s" , aux->titulo );
                        printf("\n    Artista: %s" , aux->artista );
                        printf("\n ------------------------------" );
                        aux = aux->anterior;
                    }
                }
                break;
            case 6:
                if( inicio == NULL ){
                    printf("Lista Vazia!\n");
                }else{
                    printf("Digite o título (até 50 caracteres): " );
                    scanf(" %[^\n]", &titulo );
                    bool encontrou = false;
                    
                    No *aux = inicio;
                    
                    while( aux != NULL ){
                        if( strcmp(titulo , aux->titulo) == 0 ){
                            printf("\n -- ID: %d" , aux->id );
                            printf("\n    Título: %s" , aux->titulo );
                            printf("\n    Artista: %s" , aux->artista );
                            printf("\n ------------------------------" );
                            encontrou = true;
                            break;
                        }
                        aux = aux->proximo;
                    }
                    
                    if( !encontrou ) printf("Título não encontrado");
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