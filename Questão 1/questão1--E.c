// 1. Dada uma lista sequencial ordenada L1, escreva métodos em C que:
// letra E) Inverta L1 colocando o resultado na própria L1;

#include <stdio.h>
#include <stdlib.h>
struct lista{
    int valor
};
typedef struct lista Lista;

void inverte2(Lista *l1){
    int aux, c = 9;
    for (int i = 0; i < 5; i++){
        aux = l1[i].valor;
        l1[i].valor = l1[c].valor;
        l1[c].valor = aux;
        c--;
    }
    return;
}
int main(){
    Lista l1[10];
    for (int i = 0; i < 10; i++){
        scanf("%d", &l1[i].valor);
    }
    inverte2(&l1);
    for (int i = 0; i < 10; i++){
        printf("%d\n", l1[i].valor);
    }
    return 0;
}
