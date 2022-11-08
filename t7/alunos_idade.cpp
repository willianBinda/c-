#include <iostream>
#include <stdlib.h>
#include <stdio.h>
using namespace std;

//Estrutura base do nó.
struct Node
{
    int matricula;
    int idade;
    string nome;
    struct Node *proximo;
};

typedef struct Node node;

void imprimeFila(node *raiz);
void insereNoFinal(node *raiz, int matricula, int idade);
void removeMenor(node *raiz, int n);

int main(void)
{
    printf("\n\n\n");
    node *raiz = NULL;
    raiz = (node *)malloc(sizeof(node *));
    raiz->matricula = NULL;
    raiz->idade = NULL;
    raiz->proximo = NULL;

    int matricula, idade,n;
    string nome;
    for (int i = 0; i < 5; i++)
    {
        // cout<<"Digite o nome do aluno: ";
        // cin>>nome;
        cout<<"Digite a matrícula do aluno: ";
        cin>>matricula;
        cout<<"Digite a idade do aluno: ";
        cin>>idade;
        
        insereNoFinal(raiz, matricula, idade);
    }
    cout<<"Digite um numero: ";
    cin>>n;
    imprimeFila(raiz);
    removeMenor(raiz,n);
    imprimeFila(raiz);
    

   

  free(raiz);

  return 0;
}

void removeMenor(node *raiz, int n){
    node *p = raiz->proximo;
    node *anterior = raiz;
    while (p)
    {
        if (p->idade < n)
        {
            cout<<p->idade;
            cout<<" menor de idade\n\n";

            anterior->proximo = p->proximo;
            // p->proximo = NULL;       //perguntar pro professor quando posso dar o free neste caso
            // free(p);

            
        }
        p = p->proximo;
    }
    

}


void imprimeFila(node *raiz)
{
    node *p = raiz->proximo;
    printf("Mostrando a lista:\n");
    if(p)
    {
        do
        {
            cout<<"Matricula: "<<p->matricula<<"\n";
            cout<<"Matricula: "<<p->idade<<"\n";
            cout<<"-------------------\n";
            p = p->proximo;
        }
        while(p);
        printf("\n\n");

    }
    else
        printf("Lista vazia.\n\n");
}

void insereNoFinal(node *raiz, int matricula, int idade){
    node *novo = NULL;
    novo = (node *)malloc(sizeof(node *));
    novo->matricula = matricula;
    novo->idade = idade;
    novo->proximo = NULL;

    node *ultimo = raiz;
    while (ultimo->proximo)
    {
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = novo;

}

