#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

void somar(int *ptr){
    int a= 10;

    *ptr = a;
}

int main(int argc, char const *argv[])
{
    int a = 255, *ptr , **ptrr;
    // somar(ptr);
    ptr = &a;
    cout<<&a;
    cout<<"\n"<<*ptr;
    ptrr = &ptr;
    cout<<"\n"<<*ptrr;

    // cout<<"\n"<<*ptr;

    // cout<<ptr<<"\n";//endereco de memoria
    // cout<<*ptr<<"\n";//valor desse endereco de memoria
    // cout<<&a<<"\n";
    
    return 0;
}
