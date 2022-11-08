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

void removeElemento(node *raiz, int val);
void insereElemento(node *raiz, int info);
void imprimePilha(node *p);

int main(void)
{
    printf("\n\n\n");
    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node *));
    raiz->valor = NULL;
    raiz->proximo = NULL;
    int op;
    int val;

    cout<<"\tTem um bug que diz que não existe o valor para remover mas o valor esta lá,"
    " porém quando eu tento remover outro valor da pilha e consigo o demias também é possivel."
    "Então tem que testar remover um por um.\n\n";
    do
    {
        printf(
            "\t0 - sair"
            "\n\t1 - Inserir valor"
            "\n\t2 - Remover valor"
            "\n\t3 - Mostrar pilha\n");
        cin >> op;
        switch (op)
        {
        case 1:
            cout << "Digite o valor que deseja inserir\n";
            cin >> val;
            insereElemento(raiz, val);
            break;
        case 2:
            if (raiz->proximo)
            {
                cout << "Qual valor você deseja remover da pilhaa\n";
                cin >> val;
                removeElemento(raiz, val);
            }
            else
            {
                cout << "Pilha vazia\n";
            }
            break;
        case 3:
            if (raiz)
            {
                imprimePilha(raiz);
            }
            break;
        default:
            if (op != 0)
            {
                cout << "Opcao invalida\n";
            }
        }
    } while (op != 0);

    // free(raiz);

    return 0;
}

void imprimePilha(node *raiz)
{
    raiz = raiz->proximo;
    printf("Mostrando a pilha:\n");
    if (raiz)
    {
        cout << "\n\t----------pilha---------\n";
        do
        {
            printf("\t %d, ", raiz->valor);
            raiz = raiz->proximo;
        } while (raiz);
        cout << "\n\t----------pilha---------\n";
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

void removeElemento(node *raiz, int val)
{
    node *p = raiz->proximo;
    node *anterior = raiz;
    while (p->proximo)
    {
        anterior = p;
        p = p->proximo;

        if (p->valor == val)
        {
            break;
        }
        else
        {
            cout << "Este numero não existe na pilha\n";
            return;
        }
    }
    anterior->proximo = p->proximo;
    p->proximo = NULL;
    free(p);
    cout << "Valor removido\n";
}
