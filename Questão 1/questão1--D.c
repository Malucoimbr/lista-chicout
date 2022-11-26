// 1. Dada uma lista sequencial ordenada L1, escreva métodos em C que:
// letra D) Inverta L1 colocando o resultado em L2;

#include <stdio.h>
#include <stdlib.h>
struct lista {
    int valor
};typedef struct lista Lista;

void inverte(Lista l1[], Lista *l2){
    int c = 9;
    for (int i = 0; i < 10; i++){
        l2[i].valor = l1[c].valor;
        c--;
    }
    return;
}
int main(){
    Lista l1[10], l2[10];
    for (int i = 0; i < 10; i++){
        scanf("%d", &l1[i].valor);
    }
    inverte(l1,&l2);
    for (int i = 0; i < 10; i++){
        printf("%d\n", l2[i].valor);
    }
    return 0;
}
