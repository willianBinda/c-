#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

//Estrutura base do nó.
struct Alunos
{
    int matricula;
    int idade;
    struct Alunos *proximo;
};

typedef struct Alunos aluno;

void imprimeFila(aluno *raiz);
void insereNoInicio(aluno *raiz, int matricula, int idade);
void removeNoMeio(aluno *raiz, int posicao);
void insereElemento(aluno *raiz, int matricula, int idade);
void percoreFila(aluno *raiz, int matricula);


int main(void)
{
    printf("\n\n\n");
    aluno *raiz = NULL;
    raiz = (aluno *)malloc(sizeof(aluno *));
    raiz->matricula = NULL;
    raiz->idade = NULL;
    raiz->proximo = NULL;

    int i=0,matricula,idade;
    std::string nome;
    for(i=0;i<2;i++){
        cout<<"\nDigite a matrícula do aluno: ";
        cin>>matricula;
        cout<<"\nDigite a idade do aluno: ";
        cin>>idade;

        insereElemento(raiz, matricula, idade);
        percoreFila(raiz, 321);
    }
    imprimeFila(raiz);
    free(raiz);

  return 0;
}

void percoreFila(aluno *raiz,int matricula){
    int i=0;
    raiz = raiz->proximo;
    if(raiz){
        do
        {
            if(raiz->matricula==123){
                cout<<"-----iguai---\n";
                // removeNoMeio(raiz, i);
                break;
            }
            i++;
            raiz=raiz->proximo;
        } while (raiz);
        
    }else{
        cout<<"pilha vazia\n";
    }
}

//Função pra printar o nó na tela.
void imprimeFila(aluno *raiz)
{
    aluno *p = raiz->proximo;
    printf("Mostrando a lista:\n");
    if(p)
    {
        cout << "\n\t\t--------------------fila--------------------\n";
        do
        {
            cout<<"Matricula: "<<p->matricula<<"\n";
            cout<<"Idade: "<<p->idade<<"\n";
            cout<<"--------------------------\n";
            p = p->proximo;
        }
        while(p);
        cout << "\n\t\t--------------------fila--------------------\n";
        printf("\n\n");

    }
    else
        printf("Lista vazia.\n\n");
}

// Função para inserir nó no inicio
void insereNoInicio(aluno *raiz, int matricula, int idade){
    aluno *novo = (aluno *) malloc(sizeof(aluno *));
    novo->matricula = matricula;
    novo->idade = idade;
    novo->proximo = raiz->proximo;
    raiz->proximo = novo;
}


// Função para remover nó no meio
void removeNoMeio(aluno *raiz, int posicao)
{
    aluno *p = raiz->proximo;
    aluno *anterior = raiz;
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

void insereElemento(aluno *raiz, int matricula,int idade)
{
    aluno *novo = NULL;
    novo = (aluno *)malloc(sizeof(aluno *));
    novo->matricula = matricula;
    novo->idade = idade;
    novo->proximo = NULL;

    aluno *ultimo = raiz;
    while (ultimo->proximo)
    {
        ultimo = ultimo->proximo;
    }
    ultimo->proximo = novo;
}