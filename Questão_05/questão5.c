#include<stdio.h>
#include<stdlib.h>
typedef struct no{
    int valor;
    struct no *proximo;
}No;

// procedimento para inserir no início
void inserir_no_inicio(No **lista, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = *lista;
        *lista = novo;
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no fim
void inserir_no_fim(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = NULL;

        // é o primeiro?
        if(*lista == NULL)
            *lista = novo;
        else{
            aux = *lista;
            while(aux->proximo)
                aux = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

// procedimento para inserir no meio
void inserir_no_meio(No **lista, int num, int ant){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        // é o primeiro?
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->valor != ant && aux->proximo)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}
//Ordenar (sort) uma lista por ordem crescente
void inserir_ordenado(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        // a lista está vazia?
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } // é o menor?
        else if(novo->valor < (*lista)->valor){
            novo->proximo = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

//Ordenar (sort) ima lista por ordem decrescente
void inserir_decrescente(No **lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        // a lista está vazia?
        if(*lista == NULL){
            novo->proximo = NULL;
            *lista = novo;
        } // é o menor?
        else if(novo->valor > (*lista)->valor){
            novo->proximo = *lista;
            *lista = novo;
        }
        else{
            aux = *lista;
            while(aux->proximo && novo->valor < aux->proximo->valor)
                aux = aux->proximo;
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }
    else
        printf("Erro ao alocar memoria!\n");
}

No* remover(No **lista, int num){
    No *aux, *remover = NULL;

    if(*lista){
        if((*lista)->valor == num){
            remover = *lista;
            *lista = remover->proximo;
        }
        else{
            aux = *lista;
            while(aux->proximo && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo){
                remover = aux->proximo;
                aux->proximo = remover->proximo;
            }
        }
    }
    return remover;
}

//Dividir uma lista em várias 
void dividir(No **L, No **P, No **I){
	No *aux = *L;
	  while(aux){
      if(aux -> valor > 0){
      if (aux->valor % 2 == 0)
  	    inserir_no_inicio{P, aux ->valor};
        else
  	    inserir_no_inicio(I,aux->valor);
}
      }
}

//Localize/ Pesquise/Encontre (search) elementos
No* buscar(No **lista, int num){
    No *aux, *no = NULL;

    aux = *lista;
    while(aux && aux->valor != num)
        aux = aux->proximo;
    if(aux)
        no = aux;
    return no;
}

void imprimir(No *no){
    printf("\n\tLista: ");
    while(no){
        printf("%d ", no->valor);
        no = no->proximo;
    }
    printf("\n\n");
}

int main(){

    int opcao, valor, anterior;
    No *removido, *lista = NULL;
    No *Par == NULL, Impar = NULL;

    do{
        printf("\n\t0 - Sair\n\t1 - InserirI\n\t2 - inserirF\n\t3 - InserirM\n\t4 - Inserir Crescente\n\t5 - Remover\n\t6 - Imprimir\n\t7 - Buscar\n\t8-Inserir decrescente\n\t 9-dividir");
        scanf("%d", &opcao);

        switch(opcao){
        case 1:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_inicio(&lista, valor);
            break;
        case 2:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_no_fim(&lista, valor);
            break;
        case 3:
            printf("Digite um valor e o valor de referencia: ");
            scanf("%d%d", &valor, &anterior);
            inserir_no_meio(&lista, valor, anterior);
            break;
        case 4:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_ordenado(&lista, valor);
            break;
        case 5:
            printf("Digite um valor a ser removido: ");
            scanf("%d", &valor);
            removido = remover(&lista, valor);
            if(removido){
                printf("Elemento a ser removido: %d\n", removido->valor);
                free(removido);
            }
            else
                printf("Elemento inexistente!\n");
            break;
        case 6:
          prinf("lista L:\n")
            imprimir(lista);
           prinf("lista P:\n")
          imprimir(Par);
           prinf("lista I:\n")
          imprimir(Impar);
          
            break;
        case 7:
            printf("Digite um valor a ser buscado: ");
            scanf("%d", &valor);
            removido = buscar(&lista, valor);
            if(removido)
                printf("Elemento encontrado: %d\n", removido->valor);
            else
                printf("Elemento nao encontrado!\n");
            break;
            case 8:
            printf("Digite um valor: ");
            scanf("%d", &valor);
            inserir_decrescente(&lista, valor);
            break;
          case 9:
          dividir(&lista, &Par, &Impar);
          printf("divisão realizada com sucesso");
          break;
          
        default:
            if(opcao != 0)
                printf("Opcao invalida!\n");
        }

    }while(opcao != 0);

    return 0;
}