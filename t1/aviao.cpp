#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>
#include<time.h>
using namespace std;

typedef struct no
{
    int id;
    int placa;
    int capacidade;
    float valor;
    struct no *proximo;
} No;

void inserirNaFila(No **fila, int num)
{
    srand(time(0));
    No *aux, *novo = NULL;
    novo = (No *)malloc(sizeof(No *));
    aux = (No *)malloc(sizeof(No *));
    if (novo)
    {
        novo->id = num;
        novo->placa = rand()%100;
        novo->capacidade =rand()%100;
        novo->valor = rand()%100000;
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

No *removerDaFila(No **fila)
{
    No *remover = NULL;
    if (*fila)
    {
        remover = *fila;
        *fila = remover->proximo;
    }
    else
    {
        cout << "Nenhum avião na fila de espera\n\n";
    }
    return remover;
}

void imprimir(No *fila)
{
    cout << "\t----------fila---------\n\t";
    while (fila)
    {
        cout << "id: " << fila->id<<", ";
        fila = fila->proximo;
    }

    cout << "\n\t----------fila---------\n";
    if(!fila){
        cout<<"\nNenhum avião na fila de espera\n\n";
    }
}

void nAvioes(No *fila)
{
    int nAvioes = 0;
    while (fila)
    {
        nAvioes++;
        fila = fila->proximo;
    }
    cout << "\nNúmero de avioes em espera: "<<nAvioes<<"\n\n";
}

void primeiroAV(No *fila)
{
    if(fila)
    {
        cout << "\n\nId do avião: " << fila->id;
        cout<<  "\nPlaca do avião: "<<fila->placa;
        cout<<"\nCapacidade do avião: "<<fila->capacidade;
        cout<<"\nValor do avião: "<<fila->valor<<"\n\n";
    }
    else{
        cout<<"\nNenhum avião na fila de espera\n\n";
    }
}

int main(int argc, char const *argv[])
{
    No *r, *fila = NULL;
    int op, val,id=0;

    do
    {
        printf(
            "\t0 - sair"
            "\n\t1 - Listar o numero de aviões para decolar!"
            "\n\t2 - Autorizar a decolagem do primeiro avião!"
            "\n\t3 - Adicionar avião a fila de espera!"
            "\n\t4 - Listar todos os aviões da fila de espera!"
            "\n\t5 - Listar as caracteristicas do primeiro avião da fila de espera!\n");
            
        cin >> op;
        switch (op)
        {
        case 1:
            nAvioes(fila);
            break;
        case 2:
            r = removerDaFila(&fila);
            if (r)
            {
                cout <<"avião decolando\n\n";
                free(r);
            }
            break;

        case 3:
            // id++;
            srand(time(0));
            inserirNaFila(&fila, rand());
            cout<<"\nAvião adicionado a fila de espera para a decolagem!\n\n";
            break;

        case 4:
            imprimir(fila);
            break;

        case 5:
            primeiroAV(fila);
            break;

        default:
            if (op != 0)
            {
                cout << "Opcao invalida\n";
            }
        }
    } while (op != 0);

    return 0;
}

