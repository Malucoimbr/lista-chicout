/*
1. Dada uma lista sequencial ordenada L1, escreva métodos em C que:

letra G) Gere uma lista L2 onde cada registro contém dois campos de informação: elem 
contém um elemento de L1, e count contém quantas vezes este elemento
aparece em L1. 
*/

#include <stdio.h>
#include <stdlib.h>
struct lista{
    int elem;
    int count;
};
typedef struct lista Lista;
void copiaeconta(Lista l1[],Lista *l2){
    for (int i = 0; i < 10; i++){
        int c = 0;
        l2[i].elem = l1[i].elem;
        for (int j = 0; j < 10; j++){
            if (l1[i].elem == l1[j].elem){
             c++;
            }
        }
        l2[i].count = c;
    }
    return;
}
int main(){
    Lista l1[10], l2[10];
    for (int i = 0; i < 10; i++){
        scanf("%d", &l1[i].elem);
    }
    
    copiaeconta(l1,&l2);

    for (int i = 0; i < 10; i++){
        printf("ELEMENTO: %d\nCOUNT: %d\n",l2[i].elem,l2[i].count);
    }
    return 0;
}