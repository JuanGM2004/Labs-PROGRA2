/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include <iomanip>
#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
#include "MetodoExactoDeMemoria.h"
#define INC 5


void lecturaDeLibros(const char*nomb,char ***&libros,int **&stock){
    ifstream arch(nomb,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    libros=nullptr;
    stock=nullptr;
    int capacidad=0,cantidad=0;
    int *doblete;
    char **triplete;
    while(true){
        if(capacidad==cantidad)IncrementarEspacios(libros,stock,capacidad,cantidad);
        triplete=LeerTriplete(arch);
        if(triplete==nullptr)break;
        //if(arch.eof())break;
        doblete=LeerDoblete(arch);
        libros[cantidad-1]=triplete;
        stock[cantidad-1]=doblete;
        cantidad++;
    }
//    cout<<cantidad;
    
}

void IncrementarEspacios(char ***&libros,int **&stock,int &capacidad, int &cantidad){
    capacidad+=INC;
    int **auxStock;
    char ***auxlib;
    if(libros==nullptr){
        libros=new char**[capacidad]{}; //{1="juan",2='pepe',3='unamec',4='movistar',5='null'}   cd=1234, cd+1=nullptr
        stock=new int *[capacidad]{};
        cantidad=1;
    }
    else{
        auxlib=new char**[capacidad]{};
        auxStock=new int*[capacidad]{};
        for (int i = 0;i<cantidad; i++) {
            auxlib[i]=libros[i];
            auxStock[i]=stock[i];
        }
        delete libros;
        delete stock;
        libros=auxlib;
        stock=auxStock;
    }
}

char** LeerTriplete(ifstream &arch){
    char *cod,*titu,*aut,**triple=new char*[3];
    cod=leeCadena(arch,',');
    if(cod==nullptr)return nullptr;
    titu=leeCadena(arch,',');
    aut=leeCadena(arch,',');
    triple[0]=cod;
    triple[1]=titu;
    triple[2]=aut;
    
    return triple;
}
char *leeCadena(ifstream &arch,char a){
    char *pt,buff[80];
    arch.getline(buff,80,a);
    if(arch.eof())return nullptr;
    pt=new char[strlen(buff)+1]{};
    strcpy(pt,buff);
    return pt;
}

int *LeerDoblete(ifstream &arch){
    int cant,*doble=new int[2]{};
    double pre;
    arch>>cant;
    arch.get();
    arch>>pre;
    doble[0]=cant;
    doble[1]=0;
    arch.get();
    return doble;
}

void pruebaDeLecturaDeLibros(const char*nomb,char ***libros,int **stock){
    ofstream arch(nomb,ios::out);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    arch<<left<<setw(10)<<"CODIGO"<<setw(60)<<"TITULO"<<setw(40)<<"AUTOR"<<
            right<<setw(10)<<"STOCK"<<setw(10)<<"CANT ATEN."<<endl;
    for (int i = 0;libros[i]; i++) {
        ImprimirLinea(arch,libros[i],stock[i]);
    }

    
}

void ImprimirLinea(ofstream &arch,char **libros,int *stock){
    arch<<left<<setw(10)<<libros[0]<<setw(60)<<libros[1]<<setw(40)<<libros[2]<<
            right<<setw(10)<<stock[0]<<setw(10)<<stock[1]<<endl;
}

void atencionDePedidos(const char*nomb,char ***libros,int **&stock,
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    ifstream arch(nomb,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    int capacidadPed=0,cantidad=0,nro,capCli=0,capClixP[200]{},cantCli=0,pos,dni;
    while(true){
        arch>>nro;
        if(arch.eof())break;
        cout<<nro<<endl;
        arch.get();
        arch>>dni;
//        arch.get();
        if(capCli==cantidad)IncreCli(pedidosClientes,capCli,cantCli);
        pos=BuscarCliente(pedidosClientes,dni);
        if(pos!=-1){
            AsignarDatos(arch,pedidosClientes[pos],nro,dni,capClixP[pos]);
        }
        else{
            AsignarDatos(arch,pedidosClientes[cantCli],nro,dni,capClixP[cantCli]);
            cantCli++;
        }
        if(capacidadPed<nro)Incremento(pedidosLibros,pedidosAtendidos,capacidadPed,cantidad,nro);
        while(arch.get()!='\n');
//        LeerPedidos(arch,pedidosClientes[cantidad-1],pedidosLibros[nro],pedidosAtendidos[nro]);
    }
    
}

void IncreCli(int **&pedidosClientes,int &capCli,int &cantidad){
    int **auxCli;
    capCli+=INC;
    if(pedidosClientes==nullptr){
        pedidosClientes=new int*[capCli]{};
        cantidad=1;
    }
    else{
        auxCli=new int*[capCli]{};
        for (int i = 0; i < cantidad; i++) {
            auxCli[i]=pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes=auxCli;
    }
}
int BuscarCliente(int **pedidosClientes,int dni){
    for (int i = 0; pedidosClientes[i]; i++) {
        if(EsCliente(pedidosClientes[i],dni))return i;
    }
    return -1;
}
bool EsCliente(int *pedidosClientes,int dni){
    return pedidosClientes[0]==dni;
}


void AsignarDatos(ifstream &arch,int *&pedidosClientes,int nro,int dni,int cap){
    if(pedidosClientes==nullptr or pedidosClientes[1]+3==cap)IncreDatCli(pedidosClientes,
            cap,dni);
    
    int cant=pedidosClientes[1];
    pedidosClientes[cant+2]=nro;
    cap++;
    if(cap==cant)IncreDatCli(pedidosClientes,cap,dni);
    
}
void IncreDatCli(int *&pedidosClientes,int &cap,int dni){
    cap+=INC;
    int *auxCli;
    if(pedidosClientes==nullptr){
        pedidosClientes=new int[cap]{};
        pedidosClientes[0]=dni;
        pedidosClientes[1]=0;
    }
    else{
        auxCli=new int[cap]{};
        for (int i = 0;i<pedidosClientes[1]+2; i++) {
            auxCli[i]=pedidosClientes[i];
        }
        delete pedidosClientes;
        pedidosClientes=auxCli;
    }
}


void Incremento(char ***&pedidosLibros,bool **&pedidosAtendidos,int &capacidad,
        int &cantidad,int nro){
    capacidad=nro+INC;
    char ***auxLib;
    bool **auxAten;
    
    if(cantidad==0){
        pedidosLibros=new char**[capacidad]{};
        pedidosAtendidos=new bool*[capacidad]{};
        cantidad=1;
    }
    else{
        auxLib=new char**[capacidad]{};
        auxAten=new bool*[capacidad]{};
        for (int i = 0; i <cantidad; i++) {
            auxLib[i]=pedidosLibros[i];
            auxAten[i]=pedidosAtendidos[i];
        }
        delete pedidosLibros;
        delete pedidosAtendidos;
        pedidosLibros=auxLib;
        pedidosAtendidos=auxAten;
        
    }
    
}

