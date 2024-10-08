/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"
#include "BibliotecaGenerica.h"

void crealista(void *&pedidos1,void *(*lee)(ifstream &),const char*nomb){
    ifstream arch(nomb,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    
    void *nodo;
    inicializarlista(pedidos1);
    while(true){
        nodo=lee(arch);
        if(nodo==nullptr)break;
        insertalista(pedidos1,nodo);
    }
}

void inicializarlista(void *&pedidos1){
    void **lista=new void*[2]{};
    pedidos1=lista;
}


void insertalista(void *lista,void *nodo){
    void **lis=(void **)lista;
    
    if(listavacia(lista)){
        lis[0]=nodo;
        lis[1]=nodo;
    }
    else{
        void **nodoUl=(void **)lis[1];
        nodoUl[1]=nodo;
        lis[1]=nodo;
    }
}

bool listavacia(void *lista){
    void **lis=(void **)lista;
    
    return lis[0]==nullptr;
}


void imprimelista(void *pedidos1,void (*imprime)(ofstream &,void *),const char*nomb){
    ofstream arch(nomb,ios::out);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    
    void **lista=(void **)pedidos1, **nodo;
    nodo=(void **)lista[0];
    while(nodo!=nullptr){
        imprime(arch,nodo);
        nodo=(void **)nodo[1];
    }

}

void combinalista(void *pedidos1,void *pedidos2,void *&pedidosfinal,int (*cmp)(void *,void *)){
    void *d1,*d2;
    inicializarlista(pedidosfinal);
    while(not listavacia(pedidos1) and not listavacia(pedidos2)){
        if(cmp(pedidos1,pedidos2)<0){
            d1=quitalista(pedidos1);
        }
        else if(cmp(pedidos1,pedidos2)>0){
            d1=quitalista(pedidos2);            
        }
        else{
            d1=quitalista(pedidos1);
            d2=quitalista(pedidos2);
            
        }
        insertalista(pedidosfinal,d1);
    }
    void *d;
    while(not listavacia(pedidos1)){
        d=quitalista(pedidos1);
        insertalista(pedidosfinal,d);
    }
    while(not listavacia(pedidos2)){
        d=quitalista(pedidos2);
        insertalista(pedidosfinal,d);
    }
    
}

void *quitalista(void *&ped){
    void **lista=(void **)ped;
    void **cabeza=(void **)lista[0];
    lista[0]=cabeza[1];
    return cabeza;
}



