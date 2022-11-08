#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include<time.h>
using namespace std;

// Estrutura base do nó.
struct Node
{
    int valor;
    struct Node *proximo;
};

typedef struct Node node;

void removeElemento(node *raiz, int val);
void insereElemento(node *raiz, int info);
void imprimePilha(node *p);
int cont(node *p);

int main(void)
{
    printf("\n\n\n");
    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node *));
    raiz->valor = NULL;
    raiz->proximo = NULL;
    int op,i,val,aleatorio,contador;


    cout<<"Se o número digitado for par, ele será inserido na pilha\n";
    cout<<"Se o número digitado for impar, será retirado um valor aleatório da pilha\n";
    for(i=0;i<15;i++){
        cout<<"Digite um numero: ";
        cin>>val;
        if(val%2==0){
            insereElemento(raiz,val);
        }else{
            if(raiz->proximo){
                contador = cont(raiz);
                aleatorio = rand()%contador+1;
                removeElemento(raiz,aleatorio);
            }else{
                cout<<"Pilha vazia\n";
                continue;
            }
        }
    }
    imprimePilha(raiz);

    return 0;
}

int cont(node *raiz){
    int i = 0;
    raiz = raiz->proximo;
    if (raiz)
    {
        do
        {
            i++;
            raiz = raiz->proximo;
        } while (raiz);
    }
    else
        printf("pilha vazia.\n\n");

    return i;
}

void imprimePilha(node *raiz)
{
    raiz = raiz->proximo;
    printf("Mostrando a pilha:\n");
    if (raiz)
    {
        cout << "\n\t\t----------pilha---------\n";
        do
        {
            printf("\t %d, ", raiz->valor);
            raiz = raiz->proximo;
        } while (raiz);
        cout << "\n\t\t----------pilha---------\n";
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

void removeElemento(node *raiz, int posicao)
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
