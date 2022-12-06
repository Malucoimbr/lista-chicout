//
// Created by malu on 21/11/2022.
//


#include <stdio.h>
#include <stdlib.h>
typedef struct No {
    int dado;
    struct No *prox;
} node;

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


void imprimeFile(Lista *f) {
    node *ptr = f->ini;
    if (ptr != NULL) {

        while (ptr != NULL) {
            printf(" %d ", ptr->dado);
            ptr = ptr->prox;
        }
        printf("\n");
    } else {
        printf("Fila Vazia\n");
        return;
    }
}




int qtdItems(Lista *l)
{
    node *ptr = l->ini;
    int i = 0;
    if (ptr != NULL) {
        while (ptr != NULL) {
            i++;
            ptr = ptr->prox;

        }
        return i;

    } else {
        printf("Fila Vazia\n");
        return 0;
    }
}

void at(Lista *l1, int i1, Lista *l2, int i2){
    if(i1 >= qtdItems(l1) || i2 + qtdItems(l1) > l2 || i1 < 0 || i2 < 0 || i1 + qtdItems(l1) > l2){
        printf("atendeu algumas das coisas aí");
    }else{
        node *ptr = l1->ini;
        while(ptr != NULL){
            enfileira(ptr->dado, l2);
            ptr = ptr->prox;
        }
    }
}
int main(void) {
    Lista *fila1 = (Lista *)malloc(sizeof(Lista));
    Lista *fila2 = (Lista *)malloc(sizeof(Lista));

    if (fila1 == NULL || fila2 == NULL) {
        printf("Erro de alocação");
        exit(-1);
    } else {
        inicializaFila(fila1);
        inicializaFila(fila2);

        enfileira(-10, fila1);
        enfileira(20, fila1);
        enfileira(30, fila1);
        enfileira(40, fila1);
        enfileira(10, fila2);
        enfileira(20, fila2);
        enfileira(30, fila2);
        enfileira(40, fila2);
        at(fila1, fila1->ini->dado, fila2, fila2->ini->dado);
        printf("\nLista 2 :");
        imprimeFile(fila2);
    }
}