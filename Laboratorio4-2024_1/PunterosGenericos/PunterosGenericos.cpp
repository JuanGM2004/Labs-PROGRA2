/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.cc to edit this template
 */

#include <fstream>
#include <iostream>
#include <cstring>
using namespace std;
#include "AperturaDeArchivos.h"
#include "PunterosGenericos.h"

void cargaclienctes(void *&clientes){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Clientes.csv");
    void **arrCli=new void*[70]{},*reg;//*arrcli[70]
    int nd=0;
    
    while(true){
        reg=LeerRegistro(arch);
        if(reg==nullptr)break;
        arrCli[nd]=reg;
        nd++;
    }
    void **aux=new void*[nd+1]{};
    for (int i = 0; i<nd; i++) {
        aux[i]=arrCli[i];
    }
    delete arrCli;
    clientes=aux;
}

void *LeerRegistro(ifstream &arch){
    int dni,*ptint=new int;
    char *pt;
    void **reg=new void*[2]{};
    arch>>dni;
    *ptint=dni;
    if(arch.eof())return nullptr;
    arch.get();
    pt=leeCadena(arch,'\n');
    reg[0]=ptint;
    reg[1]=pt;
    return reg;
}

char *leeCadena(ifstream &arch,char a){
    char buff[80]{},*pt;
    arch.getline(buff,80,a);
    pt=new char[strlen(buff)+1]{};
    strcpy(pt,buff);
    return pt;
}

void creareserva(void *&reserva){
    ifstream arch;
    AperturaDeUnArchivoDeTextosParaLeer(arch,"Libros.csv");
    void *reservas[300]{},*reg,**aux;
    int cant=0;
    while(true){
        reg=Leerlibros(arch);
        if(reg==nullptr)break;
        reservas[cant]=reg;
        cant++;
    }
    aux=new void*[cant+1]{};
    for (int i = 0; i < cant; i++) {
        aux[i]=reservas[i];
    }
    reserva=aux;
}

void *Leerlibros(ifstream &arch){
    char *cod,*nom,*autor;
    int cant,*ptint=new int;
    double pre;
    void **reg=new void*[5]{};
    cod=leeCadena(arch,',');
    if(arch.eof())return nullptr;
    nom=leeCadena(arch,',');
    autor=leeCadena(arch,',');
    arch>>cant;
    arch.get();
    arch>>pre;
    *ptint=cant;
    reg[0]=cod;
    reg[1]=nom;
    reg[2]=autor;
    reg[4]=ptint;
    if(cant!=0)AsignaEspacio(reg[3],cant);
    arch.get();
    return reg;
}

void AsignaEspacio(void *&reg,int cant){
    void **pedidos=new void*[cant+1]{};
    reg=pedidos;
}

void cargarreservar(void *clientes,void *&reserva){
    ifstream arch("pedidos2.csv",ios::in);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo"<<endl;
        exit(1);
    }
    int dni,pos,posLib;
    char cod[10]{};
   
    void **arrcli=(void **)clientes;
    while(true){
        arch>>dni;
        if(arch.eof())break;
        arch.get();
        arch.getline(cod,10,'\n');
        pos=BuscarCliente(clientes,dni);
        
        if(pos!=-1){
            IngresarDatos(arrcli[pos],reserva,cod);
        }
        
    }
    
}

int BuscarCliente(void *clientes,int dni){
    void**arrCli=(void**)clientes;
    for (int i = 0;arrCli[i]; i++) {
        if(Verificar(arrCli[i],dni))return i;
    }
    return -1;
    
}

bool Verificar(void *arrCli,int dni){
    void **datos=(void **)arrCli;
    int *dniD=(int *)datos[0];
    
    return dni==*dniD;
}

void IngresarDatos(void *arrcli,void *&reserva, char *cod){
    int posLib;
    void **libros=(void **)reserva;
    for (int i = 0;libros[i]; i++) {
        if(Coincide(cod,libros[i])){
            Ingresar(arrcli,libros[i]);
            break;
        }
    }
}

bool Coincide(char *cod,void *libros){
    void **datos=(void **)libros;
    char *codigo=(char *)datos[0];
    
    return strcmp(cod,codigo)==0;
}

void Ingresar(void *arrcli,void *&libros){
    void **datos=(void **)libros;
    int *cant=(int *)datos[4],pos=0,stock;
    if(*cant<1)return;
    void **cli=(void **)datos[3],*par;
    
    Llenar(par,arrcli);
    while(cli[pos])pos++;
    cli[pos]=par;
    stock=*cant;
    stock--;
    *cant=stock;
}

void Llenar(void *&par,void* arrcli){
    void **doblete=new void *[2]{}, **aux=(void **)arrcli;
    int *dni,*d2=(int *)aux[0];
    dni=new int;
    *dni=*d2;
    doblete[0]=dni;
    char *nom,*auxCli=(char *)aux[1];
    nom=new char[strlen(auxCli)+1]{};
    strcpy(nom,auxCli);
    doblete[1]=nom;
    
    par=doblete;
}

//void AperturaDeUnArchivoDeTextosParaEscribir(std::ofstream& archivo, const char* nombreArchivo) {
//    archivo.open(nombreArchivo);
//    if (!archivo.is_open()) {
//        // Manejo de errores
//        std::cerr << "No se pudo abrir el archivo: " << nombreArchivo << std::endl;
//    }
//}


void reporteFinal_2(void *reserva){
    ofstream arch("ReporteFinal2.txt",ios::out);
    if(not arch.is_open()){
        cout<<"No se pudo abrir el archivo "<<endl;
        exit(1);
    }
    
    arch<<"Reporte de libros Reservados"<<endl;
    ImprimirLinea(arch,'=');
    void **arrLib=(void **)reserva;
    for (int i = 0;arrLib[i]; i++) {
        ImprimirDatos(arch,arrLib[i]);

    }

    
    
}

void ImprimirLinea(ofstream &arch,char a){
    for (int i = 0; i <120; i++) {
        arch<<a;
    }
    arch<<endl;
}


void ImprimirDatos(ofstream &arch,void *arrLib){
    void **reg=(void **)arrLib;
    char *cod=(char *)reg[0],*nom=(char *)reg[1],*autor=(char *)reg[2];
    
    arch<<"Libro:"<<cod<<endl;
    arch<<"Nombre del libro:"<<nom<<endl;
    arch<<"Autor:"<<autor<<endl;
    arch<<left<<setw(12)<<"DNI"<<setw(40)<<"Nombre del solicitante"<<endl;
    ImprimirLinea(arch,'-');
    if(reg[3]!=nullptr){
        void **lista=(void **)reg[3];
        char *cli;
        int *dni;
        for (int i = 0;lista[i]; i++) {
            void **dato=(void **)lista[i];
            dni=(int *)dato[0];
            cli=(char *)dato[1];
            arch<<left<<setw(12)<<*dni<<setw(40)<<cli<<endl;
        }
    }
    arch<<endl;
}
