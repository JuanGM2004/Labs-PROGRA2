/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;
#include "MetodoExactoDeMemoria.h"

void lecturaDeLibros(const char*nombArch,char ***&libros,int **&stock){
    char **buffLib[280];
    int *buffStock[280];
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    int cantLib=0;
    while(true){
        LeerTriplete(arch,buffLib[cantLib]);
        if(arch.eof())break;
        LeerPar(arch,buffStock[cantLib]);
        arch.get();
        cantLib++;
    }
    libros=new char**[cantLib+1]{};
    stock=new int*[cantLib+1]{};
    for (int i = 0; i < cantLib; i++) {
        libros[i]=buffLib[i];
        stock[i]=buffStock[i];
    }
//    libros[cantLib]=nullptr;
//    stock[cantLib]=nullptr;
}

void LeerTriplete(ifstream &arch,char **&buffLib){
    buffLib=new char*[3];
    char *cod,*titu,*autor;
    cod=LeeCadena(arch);
    if(cod==nullptr)return;
    titu=LeeCadena(arch);
    autor=LeeCadena(arch);
    buffLib[0]=cod;
    buffLib[1]=titu;
    buffLib[2]=autor;
    
}
char *LeeCadena(ifstream &arch){
    char *pt,buff[80];
    arch.getline(buff,80,',');
    if(arch.eof())return nullptr;
    pt=new char[strlen(buff)+1];
    strcpy(pt,buff);
    return pt;
}


void LeerPar(ifstream &arch,int *&buffStock){
    int stock;
    double precio;
    buffStock=new int[2];
    arch>>stock;
    arch.get();
    arch>>precio;
    buffStock[0]=stock;
    buffStock[1]=0;
}
void pruebaDeLecturaDeLibros(const char*nombArch, char ***libros,
         int **stock){
    
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<left<<setw(10)<<"Codigo"<<setw(60)<<"Titulo del libro"<<setw(50)<<
            "Autor del libro"<<setw(30)<<"Stock disponible"<<setw(30)<<
            "Stock no atendido"<<endl;
    for (int i = 0;stock[i]; i++) {
        ImpresionDeDatos(arch,libros[i],stock[i]);

    }
}

void ImpresionDeDatos(ofstream &arch, char **libro, int *stock){
    
    arch<<left<<setw(10)<<libro[0]<<setw(60)<<libro[1]<<setw(50)<<libro[2]<<
            right<<setw(6)<<stock[0]<<setw(8)<<stock[1]<<endl;
}


