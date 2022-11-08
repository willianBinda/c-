#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;


typedef struct no{
    int valor;
    struct no *proximo;
}No;

void inserirNaFila(No **fila, int num ){
    No *aux, *novo = NULL;
    novo = (No *)malloc(sizeof(No *));
    aux = (No *)malloc(sizeof(No *));
    if(novo){
        novo->valor =num;
        novo->proximo = NULL;
        if(*fila ==NULL){
            *fila = novo; 
        }else{
            aux = *fila;
            while (aux->proximo)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
            
        }
    }else{
        cout<<"Erro em alocar memoria\n";
    }

}

No* removerDaFila(No **fila){
    No *remover = NULL;
    if(*fila){
        remover = *fila;
        *fila = remover->proximo;
    }else{
        cout<<"fila vazia\n";
    }
    return remover;
}

void imprimir(No *fila){
    cout<<"\t----------fila---------\n\t";
    while (fila)
    {
        cout<<fila->valor;
        fila = fila->proximo;
    }
    
    cout<<"\n\t----------fila---------\n";
}

int main(int argc, char const *argv[])
{
    No *r,*fila =NULL;
    imprimir(fila);
    inserirNaFila(&fila,1);
    inserirNaFila(&fila,2);
    inserirNaFila(&fila,3);
    imprimir(fila);
    r = removerDaFila(&fila);
    if(r){
        cout<<r->valor;
        free(r);
    }
    imprimir(fila);


    return 0;
}



// // Estrutura base do nó.
// struct Node
// {
//     int valor;
//     struct Node *proximo;
// };

// typedef struct Node node;

// void remove_no_inicio(node *raiz);
// void insere_no_final(node *raiz, int info);
// void displayLL(node *p);

// int main(void)
// {
//     printf("\n\n\n");
//     node *raiz = NULL;
//     raiz = (node *)malloc(sizeof(node *));
//     raiz->valor = NULL;
//     raiz->proximo = NULL;

//     // Mostrando a lista.
//     if (raiz)
//         displayLL(raiz);

//     int zero = 0;
//     printf("Inserindo novo item: %d\n", zero);
//     insere_no_final(raiz, zero);
//     if (raiz)
//         displayLL(raiz);

//     int um = 1;
//     printf("Inserindo novo item: %d\n", um);
//     insere_no_final(raiz, um);
//     if (raiz)
//         displayLL(raiz);

//     int dois = 2;
//     printf("Inserindo novo item: %d\n", dois);
//     insere_no_final(raiz, dois);
//     if (raiz)
//         displayLL(raiz);

//     printf("Removendo item: %d\n", zero);
//     remove_no_inicio(raiz);
//     if (raiz)
//         displayLL(raiz);

//     // printf("Removendo item: %d\n", um);
//     // remove_no_inicio(raiz);
//     // if (raiz)
//     //     displayLL(raiz);

//     // printf("Removendo item: %d\n", dois);
//     // remove_no_inicio(raiz);
//     // if (raiz)
//     //     displayLL(raiz);

//     // free(raiz);

//     return 0;
// }

// void displayLL(node *p){
//     p = p->proximo;
//     printf("Mostrando a fila:\n");
//     if (p)
//     {
//         do
//         {
//             printf(" %d", p->valor);
//             p = p->proximo;
//         } while (p);
//         printf("\n\n");
//     }
//     else
//         printf("Fila vazia.\n\n");
// }

// void insere_no_final(node *raiz, int info){

//     node *novo = NULL;
//     novo = (node *)malloc(sizeof(node *));
//     novo->valor = info;
//     novo->proximo = NULL;

//     node *ultimo = raiz;
//     while (ultimo->proximo)
//     {
//         ultimo = ultimo->proximo;
//     }
//     ultimo->proximo = novo;
// }

// void remove_no_inicio(node *raiz){

//     node *primeiro = raiz->proximo;
//     raiz->proximo = primeiro->proximo;
//     free(primeiro);
// }
