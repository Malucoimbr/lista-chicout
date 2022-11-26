/* 2. Utilize uma lista como a que implementamos em sala de aula, com 50 slots; */ 

/* letra B) Crie uma outra função que garanta a inserção de números em ordem
decrescente. Inspire-se na letra anterior; */

#include <stdio.h>
#include <stdlib.h>

struct lista{
    int elem;
};

typedef struct lista Lista;
void inserirreverse(Lista *l1, int valor, int *c) {
    int i, j;
    if (*c == 0){
        l1[0].elem = valor;
        (*c)++;
        return;
    }
    for (i = 0; i < (*c); i++){
        if (l1[i].elem < valor){
            break;
        }
    }
    for (j = *c; j > i; j--){
        l1[j].elem = l1[j - 1].elem;
    }
    l1[i].elem = valor;
    (*c)++;
    return;
}
int main(){
    Lista l1[10];
    int c = 0,v;
    for (int i = 0; i < 10; i++){
        scanf("%d", &v);
         inserirreverse(&l1,v,&c);
    }
    for (int i = 0; i < 10; i++){
        printf("%d\n", l1[i].elem);
    }
    return 0;
}