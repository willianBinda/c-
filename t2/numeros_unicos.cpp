#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

typedef struct no
{
    int val;
    struct no *proximo;
} No;

/*-----------------------INSERT------------------------------*/

void inserirNaFila(No **fila, int num)
{
    No *aux, *novo = NULL;
    novo = (No *)malloc(sizeof(No *));
    aux = (No *)malloc(sizeof(No *));
    if (novo)
    {
        novo->val = num;
        novo->proximo = NULL;
        
        if (*fila == NULL)
        {
            *fila = novo;
        }
        else{
            aux = *fila;
            while (aux->proximo)
            {
                aux = aux->proximo;
            }
            aux->proximo = novo;
        }
    }
    else
    {
        cout << "Erro em alocar memoria\n";
    }
}


/*-----------------------------IMPRIMIR-------------------------------*/

void imprimir(No *fila)
{
    cout << "\t----------fila---------\n\t";
    while (fila)
    {
        cout << fila->val<<", ";
        fila = fila->proximo;
    }
    cout << "\n\t----------fila---------\n";

}
/*----------------------Nova fila--------------------------------------*/

No *novaFila(No **fila){
    No *nova = NULL, *aux,*aux2;
    nova = (No *)malloc(sizeof(No *));
    aux = (No *)malloc(sizeof(No *));
    aux2 = (No *)malloc(sizeof(No *));
    aux = *fila;
    aux2 = *fila;
    int a = 0;

    while (aux)
    {
        while(aux2){

            if(aux->val==aux2->val){
                cout<<"igual";
            }
            aux2 = aux2->proximo;
            // cout<<aux->val;
        }
        aux = aux->proximo;
    }
    cout<<"\n";
    return aux;

}


/*----------------------MAIN--------------------------------------*/

int main(int argc, char const *argv[])
{
    No *r, *fila = NULL;

    inserirNaFila(&fila, 10);
    inserirNaFila(&fila,-4);
    inserirNaFila(&fila,2);
    inserirNaFila(&fila,6);
    inserirNaFila(&fila,4);
    inserirNaFila(&fila,2);
    imprimir(fila);
    r = novaFila(&fila);
    imprimir(r);


    return 0;
}

