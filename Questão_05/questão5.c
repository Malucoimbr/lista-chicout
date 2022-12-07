#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int dado;
    struct node *prox;
}node;

typedef struct list {
    node *ini;
    node *fim;
} Lista;

void inicializaFila(Lista *f) {
    f->ini = NULL;
    f->fim = NULL;
}

void enfileira(int dado, Lista *f) {
    node *ptr = (node *)malloc(sizeof(node));
    if (ptr == NULL) {
        printf("Erro ao alocar memoria");
        return;
    } else {
        ptr->dado = dado;
        ptr->prox = NULL;
        if (f->ini == NULL) {
            f->ini = ptr;
        } else {
            f->fim->prox = ptr;
        }

        f->fim = ptr;
    }
}

int desenfileira(Lista *f) {
    node *ptr = f->ini;
    int dado;
    if (ptr != NULL) {
        f->ini = ptr->prox;
        ptr->prox = NULL;
        dado = ptr->dado;
        free(ptr);
        if (f->ini == NULL) {
            f->fim = NULL;
        }

        return dado;
    } else {
        printf("Fila Vazia.");
        return 0;
    }
}

void imprimeFile(Lista *f) {
    node *ptr = f->ini;
    if (ptr != NULL) {
        while (ptr != NULL) {
            printf(" %d ", ptr->dado);
            ptr = ptr->prox;
        }
    } else {
        printf("Fila Vazia\n");
        return;
    }
}

void concat(Lista *f1, Lista *f2, Lista *dest)
{
    node *ptrF1 = f1->ini;
    node *ptrF2 = f2->ini;

    if(ptrF1 == NULL && ptrF2 == NULL){
        printf("Fila Vazia");
        return;
    }

    if (ptrF1 != NULL) {
        while (ptrF1 != NULL) {
            enfileira(ptrF1->dado, dest);
            ptrF1 = ptrF1->prox;
        }
    }

    if (ptrF2 != NULL) {
        while (ptrF2 != NULL) {
            enfileira(ptrF2->dado, dest);
            ptrF2 = ptrF2->prox;
        }
    }

}
void divFila(int itensPorFila, Lista *l1, Lista *l2, Lista *l3 ){
    node *ptr = l1->ini;

    if (ptr != NULL) {

        for (int j = 0; j < itensPorFila; j++) {
            enfileira(ptr->dado, l2);
            ptr = ptr->prox;
        }

        for (int k = 0; k < itensPorFila; k++) {
            enfileira(ptr->dado, l3);
            ptr = ptr->prox;
        }


    } else {
        printf("Fila Vazia\n");
        return;
    }


}


void copy(Lista *lista1, Lista *dest)
{
    node *ptrL1 = lista1->ini;

    if(ptrL1 == NULL){
        printf("Fila Vazia");
        return;
    }

    if (ptrL1 != NULL) {
        while (ptrL1 != NULL) {
            enfileira(ptrL1->dado, dest);
            ptrL1 = ptrL1->prox;
        }
    }
}

void search(int element, Lista *l)
{
    node *ptr = l->ini;
    if (ptr != NULL) {
        while (ptr != NULL) {
            if(ptr->dado == element)
            {
                printf("Numero buscado: %i Numero encontrado: %d Endereço de memoria: %i", element, ptr->dado, &ptr->dado);
                return;
            }
            ptr = ptr->prox;

        }

        printf("Valor não encontrado");
    } else {
        printf("Fila Vazia\n");
        return;
    }
}
void ordenaEmostra(Lista *f1){
    node *ptr = f1->ini;
    node *ptr2 = ptr->prox;

    int aux;

    while(ptr != NULL){
        imprimeFILA(f1);

        if(ptr->dado > ptr2->dado){


            aux = ptr->dado;

            ptr->dado = ptr2->dado;
            ptr->prox->dado = aux;
            if(ptr2 != NULL && ptr != NULL){
                ptr2 = ptr2->prox;

                ptr = ptr->prox;

            }

            }
        }


    }




int main(void) {
    Lista *fila1 = (Lista *)malloc(sizeof(Lista));
    Lista *fila2 = (Lista *)malloc(sizeof(Lista));
    Lista *fila3 = (Lista *)malloc(sizeof(Lista));
    if (fila1 == NULL) {
        printf("Erro de alocação");
        exit(-1);
    } else {
        inicializaFila(fila1);
        inicializaFila(fila2);
        inicializaFila(fila3);
        enfileira(10, fila1);
        enfileira(20, fila1);
        enfileira(30, fila1);
        enfileira(40, fila2);
        enfileira(50, fila2);
        enfileira(60, fila2);


        concat(fila1, fila2, fila3);
        imprimeFila(fila1);
        printf("\n");
        imprimeFila(fila2);
        printf("\n");
        imprimeFila(fila3);
    }
}

