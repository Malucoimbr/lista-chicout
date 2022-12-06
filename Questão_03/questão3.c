/* Questão 3. Usando listas, crie um programa que guarde strings. Re-implemente todas as
funcionalidades para que seja possível usar as funções básicas de inserção, remoção,
busca e detecção de fim de lista; 
Letra A) Implemente também a função que retorna o tamanho da lista (quantidade de
elementos), e a perda de memória (total da lista - quantidade de itens vazios) */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct lista {
    char str[100];
};
typedef struct lista Lista;

void inserir(Lista *l, int *c) {
    printf("insira a string: ");
    fflush(stdin);
    gets(l[*c].str);
    (*c)++;
    return;
}

void remover(Lista *l, int *c) {
    char str[100];
    printf("string: ");
    fflush(stdin);
    gets(str);
    for (int i = 0; i <= *c; i++) {
        int teste;
        teste = strcmp(l[i].str, str);
        if (teste == 0) {
            strcpy(l[i].str, l[i + 1].str);
            for (int j = i; j < (*c) - 1; j++){
                strcpy(l[j].str, l[j + 1].str);
            }
            (*c)--;
            return;
        }
    }
    printf("string nao encontrada!");
    return;
}
void buscar(Lista *l, int *c){
    char str[100];
    printf("string: ");
    fflush(stdin);
    gets(str);

    for (int i = 0; i < (*c); i++){
        int teste;
        teste = strcmp(l[i].str, str);
        if (teste == 0){
            printf("%s\n\n", l[i].str);
        }
    }
    printf("string nao encontrado!\n");
    return;
}
void editar(Lista *l, int *c){
    char str[100];
    printf("string: ");
    fflush(stdin);
    gets(str);
    for (int i = 0; i < (*c); i++) {
        int teste;
        teste = strcmp(l[i].str, str);
        if (teste == 0){
            char nstr[100];
            printf("string: ");
            fflush(stdin);
            gets(nstr);
            strcpy(l[i].str, nstr);
            return;
        }
        printf("string nao encontrada!\n");
        return;
    }
}
int main() {
    Lista l[50];
    int c = 0, op;
    do {
        printf("_________________\n");
        printf("LISTA DE strings\n");
        printf("_________________\n");
        printf("1-Inserir string\n2-Remover string\n3-Mostrar string\n4-Buscar string\n5-Editar string\n6-Total de strings/memoria inutil\nDigite sua opcao: ");
        scanf("%d", &op);
        switch (op) {
            case 1:
                inserir(&l, &c);
            break;
            case 2:
                remover(&l, &c);
            break;
            case 3:
            for (int i = 0; i < c; i++) {
                printf("%s\n\n", l[i].str);
                }
            break;
            case 4:
                buscar(&l, &c);
            break;
            case 5:
                editar(&l, &c);
            break;
            case 6:
                printf("%d strings cadastradas!\n%d perda de memoria!\n", c, (sizeof(l)-sizeof(c)*c));
            break;
            default:
            break;
        }
    } while (op > 0);
    return 0;
}