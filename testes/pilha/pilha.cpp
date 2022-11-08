#include <stdio.h>
#include <stdlib.h>

// Estrutura base do nó.
struct Node
{
    int valor;
    struct Node *proximo;
};

typedef struct Node node;

void removeElemento(node *raiz);
void insereElemento(node *raiz, int info);
void imprimePilha(node *p);

int main(void)
{
    printf("\n\n\n");
    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node *));
    raiz->valor = NULL;
    raiz->proximo = NULL;

    // Mostrando a lista.
    if (raiz)
        imprimePilha(raiz);

    int zero = 0;
    printf("Inserindo novo item: %d\n", zero);
    insereElemento(raiz, zero);
    if (raiz)
        imprimePilha(raiz);

    int um = 1;
    printf("Inserindo novo item: %d\n", um);
    insereElemento(raiz, um);
    if (raiz)
        imprimePilha(raiz);

    int dois = 2;
    printf("Inserindo novo item: %d\n", dois);
    insereElemento(raiz, dois);
    if (raiz)
        imprimePilha(raiz);

    printf("Removendo item: %d\n", dois);
    removeElemento(raiz);
    if (raiz)
        imprimePilha(raiz);

    printf("Removendo item: %d\n", um);
    removeElemento(raiz);
    if (raiz)
        imprimePilha(raiz);

    printf("Removendo item: %d\n", zero);
    removeElemento(raiz);
    if (raiz)
        imprimePilha(raiz);

    free(raiz);

    return 0;
}

void imprimePilha(node *raiz)
{
    raiz = raiz->proximo;
    printf("Mostrando a pilha:\n");
    if (raiz)
    {
        do
        {
            printf(" %d", raiz->valor);
            raiz = raiz->proximo;
        } while (raiz);
        printf("\n\n");
    }
    else
        printf("pilha vazia.\n\n");
}

void insereElemento(node *raiz, int info)
{
    node *novo = NULL;
    novo = (node *)malloc(sizeof(node *));
    novo->valor = info;
    novo->proximo = NULL;

    novo->proximo = raiz->proximo;
    raiz->proximo = novo;
}

void removeElemento(node *raiz)
{
    node *primeiro = raiz->proximo;
    raiz->proximo = primeiro->proximo;
}
