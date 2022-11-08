#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

// Estrutura base do nó.
struct Node
{
    int valor;
    struct Node *proximo;
};

typedef struct Node node;

void insereElemento(node *raiz, int info);
void imprimePilha(node *p);
void transferir(node *s1, node *s2);

int main(void)
{
    printf("\n\n\n");
    node *raiz = NULL, *raiz2 = NULL;

    raiz = (node *)malloc(sizeof(node *));
    raiz2 = (node *)malloc(sizeof(node *));

    raiz->valor = NULL;
    raiz2->valor = NULL;

    raiz->proximo = NULL;
    raiz2->proximo = NULL;

    insereElemento(raiz, 1);
    insereElemento(raiz, 2);
    insereElemento(raiz, 3);
    insereElemento(raiz, 4);
    insereElemento(raiz, 5);
    insereElemento(raiz, 6);
    insereElemento(raiz, 7);
    insereElemento(raiz, 8);

    transferir(raiz, raiz2);
    cout<<"\t\t\tImprimindo pilha 1\n\n";
    imprimePilha(raiz);
    cout<<"\t\t\tImprimindo pilha 2\n\n";
    imprimePilha(raiz2);

    return 0;
}

void transferir(node *raiz, node *raiz2)
{
    node *aux = NULL;
    aux = (node *)malloc(sizeof(node *));
    aux->proximo = NULL;
    raiz = raiz->proximo;
    if (raiz)
    {
        do
        {
            insereElemento(aux, raiz->valor);
            raiz = raiz->proximo;
        } while (raiz);

        aux = aux->proximo;
        if (aux)
            do
            {
                insereElemento(raiz2, aux->valor);
                aux = aux->proximo;
            } while (aux);
    }
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
void imprimePilha(node *raiz)
{
    raiz = raiz->proximo;
    printf("Mostrando a pilha:\n");
    if (raiz)
    {
        cout << "\n\t\t--------------------pilha--------------------\n";
        do
        {
            printf("\t %d, ", raiz->valor);
            raiz = raiz->proximo;
        } while (raiz);
        cout << "\n\t\t--------------------pilha--------------------\n";
        printf("\n\n");
    }
    else
        printf("pilha vazia.\n\n");
}
