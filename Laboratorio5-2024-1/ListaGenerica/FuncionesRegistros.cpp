/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include "Utils.h"
#include "FuncionesRegistros.h"


void *leeregistro(ifstream &arch){
    void **nodo=new void *[2]{},**reg=new void*[3]{};
    int *nro=new int,*dni=new int;
    char *cod,buff[10]{};
    arch>>*nro;
    if(arch.eof())return nullptr;
    arch.get();
    arch>>*dni;
    arch.get();
    arch.getline(buff,10,'\n');
    cod=new char[strlen(buff)+1]{};
    strcpy(cod,buff);
    reg[0]=nro;
    reg[1]=dni;
    reg[2]=cod;
    nodo[0]=reg;
    return nodo;
}

void imprimeregistro(ofstream &arch,void *nodo){
    void **n=(void **)nodo,**reg;
    reg=(void **)n[0];
    int *nro=(int *)reg[0],*dni=(int *)reg[1];
    char *cod=(char *)reg[2];
    
    arch<<left<<setw(10)<<*nro<<setw(12)<<*dni<<setw(12)<<cod<<endl;
}

int cmpregistro(void *li1,void *li2){
    void **lis1=(void **)li1,**lis2=(void **)li2;
    void **nodo1=(void **)lis1[0],**nodo2=(void **)lis2[0];
    
    void **d1=(void **)nodo1[0],**d2=(void **)nodo2[0];
    int *n1=(int *)d1[0],*n2=(int *)d2[0];
    
    return *n1-*n2;
}

