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
    arch.get();
}
void pruebaDeLecturaDeLibros(const char*nombArch, char ***libros,
         int **stock){
    
    ofstream arch(nombArch,ios::out);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<nombArch<<endl;
        exit(1);
    }
    arch<<left<<setw(10)<<"Codigo"<<setw(60)<<"Titulo del libro"<<setw(50)<<
            "Autor del libro"<<setw(6)<<"Stock disponible"<<endl;
    for (int i = 0;stock[i]; i++) {
        ImpresionDeDatos(arch,libros[i],stock[i]);

    }
}

void ImpresionDeDatos(ofstream &arch, char **libro, int *stock){
    
    arch<<left<<setw(10)<<libro[0]<<setw(60)<<libro[1]<<setw(50)<<libro[2]<<
            right<<setw(6)<<stock[0]<<endl;
}
