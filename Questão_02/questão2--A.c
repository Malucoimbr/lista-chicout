/* 2. Utilize uma lista como a que implementamos em sala de aula, com 50 slots; 
 letra A) Crie uma nova função de inserção de dados na lista de inteiros, garantindo que
o novo elemento x seja inserido antes do valor maior que ele e depois do valor
menor que ele, para que a lista sempre fique em ordem crescente; */

#include <stdio.h>
#include <stdlib.h>
struct lista{
    int elem;
};
typedef struct lista Lista;
void inserir(Lista *l1, int valor, int *c) {
    int i, j;
    if (*c == 0){
        l1[0].elem = valor;
        (*c)++;
        return;
    }
    for (i = 0; i < (*c); i++){
        if (l1[i].elem > valor){
            break;
        }
    }
    for (j = *c; j > i; j--)  {
        l1[j].elem = l1[j - 1].elem;
    }
    l1[i].elem = valor;
    (*c)++;
    return;
}
int main() {
    Lista l1[10];
    int c = 0,v;
    for (int i = 0; i < 10; i++) {
        scanf("%d", &v);
        inserir(&l1,v,&c);
    }
    for (int i = 0; i < 10; i++){
        printf("%d\n", l1[i].elem);
    }
    return 0;
}

