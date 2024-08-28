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
}

void LeePedidos(const char*nombArch, struct Cliente *arrcli, struct Libro *arrLib){
    ifstream arch(nombArch,ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo pedidos"<<endl;
        exit(1);
    }
    
    int nro,dni;
    char cod[8];
    
    while(true){
        arch>>nro;
        if(arch.eof())break;
        arch.get();
        arch>>dni;
        arch.get();
//        pos=Buscar
    }
    
}
