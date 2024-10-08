/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"

void *leenum(ifstream &arch){
    
    void **nodo=new void*[2]{};
    int *num=new int;
    arch>>*num;
    if(arch.eof())return nullptr;
    arch.get();
    nodo[0]=num;
    nodo[1]=nullptr;
    return nodo;
}

void imprimenum(ofstream &arch,void *nodo){
    void **dato=(void **)nodo;
    int *num=(int *)dato[0];
    
    arch<<*num<<endl;
    
}

int cmpnum(void *n1,void *n2){
    void **lis1=(void **)n1,**lis2=(void **)n2;
    void **nodo1=(void **)lis1[0],**nodo2=(void **)lis2[0];
    
    int *d1=(int *)nodo1[0],*d2=(int *)nodo2[0];
    
    return *d1-*d2;
}



