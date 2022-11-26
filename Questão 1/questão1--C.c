// 1. Dada uma lista sequencial ordenada L1, escreva métodos em C que:
// letra C) Faça uma cópia da Lista L1 em L2, eliminando elementos repetidos;


#include <stdio.h>
#include <stdlib.h>
struct lista {
    int valor
};typedef struct lista Lista;

void copiab(Lista l1[], Lista *l2){
    for (int i = 0; i < 10; i++) {
        for (int j = -1; j < i; j++){
            if (l1[i].valor == l2[j].valor){
            l2[i].valor = -1;
            break;
            }else{
                l2[i].valor = l1[i].valor;
            }
        }
    }
    return;
}

int main(){
    Lista l1[10], l2[10];
    for (int i = 0; i < 10; i++){
        scanf("%d", &l1[i].valor);
    }
    copiab(l1,&l2);
    for (int i = 0; i < 10; i++){
        if (l2[i].valor != -1){
            printf("%d\n", l2[i].valor);
        }
    }
    return 0;
}