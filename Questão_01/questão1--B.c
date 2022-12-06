
//1. Dada uma lista sequencial ordenada L1, escreva métodos em C que:
// letra B) Faça uma cópia da lista L1 em uma outra lista L2;

#include <stdio.h>
#include <stdlib.h>
struct lista{
    int valor
};typedef struct lista Lista;

void copia(Lista l1[], Lista *l2){
    for (int i = 0; i < 10; i++){
        l2[i].valor = l1[i].valor;
    }
    return;
}

int main(){
    Lista l1[10], l2[10];
    for (int i = 0; i < 10; i++){
    scanf("%d", &l1[i].valor);
    }
    copia(l1, &l2);
    for (int i = 0; i < 10; i++){
    printf("%d\n", l2[i].valor);
    }
    return 0;
}