void atencionePedidos(const char*nomb,char ***libros,int **&stock,
        int **&pedidosClientes,char ***&pedidosLibros,bool **&pedidosAtendidos){
    ifstream arch(nomb,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    int nro,dni,cantCli=0,pos,cantPed=0,maxnro=0;
    char **buffLib[200]{};
    int *buffCli[200]{};
    bool *buffAten[200]{};
    while(true){
        arch>>nro;
        if(nro>maxnro)maxnro=nro;
        if(arch.eof())break;
        arch.get();
        arch>>dni;
        pos=BuscarCli(dni,buffCli);
        if(pos!=-1){
            LlenarDatos(arch,buffCli[pos],buffLib[nro],buffAten[nro],nro,libros,stock);
        }
        else{
            Inicializar(buffCli[cantCli],dni);
            LlenarDatos(arch,buffCli[cantCli],buffLib[nro],buffAten[nro],nro,libros,stock);
            cantCli++;
        }
        cantPed++;
    }
    pedidosClientes=new int*[cantCli+1]{};
    pedidosLibros=new char**[maxnro+1]{};
    pedidosAtendidos=new bool*[maxnro+1]{};
    for (int i = 0; i < cantCli; i++) {
        ClientesExactos(pedidosClientes[i],buffCli[i]);
    }
    for (int i = 0; i < maxnro+1; i++) {
        pedidosLibros[i]=buffLib[i];
        pedidosAtendidos[i]=buffAten[i];
    }
}

int BuscarCli(int dni,int **pedidosClientes){
    for (int i = 0;pedidosClientes[i]; i++) {
        
        if(MismoDNI(dni,pedidosClientes[i])) return i;
    }
    return -1;
}

bool MismoDNI(int dni,int *pedidosClientes){
    return dni==pedidosClientes[0];
}

void Inicializar(int *&buffCli,int dni){
    buffCli=new int[35]{};
    buffCli[0]=dni;
}

void LlenarDatos(ifstream &arch,int *&buffCli,char **&buffLib,bool *&buffAten,int nro,
        char ***libros,int **&stock){
    int cantped=buffCli[1],cant=0,pos;
    buffCli[2+cantped]=nro;
    buffCli[1]++;
    char *pt,*buffLibs[30]{};
    bool buffAt[30]{};
    while(true){
        if(arch.get()=='\n')break;
        pt=leecadena(arch);
        pos=BuscarLib(libros,pt);
        buffLibs[cant]=pt;
        if(pos!=-1){
            if(HayStock(stock[pos]))buffAt[cant]=true;
            else buffAt[cant]=false;
        }
        else buffAt[cant]=false;
        cant++;
        
    }
    buffLib=new char*[cant+1]{};
    buffAten=new bool[cant+1]{};
    for (int i = 0;i<cant; i++) {
        buffLib[i]=buffLibs[i];
        buffAten[i]=buffAt[i];
    }

}

char *leecadena(ifstream &arch){
    char *pt,buff[10];
    arch>>buff;
    pt=new char[strlen(buff)+1];
    strcpy(pt,buff);
    return pt;
}

void ClientesExactos(int *&pedidosClientes,int *&buffCli){
    pedidosClientes=new int[buffCli[1]+3]{};
    
    for (int i = 0;buffCli[i]; i++) {
        pedidosClientes[i]=buffCli[i];
        
    }
//    delete buffCli;
}

int BuscarLib(char ***libros,char *pt){
    for (int i = 0;libros[i]; i++) {
        if(MismoCod(libros[i],pt)) return i;
    }
    return -1;
}

bool MismoCod(char **libros,char *pt){
    return strcmp(libros[0],pt)==0;
}
bool HayStock(int *&stock){
    int cant=stock[0];
    if(cant>0){
        cant--;
        stock[0]=cant;
        return true;
    }
    else{
        stock[1]++;
        return false;
    }
}


void reporteDeEntregaDePedidos(const char*nomb,int **pedidosClientes,
        char ***pedidosLibros,bool **pedidosAtendidos){
    ofstream arch(nomb,ios::out);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    
    arch<<"REPORTE DE ATENCION DE PEDIDOS"<<endl;
    for (int i = 0;pedidosClientes[i]; i++) {
        ImprimirLinea(arch,'=');
        ImprimirCli(arch,pedidosClientes[i],pedidosLibros,pedidosAtendidos);
    }
}

void ImprimirLinea(ofstream &arch,char a){
    for (int i = 0; i < 120; i++) arch<<a;
    arch<<endl;
}

void ImprimirCli(ofstream &arch, int *cli,char ***pedidosLibros,bool **pedidosAtendidos){
    arch<<left<<setw(10)<<"CLIENTE:"<<cli[0]<<endl;
    ImprimirLinea(arch,'=');
    int pos;
    for (int i = 0;i<cli[1]; i++) {
        pos=cli[i+2];
        arch<<right<<setw(20)<<"Pedido No."<<setw(26)<<"Codigo del libro"<<setw(20)<<"Observacion"<<endl;
        ImprimirLinea(arch,'-');
        ImprimirPedidos(arch,pedidosLibros[pos],pedidosAtendidos[pos],pos,i);
        ImprimirLinea(arch,'-');
    }

}
void ImprimirPedidos(ofstream &arch,char **pedidosLibros,bool *pedidosAtendidos,int pos,
        int j){
    
    for (int i = 0;pedidosLibros[i]; i++) {
        if(i == 0){
            arch<<right<<setw(20)<<pos<<setw(26)<<pedidosLibros[i]<<setw(20);
        }
        else{
            arch<<right<<setw(46)<<pedidosLibros[i]<<setw(20);
        }
        if(pedidosAtendidos[i])arch<<"ATENDIDO";
        else arch<<"NO ATENDIDO";
        arch<<endl;
    }
}

