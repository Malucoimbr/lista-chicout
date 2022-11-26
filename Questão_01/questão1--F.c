// 1. Dada uma lista sequencial ordenada L1, escreva métodos em C que:
// letra F) Intercale L1 com a lista L2, gerando a lista L3. considere que L1, L2 e L3 são ordenadas 

#include <stdio.h>
#include <stdlib.h>
struct lista{
    int valor
};
typedef struct lista Lista;
void intercalar(Lista l1[], Lista l2[], Lista *l3) {
    int aux1 = 0, aux2 = 0;
    for (int i = 0; i < 20; i += 2) {
        l3[i].valor = l1[aux1].valor;
        l3[i + 1].valor = l2[aux2].valor;
        aux1++;
        aux2++;
    }
    return;
}
int main() {
    Lista l1[10], l2[10], l3[20];
    for (int i = 0; i < 10; i++){
        scanf("%d", &l1[i].valor);
    }

    for (int i = 0; i < 10; i++){
        scanf("%d", &l2[i].valor);
    }

    intercalar(l1,l2,&l3);
    printf("\n\n");

    for (int i = 0; i < 20; i++){
        printf("%d\n", l3[i].valor);
    }
    return 0;
}