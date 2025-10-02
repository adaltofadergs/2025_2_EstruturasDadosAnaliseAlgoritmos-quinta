/******************************************************************************
Exercício de FILA
 
Implemente um algoritmo para uma lavagem carros, em que o carro terá os seguintes dados: 
ID, placa e modelo
Com as seguintes opções no menu:
1 - Inserir om carro na fila
2 - Lavar o carro ( remover da fila)
3 - Imprimir a fila
4 - Imprimir um carro, pela placa
0 - Sair

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


typedef struct{
    int id;
    char placa[8];
    char modelo[20] ;
    struct Carro *prox ;
} Carro;

Carro* gerarEnd( int _id, char _placa[8] , char _modelo[20] ){
    Carro *novoCarro = ( Carro* ) malloc( sizeof(Carro) );
    if( novoCarro == NULL ){
        printf("Erro ao alocar memória!");
        exit(1);
    }
    novoCarro->id = _id;
    strcpy( novoCarro->placa, _placa );
    strcpy( novoCarro->modelo, _modelo );
    novoCarro->prox = NULL;
    return novoCarro;
}

int menu(){

	printf("\n\n --:FIFO - Fila:--");
	printf("\n 1 - Adicionar carro na Fila ");
	printf("\n 2 - Lavar um carro");
	printf("\n 3 - Imprimir Fila de carros");
	printf("\n 4 - Buscar carro pela placa");
	printf("\n 0 - Sair ");
	printf("\nDigite sua escolha: ");
	int op;
	scanf("%d", &op);
	return op;
}

int main()
{
    Carro *inicio = NULL;
    Carro *fim = NULL;
    char modelo[20];
    char placa[8];
    int id = 0;
    int opcao;
    
    
    do{
        opcao = menu();
        switch( opcao ){
            case 1: 
                id++;
                printf("Digite o modelo (até 20 caracteres): " );
                scanf(" %[^\n]", &modelo );
                printf("Digite a placa (até 8 caracteres): " );
                scanf(" %[^\n]", &placa );

                Carro *endGerado = gerarEnd( id, placa, modelo );
                
                if( inicio == NULL ){
                    inicio = endGerado;
                    fim = endGerado;
                }else{
                    fim->prox = endGerado;
                    fim = endGerado;
                }
                printf("\n%s adicionado.", fim->placa);
                break;
            case 2:
                if( inicio == NULL ){
                    printf("Fila está Vazia!\n");
                }else{
                    Carro *aux = inicio;

                    inicio = inicio->prox;
                    if( inicio == NULL) 
                        fim = NULL;
                    
                    printf( "\n%s foi lavado e saiu da fila!" , aux->modelo);
                    free( aux );
                    
                }
                break;
            case 3:
                if( inicio == NULL ){
                    printf("\nFila Vazia!\n");
                }else{
                    printf("\n -- Fila -- \n");
                    int cont = 1;
                    Carro *aux = inicio;
                    while( aux != NULL ){
                        printf("\n %d) - Id: %d - %s - %s" , cont, aux->id, aux->placa, aux->modelo );
                        aux = aux->prox;
                        cont++;
                    }
                }
                break;
                
            case 4: 
                if( inicio == NULL ){
                    printf( "Fila está vazia");
                    break;
                }
                printf("Digite a placa (até 8 caracteres): " );
                scanf(" %[^\n]", &placa );
                bool encontrou = false;
                int cont = 0;
                Carro *aux = inicio;
                while( aux != NULL ){
                    cont ++;
                    if( strcmp(placa , aux->placa) == 0 ){
                        encontrou = true;
                        printf("Carro encontrado na posição %d - Id: %d - %s - %s" , cont, aux->id, aux->placa, aux->modelo );
                        break;
                    }
                    aux = aux->prox;
                }
                if( !encontrou ){
                    printf( "Carro não encontrado na fila!");
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