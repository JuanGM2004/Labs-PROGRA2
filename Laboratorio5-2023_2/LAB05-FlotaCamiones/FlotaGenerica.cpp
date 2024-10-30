/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"
#include "FlotaGenerica.h"

using namespace std;


void cargacamiones(void *flota,int numcamiones,double pesomaximo,
        void *(*leenumero)(ifstream &),void *(*calculanumero)(void *),const char*nomb){
 
    
    
    ifstream arch(nomb,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    void *dato;
    void *pesototal;
    inicializarPila(flota);
    while(true){
        dato=leenumero(arch);
        if(dato==nullptr)break;
        pesototal=calculanumero(dato);
        push(dato,flota);
        
        
    }
    
    
    
    
}
void inicializarPila(void *&flota){
    void **aux=new void*[2]{};
    
    flota=aux;
}

void push(void *dato,void *flota){
    void **lista=(void **)flota;
    lista[0]=dato;
    
}


