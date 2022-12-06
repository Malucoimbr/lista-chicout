/*
1. Dada uma lista sequencial ordenada L1, escreva métodos em C que:
letra I) Assumindo que os elementos da lista L1 são inteiros positivos, forneça os
elementos que aparecem o maior e o menor número de vezes (forneça os
elementos e o número de vezes correspondente)
*/

#include <stdio.h>
#include <stdlib.h>
struct lista {
    int elem;
    int count;
};
typedef struct lista Lista;

void maismenos(Lista *l1){

    Lista maisrep, menosrep;
    maisrep.elem = 0;
    maisrep.count = 0;
    menosrep.count = 10;
    menosrep.elem = 0;

    for (int i = 0; i < 10; i++){
        int c = 0;
        l1[i].elem = l1[i].elem;
        for (int j = 0; j < 10; j++){
            if (l1[i].elem == l1[j].elem){
                c++;
            }
        }
        l1[i].count = c;
        if (l1[i].count > maisrep.count){
            maisrep.count = l1[i].count;
            maisrep.elem = l1[i].elem;
        }
        if (l1[i].count < menosrep.count){
            menosrep.count = l1[i].count;
            menosrep.elem = l1[i].elem;
        }
    }
    printf("MAIS APARECE\nELEMENTO: %d %d VEZES\nMENOS APARECE\nELEMENTO: %d %d VEZES", maisrep.elem, maisrep.count, menosrep.elem, menosrep.count);
    return;
}
int main(){
    Lista l1[10];
    for (int i = 0; i < 10; i++) {
        scanf("%d", &l1[i].elem);
    }
    maismenos(&l1);
    return 0;
}