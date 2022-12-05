//
// Created by malu on 30/11/2022.
//

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int dado;
    struct NO *prox;
} NO;

typedef struct FILA {
    NO *ini;
    NO *fim;
} FILA;
void inicializaFILA(FILA *f) {
    f->ini = NULL;
    f->fim = NULL;
}
void enfileira(int dado, FILA *f) {
    NO *ptr = (NO *)malloc(sizeof(NO));
    if (ptr == NULL) {
        printf("ERRO");
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


void imprimirFILA(FILA *f) {
    NO *ptr = f->ini;
    if (ptr != NULL) {
        while (ptr != NULL) {
            printf(" %d ", ptr->dado);
            ptr = ptr->prox;
        }
    } else {
        printf("vazia");
        return;
    }
}
void alterar(FILA *f) {
    NO *ptr = f->ini;
    int OP;
    int dado;

    if (ptr != NULL) {
        printf("\ndigite o valor para ser trocado:");
        scanf("%d", &OP);

        while (ptr != NULL) {
            if (OP == ptr->dado) {
                printf("\nDigite o novo valor:");
                scanf("%d", &dado);
                ptr->dado = dado;

            } else {
                ptr = ptr->prox;
            }
        }
    }
}

int a() {
    FILA *f1 = (FILA *)malloc(sizeof(FILA));
    if (f1 == NULL) {
        printf("erro ao alocar fila");
        exit(-1);
    } else {
        inicializaFILA(f1);

        enfileira(10, f1);
        enfileira(20, f1);
        enfileira(30, f1);

        imprimirFILA(f1);
        alterar(f1);

        imprimirFILA(f1);
    }
}
