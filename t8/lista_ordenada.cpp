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
void inserirOrdenado(node *raiz, int val);

int main(void)
{
    printf("\n\n\n");
    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node *));
    raiz->valor = NULL;
    raiz->proximo = NULL;
    int val;

    inserirOrdenado(raiz,8);
    inserirOrdenado(raiz,20);
    inserirOrdenado(raiz,5);
    inserirOrdenado(raiz,30);
    imprimeFila(raiz);
    do
    {
        cout<<"Digite um valor: ";
        cin>>val;
        inserirOrdenado(raiz, val);
        imprimeFila(raiz);
    } while (true);
    
    


  free(raiz);

  return 0;
}


void inserirOrdenado(node *raiz, int val){
    node *novo;
    node *raiz2 = raiz;
    node *aux;
    novo = (node *)malloc(sizeof(node *));
    

    if(novo){
        novo->valor = val;
        // novo->proximo = NULL;
        if(raiz2 == NULL){
            novo->proximo = NULL;
            raiz2 = novo;
        }else if(novo->valor < raiz2->valor){
            novo->proximo = raiz2;
            raiz2 = novo;
        }else{
            aux = raiz2;
            while (aux->proximo && novo->valor > aux->proximo->valor)
            {
                aux = aux->proximo;
            }
            novo->proximo = aux->proximo;
            aux->proximo = novo;
        }
    }else{
        cout<<"Erro ao alocar memoria\n";
    }

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
