/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */


#include <fstream>
#include <cstring>
#include <iostream>
using namespace std;
#include "Estructuras.h"
#include "FuncionesAuxiliares.h"
#include "FuncionesBiblioteca.h"


void LeerLibros(struct Libro *arrLibros){
    ifstream arch("Libros.csv",ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    int cantLib=0;
    while(arch>>arrLibros[cantLib])cantLib++;

    strcpy(arrLibros[cantLib].codigo,"FIN");
}

void LeerClientes(struct Cliente *arrCli){
    int cantCli=0;
    ifstream archCli("Cientes.csv",ios::in);
    if(not archCli.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    while(archCli>>arrCli[cantCli])cantCli++;
    arrCli[cantCli].dni=0;
}

void LeePedidos(const char*nombArch, struct Cliente *arrcli, struct Libro *arrLib){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo pedidos"<<endl;
        exit(1);
    }
    
    int nro,dni,pos;
    char cod[8];
    struct LibroSolicitado pedido;
    while(true){
        arch>>nro;
        if(arch.eof())break;
        arch.get();
        arch>>dni;
        arch.get();
        pos=Buscar(dni,arrcli);
        if(pos!=-1){
            while(true){
                arch>>cod;
                if(arch.get()=='\n')break;
                strcpy(pedido.codigoDelLibro,cod);
                pedido.numeroDePedido=nro;
                if((pedido>>arrLib)){
                    if((arrcli[pos]<<pedido)){
                        ++arrcli[pos];
                    }
                }
                else arrcli[pos]<<pedido;
            }            
        }
        else{
            while(arch.get()!='\n');
        }

    }
    
}

int Buscar(int dni,const struct Cliente *arrcli){
    for (int i = 0;arrcli[i].dni; i++) {
        if(arrcli[i].dni==dni) return i;

    }
    return -1;
}

void EmitirReporte(const char*nomb,const struct Cliente *arrCli){
    ofstream archRep(nomb,ios::out);
    if(not archRep.is_open()){
        cout<<"No se pudo abrir el archivo "<<nomb<<endl;
        exit(1);
    }
    for (int i = 0;arrCli[i].dni; i++) {
        archRep<<arrCli[i];

    }

    
}

