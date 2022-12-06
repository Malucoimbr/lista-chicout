/* Escreva uma função que obtém o espelho de uma árvore, ou seja, troca a subárvore
direita pela subárvore esquerda de todos os nós da árvore */ 
#include<stdio.h>
#include<stdlib.h>
#include <malloc.h>
typedef struct noarvore{
    int dado;
    struct noarvore *esquerda;
    struct noarvore *direita; 
}No;

No* criarNo(int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo -> dado = valor;
    novo -> esquerda = NULL;
    novo -> direita = NULL;
    return novo;
}




void arvoreEmOrdem(No* raiz){
    if(raiz == NULL){
        return;
    }
    arvoreEmOrdem(raiz->esquerda);
    printf("%d->", raiz->dado);
    arvoreEmOrdem(raiz->direita);

}

void espelhoArvore(No* raiz, No** espelho){
    if(raiz == NULL){
        espelho = NULL;
        return;
    }

    *espelho = criarNo(raiz->dado);
    espelhoArvore(raiz->esquerda, &((*espelho)->direita));
    espelhoArvore(raiz->direita, &((*espelho)->esquerda));
}


int main(){
    No * arvore = criarNo(4);
    arvore->esquerda = criarNo(2);
    arvore->direita = criarNo(6);
    arvore->esquerda->esquerda = criarNo(1);
    arvore->esquerda->direita = criarNo(3);
    arvore->direita->esquerda = criarNo(5);
    arvore->direita->direita = criarNo(10);
    arvore->direita->direita->esquerda = criarNo(8);

    printf("arvore original: ");
    arvoreEmOrdem(arvore);
    No* espelho = NULL;
    espelhoArvore(arvore, &espelho);

    printf("\narvore espelhada: ");
    arvoreEmOrdem(espelho);

    return 0;

}