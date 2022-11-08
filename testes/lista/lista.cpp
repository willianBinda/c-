#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//Estrutura base do nó.
struct Node
{
    int valor;
    struct Node *proximo;
};

typedef struct Node node;

void imprimeFila(node *raiz);
void insereNoInicio(node *raiz, int info);
void insereNoMeio(node *raiz, int info, int posicao);
void insereNoFinal(node *raiz, int info);

void removeNoInicio(node *raiz);
void removeNoMeio(node *raiz, int posicao);
void removeNoFinal(node *raiz);


int main(void)
{
    printf("\n\n\n");
    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node *));
    raiz->valor = NULL;
    raiz->proximo = NULL;


    printf("Mostrando a lista\n");
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 1 no início\n");
    insereNoInicio(raiz, 1);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 0 no início\n");
    insereNoInicio(raiz, 0);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 2 no final\n");
    insereNoFinal(raiz, 2);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 5 no final\n");
    insereNoFinal(raiz, 5);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 3 na posicao 3\n");
    insereNoMeio(raiz, 3, 3);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Insere 4 na posicao 4\n");
    insereNoMeio(raiz, 4, 4);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Remove primeiro node\n");
    removeNoInicio(raiz);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Remove primeiro node\n");
    removeNoInicio(raiz);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Remove ultimo node\n");
    removeNoFinal(raiz);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

    printf("Remove segundo node da lista\n");
    removeNoMeio(raiz, 1);
    //Mostrando a lista.
    if (raiz)
        imprimeFila(raiz);

  free(raiz);

  return 0;
}


//Função pra printar o nó na tela.
void imprimeFila(node *raiz)
{
    node *p = raiz->proximo;
    printf("Mostrando a lista:\n");
    if(p)
    {
        do
        {
            printf(" %d", p->valor);
            p = p->proximo;
        }
        while(p);
        printf("\n\n");

    }
    else
        printf("Lista vazia.\n\n");
}

// Função para inserir nó no inicio
void insereNoInicio(node *raiz, int info){
    node *novo = (node *) malloc(sizeof(node *));
    novo->valor = info;
    novo->proximo = raiz->proximo;
    raiz->proximo = novo;
}

// Função para inserir nó no final
void insereNoFinal(node *raiz, int info){
    node *novo = NULL;
    novo = (node *)malloc(sizeof(node *));
    novo->valor = info;
    novo->proximo = NULL;

    node *ultimo = raiz->proximo;
    while (ultimo->proximo)
    {
        ultimo = ultimo->proximo;
    }

    ultimo->proximo = novo;
    novo->proximo = NULL;
}

// Função para inserir nó no meio
void insereNoMeio(node *raiz, int info, int posicao){
    node *novo = NULL;
    novo = (node *)malloc(sizeof(node *));
    novo->valor = info;

    node *p = raiz->proximo;

    int i = 0;
    while (p->proximo)
    {
        i++;
        if (i == posicao)
            break;
        p = p->proximo;

    }
    novo->proximo = p->proximo;
    p->proximo = novo;

}



// Função para remover nó no inicio
void removeNoInicio(node *raiz){
    node *primeiro = raiz->proximo;
    raiz->proximo = primeiro->proximo;
    free(primeiro);
}


// Função para remover nó no final
void removeNoFinal(node *raiz)
{
    node *p = raiz->proximo;
    node *anterior = raiz;

    while(p->proximo){
        anterior = p;
        p = p->proximo;
    }
    anterior->proximo = p->proximo;
    p->proximo = NULL;
    free(p);
}


// Função para remover nó no meio
void removeNoMeio(node *raiz, int posicao)
{
    node *p = raiz->proximo;
    node *anterior = raiz;
    int i = 0;
    while (p->proximo)
    {
        anterior = p;
        p = p->proximo;
        i++;
        if (i == posicao)
            break;
    }
    anterior->proximo = p->proximo;
    p->proximo = NULL;
    free(p);
}